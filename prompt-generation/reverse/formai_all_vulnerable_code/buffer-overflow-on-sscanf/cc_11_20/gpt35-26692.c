//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 2048
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 21

int main()
{
    int client_socket;
    struct sockaddr_in server_address;
    char buffer[MAX_BUFFER_SIZE];
    char filename[512];

    memset(buffer, 0, sizeof(buffer));
    memset(filename, 0, sizeof(filename));
    
    // create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0)
    {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // set server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = inet_addr(SERVER_IP);

    // connect to server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // receive welcome message from server
    if (recv(client_socket, buffer, sizeof(buffer), 0) < 0)
    {
        perror("Failed to receive welcome message");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer);

    // send username to server
    printf("Enter username: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\r\n")] = '\0';
    sprintf(buffer, "USER %s\r\n", buffer);
    if (send(client_socket, buffer, strlen(buffer), 0) < 0)
    {
        perror("Failed to send username");
        exit(EXIT_FAILURE);
    }

    // receive response from server
    if (recv(client_socket, buffer, sizeof(buffer), 0) < 0)
    {
        perror("Failed to receive response");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer);

    // send password to server
    printf("Enter password: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\r\n")] = '\0';
    sprintf(buffer, "PASS %s\r\n", buffer);
    if (send(client_socket, buffer, strlen(buffer), 0) < 0)
    {
        perror("Failed to send password");
        exit(EXIT_FAILURE);
    }

    // receive response from server
    if (recv(client_socket, buffer, sizeof(buffer), 0) < 0)
    {
        perror("Failed to receive response");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer);

    // send passive mode command
    if (send(client_socket, "PASV\r\n", 6, 0) < 0)
    {
        perror("Failed to send PASV command");
        exit(EXIT_FAILURE);
    }

    // receive response from server
    if (recv(client_socket, buffer, sizeof(buffer), 0) < 0)
    {
        perror("Failed to receive response");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer);

    // parse passive mode response and get data connection address and port
    char *p1, *p2;
    char ip_address[20];
    int port_number;
    p1 = strchr(buffer, '(');
    p2 = strchr(buffer, ')');
    if (p1 != NULL && p2 != NULL)
    {
        sscanf(p1+1, "%d,%d,%d,%d,%d,%d", &port_number, &port_number, &port_number, &port_number, &port_number, &port_number);
        sprintf(ip_address, "%s.%s.%s.%s", strtok(buffer+strlen("227 Entering Passive Mode ("), ","), strtok(NULL, ","), strtok(NULL, ","), strtok(NULL, ","));
    }

    // create data socket and connect to server
    int data_socket;
    struct sockaddr_in data_address;
    memset(&data_address, 0, sizeof(data_address));
    data_address.sin_family = AF_INET;
    data_address.sin_addr.s_addr = inet_addr(ip_address);
    data_address.sin_port = htons(port_number);
    data_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (data_socket < 0)
    {
        perror("Failed to create data socket");
        exit(EXIT_FAILURE);
    }
    if (connect(data_socket, (struct sockaddr *)&data_address, sizeof(data_address)) < 0)
    {
        perror("Failed to connect to data socket");
        exit(EXIT_FAILURE);
    }

    // send retrieve command
    printf("Enter filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\r\n")] = '\0';
    sprintf(buffer, "RETR %s\r\n", filename);
    if (send(client_socket, buffer, strlen(buffer), 0) < 0)
    {
        perror("Failed to send retrieve command");
        exit(EXIT_FAILURE);
    }

    // receive response from server
    if (recv(client_socket, buffer, sizeof(buffer), 0) < 0)
    {
        perror("Failed to receive response");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer);

    // receive file from server
    FILE *fp;
    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        perror("Failed to create file");
        exit(EXIT_FAILURE);
    }

    int bytes_received;
    while ((bytes_received = recv(data_socket, buffer, sizeof(buffer), 0)) > 0)
    {
        fwrite(buffer, 1, bytes_received, fp);
    }
    printf("File received successfully\n");

    // close sockets and file
    fclose(fp);
    close(data_socket);
    close(client_socket);

    return 0;
}