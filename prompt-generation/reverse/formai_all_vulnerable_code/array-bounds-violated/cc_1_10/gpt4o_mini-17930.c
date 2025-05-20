//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <math.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void calculate_prime_factors(int number, int *factors, int *size) {
    int idx = 0;
    while (number % 2 == 0) {
        factors[idx++] = 2;
        number /= 2;
    }
    for (int i = 3; i <= sqrt(number); i += 2) {
        while (number % i == 0) {
            factors[idx++] = i;
            number /= i;
        }
    }
    if (number > 2) {
        factors[idx++] = number;
    }
    *size = idx;
}

void process_client_data(int client_socket) {
    char buffer[BUFFER_SIZE];
    int recv_len = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    if (recv_len < 0) {
        perror("Receive failed");
        close(client_socket);
        return;
    }

    buffer[recv_len] = '\0'; 
    int number = atoi(buffer);
    int factors[BUFFER_SIZE];
    int size = 0;

    calculate_prime_factors(number, factors, &size);

    char result[BUFFER_SIZE] = "Prime factors: ";
    for (int i = 0; i < size; i++) {
        char temp[10];
        sprintf(temp, "%d", factors[i]);
        strcat(result, temp);
        if (i < size - 1) {
            strcat(result, ", ");
        }
    }

    send(client_socket, result, strlen(result), 0);
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        printf("Connection accepted from %s:%d\n",
            inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        process_client_data(client_socket);
    }

    close(server_socket);
    return 0;
}