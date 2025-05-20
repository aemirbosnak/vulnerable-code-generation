//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 21
#define MAXSIZE 1024

int main(int argc, char *argv[]) {
    char server_address[MAXSIZE], username[MAXSIZE], password[MAXSIZE], command[MAXSIZE];
    int data_socket, control_socket, connection_status;
    struct sockaddr_in server;
    char recv_buffer[MAXSIZE];
    int recv_length = 0;

    printf("Enter the address of the FTP server: ");
    fgets(server_address, MAXSIZE, stdin);
    server_address[strcspn(server_address, "\n")] = 0; // remove newline character

    printf("Enter your username: ");
    fgets(username, MAXSIZE, stdin);
    username[strcspn(username, "\n")] = 0;

    printf("Enter your password: ");
    fgets(password, MAXSIZE, stdin);
    password[strcspn(password, "\n")] = 0;

    // create control socket
    control_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (control_socket == -1) {
        printf("Failed to create control socket\n");
        exit(1);
    }

    // set server information
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_address);
    server.sin_port = htons(PORT);

    // connect to FTP server
    connection_status = connect(control_socket, (struct sockaddr*)&server, sizeof(server));

    if (connection_status == -1) {
        printf("Failed to connect to FTP server\n");
        exit(1);
    }

    printf("Connected to FTP server\n");

    // log in to FTP server
    char* expected_response = "230";

    // send username
    sprintf(command, "USER %s\r\n", username);
    write(control_socket, command, strlen(command));

    // receive response
    bzero(recv_buffer, MAXSIZE);
    recv(control_socket, recv_buffer, MAXSIZE, 0);
    sscanf(recv_buffer, "%d", &recv_length);

    if (strncmp(recv_buffer + 4, expected_response, 3) != 0) {
        printf("Failed to log in to FTP server\n");
        exit(1);
    }

    // send password
    sprintf(command, "PASS %s\r\n", password);
    write(control_socket, command, strlen(command));

    // receive response
    bzero(recv_buffer, MAXSIZE);
    recv(control_socket, recv_buffer, MAXSIZE, 0);
    sscanf(recv_buffer, "%d", &recv_length);

    if (strncmp(recv_buffer + 4, expected_response, 3) != 0) {
        printf("Failed to log in to FTP server\n");
        exit(1);
    }

    printf("Logged in to FTP server\n");

    // enter passive mode
    expected_response = "227";

    sprintf(command, "PASV\r\n");
    write(control_socket, command, strlen(command));

    bzero(recv_buffer, MAXSIZE);
    recv(control_socket, recv_buffer, MAXSIZE, 0);
    sscanf(recv_buffer, "%d", &recv_length);

    if (strncmp(recv_buffer + 4, expected_response, 3) != 0) {
        printf("Failed to enter passive mode\n");
        exit(1);
    }

    int port1, port2, data_port;
    char ip[16];
    sscanf(recv_buffer, "%*[^(](%d,%d,%d,%d,%d,%d)", &recv_length, &recv_length, &recv_length, &recv_length, &port1, &port2);
    sprintf(ip, "%s.%s.%s.%s", strtok(server_address, "."), strtok(NULL, "."), strtok(NULL, "."), strtok(NULL, "."));
    data_port = port1 * 256 + port2;

    // create data socket
    data_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (data_socket == -1) {
        printf("Failed to create data socket\n");
        exit(1);
    }

    // set data server information
    struct sockaddr_in data_server;
    data_server.sin_family = AF_INET;
    data_server.sin_addr.s_addr = inet_addr(ip);
    data_server.sin_port = htons(data_port);

    // connect to data server
    connection_status = connect(data_socket, (struct sockaddr*)&data_server, sizeof(data_server));

    if (connection_status == -1) {
        printf("Failed to connect to FTP data server\n");
        exit(1);
    }

    printf("Connected to FTP data server in passive mode\n");

    // send list command
    expected_response = "150";
    sprintf(command, "LIST\r\n");
    write(control_socket, command, strlen(command));

    // receive response
    bzero(recv_buffer, MAXSIZE);
    recv(control_socket, recv_buffer, MAXSIZE, 0);
    sscanf(recv_buffer, "%d", &recv_length);

    if (strncmp(recv_buffer + 4, expected_response, 3) != 0) {
        printf("Failed to get list of files from FTP server\n");
        exit(1);
    }

    // receive list of files
    bzero(recv_buffer, MAXSIZE);

    do {
        recv_length = recv(data_socket, recv_buffer, MAXSIZE, 0);
        recv_buffer[recv_length] = '\0';
        printf("%s", recv_buffer);
    } while (recv_length > 0);

    bzero(recv_buffer, MAXSIZE);
    recv(control_socket, recv_buffer, MAXSIZE, 0);
    sscanf(recv_buffer, "%d", &recv_length);

    if (strncmp(recv_buffer + 4, "226", 3) != 0) {
        printf("Failed to get list of files from FTP server\n");
        exit(1);
    }

    // close data socket
    close(data_socket);

    // disconnect from FTP server
    expected_response = "221";
    sprintf(command, "QUIT\r\n");
    write(control_socket, command, strlen(command));

    // receive response
    bzero(recv_buffer, MAXSIZE);
    recv(control_socket, recv_buffer, MAXSIZE, 0);
    sscanf(recv_buffer, "%d", &recv_length);

    if (strncmp(recv_buffer + 4, expected_response, 3) != 0) {
        printf("Failed to disconnect from FTP server\n");
        exit(1);
    }

    printf("Disconnected from FTP server\n");

    // close control socket
    close(control_socket);

    return 0;
}