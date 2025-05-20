//FormAI DATASET v1.0 Category: Networking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <math.h>

#define ERROR -1
#define BUFFER_SIZE 256
#define PORT 8080

// Function to handle the TCP connection
void handle_connection(int client_socket_fd){
    char buffer[BUFFER_SIZE];
    int result, bytes_received;
    double n;
    while(1){
        // Read the number sent by the client
        bytes_received = recv(client_socket_fd, buffer, BUFFER_SIZE, 0);
        if(bytes_received == ERROR){
            perror("Error receiving number from client");
            break;
        }
        if(bytes_received == 0){
            printf("Connection closed by the client\n");
            break;
        }
        buffer[bytes_received] = '\0';
        n = atof(buffer);
        printf("Received number from client: %lf\n", n);
        
        // Calculate the square root of the number
        double result_sqrt = sqrt(n);
        printf("Square root of the number: %lf\n", result_sqrt);

        // Calculate the sine of the number
        double result_sin = sin(n);
        printf("Sine of the number: %lf\n", result_sin);

        // Calculate the cosine of the number
        double result_cos = cos(n);
        printf("Cosine of the number: %lf\n", result_cos);

        // Convert the results to strings and send them back to the client
        char result_buffer[BUFFER_SIZE];
        snprintf(result_buffer, BUFFER_SIZE, "%.2lf,%.2lf,%.2lf", result_sqrt, result_sin, result_cos);
        result = send(client_socket_fd, result_buffer, strlen(result_buffer), 0);
        if(result == ERROR){
            perror("Error sending results to client");
            break;
        }
        printf("Results sent to client\n");
    }
    close(client_socket_fd);
}

// Driver function
int main(){
    int server_socket_fd, client_socket_fd;
    struct sockaddr_in server_address, client_address;
    socklen_t address_length;

    // Create the TCP socket
    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket_fd == ERROR){
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Bind the server socket to the specified port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    memset(server_address.sin_zero, '\0', sizeof(server_address.sin_zero));
    if(bind(server_socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == ERROR){
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if(listen(server_socket_fd, 1) == ERROR){
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }
    printf("Listening on port %d\n", PORT);

    while(1){
        // Accept incoming connections
        address_length = sizeof(client_address);
        client_socket_fd = accept(server_socket_fd, (struct sockaddr *)&client_address, &address_length);
        if(client_socket_fd == ERROR){
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }

        // Handle the connection in a separate function
        handle_connection(client_socket_fd);
    }

    close(server_socket_fd);
    return 0;
}