//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

int ftp_client(char *server_ip, char *username, char *password, char *file_name) {

    int control_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (control_sock == -1) {
        printf("Error: Could not create socket.\n");
        return 1;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(21);

    if (inet_pton(AF_INET, server_ip, &server.sin_addr) == -1) {
        printf("Error: Invalid address.\n");
        close(control_sock);
        return 1;
    }

    if (connect(control_sock, (struct sockaddr *) &server, sizeof(server)) == -1) {
        printf("Error: Could not connect to server.\n");
        close(control_sock);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int bytes;

    bytes = recv(control_sock, buffer, BUFFER_SIZE, 0);
    buffer[bytes] = '\0';

    if (buffer[0] != '2' || buffer[1] != '2' || buffer[2] != '0') {
        printf("Error: Server not ready.\n");
        close(control_sock);
        return 1;
    }

    char *user_cmd = "USER ";
    strcat(user_cmd, username);
    strcat(user_cmd, "\r\n");

    if (send(control_sock, user_cmd, strlen(user_cmd), 0) == -1) {
        printf("Error: Could not send username.\n");
        close(control_sock);
        return 1;
    }

    bytes = recv(control_sock, buffer, BUFFER_SIZE, 0);
    buffer[bytes] = '\0';

    if (buffer[0] != '3') {
        printf("Error: Invalid username.\n");
        close(control_sock);
        return 1;
    }

    char *pass_cmd = "PASS ";
    strcat(pass_cmd, password);
    strcat(pass_cmd, "\r\n");

    if (send(control_sock, pass_cmd, strlen(pass_cmd), 0) == -1) {
        printf("Error: Could not send password.\n");
        close(control_sock);
        return 1;
    }

    bytes = recv(control_sock, buffer, BUFFER_SIZE, 0);
    buffer[bytes] = '\0';

    if (buffer[0] != '2' || buffer[1] != '3' || buffer[2] != '0') {
        printf("Error: Invalid password.\n");
        close(control_sock);
        return 1;
    }

    char *type_cmd = "TYPE I\r\n";

    if (send(control_sock, type_cmd, strlen(type_cmd), 0) == -1) {
        printf("Error: Could not set type.\n");
        close(control_sock);
        return 1;
    }

    bytes = recv(control_sock, buffer, BUFFER_SIZE, 0);
    buffer[bytes] = '\0';

    if (buffer[0] != '2' || buffer[1] != '0' || buffer[2] != '0') {
        printf("Error: Could not set type.\n");
        close(control_sock);
        return 1;
    }

    char *pasv_cmd = "PASV\r\n";

    if (send(control_sock, pasv_cmd, strlen(pasv_cmd), 0) == -1) {
        printf("Error: Could not send PASV.\n");
        close(control_sock);
        return 1;
    }

    bytes = recv(control_sock, buffer, BUFFER_SIZE, 0);
    buffer[bytes] = '\0';

    if (buffer[0] != '2' || buffer[1] != '2' || buffer[2] != '7') {
        printf("Error: Could not enter passive mode.\n");
        close(control_sock);
        return 1;
    }

    int ip1, ip2, ip3, ip4, port1, port2;

    sscanf(buffer, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)",
           &ip1, &ip2, &ip3, &ip4, &port1, &port2);

    int data_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sock == -1) {
        printf("Error: Could not create socket.\n");
        close(control_sock);
        return 1;
    }

    struct sockaddr_in data;
    data.sin_family = AF_INET;
    data.sin_port = htons((port1 * 256) + port2);

    char data_ip[16];
    sprintf(data_ip, "%d.%d.%d.%d", ip1, ip2, ip3, ip4);

    if (inet_pton(AF_INET, data_ip, &data.sin_addr) == -1) {
        printf("Error: Invalid address.\n");
        close(control_sock);
        return 1;
    }

    if (connect(data_sock, (struct sockaddr *) &data, sizeof(data)) == -1) {
        printf("Error: Could not connect to server.\n");
        close(control_sock);
        return 1;
    }

    char *retr_cmd = "RETR ";
    strcat(retr_cmd, file_name);
    strcat(retr_cmd, "\r\n");

    if (send(control_sock, retr_cmd, strlen(retr_cmd), 0) == -1) {
        printf("Error: Could not request file.\n");
        close(control_sock);
        close(data_sock);
        return 1;
    }

    bytes = recv(control_sock, buffer, BUFFER_SIZE, 0);
    buffer[bytes] = '\0';

    if (buffer[0] != '1' && buffer[0] != '2' && buffer[0] != '3') {
        printf("Error: Could not retrieve file.\n");
        close(control_sock);
        close(data_sock);
        return 1;
    }

    char *local_file_name = file_name;

    int local_file = open(local_file_name, O_WRONLY | O_CREAT, 0644);

    if (local_file == -1) {
        printf("Error: Could not create local file.\n");
        close(control_sock);
        close(data_sock);
        return 1;
    }

    while ((bytes = recv(data_sock, buffer, BUFFER_SIZE, 0)) > 0) {
        write(local_file, buffer, bytes);
    }

    close(local_file);
    close(control_sock);
    close(data_sock);

    return 0;
}

int main() {
    char server_ip[16] = "192.168.1.1";
    char username[16] = "username";
    char password[16] = "password";
    char file_name[100] = "test.txt";
    printf("Downloading %s...\n", file_name);
    int result = ftp_client(server_ip, username, password, file_name);
    if (result == 0) {
        printf("File downloaded successfully.\n");
    }
    return 0;
}