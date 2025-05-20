//FormAI DATASET v1.0 Category: System administration ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main() {
    char choice;

    do {
        printf("\n------[ SYSTEM ADMINISTRATION MENU ]------\n");
        printf("1. Check system status\n");
        printf("2. Clean up disk space\n");
        printf("3. Create new user\n");
        printf("4. Delete user\n");
        printf("5. Exit\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("\nSYSTEM STATUS:\n");
                system("top");
                break;
            case '2':
                printf("\nCLEANING UP DISK SPACE:\n");
                system("sudo apt-get clean && sudo apt-get autoremove");
                break;
            case '3':
                printf("\nCREATE NEW USER:\n");
                char username[25];
                printf("Enter the username: ");
                scanf("%s", username);
                char command[50];
                sprintf(command, "sudo useradd -m %s", username);
                system(command);
                break;
            case '4':
                printf("\nDELETE USER:\n");
                char u[25];
                printf("Enter the username: ");
                scanf("%s", u);
                char c[50];
                sprintf(c, "sudo userdel -r %s", u);
                system(c);
                break;
            case '5':
                printf("\nGOODBYE!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    } while (choice != '5');

    return 0;
}