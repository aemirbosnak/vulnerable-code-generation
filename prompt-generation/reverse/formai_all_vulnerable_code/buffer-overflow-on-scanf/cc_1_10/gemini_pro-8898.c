//GEMINI-pro DATASET v1.0 Category: Password management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    char website[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    if (num_passwords == MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    Password new_password;

    printf("Enter the website: ");
    scanf("%s", new_password.website);

    printf("Enter the username: ");
    scanf("%s", new_password.username);

    printf("Enter the password: ");
    scanf("%s", new_password.password);

    passwords[num_passwords] = new_password;
    num_passwords++;
}

void list_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        printf("%d. %s\t%s\t%s\n", i + 1, passwords[i].website, passwords[i].username, passwords[i].password);
    }
}

void search_password() {
    char website[MAX_PASSWORD_LENGTH];

    printf("Enter the website: ");
    scanf("%s", website);

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            printf("Website: %s\n", passwords[i].website);
            printf("Username: %s\n", passwords[i].username);
            printf("Password: %s\n", passwords[i].password);
            return;
        }
    }

    printf("Error: Website not found.\n");
}

void delete_password() {
    char website[MAX_PASSWORD_LENGTH];

    printf("Enter the website: ");
    scanf("%s", website);

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            for (int j = i; j < num_passwords - 1; j++) {
                passwords[j] = passwords[j + 1];
            }
            num_passwords--;
            return;
        }
    }

    printf("Error: Website not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("1. Add password\n");
        printf("2. List passwords\n");
        printf("3. Search password\n");
        printf("4. Delete password\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                list_passwords();
                break;
            case 3:
                search_password();
                break;
            case 4:
                delete_password();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}