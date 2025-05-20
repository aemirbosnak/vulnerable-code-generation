//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <sys/wait.h>

// Function to add a user
int add_user(const char* username) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return -1;
    } else if (pid == 0) {
        char *args[] = {"sudo", "useradd", username, NULL};
        execvp(args[0], args);
        perror("exec failed");
        exit(EXIT_FAILURE);
    } else {
        int status;
        waitpid(pid, &status, 0);
        return WEXITSTATUS(status);
    }
}

// Function to delete a user
int delete_user(const char* username) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return -1;
    } else if (pid == 0) {
        char *args[] = {"sudo", "userdel", username, NULL};
        execvp(args[0], args);
        perror("exec failed");
        exit(EXIT_FAILURE);
    } else {
        int status;
        waitpid(pid, &status, 0);
        return WEXITSTATUS(status);
    }
}

// Function to list system users
void list_users() {
    FILE *fp = fopen("/etc/passwd", "r");
    if (fp == NULL) {
        perror("Failed to open /etc/passwd");
        return;
    }
    
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        char *username = strtok(line, ":");
        if (username != NULL) {
            printf("User: %s\n", username);
        }
    }
    
    fclose(fp);
}

int main() {
    int choice;
    char username[100];

    while (1) {
        printf("\nSystem User Management\n");
        printf("1. Add User\n");
        printf("2. Delete User\n");
        printf("3. List Users\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // clear buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter username to add: ");
                scanf("%s", username);
                if (add_user(username) == 0) {
                    printf("User '%s' added successfully.\n", username);
                } else {
                    printf("Failed to add user '%s'.\n", username);
                }
                break;

            case 2:
                printf("Enter username to delete: ");
                scanf("%s", username);
                if (delete_user(username) == 0) {
                    printf("User '%s' deleted successfully.\n", username);
                } else {
                    printf("Failed to delete user '%s'.\n", username);
                }
                break;

            case 3:
                printf("Listing users:\n");
                list_users();
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    }

    return 0;
}