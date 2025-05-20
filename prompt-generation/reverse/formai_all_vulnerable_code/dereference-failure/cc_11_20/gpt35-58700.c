//FormAI DATASET v1.0 Category: Socket programming ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

// Players are limited up to 5
#define MAX_PLAYERS 5

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1, addrlen = sizeof(address);
    char buffer[1024] = {0};

    //Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    int player_socket[MAX_PLAYERS], i = 0;
    while(i < MAX_PLAYERS) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        char welcome_msg[100];
        sprintf(welcome_msg, "Welcome Player %d. Waiting for other players to join...\n", i+1);
        send(new_socket, welcome_msg, strlen(welcome_msg)+1, 0); 
        player_socket[i] = new_socket;
        i++;
    }
    while(1) {
        for(int j=0; j<MAX_PLAYERS; j++) { 
            memset(buffer, 0, sizeof(buffer));
            valread = read(player_socket[j], buffer, sizeof(buffer));
            if(valread > 0) {
                for(int k=0; k<MAX_PLAYERS; k++) {
                    if(k != j) {
                        send(player_socket[k], buffer, strlen(buffer)+1, 0);
                    }
                }
            }
        }
    }
    return 0;
}