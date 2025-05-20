//FormAI DATASET v1.0 Category: System administration ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Welcome, brave administrator!\n");
    sleep(1);

    while(1) {
        int choice;
        printf("\nWhat do you need to do?\n");
        printf("1. Check disk usage\n");
        printf("2. Check CPU usage\n");
        printf("3. Restart Apache\n");
        printf("4. View log files\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nChecking disk usage...\n");
                system("df -h");
                break;

            case 2:
                printf("\nChecking CPU usage...\n");
                system("top");
                break;

            case 3:
                printf("\nRestarting Apache...\n");
                system("sudo systemctl restart apache2");
                printf("Apache restarted successfully.\n");
                break;

            case 4:
                printf("\nViewing log files...\n");
                printf("Enter the path to the log file: ");
                char file_path[100];
                scanf("%s", file_path);
                char command[150];
                sprintf(command, "less %s", file_path);
                system(command);
                break;

            case 5:
                printf("\nExiting...\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice, please try again.\n");
        }
    }

    return 0;
}