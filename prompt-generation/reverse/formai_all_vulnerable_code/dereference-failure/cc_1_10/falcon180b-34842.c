//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void die(char *error) {
    perror(error);
    exit(1);
}

void print_usage() {
    printf("Usage:./ftp_client <hostname> <username> <password> <local_file> <remote_file>\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 6) {
        print_usage();
    }

    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];
    char *local_file = argv[4];
    char *remote_file = argv[5];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        die("Failed to create socket");
    }

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        die("Invalid hostname");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);
    server_addr.sin_addr = *((struct in_addr *) host->h_addr);

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        die("Failed to connect to server");
    }

    char *login_message = "USER ";
    strcat(login_message, username);
    strcat(login_message, "\r\n");

    send(sock, login_message, strlen(login_message), 0);

    char *password_message = "PASS ";
    strcat(password_message, password);
    strcat(password_message, "\r\n");

    send(sock, password_message, strlen(password_message), 0);

    char *change_dir_message = "CWD /";
    send(sock, change_dir_message, strlen(change_dir_message), 0);

    char *binary_mode_message = "TYPE I";
    send(sock, binary_mode_message, strlen(binary_mode_message), 0);

    char *store_file_message = "STOR ";
    strcat(store_file_message, remote_file);
    send(sock, store_file_message, strlen(store_file_message), 0);

    FILE *local_file_ptr = fopen(local_file, "rb");
    if (local_file_ptr == NULL) {
        die("Failed to open local file");
    }

    char buffer[BUFFER_SIZE];
    while (fread(buffer, 1, BUFFER_SIZE, local_file_ptr) > 0) {
        send(sock, buffer, BUFFER_SIZE, 0);
    }

    fclose(local_file_ptr);

    char *end_transfer_message = "\r\n";
    send(sock, end_transfer_message, strlen(end_transfer_message), 0);

    close(sock);

    return 0;
}