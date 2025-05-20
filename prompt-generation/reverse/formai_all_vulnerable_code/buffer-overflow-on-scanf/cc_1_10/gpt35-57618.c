//FormAI DATASET v1.0 Category: Socket programming ; Style: puzzling
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

void mystery() {
  int a = 0, b = 1, c = 0, num;
  
  printf("Please enter an integer: ");
  scanf("%d", &num);
  
  for(int i = 1; i <= num; i++) {
    c = a + b;
    a = b;
    b = c;
  }
  
  printf("The %dth Fibonacci number is: %d\n", num, c);
}

int main() {
  int sockfd, connfd, len;
  struct sockaddr_in servaddr, cli;
  
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd == -1) {
    printf("Socket creation failed... \n");
    return 0;
  } else {
    printf("Socket successfully created... \n");
  }
  
  bzero(&servaddr, sizeof(servaddr));
  
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  servaddr.sin_port = htons(8080);
  
  if(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
    printf("Connection with the server failed... \n");
    return 0;
  } else {
    printf("Connected to the server successfully... \n");
  }
  
  mystery();
  
  char buff[1024];
  bzero(buff, sizeof(buff));
  printf("Enter a message: ");
  int index = 0;
  
  while((buff[index++] = getchar()) != '\n');
  
  write(sockfd, buff, sizeof(buff));
  bzero(buff, sizeof(buff));
  
  read(sockfd, buff, sizeof(buff));
  printf("Received: %s", buff);
  
  close(sockfd);
  
  return 0;
}