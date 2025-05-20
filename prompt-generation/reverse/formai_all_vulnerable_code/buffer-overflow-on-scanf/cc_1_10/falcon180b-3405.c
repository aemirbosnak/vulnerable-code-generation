//Falcon-180B DATASET v1.0 Category: Password management ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);
    num_passwords++;
}

void remove_password() {
    char username[MAX_PASSWORD_LENGTH];

    printf("Enter username to remove: ");
    scanf("%s", username);

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            memmove(passwords + i, passwords + i + 1, sizeof(Password) * (num_passwords - i - 1));
            num_passwords--;
            break;
        }
    }
}

void display_passwords() {
    printf("Username\t\tPassword\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t\t%s\n", passwords[i].username, passwords[i].password);
    }
}

void save_passwords() {
    FILE *file;
    file = fopen("passwords.txt", "w");

    if (!file) {
        printf("Error: Could not create file.\n");
        return;
    }

    for (int i = 0; i < num_passwords; i++) {
        fprintf(file, "%s\t\t%s\n", passwords[i].username, passwords[i].password);
    }

    fclose(file);
}

void load_passwords() {
    FILE *file;
    char line[MAX_PASSWORD_LENGTH];
    char *token;
    int i = 0;

    file = fopen("passwords.txt", "r");

    if (!file) {
        printf("Error: Could not open file.\n");
        return;
    }

    while (fgets(line, MAX_PASSWORD_LENGTH, file)) {
        token = strtok(line, "\t");
        strcpy(passwords[i].username, token);

        token = strtok(NULL, "\t");
        strcpy(passwords[i].password, token);

        i++;
    }

    fclose(file);
}

int main() {
    int choice;

    do {
        printf("1. Add Password\n");
        printf("2. Remove Password\n");
        printf("3. Display Passwords\n");
        printf("4. Save Passwords\n");
        printf("5. Load Passwords\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                remove_password();
                break;
            case 3:
                display_passwords();
                break;
            case 4:
                save_passwords();
                break;
            case 5:
                load_passwords();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice!= 6);

    return 0;
}