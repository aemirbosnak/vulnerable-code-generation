//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    char *username, *password, *command;
    
    // check for correct number of arguments
    if (argc != 4)
    {
        printf("Usage: %s [server_address] [port_number] [username]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    // get user credentials
    username = argv[3];
    printf("Enter password: ");
    password = getpass("");
    
    // setup socket
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0)
    {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }
    
    // setup connection details
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);
    
    // establish connection
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error connecting");
        exit(EXIT_FAILURE);
    }
    
    // receive banner message from server
    bzero(buffer, BUFFER_SIZE);
    if ((n = recv(sockfd, buffer, BUFFER_SIZE-1, 0)) < 0)
    {
        perror("Error receiving data");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);
    
    // send login credentials
    command = (char *) malloc((strlen(username)+strlen(password)+8)*sizeof(char));
    sprintf(command, "USER %s\r\n", username);
    write(sockfd, command, strlen(command));
    free(command);
    
    bzero(buffer, BUFFER_SIZE);
    if ((n = recv(sockfd, buffer, BUFFER_SIZE-1, 0)) < 0)
    {
        perror("Error receiving data");
        exit(EXIT_FAILURE);
    }
    
    if (strncmp(buffer, "+OK", 3) == 0)
    {
        command = (char *) malloc((strlen(password)+8)*sizeof(char));
        sprintf(command, "PASS %s\r\n", password);
        write(sockfd, command, strlen(command));
        free(command);
        
        bzero(buffer, BUFFER_SIZE);
        if ((n = recv(sockfd, buffer, BUFFER_SIZE-1, 0)) < 0)
        {
            perror("Error receiving data");
            exit(EXIT_FAILURE);
        }
        
        if (strncmp(buffer, "+OK", 3) != 0)
        {
            printf("Invalid password\n");
            close(sockfd);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        printf("Invalid username\n");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    
    // list messages
    write(sockfd, "LIST\r\n", 6);
    
    bzero(buffer, BUFFER_SIZE);
    if ((n = recv(sockfd, buffer, BUFFER_SIZE-1, 0)) < 0)
    {
        perror("Error receiving data");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    
    printf("%s", buffer);
    
    // quit session
    write(sockfd, "QUIT\r\n", 6);
    
    bzero(buffer, BUFFER_SIZE);
    if ((n = recv(sockfd, buffer, BUFFER_SIZE-1, 0)) < 0)
    {
        perror("Error receiving data");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    
    printf("%s", buffer);
    
    // cleanup
    close(sockfd);
    exit(EXIT_SUCCESS);
}