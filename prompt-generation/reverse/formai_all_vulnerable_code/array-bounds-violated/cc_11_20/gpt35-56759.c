//FormAI DATASET v1.0 Category: Socket programming ; Style: post-apocalyptic
/*
 * Post-apocalyptic C Socket Programming Example
 * Author: AI Bot
 * Description: A server program that accepts connections from clients and echoes a message back after converting it into Morse Code.
 */

#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<ctype.h>

#define BUFF_SIZE 1024

char* morse_code(char c) {
    /*
     * Returns the morse code for a given character
     */
    switch (tolower(c)) {
        case 'a': return ".- ";
        case 'b': return "-... ";
        case 'c': return "-.-. ";
        case 'd': return "-.. ";
        case 'e': return ". ";
        case 'f': return "..-. ";
        case 'g': return "--. ";
        case 'h': return ".... ";
        case 'i': return ".. ";
        case 'j': return ".--- ";
        case 'k': return "-.- ";
        case 'l': return ".-.. ";
        case 'm': return "-- ";
        case 'n': return "-. ";
        case 'o': return "--- ";
        case 'p': return ".--. ";
        case 'q': return "--.- ";
        case 'r': return ".-. ";
        case 's': return "... ";
        case 't': return "- ";
        case 'u': return "..- ";
        case 'v': return "...- ";
        case 'w': return ".-- ";
        case 'x': return "-..- ";
        case 'y': return "-.-- ";
        case 'z': return "--.. ";
        case ' ': return "/ ";
        default: return "";
    }
}

int main(){
    int socket_fd, client_fd, read_size;
    char buff[BUFF_SIZE];
    struct sockaddr_in server_addr, client_addr;

    // Create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("Error: Socket Creation Failed");
        return 1;
    }

    // Set server address and port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8888);

    // Bind socket to server address and port
    if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error: Binding Failed");
        return 1;
    }

    // Listen for incoming connections
    if (listen(socket_fd, 3) == -1) {
        perror("Error: Listening Failed");
        return 1;
    }

    puts("Waiting for incoming connections...");

    while(1) {
        // Accept incoming connection from client
        socklen_t client_addr_len = sizeof(client_addr);
        client_fd = accept(socket_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_fd == -1) {
            perror("Error: Connection Accept Failed");
            continue;
        }

        puts("Connection Accepted");

        // Read message from client
        while((read_size = recv(client_fd, buff, BUFF_SIZE, 0)) > 0) {
            buff[read_size] = '\0';

            // Convert message to Morse Code and send back to client
            char* morse_buff = (char*) malloc(sizeof(char) * BUFF_SIZE);
            memset(morse_buff, 0, sizeof(char) * BUFF_SIZE);
            int i = 0;
            while(buff[i]) {
                strcat(morse_buff, morse_code(buff[i++]));
            }
            write(client_fd, morse_buff, strlen(morse_buff));
            free(morse_buff);
        }

        // Client disconnected
        if (read_size == 0) {
            puts("Client Disconnected");
            fflush(stdout);
        }
        else if (read_size == -1) {
            perror("Error: Receive Failed");
        }

        close(client_fd);
    }

    return 0;
}