//MISTRAL-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>

#define SERVER_ADDRESS "192.168.1.1"
#define PORT 80
#define BUFFER_SIZE 1024
#define TEST_FILE_SIZE 1024 * 1024

int main(void) {
    int sockfd, new_sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    struct hostent *server;
    struct timeval start, end;
    unsigned long downloaded, total;
    double speed;
    char request[BUFFER_SIZE], response[BUFFER_SIZE], file[BUFFER_SIZE];
    FILE *fp;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(SERVER_ADDRESS);
    if (server == NULL) {
        fprintf(stderr, "Error: Unknown server %s\n", SERVER_ADDRESS);
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server->h_addr_list[0], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    gettimeofday(&start, NULL);

    snprintf(request, sizeof(request), "GET /testfile.bin HTTP/1.1\r\nHost: %s\r\nAccept: */*\r\nConnection: close\r\n\r\n", SERVER_ADDRESS);
    write(sockfd, request, strlen(request));

    downloaded = 0;
    fp = fopen("testfile.bin", "wb");

    while (1) {
        int bytes_received = recv(sockfd, response, BUFFER_SIZE - 1, 0);
        if (bytes_received <= 0) {
            break;
        }

        response[bytes_received] = '\0';
        if (strncmp(response, "HTTP/1.1 200 OK\r\nContent-Length: ", 18) == 0) {
            sscanf(response + strlen("Content-Length: ") + strlen("%d"), "%ld", &total);
            total -= downloaded;
        }

        fwrite(response, bytes_received, 1, fp);
        downloaded += bytes_received;

        if (feof(fp)) {
            break;
        }
    }

    fclose(fp);
    close(sockfd);

    gettimeofday(&end, NULL);
    speed = (double) downloaded / ((end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000000);

    printf("Download Speed: %.2f Mbps\n", speed * 8 / 1024 / 1024);

    return 0;
}