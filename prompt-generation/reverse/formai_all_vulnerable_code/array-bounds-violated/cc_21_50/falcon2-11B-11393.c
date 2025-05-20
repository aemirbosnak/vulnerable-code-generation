//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: inquisitive
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  char buffer[256];
  char* hostname = argv[1];
  char* username = argv[2];
  char* password = argv[3];

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(21); // default port for FTP
  if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0) {
    fprintf(stderr, "ERROR, couldn't resolve hostname\n");
    exit(1);
  }

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  if (argc > 3) {
    fprintf(stderr, "Username: %s\n", username);
    fprintf(stderr, "Password: %s\n", password);
    if (send(sockfd, username, strlen(username), 0) < 0) {
      perror("ERROR sending username");
      exit(1);
    }
    if (send(sockfd, password, strlen(password), 0) < 0) {
      perror("ERROR sending password");
      exit(1);
    }
  }

  if (send(sockfd, "USER ", 5, 0) < 0) {
    perror("ERROR sending USER command");
    exit(1);
  }

  n = recv(sockfd, buffer, 256, 0);
  if (n < 0) {
    perror("ERROR receiving data");
    exit(1);
  }

  if (n < 5) {
    fprintf(stderr, "ERROR, couldn't receive data\n");
    exit(1);
  }

  buffer[n] = '\0';
  printf("Response from server: %s\n", buffer);

  if (strcmp(buffer, "331")!= 0) {
    fprintf(stderr, "Invalid response from server\n");
    exit(1);
  }

  if (send(sockfd, "PASS ", 5, 0) < 0) {
    perror("ERROR sending PASS command");
    exit(1);
  }

  n = recv(sockfd, buffer, 256, 0);
  if (n < 0) {
    perror("ERROR receiving data");
    exit(1);
  }

  buffer[n] = '\0';
  printf("Response from server: %s\n", buffer);

  if (strcmp(buffer, "230")!= 0) {
    fprintf(stderr, "Invalid response from server\n");
    exit(1);
  }

  printf("Welcome to the FTP server!\n");

  while (1) {
    printf("Enter command (help for options): ");
    if (fgets(buffer, 256, stdin) == NULL) {
      fprintf(stderr, "ERROR reading input\n");
      exit(1);
    }
    buffer[strlen(buffer)-1] = '\0'; // remove newline character

    n = strlen(buffer);
    if (n == 0) {
      fprintf(stderr, "ERROR, empty command\n");
      exit(1);
    }

    if (strcmp(buffer, "help") == 0) {
      printf("Commands:\n");
      printf("    ls          List files in the current directory\n");
      printf("    get <file>   Get a file from the server\n");
      printf("    put <file>   Put a file to the server\n");
      printf("    quit         Exit from FTP client\n");
    } else if (strcmp(buffer, "ls") == 0) {
      if (send(sockfd, "NLST ", 5, 0) < 0) {
        perror("ERROR sending NLST command");
        exit(1);
      }

      n = recv(sockfd, buffer, 256, 0);
      if (n < 0) {
        perror("ERROR receiving data");
        exit(1);
      }

      buffer[n] = '\0';
      printf("Response from server: %s\n", buffer);
    } else if (strcmp(buffer, "get") == 0) {
      if (sscanf(buffer, "get %s", buffer)!= 1) {
        fprintf(stderr, "ERROR, invalid format for get command\n");
        exit(1);
      }

      if (send(sockfd, "RETR ", 5, 0) < 0) {
        perror("ERROR sending RETR command");
        exit(1);
      }

      n = recv(sockfd, buffer, 256, 0);
      if (n < 0) {
        perror("ERROR receiving data");
        exit(1);
      }

      buffer[n] = '\0';
      printf("Response from server: %s\n", buffer);
    } else if (strcmp(buffer, "put") == 0) {
      if (sscanf(buffer, "put %s", buffer)!= 1) {
        fprintf(stderr, "ERROR, invalid format for put command\n");
        exit(1);
      }

      if (send(sockfd, "STOR ", 5, 0) < 0) {
        perror("ERROR sending STOR command");
        exit(1);
      }

      n = recv(sockfd, buffer, 256, 0);
      if (n < 0) {
        perror("ERROR receiving data");
        exit(1);
      }

      buffer[n] = '\0';
      printf("Response from server: %s\n", buffer);
    } else if (strcmp(buffer, "quit") == 0) {
      if (send(sockfd, "QUIT ", 5, 0) < 0) {
        perror("ERROR sending QUIT command");
        exit(1);
      }

      n = recv(sockfd, buffer, 256, 0);
      if (n < 0) {
        perror("ERROR receiving data");
        exit(1);
      }

      buffer[n] = '\0';
      printf("Response from server: %s\n", buffer);
      break;
    } else {
      fprintf(stderr, "ERROR, invalid command\n");
      exit(1);
    }
  }

  close(sockfd);
  return 0;
}