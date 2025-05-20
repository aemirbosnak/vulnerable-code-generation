//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Romeo's heart
#define PORT 21

// Juliet's heart
#define IP "127.0.0.1"

// Romeo's initial words
#define USER "USER romeo"
#define PASS "PASS juliet"

// Juliet's welcome
#define OK "220 Juliet FTP server"

// Romeo's desire
#define RETR "RETR love.txt"

// Juliet's gift
#define SUCC "150 Opening BINARY mode data connection"

// Romeo's pleasure
#define BYTE "226 Transfer complete"

int main() {
  // Romeo's socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    fprintf(stderr, "Romeo's socket failed\n");
    return 1;
  }

  // Romeo's destination
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);
  struct hostent *server = gethostbyname(IP);
  if (server == NULL) {
    fprintf(stderr, "Unknown host\n");
    return 1;
  }
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

  // Romeo's connection
  if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    fprintf(stderr, "Romeo's connection failed\n");
    return 1;
  }

  // Juliet's welcome
  char welcome[1024];
  recv(sock, welcome, sizeof(welcome), 0);
  if (strncmp(welcome, OK, strlen(OK)) != 0) {
    fprintf(stderr, "Juliet's welcome not as expected\n");
    return 1;
  }

  // Romeo's user
  char user[1024];
  snprintf(user, sizeof(user), "%s\r\n", USER);
  send(sock, user, strlen(user), 0);

  // Juliet's approval
  char user_ok[1024];
  recv(sock, user_ok, sizeof(user_ok), 0);
  if (strncmp(user_ok, "331", 3) != 0) {
    fprintf(stderr, "Juliet's user approval not as expected\n");
    return 1;
  }

  // Romeo's password
  char pass[1024];
  snprintf(pass, sizeof(pass), "%s\r\n", PASS);
  send(sock, pass, strlen(pass), 0);

  // Juliet's kiss
  char pass_ok[1024];
  recv(sock, pass_ok, sizeof(pass_ok), 0);
  if (strncmp(pass_ok, "230", 3) != 0) {
    fprintf(stderr, "Juliet's kiss not as expected\n");
    return 1;
  }

  // Romeo's request
  char retr[1024];
  snprintf(retr, sizeof(retr), "%s\r\n", RETR);
  send(sock, retr, strlen(retr), 0);

  // Juliet's present
  char succ[1024];
  recv(sock, succ, sizeof(succ), 0);
  if (strncmp(succ, SUCC, strlen(SUCC)) != 0) {
    fprintf(stderr, "Juliet's present not as expected\n");
    return 1;
  }

  // Romeo's love
  FILE *love = fopen("love.txt", "w");
  if (love == NULL) {
    fprintf(stderr, "Romeo's love cannot be written\n");
    return 1;
  }

  // Juliet's bytes
  char byte[1024];
  while (recv(sock, byte, sizeof(byte), 0) > 0) {
    fwrite(byte, 1, strlen(byte), love);
  }

  // Romeo's satisfaction
  char byte_ok[1024];
  recv(sock, byte_ok, sizeof(byte_ok), 0);
  if (strncmp(byte_ok, BYTE, strlen(BYTE)) != 0) {
    fprintf(stderr, "Romeo's satisfaction not as expected\n");
    return 1;
  }

  // Romeo's farewell
  fclose(love);
  close(sock);
  return 0;
}