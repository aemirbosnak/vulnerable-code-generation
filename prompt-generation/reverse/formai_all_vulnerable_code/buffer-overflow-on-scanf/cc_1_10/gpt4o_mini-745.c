//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void add_user(const char *username) {
    if (fork() == 0) {
        char *args[] = {"/usr/sbin/useradd", (char *)username, NULL};
        execvp(args[0], args);
        perror("Add User Error");
        exit(EXIT_FAILURE);
    } else {
        wait(NULL);
        printf("User '%s' added successfully.\n", username);
    }
}

void delete_user(const char *username) {
    if (fork() == 0) {
        char *args[] = {"/usr/sbin/userdel", (char *)username, NULL};
        execvp(args[0], args);
        perror("Delete User Error");
        exit(EXIT_FAILURE);
    } else {
        wait(NULL);
        printf("User '%s' deleted successfully.\n", username);
    }
}

void list_users() {
    if (fork() == 0) {
        char *args[] = {"cat", "/etc/passwd", NULL};
        execvp(args[0], args);
        perror("List Users Error");
        exit(EXIT_FAILURE);
    } else {
        wait(NULL);
    }
}

void display_menu() {
    printf("\n--- User Management System ---\n");
    printf("1. Add User\n");
    printf("2. Delete User\n");
    printf("3. List Users\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    char username[256];

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username to add: ");
                scanf("%s", username);
                add_user(username);
                break;
            case 2:
                printf("Enter username to delete: ");
                scanf("%s", username);
                delete_user(username);
                break;
            case 3:
                printf("Listing all users:\n");
                list_users();
                break;
            case 4:
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}