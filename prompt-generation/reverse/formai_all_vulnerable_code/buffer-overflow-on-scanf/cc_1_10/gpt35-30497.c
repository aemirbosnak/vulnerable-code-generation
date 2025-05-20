//FormAI DATASET v1.0 Category: System administration ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // Welcome message for the user
    printf("Welcome to the mysterious system administration program!\n");
    printf("Enter your command: ");
    
    char command[1000];
    fgets(command, 1000, stdin);
    
    // Puzzle 1: Checking for sudo access
    if (strstr(command, "sudo") != NULL) {
        printf("You have sudo access... but do you really have it?\n");
        printf("Thinking...\n");
        sleep(2);
        printf("Checking...\n");
        sleep(3);
        printf("Are you sure you want to use sudo? (y/n)\n");
        
        char choice;
        scanf(" %c", &choice);
        
        if (choice == 'y' || choice == 'Y') {
            // Puzzle 2: Fork bomb warning
            printf("Executing command... but before that, watch out for the fork bombs!\n");
            printf("You have 5 seconds to abort the process...\n");
            
            for (int i = 5; i > 0; i--) {
                printf("%d...\n", i);
                sleep(1);
            }
            
            printf("Good luck!\n");
            
            // Execute command with fork
            int pid = fork();
            
            if (pid == 0) {
                // Child process
                system(command);
            } else {
                // Parent process
                wait(NULL);
                printf("Command executed successfully...\n");
            }
        } else {
            printf("Command aborted...\n");
        }
    } else {
        printf("Sorry, but you need to have sudo access to use this program.\n");
    }
    
    return 0;
}