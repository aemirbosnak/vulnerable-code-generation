//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#define PORT 993 
#define SA struct sockaddr

int socket_connection() 
{ 
  int sockfd, connfd; 
  struct sockaddr_in servaddr, cli; 

  // socket creation 
  sockfd = socket(AF_INET, SOCK_STREAM, 0); 
  if (sockfd == -1) { 
      printf("socket creation failed...\n"); 
      exit(0); 
  } 
  else
      printf("Socket successfully created..\n"); 
  bzero(&servaddr, sizeof(servaddr)); 

  // assign IP, PORT 
  servaddr.sin_family = AF_INET; 
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
  servaddr.sin_port = htons(PORT); 

  // connect the client socket to server socket 
  if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
      printf("connection with the server failed...\n"); 
      exit(0); 
  } 
  else
      printf("connected to the server..\n"); 
  return sockfd; 
} 

void login(int sockfd) 
{ 
  char userid[50]; 
  char passwd[50]; 
  printf("Enter User Id : ");
  scanf("%s", userid);
  printf("Enter Password : ");
  scanf("%s", passwd);
  char buffer[1024]; 
  sprintf(buffer, ". LOGIN %s %s\r\n",userid,passwd); 
  send(sockfd, buffer, sizeof(buffer), 0); 
  memset(buffer, 0, 1024);
  recv(sockfd, buffer, sizeof(buffer), 0);
  printf("%s", buffer);
} 

void list_mails(int sockfd)
{
    char buffer[1024];
    sprintf(buffer, ". LIST \"\" \"*\"\r\n");
    send(sockfd, buffer, sizeof(buffer), 0);
    memset(buffer, 0, 1024);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
}

void get_mail(int sockfd, char* mailnum)
{
    char buffer[1024];
    sprintf(buffer, ". FETCH %s BODY[]\r\n", mailnum);
    send(sockfd, buffer, sizeof(buffer), 0);
    memset(buffer, 0, 1024);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
}

void logout(int sockfd) 
{ 
  char buffer[1024]; 
  sprintf(buffer, ". LOGOUT\r\n"); 
  send(sockfd, buffer, sizeof(buffer), 0); 
  memset(buffer, 0, 1024);
  recv(sockfd, buffer, sizeof(buffer), 0);
  printf("%s", buffer);
} 

int main() 
{ 
  int sockfd;
  sockfd = socket_connection();
  login(sockfd);
  list_mails(sockfd);
  char choice[5];
  printf("Enter the mail number to view the details or q to quit : ");
  scanf("%s", choice);
  while(strcmp(choice, "q") != 0)
  {
    get_mail(sockfd, choice);
    printf("Enter the mail number to view the details or q to quit : ");
    scanf("%s", choice);    
  }
  logout(sockfd);
  close(sockfd); 
}