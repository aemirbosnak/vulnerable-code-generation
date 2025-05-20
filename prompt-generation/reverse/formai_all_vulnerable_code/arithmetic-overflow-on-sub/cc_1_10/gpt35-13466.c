//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define PORT 8080
#define BUFF_SIZE 1024
#define NUM_OF_PACKETS 10

int main(int argc, char const *argv[]) {
    int sock = 0;
    struct sockaddr_in serv_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    char buffer[BUFF_SIZE] = {0};
    int total_sent_bytes = 0; // total number of sent bytes
    int total_received_bytes = 0; // total number of received bytes
    clock_t start_time, end_time; // for measuring elapsed time
    double elapsed_time; // elapsed time since start_time

    // send NUM_OF_PACKETS packets to the server
    for (int i = 1; i <= NUM_OF_PACKETS; i++) {
        sprintf(buffer, "Packet #%d", i);
        int sent_bytes = send(sock, buffer, strlen(buffer), 0);
        total_sent_bytes += sent_bytes;

        printf("Sent: %s\n", buffer);

        int received_bytes = 0;
        start_time = clock(); // start measuring time
        while (received_bytes < sent_bytes) {
            int valread = read(sock, buffer + received_bytes, sent_bytes - received_bytes);
            if(valread == -1)
                break;

            received_bytes += valread;
        }
        if (received_bytes == -1) {
            printf("Error reading from socket\n");
            close(sock);
            return -1;
        }
        end_time = clock(); // stop measuring time
        elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC * 1000;
        total_received_bytes += received_bytes;

        printf("Received: %s, RTT: %f ms\n", buffer, elapsed_time);
    }

    double throughput = (double) total_sent_bytes / elapsed_time;
    printf("\nThroughput: %f bytes/ms\n", throughput);

    close(sock);
    return 0;
}