//FormAI DATASET v1.0 Category: Password management ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20
#define FILE_NAME "passwords.dat"

struct password {
    char service[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    if (num_passwords == MAX_PASSWORDS) {
        printf("Sorry, you have reached the maximum number of passwords.\n");
        return;
    }

    struct password new_password;

    printf("Service: ");
    fgets(new_password.service, MAX_PASSWORD_LENGTH, stdin);

    printf("Username: ");
    fgets(new_password.username, MAX_PASSWORD_LENGTH, stdin);

    printf("Password: ");
    fgets(new_password.password, MAX_PASSWORD_LENGTH, stdin);

    passwords[num_passwords++] = new_password;

    printf("Password added successfully.\n");
}

void list_passwords() {
    if (num_passwords == 0) {
        printf("No passwords found.\n");
        return;
    }

    printf("Service\t\tUsername\tPassword\n");

    for (int i = 0; i < num_passwords; i++) {
        struct password p = passwords[i];
        printf("%s\t%s\t%s\n", p.service, p.username, p.password);
    }
}

void save_passwords() {
    FILE *fp = fopen(FILE_NAME, "w");

    if (!fp) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    fprintf(fp, "%d\n", num_passwords);

    for (int i = 0; i < num_passwords; i++) {
        struct password p = passwords[i];
        fprintf(fp, "%s,%s,%s\n", p.service, p.username, p.password);
    }

    fclose(fp);

    printf("Passwords saved successfully.\n");
}

void load_passwords() {
    FILE *fp = fopen(FILE_NAME, "r");

    if (!fp) {
        printf("No file found.\n");
        return;
    }

    fscanf(fp, "%d\n", &num_passwords);

    for (int i = 0; i < num_passwords; i++) {
        struct password p;

        fscanf(fp, "%[^,],%[^,],%[^\n]\n", p.service, p.username, p.password);

        passwords[i] = p;
    }

    fclose(fp);

    printf("Passwords loaded successfully.\n");
}

int main() {
    int choice = -1;

    do {
        printf("Welcome to Retro Password Manager\n");
        printf("1. Add password\n");
        printf("2. List passwords\n");
        printf("3. Save passwords to file\n");
        printf("4. Load passwords from file\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                list_passwords();
                break;
            case 3:
                save_passwords();
                break;
            case 4:
                load_passwords();
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}