//FormAI DATASET v1.0 Category: System administration ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "users.txt"

struct user {
    char username[20];
    char password[20];
};

void add_user() {
    FILE *file_ptr;
    file_ptr = fopen(FILENAME, "a");

    if (file_ptr == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    struct user new_user;

    printf("Enter username: ");
    scanf("%s", new_user.username);

    printf("Enter password: ");
    scanf("%s", new_user.password);

    fprintf(file_ptr, "%s:%s\n", new_user.username, new_user.password);

    fclose(file_ptr);
    printf("User added successfully.\n");
}

void list_users() {
    FILE *file_ptr;
    file_ptr = fopen(FILENAME, "r");

    if (file_ptr == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char line[50];

    printf("List of Users:\n");

    while(fgets(line, 50, file_ptr) != NULL) {
        char *token = strtok(line, ":");
        printf("%s\n", token);
    }

    fclose(file_ptr);
}

int main() {
    int choice;

    while(1) {
        printf("Menu\n");
        printf("1. Add User\n");
        printf("2. List Users\n");
        printf("3. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_user();
                break;
            case 2:
                list_users();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}