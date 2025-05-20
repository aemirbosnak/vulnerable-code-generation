//FormAI DATASET v1.0 Category: Password management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

int num_passwords = 0;

struct Password {
    char service[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct Password passwords[MAX_PASSWORDS];

void add_password() {
    printf("\nEnter details of the password:\n");
    printf("Service: ");
    scanf("%s", passwords[num_passwords].service);
    printf("Username: ");
    scanf("%s", passwords[num_passwords].username);
    printf("Password: ");
    scanf("%s", passwords[num_passwords].password);
    num_passwords++;
    printf("\nPassword successfully added!");
}

void view_passwords() {
    if (num_passwords == 0) {
        printf("\nYou have not added any passwords yet!");
    } else {
        printf("\nYour saved passwords:\n");
        printf("-------------------------\n");
        for (int i = 0; i < num_passwords; i++) {
            printf("Service: %s\n", passwords[i].service);
            printf("Username: %s\n", passwords[i].username);
            printf("Password: %s\n", passwords[i].password);
            printf("-------------------------\n");
        }
    }
}

void search_password() {
    char service[MAX_PASSWORD_LENGTH];
    printf("\nEnter the service name: ");
    scanf("%s", service);
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(service, passwords[i].service) == 0) {
            printf("\nService: %s\n", passwords[i].service);
            printf("Username: %s\n", passwords[i].username);
            printf("Password: %s\n", passwords[i].password);
            return;
        }
    }
    printf("\nPassword not found!");
}

void generate_password(char password[], int length) {
    srand(time(NULL));
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=";
    int charset_length = strlen(charset);
    for (int i = 0; i < length; i++) {
        int index = rand() % charset_length;
        password[i] = charset[index];
    }
    password[length] = '\0';
}

void change_password() {
    char service[MAX_PASSWORD_LENGTH];
    printf("\nEnter the service name: ");
    scanf("%s", service);
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(service, passwords[i].service) == 0) {
            char new_password[MAX_PASSWORD_LENGTH];
            int length;
            printf("\nEnter the length of new password (maximum length is %d): ", MAX_PASSWORD_LENGTH);
            scanf("%d", &length);
            generate_password(new_password, length);
            strcpy(passwords[i].password, new_password);
            printf("\nNew password for %s has been set to: %s", service, new_password);
            return;
        }
    }
    printf("\nPassword not found!");
}

int main() {
    printf("Welcome to the Password Manager!\n");
    printf("---------------------------------\n");

    int choice;
    do {
        printf("\nChoose an option:\n");
        printf("1. Add a password\n");
        printf("2. View saved passwords\n");
        printf("3. Search for a password\n");
        printf("4. Change a password\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                view_passwords();
                break;
            case 3:
                search_password();
                break;
            case 4:
                change_password();
                break;
            case 5:
                printf("\nThank you for using the Password Manager!\n");
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}