//MISTRAL-7B DATASET v1.0 Category: TCP/IP Programming ; Style: Alan Turing
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

bool is_prime(int number) {
    if (number <= 1) {
        return false;
    }

    for (int divisor = 2; divisor * divisor <= number; ++divisor) {
        if (number % divisor == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int master_socket, client_socket;
    struct sockaddr_in server_address, client_address;

    memset(&server_address, 0, sizeof(server_address));
    memset(&client_address, 0, sizeof(client_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(54000);
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);

    master_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    bind(master_socket, (struct sockaddr *)&server_address, sizeof(server_address));

    listen(master_socket, 5);

    printf("Echo server is running...\n");

    while (true) {
        socklen_t client_length = sizeof(client_address);
        client_socket = accept(master_socket, (struct sockaddr *)&client_address, &client_length);

        char buffer[1024];
        int read_size;

        while ((read_size = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
            printf("Received data: %s\n", buffer);

            int prime_number = 0;
            for (int i = 0; i < read_size; ++i) {
                prime_number = (prime_number * 263 + buffer[i]) & 0xFFFFFFFF;
            }

            if (is_prime(prime_number)) {
                send(client_socket, "Prime number received.\n", 16, 0);
            } else {
                send(client_socket, "Not a prime number.\n", 14, 0);
            }
        }

        close(client_socket);
    }

    close(master_socket);

    return 0;
}