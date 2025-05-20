//GEMINI-pro DATASET v1.0 Category: Password management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LEN 20

typedef struct password_entry {
    char *username;
    char *password;
} password_entry;

password_entry *passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        fprintf(stderr, "Error: Too many passwords.\n");
        return;
    }

    passwords[num_passwords] = (password_entry *)malloc(sizeof(password_entry));
    passwords[num_passwords]->username = strdup(username);
    passwords[num_passwords]->password = strdup(password);
    num_passwords++;
}

void delete_password(int index) {
    if (index < 0 || index >= num_passwords) {
        fprintf(stderr, "Error: Invalid index.\n");
        return;
    }

    free(passwords[index]->username);
    free(passwords[index]->password);
    free(passwords[index]);

    for (int i = index + 1; i < num_passwords; i++) {
        passwords[i - 1] = passwords[i];
    }

    num_passwords--;
}

void print_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        printf("%d. %s: %s\n", i + 1, passwords[i]->username, passwords[i]->password);
    }
}

int main() {
    int choice;
    char username[MAX_PASSWORD_LEN];
    char password[MAX_PASSWORD_LEN];
    int index;

    while (1) {
        printf("1. Add password\n");
        printf("2. Delete password\n");
        printf("3. Print passwords\n");
        printf("4. Quit\n");
        printf("> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                add_password(username, password);
                break;
            case 2:
                printf("Enter index of password to delete: ");
                scanf("%d", &index);
                delete_password(index - 1);
                break;
            case 3:
                print_passwords();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}