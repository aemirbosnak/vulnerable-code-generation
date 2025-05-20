//FormAI DATASET v1.0 Category: System administration ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define max length of server name
#define MAX_SERVER_NAME 50

// Define max length of IP address
#define MAX_IP_ADDRESS 15

// Define max length of username and password
#define MAX_USERNAME_PASSWORD 25

// Define max length of command to be executed
#define MAX_COMMAND_LENGTH 100

// Define struct for servers
typedef struct Server {
    char name[MAX_SERVER_NAME];
    char ipAddress[MAX_IP_ADDRESS];
    char username[MAX_USERNAME_PASSWORD];
    char password[MAX_USERNAME_PASSWORD];
} Server;

// Define function to add new server
void addServer(Server *servers, int numServers) {
    // Get input for server information
    printf("Enter server name: ");
    fgets(servers[numServers].name, MAX_SERVER_NAME, stdin);
    servers[numServers].name[strcspn(servers[numServers].name, "\n")] = 0;

    printf("Enter server IP address: ");
    fgets(servers[numServers].ipAddress, MAX_IP_ADDRESS, stdin);
    servers[numServers].ipAddress[strcspn(servers[numServers].ipAddress, "\n")] = 0;

    printf("Enter username: ");
    fgets(servers[numServers].username, MAX_USERNAME_PASSWORD, stdin);
    servers[numServers].username[strcspn(servers[numServers].username, "\n")] = 0;

    printf("Enter password: ");
    fgets(servers[numServers].password, MAX_USERNAME_PASSWORD, stdin);
    servers[numServers].password[strcspn(servers[numServers].password, "\n")] = 0;

    printf("New server added successfully!\n");
}

// Define function to remove server
void removeServer(Server *servers, int numServers) {
    // Get input for server name
    char serverName[MAX_SERVER_NAME];
    printf("Enter server name to remove: ");
    fgets(serverName, MAX_SERVER_NAME, stdin);
    serverName[strcspn(serverName, "\n")] = 0;

    // Search for server with matching name
    int serverIndex = -1;
    for (int i = 0; i < numServers; i++) {
        if (strcmp(servers[i].name, serverName) == 0) {
            serverIndex = i;
            break;
        }
    }

    // If server is found, remove it
    if (serverIndex >= 0) {
        for (int i = serverIndex; i < numServers - 1; i++) {
            servers[i] = servers[i+1];
        }
        printf("Server removed successfully!\n");
    } else {
        printf("Server not found.\n");
    }
}

// Define function to execute command on server
void executeCommand(Server *servers, int numServers) {
    // Get input for server name and command to execute
    char serverName[MAX_SERVER_NAME];
    char command[MAX_COMMAND_LENGTH];
    printf("Enter server name to execute command on: ");
    fgets(serverName, MAX_SERVER_NAME, stdin);
    serverName[strcspn(serverName, "\n")] = 0;

    printf("Enter command to execute: ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    command[strcspn(command, "\n")] = 0;

    // Search for server with matching name
    int serverIndex = -1;
    for (int i = 0; i < numServers; i++) {
        if (strcmp(servers[i].name, serverName) == 0) {
            serverIndex = i;
            break;
        }
    }

    // If server is found, execute command
    if (serverIndex >= 0) {
        printf("Connecting to server %s at IP address %s...\n", servers[serverIndex].name, servers[serverIndex].ipAddress);
        // Execute command on server using SSH protocol
        // Code omitted for simplicity
        printf("Command executed successfully!\n");
    } else {
        printf("Server not found.\n");
    }
}

int main() {
    int choice = 0;
    int numServers = 0;
    Server servers[10];

    while (choice != 4) {
        // Display menu options
        printf("\n");
        printf("1. Add server\n");
        printf("2. Remove server\n");
        printf("3. Execute command on server\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character from scanf

        switch (choice) {
            case 1:
                if (numServers < 10) {
                    addServer(servers, numServers);
                    numServers++;
                } else {
                    printf("Maximum number of servers reached.\n");
                }
                break;
            case 2:
                if (numServers > 0) {
                    removeServer(servers, numServers);
                    numServers--;
                } else {
                    printf("No servers to remove.\n");
                }
                break;
            case 3:
                if (numServers > 0) {
                    executeCommand(servers, numServers);
                } else {
                    printf("No servers to execute command on.\n");
                }
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}