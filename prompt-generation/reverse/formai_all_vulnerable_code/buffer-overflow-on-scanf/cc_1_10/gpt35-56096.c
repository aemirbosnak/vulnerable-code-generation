//FormAI DATASET v1.0 Category: System administration ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char username[1024];
    int choice;

    system("clear");
    printf("Welcome to System Admin\n\n");

    // Get the current user's username
    getlogin_r(username, sizeof(username));

    // Check if the user is root
    if (getuid() == 0) {
        printf("Hello, root %s!\n\n", username);
    } else {
        printf("Hello, %s!\n\n", username);
    }

    printf("What would you like to do?\n");
    printf("1. View system info\n");
    printf("2. Manage users\n");
    printf("3. Manage services\n");
    printf("4. Exit\n");

    // Get user choice
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            system("uname -a");
            break;
        case 2:
            printf("Here are the current user accounts:\n");
            printf("1. root\n");
            printf("2. %s\n", username);
            printf("3. Add new user\n");
            break;
        case 3:
            printf("Here are the current services:\n");
            printf("1. sshd\n");
            printf("2. httpd\n");
            printf("3. mysql\n");
            printf("4. Stop a service\n");
            break;
        case 4:
            printf("Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}