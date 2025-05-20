//Gemma-7B DATASET v1.0 Category: System administration ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_CMD_LEN 255

int main() {
    char cmd[MAX_CMD_LEN];

    printf("Welcome to the C System Administration Interface!\n");
    printf("Please enter your command: ");

    fgets(cmd, MAX_CMD_LEN, stdin);

    if (strcmp(cmd, "help") == 0) {
        printf("Available commands:\n");
        printf("help - displays this help message\n");
        printf("shutdown - shuts down the system\n");
        printf("reboot - reboots the system\n");
        printf("useradd - adds a new user\n");
        printf("userdel - deletes a user\n");
        printf("passwd - changes a user's password\n");
    } else if (strcmp(cmd, "shutdown") == 0) {
        printf("Are you sure you want to shut down the system? (y/n) ");
        char answer;
        scanf("%c", &answer);

        if (answer == 'y') {
            system("shutdown -h now");
        }
    } else if (strcmp(cmd, "reboot") == 0) {
        printf("Are you sure you want to reboot the system? (y/n) ");
        char answer;
        scanf("%c", &answer);

        if (answer == 'y') {
            system("reboot");
        }
    } else if (strcmp(cmd, "useradd") == 0) {
        printf("Enter the new user's name: ");
        char username[MAX_CMD_LEN];
        scanf("%s", username);

        printf("Enter the new user's password: ");
        char password[MAX_CMD_LEN];
        scanf("%s", password);

        system("useradd -c \" $username $password\"");
    } else if (strcmp(cmd, "userdel") == 0) {
        printf("Enter the user's name: ");
        char username[MAX_CMD_LEN];
        scanf("%s", username);

        system("userdel -r $username");
    } else if (strcmp(cmd, "passwd") == 0) {
        printf("Enter the user's name: ");
        char username[MAX_CMD_LEN];
        scanf("%s", username);

        printf("Enter the new password: ");
        char new_password[MAX_CMD_LEN];
        scanf("%s", new_password);

        system("passwd $username $new_password");
    } else {
        printf("Invalid command. Please try again.\n");
    }

    return 0;
}