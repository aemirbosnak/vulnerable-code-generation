//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h> 

#define MAX_BUFFER 1024

int main(int argc, char *argv[])
{
    char buffer[MAX_BUFFER];
    struct hostent *host;
    struct sockaddr_in server_address;
    int pop3_socket, port_number, read_size;

    if(argc != 3)
    {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    memset(buffer, 0, MAX_BUFFER);
    if((host = gethostbyname(argv[1])) == NULL)
    {
        fprintf(stderr, "Error: Cannot resolve hostname %s\n", argv[1]);
        return 2;
    }

    port_number = atoi(argv[2]);
    if(port_number < 0 || port_number > 65535)
    {
        fprintf(stderr, "Error: Invalid port number %d\n", port_number);
        return 3;
    }

    pop3_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(pop3_socket < 0)
    {
        perror("Error: Cannot create socket");
        return 4;
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    memcpy(&server_address.sin_addr, host->h_addr_list[0], host->h_length);

    if(connect(pop3_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0)
    {
        perror("Error: Cannot connect to server");
        return 5;
    }

    printf("Connected to server %s:%d\n", argv[1], port_number);

    memset(buffer, 0, MAX_BUFFER);
    read_size = read(pop3_socket, buffer, MAX_BUFFER);
    if(read_size < 0)
    {
        perror("Error: Cannot read from socket");
        return 6;
    }
    printf("Server: %s\n", buffer);

    // Send POP3 authentication commands
    char user_name[MAX_BUFFER] = "USER username\r\n";
    char password[MAX_BUFFER] = "PASS password\r\n";

    memset(buffer, 0, MAX_BUFFER);
    printf("Enter your username: ");
    fgets(buffer, MAX_BUFFER, stdin);
    strcat(user_name, buffer);

    memset(buffer, 0, MAX_BUFFER);
    printf("Enter your password: ");
    fgets(buffer, MAX_BUFFER, stdin);
    strcat(password, buffer);

    write(pop3_socket, user_name, strlen(user_name));
    memset(buffer, 0, MAX_BUFFER);
    read_size = read(pop3_socket, buffer, MAX_BUFFER);
    if(read_size < 0)
    {
        perror("Error: Cannot read from socket");
        return 6;
    }
    printf("Server: %s\n", buffer);

    write(pop3_socket, password, strlen(password));
    memset(buffer, 0, MAX_BUFFER);
    read_size = read(pop3_socket, buffer, MAX_BUFFER);
    if(read_size < 0)
    {
        perror("Error: Cannot read from socket");
        return 6;
    }
    printf("Server: %s\n", buffer);

    // Send LIST command to display all messages and their sizes
    char list_command[MAX_BUFFER] = "LIST\r\n";
    write(pop3_socket, list_command, strlen(list_command));
    memset(buffer, 0, MAX_BUFFER);
    read_size = read(pop3_socket, buffer, MAX_BUFFER);
    if(read_size < 0)
    {
        perror("Error: Cannot read from socket");
        return 6;
    }
    printf("Server: %s\n", buffer);

    // Send RETR command to retrieve a specific message
    char retr_command[MAX_BUFFER] = "RETR 1\r\n";
    write(pop3_socket, retr_command, strlen(retr_command));
    memset(buffer, 0, MAX_BUFFER);
    read_size = read(pop3_socket, buffer, MAX_BUFFER);
    if(read_size < 0)
    {
        perror("Error: Cannot read from socket");
        return 6;
    }
    printf("Server: %s\n", buffer);

    // Send DELE command to delete the retrieved message
    char dele_command[MAX_BUFFER] = "DELE 1\r\n";
    write(pop3_socket, dele_command, strlen(dele_command));
    memset(buffer, 0, MAX_BUFFER);
    read_size = read(pop3_socket, buffer, MAX_BUFFER);
    if(read_size < 0)
    {
        perror("Error: Cannot read from socket");
        return 6;
    }
    printf("Server: %s\n", buffer);

    // Send QUIT command to disconnect from server
    char quit_command[MAX_BUFFER] = "QUIT\r\n";
    write(pop3_socket, quit_command, strlen(quit_command));
    memset(buffer, 0, MAX_BUFFER);
    read_size = read(pop3_socket, buffer, MAX_BUFFER);
    if(read_size < 0)
    {
        perror("Error: Cannot read from socket");
        return 6;
    }
    printf("Server: %s\n", buffer);

    close(pop3_socket);

    return 0;
}