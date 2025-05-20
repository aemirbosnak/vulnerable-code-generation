//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PARANOID_MODE // define this to enable paranoid mode

#ifdef PARANOID_MODE
  #define memset_s(dest, size, value) memset(dest, 0, sizeof(*dest)) // paranoid memset implementation
#else
  #define memset_s(dest, size, value) memset(dest, value, size) // normal memset implementation
#endif

void error(char* msg){
  perror(msg);
  exit(0);
}

int main(int argc, char* argv[]){
  int sockfd, n, port = 21;
  struct sockaddr_in serv_addr;
  struct hostent* server;

  char buffer[256];
  char username[50];
  char password[50];
  char filename[100];
  char path[100];
  char command[100];

  if(argc < 2){
      fprintf(stderr, "Usage: %s hostname [port]\n", argv[0]);
      exit(0);
  }

  if(argc == 3){
      port = atoi(argv[2]);
      if(!port){
          fprintf(stderr, "Invalid port number\n");
          exit(0);
      }
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0) {
      error("Error opening socket");
  }
  server = gethostbyname(argv[1]);
  if(server == NULL){
      fprintf(stderr, "Error: Host not found\n");
      exit(0);
  }

  memset_s(&serv_addr, sizeof(serv_addr), 0);
  serv_addr.sin_family = AF_INET;
  memcpy((char*)&serv_addr.sin_addr.s_addr, (char*)server->h_addr, server->h_length);
  serv_addr.sin_port = htons(port);

  if(connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0){
      error("Error connecting to server");
  }

  memset_s(buffer, sizeof(buffer), 0);
  n = read(sockfd, buffer, sizeof(buffer)-1);
  if(n < 0){
      error("Error reading from socket");
  }
  printf("%s\n",buffer);

  printf("Username: ");
  memset_s(username, sizeof(username), 0); // paranoid clear
  fgets(username, sizeof(username)-1, stdin);
  username[strcspn(username, "\r\n")] = 0;

  printf("Password: ");
  memset_s(password, sizeof(password), 0); // paranoid clear
  fgets(password, sizeof(password)-1, stdin);
  password[strcspn(password, "\r\n")] = 0;

#ifdef PARANOID_MODE
  memset_s(buffer, sizeof(buffer), 0); // paranoid clear
#endif
  snprintf(buffer, sizeof(buffer)-1, "USER %s\r\n", username);
  n = write(sockfd, buffer, strlen(buffer));
  if(n < 0){
      error("Error writing to socket");
  }

#ifdef PARANOID_MODE
  memset_s(buffer, sizeof(buffer), 0); // paranoid clear
#endif
  n = read(sockfd, buffer, sizeof(buffer)-1);
  if(n < 0){
      error("Error reading from socket");
  }
  printf("%s\n",buffer);

#ifdef PARANOID_MODE
  memset_s(buffer, sizeof(buffer), 0); // paranoid clear
#endif
  snprintf(buffer, sizeof(buffer)-1, "PASS %s\r\n", password);
  n = write(sockfd, buffer, strlen(buffer));
  if(n < 0){
      error("Error writing to socket");
  }

#ifdef PARANOID_MODE
  memset_s(buffer, sizeof(buffer), 0); // paranoid clear
#endif
  n = read(sockfd, buffer, sizeof(buffer)-1);
  if(n < 0){
      error("Error reading from socket");
  }
  printf("%s\n",buffer);

  do {
      printf("FTP> ");
      memset_s(command, sizeof(command), 0); // paranoid clear
      memset_s(filename, sizeof(filename), 0); // paranoid clear
      memset_s(path, sizeof(path), 0); // paranoid clear
      fgets(command, sizeof(command)-1, stdin);
      command[strcspn(command, "\r\n")] = 0;
      if(strcmp(command, "quit") == 0) {
          break;
      } else if(strncmp(command, "get", 3) == 0) {
          if(strlen(command) < 5) {
              printf("Usage: get [remote-file] [local-file]\n");
              continue;
          }
          char* token = strtok(command+4, " ");
          if(token) {
              strcpy(filename, token);
          }
          token = strtok(NULL, " ");
          if(token) {
              strcpy(path, token);
          } else {
              strcpy(path, filename);
          }

#ifdef PARANOID_MODE
          memset_s(buffer, sizeof(buffer), 0); // paranoid clear
#endif
          snprintf(buffer, sizeof(buffer)-1, "RETR %s\r\n", filename);
          n = write(sockfd, buffer, strlen(buffer));
          if(n < 0){
              error("Error writing to socket");
          }

#ifdef PARANOID_MODE
          memset_s(buffer, sizeof(buffer), 0); // paranoid clear
#endif
          n = read(sockfd, buffer, sizeof(buffer)-1);
          if(n < 0){
              error("Error reading from socket");
          }
          if(strncmp(buffer, "550", 3) == 0) {
              printf("Error: File not found on server\n");
              continue;
          } else if(strncmp(buffer, "150", 3) != 0) {
              printf("Error: Unknown response from server\n");
              continue;
          } else {
              FILE* fp = fopen(path, "wb");
              if(fp == NULL) {
                  printf("Error: Could not open local file for writing\n");
                  continue;
              }
              while(1) {
#ifdef PARANOID_MODE
                  memset_s(buffer, sizeof(buffer), 0); // paranoid clear
#endif
                  n = read(sockfd, buffer, sizeof(buffer));
                  if(n < 0){
                      error("Error reading from socket");
                  }
                  if(n == 0) break;
                  fwrite(buffer, 1, n, fp);
              }
              fclose(fp);

#ifdef PARANOID_MODE
              memset_s(buffer, sizeof(buffer), 0); // paranoid clear
#endif
              n = read(sockfd, buffer, sizeof(buffer)-1);
              if(n < 0){
                  error("Error reading from socket");
              }
              if(strncmp(buffer, "226", 3) != 0) {
                  printf("Error: Unknown response from server\n");
                  continue;
              } else {
                  printf("File transfer complete\n");
              }
          }
      } else {
          printf("Unknown command\n");
      }
  } while(1);

#ifdef PARANOID_MODE
  memset_s(buffer, sizeof(buffer), 0); // paranoid clear
#endif
  snprintf(buffer, sizeof(buffer)-1, "QUIT\r\n");
  n = write(sockfd, buffer, strlen(buffer));
  close(sockfd);
  return 0;
}