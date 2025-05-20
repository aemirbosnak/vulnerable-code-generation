//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: light-weight
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <netdb.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
  
#define PORT 110  // POP3 port number

int main(int argc, char *argv[]) 
{ 
    int sockfd, numbytes; 
    char buffer[1024]; 
    struct hostent *he; 
    struct sockaddr_in their_addr; 
  
    if (argc != 3) { 
        fprintf(stderr,"usage: popclient hostname username\n"); 
        exit(1); 
    } 
  
    if ((he=gethostbyname(argv[1])) == NULL) { 
        perror("gethostbyname"); 
        exit(1); 
    } 
  
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) { 
        perror("socket"); 
        exit(1); 
    } 
  
    their_addr.sin_family = AF_INET; 
    their_addr.sin_port = htons(PORT); 
    their_addr.sin_addr = *((struct in_addr *)he->h_addr); 
    memset(&(their_addr.sin_zero), '\0', 8); 
  
    if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1) { 
        perror("connect"); 
        exit(1); 
    } 

    recv(sockfd, buffer, 1023, 0);   // receive POP3 server greeting
  
    printf("%s", buffer); 

    // authenticate and login
    sprintf(buffer, "USER %s\r\n", argv[2]);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, 1023, 0);

    sprintf(buffer, "PASS ");
    char *password = getpass("Enter your password:");
    sprintf(buffer, "%s%s\r\n", buffer, password);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, 1023, 0);

    // list the email messages
    sprintf(buffer, "LIST\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, 1023, 0);
    printf("%s", buffer);

    printf("Which message do you want to read? ");
    int msgnum;
    scanf("%d", &msgnum);

    // retrieve the selected message
    sprintf(buffer, "RETR %d\r\n", msgnum);
    send(sockfd, buffer, strlen(buffer), 0);

    // read the response from the server
    while ((numbytes = recv(sockfd, buffer, 1023, 0)) > 0) {
        buffer[numbytes] = '\0';
        printf("%s", buffer);
    }

    // send the quit command and close the socket
    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    close(sockfd);

    return 0; 
}