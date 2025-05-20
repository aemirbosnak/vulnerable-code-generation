//FormAI DATASET v1.0 Category: Networking ; Style: Cyberpunk
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 

#define PORT 8080 

void welcome_message() {
    printf("Welcome to the cyber network!\n");
    printf("We are here to connect you to other hackers and cyberpunks around the world.\n");
    printf("Enter \"help\" for a list of available commands.\n\n");
}

void list_commands() {
    printf("Available commands:\n");
    printf("1. connect <ip_address> <port>\n");
    printf("2. disconnect\n");
    printf("3. send <message>\n");
    printf("4. exit\n\n");
}

void connect_to_server(char* ip_address, int port) {
    int sock = 0; 
    struct sockaddr_in serv_addr; 

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) { 
        printf("\n Socket creation error \n"); 
        return; 
    } 

    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(port); 
    
    if(inet_pton(AF_INET, ip_address, &serv_addr.sin_addr)<=0) { 
        printf("\nInvalid address/ Address not supported \n"); 
        return; 
    } 

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) { 
        printf("\nConnection Failed \n"); 
        return; 
    } 

    printf("Connected to: %s:%d\n", ip_address, port);
}

void disconnect_from_server() {
    printf("Disconnected from server.\n");
}

void send_message(int sock, char* message) {
    if(send(sock, message, strlen(message), 0) < 0) {
        printf("Message failed to send.\n");
        return;
    }

    printf("Message sent.\n");
}

int main() { 
    int sock = 0;
    char input[1000];
    char command[20];
    char ip_address[16];
    int port;
    char message[1000];
    struct sockaddr_in serv_addr; 

    welcome_message();
    list_commands();

    while(1) { 
        printf("> ");

        fgets(input, 1000, stdin);
        sscanf(input, "%s", command);

        if(strcmp(command, "help") == 0) {
            list_commands();
        }
        else if(strcmp(command, "connect") == 0) {
            sscanf(input, "%*s %s %d", ip_address, &port);
            connect_to_server(ip_address, port);
        }
        else if(strcmp(command, "disconnect") == 0) {
            disconnect_from_server();
        }
        else if(strcmp(command, "send") == 0) {
            sscanf(input, "%*s %[^\t\n]", message);
            send_message(sock, message);
        }
        else if(strcmp(command, "exit") == 0) {
            break;
        }
        else {
            printf("Invalid command. Enter \"help\" for a list of available commands.\n");
        }
    }

    return 0; 
}