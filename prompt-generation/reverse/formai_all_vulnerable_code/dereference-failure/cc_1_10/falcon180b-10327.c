//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: shocked
//This is a ping test program written in C. It is designed to test the connectivity between two devices on a network.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define MAX 100

void die(char *s)
{
    perror(s);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sock, len, numbytes;
    char buffer[MAX];
    struct hostent *host;
    struct sockaddr_in serv_addr;
    char *ip;
    int port;

    if(argc!= 3)
    {
        fprintf(stderr, "Usage: %s <IP Address> <Port Number>\n", argv[0]);
        exit(1);
    }

    ip = argv[1];
    port = atoi(argv[2]);

    //Create socket
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        die("socket failed");

    printf("Socket created\n");

    //Set the hostent structure
    if((host = gethostbyname(ip)) == NULL)
        die("gethostbyname failed");

    printf("Hostent set\n");

    //Set the serv_addr structure
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&serv_addr.sin_addr.s_addr, host->h_length);
    serv_addr.sin_port = htons(port);

    printf("Serv_addr set\n");

    //Connect to the server
    if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        die("connect failed");

    printf("Connected to server\n");

    //Send data to server
    send(sock, "PING", strlen("PING"), 0);

    //Receive data from server
    len = sizeof(serv_addr);
    numbytes = recv(sock, buffer, MAX, 0);
    buffer[numbytes] = '\0';
    printf("Received %d bytes from server\n", numbytes);

    printf("Server response: %s\n", buffer);

    //Close socket
    close(sock);

    return 0;
}