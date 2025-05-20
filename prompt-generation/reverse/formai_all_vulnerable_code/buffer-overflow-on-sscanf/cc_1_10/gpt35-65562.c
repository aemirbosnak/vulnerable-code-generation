//FormAI DATASET v1.0 Category: System administration ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void startServer(char* serverName) {
    printf("Starting server %s...\n", serverName);
    // add relevant code to start the server
}

void stopServer(char* serverName) {
    printf("Stopping server %s...\n", serverName);
    // add relevant code to stop the server
}

void restartServer(char* serverName) {
    printf("Restarting server %s...\n", serverName);
    stopServer(serverName);
    startServer(serverName);
}

int main() {
    char input[100];
    char serverName[50];
    
    printf("Welcome to the Server Administration Program!\n");
    
    while(1) {
        printf("\nEnter command: ");
        fgets(input, sizeof(input), stdin);
        
        // remove newline character from input
        input[strcspn(input, "\n")] = 0;
        
        if(strcmp(input, "quit") == 0) {
            printf("Exiting program...\n");
            break;
        }
        else if(strncmp(input, "start", 5) == 0) {
            sscanf(input, "start %s", serverName);
            startServer(serverName);
        }
        else if(strncmp(input, "stop", 4) == 0) {
            sscanf(input, "stop %s", serverName);
            stopServer(serverName);
        }
        else if(strncmp(input, "restart", 7) == 0) {
            sscanf(input, "restart %s", serverName);
            restartServer(serverName);
        }
        else {
            printf("Invalid command. Please try again.\n");
        }
    }
    
    return 0;
}