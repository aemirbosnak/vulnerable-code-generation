//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#define PORT 80
#define MAX_LENGTH 100

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char message[MAX_LENGTH];

    if ( ( sockfd = socket( AF_INET, SOCK_STREAM, 0 ) ) < 0 ) {
        perror( "socket failed" );
        exit( EXIT_FAILURE );
    }

    bzero( ( char * ) &serv_addr, sizeof( serv_addr ) );
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons( PORT );

    if ( bind( sockfd, ( struct sockaddr * ) &serv_addr, sizeof( serv_addr ) ) < 0 ) {
        perror( "bind failed. Error" );
        exit( EXIT_FAILURE );
    }

    listen( sockfd, 5 );

    while ( 1 ) {
        sockfd = accept( sockfd, ( struct sockaddr * ) &serv_addr, ( socklen_t * ) &n );
        if ( sockfd < 0 ) {
            perror( "accept failed" );
            exit( EXIT_FAILURE );
        }

        printf( "Connected with %s:%d\n", inet_ntoa( serv_addr.sin_addr ), ntohs( serv_addr.sin_port ) );
        bzero( message, MAX_LENGTH );
        n = read( sockfd, message, MAX_LENGTH );
        if ( n < 0 ) {
            perror( "read failed" );
            exit( EXIT_FAILURE );
        }
        message[n] = '\0';
        printf( "Received: %s\n", message );
        bzero( message, MAX_LENGTH );
        n = write( sockfd, "Hello World\n", 13 );
        if ( n < 0 ) {
            perror( "write failed" );
            exit( EXIT_FAILURE );
        }
        printf( "Sent: Hello World\n" );
        close( sockfd );
    }
    return 0;
}