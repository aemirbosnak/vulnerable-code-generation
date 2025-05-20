//FormAI DATASET v1.0 Category: System administration ; Style: relaxed
// This program demonstrates an example of system administration in C language.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char command[100];
    int option;

    printf("******** Welcome to System Administration ********\n");

    do {
        printf("\nPlease choose an option:\n");
        printf("1. View system information\n");
        printf("2. Check disk usage\n");
        printf("3. Restart the system\n");
        printf("4. Check running processes\n");
        printf("5. Exit\n");

        printf("\nEnter option number: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                strcpy(command, "uname -a");
                system(command);
                break;
            case 2:
                strcpy(command, "df -h");
                system(command);
                break;
            case 3:
                printf("Are you sure you want to restart the system? (y/n): ");
                char answer[2];
                scanf("%s", answer);
                if(strcmp(answer, "y") == 0) {
                    strcpy(command, "sudo reboot");
                    system(command);
                }
                break;
            case 4:
                strcpy(command, "ps -aux");
                system(command);
                break;
            case 5:
                printf("\nThank you for using System Administration. Goodbye.\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }

    } while(option != 5);

    return 0;
}