//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Cyberpunk
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/sendfile.h>

int main()
{
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(21);
    server_address.sin_addr.s_addr= inet_addr("127.0.0.1");

    int connect_status = connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    if(connect_status == -1)
    {
        printf("Error connecting to FTP server.\n");
        return 1;
    }

    char username[50], password[50];
    printf("Enter FTP server username: ");
    scanf("%s", username);
    printf("Enter FTP server password: ");
    scanf("%s", password);

    char user_command[100], pass_command[100];
    sprintf(user_command, "USER %s\r\n", username);
    sprintf(pass_command, "PASS %s\r\n", password);

    send(client_socket, user_command, strlen(user_command), 0);
    char response[1024];
    memset(response, '\0', sizeof(response));
    recv(client_socket, response, sizeof(response), 0);

    if(strncmp(response, "331", 3) != 0)
    {
        printf("FTP server rejected username.\n");
        return 1;
    }

    send(client_socket, pass_command, strlen(pass_command), 0);
    memset(response, '\0', sizeof(response));
    recv(client_socket, response, sizeof(response), 0);

    if(strncmp(response, "230", 3) != 0)
    {
        printf("FTP server rejected password.\n");
        return 1;
    }

    printf("Login successful!\n");

    printf("Enter file path to be uploaded: ");
    char file_path[100];
    scanf("%s", file_path);
    int fd = open(file_path, O_RDONLY);

    if(fd == -1)
    {
        printf("Error opening file: %s\n", file_path);
        return 1;
    }

    printf("Enter destination file name: ");
    char file_name[50];
    scanf("%s", file_name);

    char type_command[50];
    sprintf(type_command, "TYPE I\r\n");
    send(client_socket, type_command, strlen(type_command), 0);
    recv(client_socket, response, sizeof(response), 0);
    if(strncmp(response, "200", 3) != 0)
    {
        printf("Error setting file type.\n");
        return 1;
    }

    char pasv_command[50];
    sprintf(pasv_command, "PASV\r\n");
    send(client_socket, pasv_command, strlen(pasv_command), 0);
    memset(response, '\0', sizeof(response));
    recv(client_socket, response, sizeof(response), 0);

    if(strncmp(response, "227", 3) != 0)
    {
        printf("Error entering passive mode.\n");
        return 1;
    }

    int h1, h2, h3, h4, p1, p2;
    sscanf(response, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)\n", &h1, &h2, &h3, &h4, &p1, &p2);

    char destination_address[50];
    sprintf(destination_address, "%d.%d.%d.%d", h1, h2, h3, h4);
    int port = p1 * 256 + p2;
    struct sockaddr_in destination;
    destination.sin_family = AF_INET;
    inet_pton(AF_INET, destination_address, &destination.sin_addr);
    destination.sin_port = htons(port);

    int data_socket = socket(AF_INET, SOCK_STREAM, 0);
    connect(data_socket, (struct sockaddr *)&destination, sizeof(destination));

    char stor_command[50];
    sprintf(stor_command, "STOR %s\r\n", file_name);
    send(client_socket, stor_command, strlen(stor_command), 0);
    memset(response, '\0', sizeof(response));
    recv(client_socket, response, sizeof(response), 0);

    if(strncmp(response, "150", 3) != 0)
    {
        printf("Error starting file transfer.\n");
        return 1;
    }

    struct stat file_stat;
    fstat(fd, &file_stat);
    int remaining = file_stat.st_size;
    sendfile(data_socket, fd, NULL, file_stat.st_size);

    printf("File upload successful!\n");

    close(client_socket);
    close(data_socket);
    return 0;
}