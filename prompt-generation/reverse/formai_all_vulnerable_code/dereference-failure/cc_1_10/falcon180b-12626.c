//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>

#define PORT 80
#define MAX 100

int main() {
    int sd, i;
    struct hostent *host;
    struct sockaddr_in server;
    char buffer[MAX];
    int addrlen = sizeof(server);

    //Create socket
    sd = socket(AF_INET, SOCK_STREAM, 0);
    if(sd == -1) {
        printf("Socket creation failed\n");
        exit(1);
    }

    //Resolve hostname
    host = gethostbyname("www.google.com");
    if(host == NULL) {
        printf("Host not found\n");
        exit(1);
    }

    //Fill server structure
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    memcpy(&server.sin_addr, host->h_addr, host->h_length);

    //Connect to server
    if(connect(sd, (struct sockaddr*)&server, addrlen) == -1) {
        printf("Connection failed\n");
        exit(1);
    }

    //Send request
    send(sd, "GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n"), 0);

    //Receive response
    if(recv(sd, buffer, MAX, 0) == -1) {
        printf("Error receiving data\n");
        exit(1);
    }

    //Print response
    printf("Response:\n%s", buffer);

    //Close socket
    close(sd);

    return 0;
}