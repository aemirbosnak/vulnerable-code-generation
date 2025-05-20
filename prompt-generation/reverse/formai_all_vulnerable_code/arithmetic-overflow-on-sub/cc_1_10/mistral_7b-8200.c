//MISTRAL-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define TIMEOUT 3
#define PACKET_SIZE 65535
#define NUM_PACKETS 5

typedef struct {
    int sockfd;
    struct sockaddr_in server_addr;
} connection_t;

double calculate_mean(double *data, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum / size;
}

void print_results(char *test_name, double *data, int size) {
    printf("\n%s Test Results:\n", test_name);
    printf("-------------------\n");
    printf("Mean: %.2f Kbps\n", calculate_mean(data, size) / 1024.0);
}

int create_socket(int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    return sockfd;
}

void send_data(int sockfd, char *buffer, int length) {
    send(sockfd, buffer, length, 0);
}

void receive_data(int sockfd, char *buffer, int length) {
    int received_bytes = recv(sockfd, buffer, length, 0);
    if (received_bytes <= 0) {
        perror("Error receiving data");
        exit(EXIT_FAILURE);
    }
}

void test_internet_speed(char *server_ip, int port) {
    int sockfd = create_socket(port);
    double *received_data = malloc(NUM_PACKETS * sizeof(double));

    for (int i = 0; i < NUM_PACKETS; i++) {
        char buffer[BUFFER_SIZE];
        memset(buffer, 'a', PACKET_SIZE);

        send_data(sockfd, buffer, PACKET_SIZE);

        clock_t start = clock();
        receive_data(sockfd, buffer, PACKET_SIZE);
        clock_t end = clock();

        double time_taken = (end - start) / CLOCKS_PER_SEC * 1024.0;
        double received_kb = (PACKET_SIZE / 1024.0) / (time_taken);

        received_data[i] = received_kb;
    }

    print_results("Download", received_data, NUM_PACKETS);

    close(sockfd);
    free(received_data);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <server_ip> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    test_internet_speed(argv[1], atoi(argv[2]));

    return EXIT_SUCCESS;
}