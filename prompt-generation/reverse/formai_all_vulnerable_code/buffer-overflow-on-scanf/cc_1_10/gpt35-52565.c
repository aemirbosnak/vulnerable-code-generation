//FormAI DATASET v1.0 Category: System administration ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char command[100];
    printf("Welcome to My System Administration Program!\n");
    while(1) {
        printf("> ");
        scanf("%s", command);

        if(strcmp(command, "info") == 0) {
            printf("System Information:\n");
            system("uname -a");
            system("uptime");
            system("df -h");
        }
        else if(strcmp(command, "apps") == 0) {
            printf("Installed Applications:\n");
            system("ls /Applications");
        }
        else if(strcmp(command, "users") == 0) {
            printf("System Users:\n");
            system("dscacheutil -q user");
        }
        else if(strcmp(command, "processes") == 0) {
            printf("Running Processes:\n");
            system("ps -aux");
        }
        else if(strcmp(command, "shutdown") == 0) {
            printf("Shutting down the system...\n");
            system("sudo shutdown now");
        }
        else if(strcmp(command, "help") == 0) {
            printf("Available Commands:\n");
            printf("- info: Display system information.\n");
            printf("- apps: List installed applications.\n");
            printf("- users: List system users.\n");
            printf("- processes: List running processes.\n");
            printf("- shutdown: Shut down the system.\n");
            printf("- exit: Exit the program.\n");
        }
        else if(strcmp(command, "exit") == 0) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Command not recognized. Type 'help' for available commands.\n");
        }
    }
    return 0;
}