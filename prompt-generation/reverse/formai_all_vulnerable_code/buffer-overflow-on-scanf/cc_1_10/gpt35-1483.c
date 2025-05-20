//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

void error_handler(char* error_message) {
    fprintf(stderr, "%s\n", error_message);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_address;
    char buffer[BUFSIZ];
    char filename[BUFSIZ];
    char* file_name_ptr;
    FILE* file;
    ssize_t read_result;
    ssize_t send_result, write_result;

    if (argc != 3) {
        error_handler("Usage: ./ftp_client <Server IP> <Port>");
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error_handler("Socket creation failed");
    }

    memset(&server_address, 0, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        error_handler("Invalid address/ Address not supported");
    }

    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        error_handler("Connection Failed");
    }

    printf("Connected to FTP Server\n");

    printf("Enter file name to download: ");
    scanf("%[^\n]", filename);
    getchar();

    send_result = send(sock, filename, sizeof(filename), 0);

    if (send_result <= 0) {
        error_handler("Send failed");
    }

    file_name_ptr = strrchr(filename, '/') + 1;
    file = fopen(file_name_ptr, "wb");

    if (file == NULL) {
        error_handler("File open failed");
    }

    while ((read_result = read(sock, buffer, BUFSIZ)) > 0) {
        write_result = fwrite(buffer, 1, read_result, file);

        if (write_result < read_result) {
            error_handler("Write failed");
        }

        memset(buffer, 0, BUFSIZ);
    }

    if (read_result < 0) {
        error_handler("Read failed");
    }

    printf("File Download Successful\n");

    close(sock);
    fclose(file);

    return 0;
}