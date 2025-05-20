//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define IMAP_PORT 143

int main()
{
    // Our dear old IMAP server
    char *imap_server = "imap.example.com";
    
    // We need a sturdy ship to sail the digital seas 
    int sockfd;
    
    // Prepare our trusty ship for the high seas
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
    {
        perror("socket");
        exit(1);
    }
    
    // Let's chart a course for our intrepid vessel
    struct hostent *server;
    server = gethostbyname(imap_server);
    if (server == NULL) 
    {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }
    
    // Set sail for the vast network expanse
    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(IMAP_PORT);
    
    // Let's board our mighty ship and hoist the Jolly Roger
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
    {
        perror("connect");
        exit(1);
    }
    
    // Let's hoist the sails and embark on our IMAP adventure
    char buffer[256];
    bzero(buffer,256);
    int n;
    
    // Ahoy there, IMAP server! Let's say hello and see what treasures await us
    n = read(sockfd,buffer,255);
    if (n < 0) 
    {
        perror("read");
        exit(1);
    }
    printf("%s",buffer);
    
    // Let's don our finest attire and introduce ourselves with grace
    char *greeting = "Ahoy there, fair IMAP server! 'Tis I, a humble client, seeking your wisdom and treasures\r\n";
    n = write(sockfd,greeting,strlen(greeting));
    if (n < 0) 
    {
        perror("write");
        exit(1);
    }
    
    // Prepare to receive the server's warm embrace or perhaps a cold shoulder
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) 
    {
        perror("read");
        exit(1);
    }
    printf("%s",buffer);
    
    // Let's dive into the depths of our IMAP journey
    while(1) 
    {
        // Prepare our trusty vessel for incoming messages
        bzero(buffer,256);
        n = read(sockfd,buffer,255);
        if (n < 0) 
        {
            perror("read");
            exit(1);
        }
        
        // Decipher the server's cryptic messages
        if(strstr(buffer,"OK") != NULL) 
        {
            printf("Avast! The server has graced us with its blessing\n");
        } 
        else if(strstr(buffer,"NO") != NULL) 
        {
            printf("Shiver me timbers! The server has rejected our request\n");
        } 
        else if(strstr(buffer,"BAD") != NULL) 
        {
            printf("Avast! The server has deemed our request unworthy\n");
        } 
        else if(strstr(buffer,"BYE") != NULL) 
        {
            printf("Farewell, dear server! May our paths cross again in the vast digital realm\n");
            break;
        } 
        else 
        {
            printf("Arrr! The server's response bewilders us\n");
        }
        
        // Let's send a hearty response to the server, showing our appreciation
        char *response = "Ahoy there, fair IMAP server! We thank ye for your wisdom and treasures. May our paths cross again soon\r\n";
        n = write(sockfd,response,strlen(response));
        if (n < 0) 
        {
            perror("write");
            exit(1);
        }
    }
    
    // As we bid farewell to the IMAP server, let's close our connection and set sail for new horizons
    close(sockfd);
    
    return 0;
}