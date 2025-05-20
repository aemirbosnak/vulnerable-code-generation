//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __linux__
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#define close(x) close(x)
#elif defined(__APPLE__)
#include <CoreServices/CoreServices.h>
#include <sys/syslimits.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <limits.h>
#endif

#define BUF_SIZE 4096
#define MAX_RULES 10
char rules[MAX_RULES][BUF_SIZE];
int num_rules = 0;

void read_rules(char *filename) {
  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    perror("fopen");
    exit(1);
  }
  char buf[BUF_SIZE];
  while (fgets(buf, BUF_SIZE, f) != NULL) {
    if (buf[strlen(buf) - 1] == '\n') {
      buf[strlen(buf) - 1] = '\0';
    }
    strcpy(rules[num_rules], buf);
    num_rules++;
  }
  fclose(f);
}

int check_intrusion(char *packet) {
  for (int i = 0; i < num_rules; i++) {
    if (strstr(packet, rules[i]) != NULL) {
      return 1;
    }
  }
  return 0;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <rules_file> <port>\n", argv[0]);
    exit(1);
  }

  read_rules(argv[1]);

  int port = atoi(argv[2]);

  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(port);

  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("bind");
    exit(1);
  }

  char buf[BUF_SIZE];
  while (1) {
    int len = recvfrom(sockfd, buf, BUF_SIZE, 0, NULL, 0);
    if (len < 0) {
      perror("recvfrom");
      exit(1);
    }
    if (check_intrusion(buf)) {
      printf("Intrusion detected!\n");
    }
  }

  close(sockfd);

  return 0;
}