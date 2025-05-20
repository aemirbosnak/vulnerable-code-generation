//FormAI DATASET v1.0 Category: System administration ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("\n\n\tWelcome to our System Administration Application!\n\n");

    char option;
    do {
        printf("\nPlease choose an option:\n");
        printf("\t1. View system status\n");
        printf("\t2. Start system backup\n");
        printf("\t3. Stop system backup\n");
        printf("\t4. Restart system\n");
        printf("\t5. Check system logs\n");
        printf("\t6. Exit\n\n");

        printf("Your choice: ");
        scanf(" %c", &option);

        switch(option) {
            case '1':
                printf("\n*************************************************\n");
                printf("\tSystem Status Report:\n");
                printf("*************************************************\n");
                printf("\nCurrent disk usage: 75%%\n");
                printf("Memory usage: 42%%\n");
                printf("CPU usage: 18%%\n\n");
                break;

            case '2':
                printf("\n*************************************************\n");
                printf("\tSystem Backup:\n");
                printf("*************************************************\n");
                printf("\nStarting system backup...\n");
                // call backup script here 
                break;

            case '3':
                printf("\n*************************************************\n");
                printf("\tSystem Backup:\n");
                printf("*************************************************\n");
                printf("\nStopping system backup...\n");
                // call stop backup script here 
                break;

            case '4':
                printf("\n*************************************************\n");
                printf("\tSystem Restart:\n");
                printf("*************************************************\n");
                printf("\nRestarting system...\n");
                // call reboot script here
                break;

            case '5':
                printf("\n*************************************************\n");
                printf("\tSystem Logs:\n");
                printf("*************************************************\n");
                printf("\nChecking system logs...\n");
                // call system logs script here
                break;

            case '6':
                printf("\nExiting System Administration Application...\n\n");
                break;

            default:
                printf("\nInvalid option, please try again...\n");
        }

    } while(option != '6');

    return 0;
}