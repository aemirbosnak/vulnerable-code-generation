//FormAI DATASET v1.0 Category: Password management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10

struct password_entry {
    char *username;
    char *password;
};

void print_menu() {
    printf("Welcome to Password Manager\n");
    printf("1. Add password\n");
    printf("2. Remove password\n");
    printf("3. List passwords\n");
    printf("4. Exit\n");
}

void add_password(struct password_entry *passwords, int *count) {
    if (*count >= MAX_PASSWORDS) {
        printf("Maximum number of passwords reached\n");
        return;
    }

    char username[20];
    char password[20];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    passwords[*count].username = strdup(username);
    passwords[*count].password = strdup(password);
    (*count)++;
}

void remove_password(struct password_entry *passwords, int *count) {
    char username[20];
    printf("Enter username: ");
    scanf("%s", username);

    for (int i = 0; i < *count; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            free(passwords[i].username);
            free(passwords[i].password);
            for (int j = i+1; j < *count; j++) {
                passwords[j-1].username = passwords[j].username;
                passwords[j-1].password = passwords[j].password;
            }
            (*count)--;
            return;
        }
    }

    printf("Password not found\n");
}

void list_passwords(struct password_entry *passwords, int count) {
    if (count == 0) {
        printf("No passwords stored\n");
        return;
    }

    printf("Username\tPassword\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    struct password_entry passwords[MAX_PASSWORDS];
    int count = 0;
    int choice;

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password(passwords, &count);
                break;
            case 2:
                remove_password(passwords, &count);
                break;
            case 3:
                list_passwords(passwords, count);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}