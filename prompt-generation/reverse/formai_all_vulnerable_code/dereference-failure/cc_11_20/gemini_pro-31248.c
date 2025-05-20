//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: Linus Torvalds
// Linus Torvalds-style Smart Home Automation Example

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define some macros for easier coding
#define ERROR -1
#define OK 0

// Define the port number for the server
#define PORT 5555

// Define the maximum size of the message buffer
#define MAX_BUFFER_SIZE 1024

// Define the commands that the server can handle
#define CMD_ON "ON"
#define CMD_OFF "OFF"
#define CMD_STATUS "STATUS"

// Define the states of the smart home devices
#define STATE_ON 1
#define STATE_OFF 0

// Define the structure of the smart home device
struct device {
    char name[32];
    int state;
};

// Define an array of smart home devices
struct device devices[] = {
    { "Light 1", STATE_OFF },
    { "Light 2", STATE_OFF },
    { "Fan", STATE_OFF },
    { "AC", STATE_OFF }
};

// Define the main function
int main(int argc, char **argv) {
    // Create a socket for the server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == ERROR) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set the server address and port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == ERROR) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == ERROR) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Accept incoming connections
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);
    int client_socket;
    while ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len)) != ERROR) {
        // Get the message from the client
        char buffer[MAX_BUFFER_SIZE];
        int bytes_received = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
        if (bytes_received == ERROR) {
            perror("recv");
            return EXIT_FAILURE;
        }

        // Parse the message
        char *command = strtok(buffer, " ");
        char *device_name = strtok(NULL, " ");

        // Find the device by name
        struct device *device;
        for (int i = 0; i < sizeof(devices) / sizeof(struct device); i++) {
            if (strcmp(devices[i].name, device_name) == 0) {
                device = &devices[i];
                break;
            }
        }

        // If the device was not found, send an error message to the client
        if (device == NULL) {
            char *error_message = "Device not found.";
            int bytes_sent = send(client_socket, error_message, strlen(error_message), 0);
            if (bytes_sent == ERROR) {
                perror("send");
                return EXIT_FAILURE;
            }
            continue;
        }

        // If the command is "ON", turn on the device
        if (strcmp(command, CMD_ON) == 0) {
            device->state = STATE_ON;
            char *success_message = "Device turned on.";
            int bytes_sent = send(client_socket, success_message, strlen(success_message), 0);
            if (bytes_sent == ERROR) {
                perror("send");
                return EXIT_FAILURE;
            }
            continue;
        }

        // If the command is "OFF", turn off the device
        if (strcmp(command, CMD_OFF) == 0) {
            device->state = STATE_OFF;
            char *success_message = "Device turned off.";
            int bytes_sent = send(client_socket, success_message, strlen(success_message), 0);
            if (bytes_sent == ERROR) {
                perror("send");
                return EXIT_FAILURE;
            }
            continue;
        }

        // If the command is "STATUS", send the status of the device to the client
        if (strcmp(command, CMD_STATUS) == 0) {
            char *status_message;
            if (device->state == STATE_ON) {
                status_message = "Device is on.";
            } else {
                status_message = "Device is off.";
            }
            int bytes_sent = send(client_socket, status_message, strlen(status_message), 0);
            if (bytes_sent == ERROR) {
                perror("send");
                return EXIT_FAILURE;
            }
            continue;
        }

        // If the command is not recognized, send an error message to the client
        char *error_message = "Invalid command.";
        int bytes_sent = send(client_socket, error_message, strlen(error_message), 0);
        if (bytes_sent == ERROR) {
            perror("send");
            return EXIT_FAILURE;
        }
    }

    // Close the client socket
    close(client_socket);

    // Close the server socket
    close(server_socket);

    return EXIT_SUCCESS;
}