//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>

#define MAX_LINE 1024

void sig_handler(int signo) {
  printf("\nProgram terminated by signal %d\n", signo);
  exit(signo);
}

int main(int argc, char *argv[]) {
  struct sockaddr_in server_addr;
  struct hostent *server_name;
  int sockfd, n;
  char buffer[MAX_LINE];
  char *result;
  struct timeval start, end;
  double elapsed;
  FILE *sound;
  int volume;

  if (argc!= 2) {
    fprintf(stderr, "Usage: %s <server name or IP>\n", argv[0]);
    exit(1);
  }

  server_name = gethostbyname(argv[1]);
  if (server_name == NULL) {
    fprintf(stderr, "No such host\n");
    exit(1);
  }

  bzero((char *)&server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  bcopy((char *)server_name->h_addr, (char *)&server_addr.sin_addr.s_addr, server_name->h_length);
  server_addr.sin_port = htons(80);

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("Socket creation failed");
    exit(1);
  }

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Connection failed");
    exit(1);
  }

  gettimeofday(&start, NULL);

  while ((n = recv(sockfd, buffer, MAX_LINE, 0)) > 0) {
    memset(buffer, 0, MAX_LINE);
    gettimeofday(&end, NULL);
    elapsed = (double)(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    result = buffer;
    if (n > 0) {
      printf("%s\n", result);
    }

    if (elapsed >= 5) {
      sound = fopen("medieval-music.wav", "rb");
      volume = fgetc(sound);
      fclose(sound);
      printf("\nYour internet connection speed is: %s\n", result);
      printf("Playing medieval-themed music!\n");
      printf("\n");
      sleep(5);
      printf("\n");
    }
  }

  if (n < 0) {
    perror("Recv failed");
    exit(1);
  }

  close(sockfd);

  return 0;
}