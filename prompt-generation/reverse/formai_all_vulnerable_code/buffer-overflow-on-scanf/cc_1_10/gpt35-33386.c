//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    int socket_descriptor, data_socket_descriptor, command_sock_result, data_sock_result;
    struct sockaddr_in server_address, data_address;
    char buffer[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    char filename[BUFFER_SIZE];
    int bytes_read;

    if (argc < 3) {
        printf("Usage: ./ftpclient ftp_server_ip_address ftp_port_number\n");
        exit(1);
    }

    // create the socket
    socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_descriptor == -1) {
        printf("Could not create the socket.\n");
        exit(1);
    }

    // prepare the sockaddr_in structure for the server
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(atoi(argv[2]));

    // connect to the server
    command_sock_result = connect(socket_descriptor, (struct sockaddr *)&server_address, sizeof(server_address));

    if (command_sock_result < 0) {
        printf("Could not connect to the server.\n");
        close(socket_descriptor);
        exit(1);
    }

    printf("Connected to the server...\n");

    // send the username
    printf("Enter the username: ");
    char username[BUFFER_SIZE];
    scanf("%s", username);
    bzero(buffer, BUFFER_SIZE);
    strncpy(buffer, username, strlen(username));
    send(socket_descriptor, buffer, strlen(buffer), 0);
    bzero(buffer, BUFFER_SIZE);
    recv(socket_descriptor, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // send the password
    printf("Enter the password: ");
    char password[BUFFER_SIZE];
    scanf("%s", password);
    bzero(buffer, BUFFER_SIZE);
    strncpy(buffer, password, strlen(password));
    send(socket_descriptor, buffer, strlen(buffer), 0);
    bzero(buffer, BUFFER_SIZE);
    recv(socket_descriptor, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // get the file name
    printf("Enter the filename: ");
    scanf("%s", filename);
    bzero(buffer, BUFFER_SIZE);
    strncpy(buffer, filename, strlen(filename));
    send(socket_descriptor, buffer, strlen(buffer), 0);
    bzero(buffer, BUFFER_SIZE);
    recv(socket_descriptor, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // connect to data socket
    data_socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);

    if (data_socket_descriptor == -1) {
        printf("Could not create the data socket.\n");
        close(socket_descriptor);
        exit(1);
    }

    bzero(&data_address, sizeof(data_address));
    data_address.sin_family = AF_INET;
    data_address.sin_addr.s_addr = inet_addr(argv[1]);
    data_address.sin_port = htons(atoi(buffer));

    data_sock_result = connect(data_socket_descriptor, (struct sockaddr *)&data_address, sizeof(data_address));
    if (data_sock_result == -1) {
        printf("Could not connect to server data port.\n");
        close(socket_descriptor);
        close(data_socket_descriptor);
        exit(1);
    }

    printf("Connected to server data port.\n");

    // get the file size
    bzero(buffer, BUFFER_SIZE);
    recv(socket_descriptor, buffer, BUFFER_SIZE, 0);
    int fileSize = atoi(buffer);

    // receive the file
    FILE *outputFile;
    outputFile = fopen(filename, "wb");
    int total = 0;
    while (total < fileSize) {
        bzero(buffer, BUFFER_SIZE);
        bytes_read = read(data_socket_descriptor, buffer, BUFFER_SIZE);
        total += bytes_read;
        fwrite(buffer, 1, bytes_read, outputFile);
    }
    fclose(outputFile);

    printf("File transfer complete. Closing connections.\n");

    // close data socket and command socket
    close(data_socket_descriptor);
    close(socket_descriptor);

    return 0;
}