//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char send_buffer[BUFFER_SIZE];
    int bytes_received;
    int bytes_sent;
    char *user = "anonymous";
    char *pass = "anonymous@";

    if (argc!= 4) {
        printf("Usage:./ftp_client <server_ip> <port> <file_name>\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Failed to create socket\n");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Failed to connect to server\n");
        close(sock);
        return 1;
    }

    printf("Connected to server\n");

    send(sock, user, strlen(user), 0);
    send(sock, pass, strlen(pass), 0);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received == 0) {
            printf("Disconnected from server\n");
            break;
        }

        printf("Received from server: %s", buffer);

        if (strcmp(buffer, "220") == 0) {
            sprintf(send_buffer, "USER %s\r\n", user);
            send(sock, send_buffer, strlen(send_buffer), 0);
        } else if (strcmp(buffer, "331") == 0) {
            sprintf(send_buffer, "PASS %s\r\n", pass);
            send(sock, send_buffer, strlen(send_buffer), 0);
        } else if (strcmp(buffer, "230") == 0) {
            sprintf(send_buffer, "TYPE I\r\n");
            send(sock, send_buffer, strlen(send_buffer), 0);
        } else if (strcmp(buffer, "200") == 0) {
            sprintf(send_buffer, "RETR %s\r\n", argv[3]);
            send(sock, send_buffer, strlen(send_buffer), 0);

            FILE *fp;
            fp = fopen(argv[3], "wb");

            while (1) {
                memset(buffer, 0, BUFFER_SIZE);
                bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);

                if (bytes_received == 0) {
                    printf("Disconnected from server\n");
                    break;
                }

                fwrite(buffer, 1, bytes_received, fp);

                if (feof(fp)) {
                    printf("File transfer complete\n");
                    fclose(fp);
                    break;
                }
            }
        }
    }

    close(sock);
    return 0;
}