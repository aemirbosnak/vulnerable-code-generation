//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define BUF_SIZE 1024

long long get_file_size(char *file_path) {
  struct stat st;
  if (stat(file_path, &st) == -1) {
    perror("stat() failed.");
    exit(1);
  }
  return st.st_size;
}

long long get_time_in_ms() {
  struct timeval tv;
  if (gettimeofday(&tv, NULL) == -1) {
    perror("gettimeofday() failed.");
    exit(1);
  }
  return tv.tv_sec * 1000LL + tv.tv_usec / 1000;
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <server_ip> <file_path>\n", argv[0]);
    exit(1);
  }
  char *server_ip = argv[1];
  char *file_path = argv[2];
  long long file_size = get_file_size(file_path);
  int fd = open(file_path, O_RDONLY);
  if (fd == -1) {
    perror("open() failed.");
    exit(1);
  }
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(server_ip);
  server_addr.sin_port = htons(8080);
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket() failed.");
    exit(1);
  }
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect() failed.");
    exit(1);
  }
  long long start_time = get_time_in_ms();
  char buf[BUF_SIZE];
  long long bytes_sent = 0;
  while (bytes_sent < file_size) {
    ssize_t sent_bytes = sendfile(sockfd, fd, NULL, BUF_SIZE);
    if (sent_bytes == -1) {
      perror("sendfile() failed.");
      exit(1);
    }
    bytes_sent += sent_bytes;
  }
  close(fd);
  long long end_time = get_time_in_ms();
  double elapsed_time = (double)(end_time - start_time) / 1000.0;
  double speed = (double)file_size / (1024.0 * 1024.0 * elapsed_time);
  printf("File size: %lld MB\n", file_size / (1024LL * 1024LL));
  printf("Elapsed time: %.3f s\n", elapsed_time);
  printf("Speed: %.3f MB/s\n", speed);
  close(sockfd);
  return 0;
}