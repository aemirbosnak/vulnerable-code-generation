//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <shadow.h>
#include <grp.h>

#define MAX_USERNAME_LEN 100
#define MAX_PASSWORD_LEN 100

void addUser(const char *username, const char *password) {
    if (system("id -u") != 0) {
        printf("Error: You need superuser privileges to add a user.\n");
        return;
    }

    char command[256];
    snprintf(command, sizeof(command), "sudo useradd -m %s", username);
    if (system(command) == 0) {
        snprintf(command, sizeof(command), "echo '%s:%s' | sudo chpasswd", username, password);
        if (system(command) == 0) {
            printf("User %s added successfully!\n", username);
        } else {
            printf("Error: Unable to set password for user %s.\n", username);
        }
    } else {
        printf("Error: Unable to add user %s.\n", username);
    }
}

void deleteUser(const char *username) {
    if (system("id -u") != 0) {
        printf("Error: You need superuser privileges to delete a user.\n");
        return;
    }

    char command[256];
    snprintf(command, sizeof(command), "sudo userdel -r %s", username);
    if (system(command) == 0) {
        printf("User %s deleted successfully!\n", username);
    } else {
        printf("Error: Unable to delete user %s.\n", username);
    }
}

void displayUserInfo(const char *username) {
    struct passwd *pw = getpwnam(username);
    struct spwd *sp = getspnam(username);

    if (pw == NULL) {
        printf("User %s does not exist.\n", username);
        return;
    }

    printf("User Info for %s:\n", username);
    printf("  User ID (UID): %d\n", pw->pw_uid);
    printf("  Group ID (GID): %d\n", pw->pw_gid);
    printf("  Home Directory: %s\n", pw->pw_dir);
    printf("  Shell: %s\n", pw->pw_shell);
    if (sp != NULL) {
        printf("  Last Password Change: %ld\n", (long) sp->sp_lstchg);
    }
}

int main() {
    int choice;
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];

    while (1) {
        printf("\n=== User Management System ===\n");
        printf("1. Add User\n");
        printf("2. Delete User\n");
        printf("3. Display User Info\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username to add: ");
                scanf("%s", username);
                printf("Enter password for %s: ", username);
                scanf("%s", password);
                addUser(username, password);
                break;

            case 2:
                printf("Enter username to delete: ");
                scanf("%s", username);
                deleteUser(username);
                break;

            case 3:
                printf("Enter username to display info: ");
                scanf("%s", username);
                displayUserInfo(username);
                break;

            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}