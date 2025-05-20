//FormAI DATASET v1.0 Category: Password management ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 128

typedef struct password {
    char domain[MAX_LEN];
    char username[MAX_LEN];
    char password[MAX_LEN];
} Password;

Password *passwords;
int num_passwords = 0;

void add_password() {
    printf("Enter domain name: ");
    char domain[MAX_LEN];
    scanf("%s", domain);

    printf("Enter username: ");
    char username[MAX_LEN];
    scanf("%s", username);

    printf("Enter password: ");
    char password[MAX_LEN];
    scanf("%s", password);

    Password *temp = realloc(passwords, (num_passwords + 1) * sizeof(Password));
    if (temp == NULL) {
        printf("Error: could not add password.\n");
        return;
    }

    passwords = temp;

    strcpy(passwords[num_passwords].domain, domain);
    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;

    printf("Password added successfully.\n");
}

void delete_password() {
    printf("Enter domain name: ");
    char domain[MAX_LEN];
    scanf("%s", domain);

    int i, found = 0;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].domain, domain) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Error: password not found.\n");
        return;
    }

    Password *temp = malloc((num_passwords - 1) * sizeof(Password));
    if (temp == NULL) {
        printf("Error: could not delete password.\n");
        return;
    }

    int j = 0;
    for (i = 0; i < num_passwords; i++) {
        if (i != j) {
            temp[j] = passwords[i];
            j++;
        }
    }

    free(passwords);
    passwords = temp;

    num_passwords--;

    printf("Password deleted successfully.\n");
}

void list_passwords() {
    if (num_passwords == 0) {
        printf("No passwords stored.\n");
        return;
    }

    printf("%-25s %-15s %s\n", "Domain", "Username", "Password");

    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("%-25s %-15s %s\n", passwords[i].domain, passwords[i].username, passwords[i].password);
    }
}

int main() {
    printf("Welcome to the futuristic password management system!\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add password\n");
        printf("2. Delete password\n");
        printf("3. List passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;

            case 2:
                delete_password();
                break;

            case 3:
                list_passwords();
                break;

            case 4:
                printf("\nThank you for using the futuristic password management system!\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}