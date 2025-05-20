//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024
#define MIN_BUF_SIZE 64
#define QOS_MEASURE_PORT 9999
#define QOS_REPORT_PORT 8888

struct qos_report {
  char ip_addr[MIN_BUF_SIZE];
  float jitter;
  float loss;
};

void report_qos_meas(char *ip_addr, float jitter, float loss) {
  struct qos_report report;
  strcpy(report.ip_addr, ip_addr);
  report.jitter = jitter;
  report.loss = loss;
  
  int sock_fd;
  struct sockaddr_in serv_addr;
  char buf[MAX_BUF_SIZE];

  sock_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (sock_fd < 0) {
    perror("Error: Failed to create socket for QoS report.");
    return;
  }

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(QOS_REPORT_PORT);
  if (inet_aton("127.0.0.1", &serv_addr.sin_addr) == 0) {
    perror("Error: Failed to convert target IP address.");
    close(sock_fd);
    return;
  }

  sprintf(buf, "%.2f/%.2f", report.jitter, report.loss);

  if (sendto(sock_fd, buf, strlen(buf), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
    perror("Error: Failed to send QoS report.");
  }

  close(sock_fd);
}

int main() {
  int sock_fd;
  struct sockaddr_in serv_addr, cli_addr;
  socklen_t cli_addrlen = sizeof(cli_addr);
  char buf[MAX_BUF_SIZE];
  float jitter, loss;
  char *ip_addr;

  sock_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (sock_fd < 0) {
    perror("Error: Failed to create socket for QoS measures.");
    return 1;
  }

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(QOS_MEASURE_PORT);
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error: Failed to bind socket for QoS measures.");
    close(sock_fd);
    return 1;
  }

  while (1) {
    if (recvfrom(sock_fd, buf, MAX_BUF_SIZE, 0, (struct sockaddr *)&cli_addr, &cli_addrlen) == -1) {
      perror("Error: Failed to receive QoS measures.");
      continue;
    }

    if (buf[0] == 'q' && buf[1] == 'u' && buf[2] == 'i' && buf[3] == 't') {
      break;
    }

    sscanf(buf, "%f/%f", &jitter, &loss);
    inet_ntop(AF_INET, &(cli_addr.sin_addr), buf, INET_ADDRSTRLEN);
    ip_addr = buf;

    printf("Received QoS measure from: %s - jitter: %.2f ms, loss: %.2f %%\n", ip_addr, jitter, loss);

    report_qos_meas(ip_addr, jitter, loss);
  }

  close(sock_fd);
  return 0;
}