//Code Llama-13B DATASET v1.0 Category: Internet Speed Test Application ; Style: minimalist
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <time.h>
    #include <stdint.h>

    #define BUF_SIZE 1024

    void print_usage() {
        printf("Usage: ./internet_speed_test <server_ip> <server_port>\n");
        exit(1);
    }

    int main(int argc, char **argv) {
        if (argc != 3) {
            print_usage();
        }

        char *server_ip = argv[1];
        int server_port = atoi(argv[2]);

        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        inet_pton(AF_INET, server_ip, &server_addr.sin_addr);
        server_addr.sin_port = htons(server_port);

        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("socket");
            exit(1);
        }

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("connect");
            exit(1);
        }

        printf("Connected to %s:%d\n", server_ip, server_port);

        struct timeval start_time, end_time;
        gettimeofday(&start_time, NULL);

        char buffer[BUF_SIZE];
        int bytes_sent = 0;
        while (bytes_sent < 100000000) {
            int n = write(sock, buffer, BUF_SIZE);
            if (n < 0) {
                perror("write");
                exit(1);
            }
            bytes_sent += n;
        }

        gettimeofday(&end_time, NULL);
        double elapsed_time = (double)(end_time.tv_sec - start_time.tv_sec) + (double)(end_time.tv_usec - start_time.tv_usec) / 1000000;
        double speed = (double)bytes_sent / elapsed_time / 1000;
        printf("Download speed: %.2f kbps\n", speed);

        close(sock);

        return 0;
    }