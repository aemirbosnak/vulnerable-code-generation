//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: futuristic
//Futuristic POP3 client program
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netdb.h>
#include<netinet/in.h>
#include<sys/socket.h>
#define PORT 110 //Default POP3 port number
#define MAX_LENGTH 1024 //Maximum length for client input and server responses
int main(int argc, char *argv[]) {
    int sock_fd, num_bytes;
    char recvbuf[MAX_LENGTH], sendbuf[MAX_LENGTH];
    struct hostent *he;
    struct sockaddr_in srv_addr;
    if(argc != 2) {
        printf("Usage: %s [Server Address] \n", argv[0]);
        exit(1);
    }
    if((he=gethostbyname(argv[1])) == NULL) {
        perror("gethostbyname() error");
        exit(1);
    }
    if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) { 
        perror("socket() error");
        exit(1); 
    }
    bzero(&srv_addr, sizeof(srv_addr));
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons(PORT);
    srv_addr.sin_addr = *((struct in_addr *)he->h_addr);
    if(connect(sock_fd, (struct sockaddr *)&srv_addr, sizeof(srv_addr)) < 0) {
        perror("connect() error");
        exit(1);
    }
    num_bytes = recv(sock_fd, recvbuf, MAX_LENGTH-1, 0);
    recvbuf[num_bytes] = '\0';
    printf("%s",recvbuf); //Printing server greeting message
    while(1) {
       printf("Enter POP3 Command: ");
       scanf("%s",sendbuf);
       send(sock_fd, sendbuf, strlen(sendbuf), 0);
       num_bytes = recv(sock_fd, recvbuf, MAX_LENGTH-1, 0);
       recvbuf[num_bytes]='\0';
       printf("%s\n",recvbuf); //Printing server response to client command
       if(!strcmp(sendbuf,"QUIT")) //Stopping further communication with server on client's command
           break;
    }
    close(sock_fd);
    return 0;
}