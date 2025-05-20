//Gemma-7B DATASET v1.0 Category: Building a FTP Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main() {
  int sockfd, n, len, flag = 1;
  char buf[BUFFER_SIZE], hostname[256];

  printf("Enter hostname: ");
  scanf("%s", hostname);

  sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  inet_aton(hostname, &server_addr.sin_addr);

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  printf("Connected to server.\n");

  while (flag) {
    printf("Enter command (quit, list, upload, download): ");
    scanf("%s", buf);

    if (strcmp(buf, "quit") == 0) {
      flag = 0;
    } else if (strcmp(buf, "list") == 0) {
      n = recv(sockfd, buf, BUFFER_SIZE, 0);
      printf("%s", buf);
    } else if (strcmp(buf, "upload") == 0) {
      FILE *fp;
      fp = fopen("file.txt", "r");
      if (fp) {
        n = fread(buf, 1, BUFFER_SIZE, fp);
        send(sockfd, buf, n, 0);
        fclose(fp);
      }
    } else if (strcmp(buf, "download") == 0) {
      n = recv(sockfd, buf, BUFFER_SIZE, 0);
      FILE *fp;
      fp = fopen("file.txt", "w");
      if (fp) {
        fwrite(buf, 1, n, fp);
        fclose(fp);
      }
    } else {
      printf("Invalid command.\n");
    }
  }

  close(sockfd);
  return 0;
}