//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <ifaddrs.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PORT_NO 65535
#define MIN_PORT_NO 0

struct addr_port {
  char ipv4[INET_ADDRSTRLEN+1];
  int port;
};

struct scanning_args {
  char *ip_addr;
  int start_port;
  int end_port;
};

bool is_port_open(char *ip_address, int port_no); 
void sig_handler(int signum);
void scan_network(char *ip_addr);
void collect_ip_addresses(char *ip_range_start, char *ip_range_end);
void *scan_single_port_thread_job(void *args);
struct scanning_args *create_scanning_args(char *ip_addr, int start_port, int end_port);

int main(int argc, char *argv[]) {
  signal(SIGINT, sig_handler);
  if(argc != 3) {
    printf("Please run the program by entering the starting and ending IP addresses in the following format:\n./network_mapper <start_ip_address> <end_ip_address>\n");
    exit(EXIT_FAILURE);
  }

  collect_ip_addresses(argv[1], argv[2]);
  return 0;
}

void sig_handler(int signum) {
  printf("Interrupt signal received\n");
  exit(signum);
}

bool is_port_open(char *ip_address, int port_no) {
  int sockfd, conn_rtn;
  struct sockaddr_in server_address;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0) {
    perror("Socket creation error");
  }

  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(port_no);
  inet_pton(AF_INET, ip_address, &server_address.sin_addr);

  conn_rtn = connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address));
  if(conn_rtn < 0) {
    if(errno != ECONNREFUSED) {
      perror("Error connecting socket");
    }
    close(sockfd);
    return false;
  }

  close(sockfd);
  return true;
}

void scan_network(char *ip_addr) {
  int start_port, end_port, i;
  scanf("%d", &start_port);
  scanf("%d", &end_port);

  pthread_t thread_id[end_port-start_port+1];
  struct scanning_args *args;

  printf("Scanning IP address: %s\n", ip_addr);

  for(i = start_port; i <= end_port; i++) {
    args = create_scanning_args(ip_addr, i, i);
    pthread_create(&thread_id[i-start_port], NULL, scan_single_port_thread_job, (void *)args);
  }

  for(i = start_port; i <= end_port; i++) {
    pthread_join(thread_id[i-start_port], NULL);
  }
}

void collect_ip_addresses(char *ip_range_start, char *ip_range_end) {
  char current_ip[INET_ADDRSTRLEN+1];
  struct in_addr start, end;
  struct in_addr *current_ip_addr;
  inet_pton(AF_INET, ip_range_start, &start);
  inet_pton(AF_INET, ip_range_end, &end);

  current_ip_addr = &start;
  while(memcmp(current_ip_addr, &end, 4) <= 0) {
    inet_ntop(AF_INET, current_ip_addr, current_ip, INET_ADDRSTRLEN);
    scan_network(current_ip);
    current_ip_addr->s_addr = htonl(ntohl(current_ip_addr->s_addr)+1);
  }
}

void *scan_single_port_thread_job(void *args) {
  struct scanning_args *scan_args = (struct scanning_args *)args;
  int port_no = scan_args->start_port;
  bool is_open = is_port_open(scan_args->ip_addr, port_no);

  if(is_open) {
    printf("%s:%d is open\n", scan_args->ip_addr, port_no);
  }

  free(scan_args);
  return NULL;
}

struct scanning_args *create_scanning_args(char *ip_addr, int start_port, int end_port) {
  struct scanning_args *args = (struct scanning_args *)malloc(sizeof(struct scanning_args));
  strncpy(args->ip_addr, ip_addr, sizeof(args->ip_addr));
  args->start_port = start_port;
  args->end_port = end_port;

  return args;
}