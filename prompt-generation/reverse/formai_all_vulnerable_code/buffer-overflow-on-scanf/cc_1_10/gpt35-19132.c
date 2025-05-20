//FormAI DATASET v1.0 Category: System administration ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (geteuid() != 0) {
        printf("ERROR: This program must be run as root!\n");
        exit(1);
    }

    printf("Welcome to the System Administration Example Program!\n");
    printf("What would you like to do?\n\n");

    while (1) {
        printf("1. View system information\n");
        printf("2. Edit user permissions\n");
        printf("3. Shut down the system\n");
        printf("4. Exit program\n\n");

        int choice = 0;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("uname -a");
                system("ps aux");
                break;
            case 2:
                printf("Enter the username you wish to edit permissions for: ");
                char user[50];
                scanf("%s", user);

                printf("Enter the permission level you wish to set for this user: ");
                int permission_level = 0;
                scanf("%d", &permission_level);

                char command[100];
                sprintf(command, "usermod -a -G %d %s", permission_level, user);
                system(command);
                break;
            case 3:
                printf("Are you sure you want to shut down the system? (y/n) ");
                char answer;
                scanf(" %c", &answer);

                if (answer == 'y' || answer == 'Y') {
                    system("shutdown -h now");
                }
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }

        printf("\n");
    }

    return 0;
}