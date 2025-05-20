//FormAI DATASET v1.0 Category: Password management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

typedef struct Password {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Password;

/**
 * Generates a random password of length `len`
 */
char *generate_password(int len) {
    char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}\\|;:'\",.<>/?";
    int chars_len = strlen(chars);
    char *password = malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        password[i] = chars[rand() % chars_len];
    }
    password[len] = '\0';
    return password;
}

/**
 * Checks if the username and password match the stored password.
 * Returns 1 if match, otherwise 0.
 */
int validate_password(char *username, char *password) {
    FILE *f = fopen("passwords.txt", "r");
    if (f == NULL) {
        printf("Error opening passwords file.\n");
        return 0;
    }
    Password p;
    while (fscanf(f, "%s %s %s", p.website, p.username, p.password) != EOF) {
        if (strcmp(p.username, username) == 0 && strcmp(p.password, password) == 0) {
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}

/**
 * Adds a new password for a website and associated username.
 */
void add_password() {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char *password;

    printf("Enter website: ");
    scanf("%s", website);
    printf("Enter username: ");
    scanf("%s", username);
    password = generate_password(12);

    FILE *f = fopen("passwords.txt", "a");
    if (f == NULL) {
        printf("Error opening passwords file.\n");
        return;
    }
    fprintf(f, "%s %s %s\n", website, username, password);
    fclose(f);

    printf("Password added successfully.\n");
}

/**
 * Deletes a password for a given website and username.
 */
void delete_password() {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    printf("Enter website: ");
    scanf("%s", website);
    printf("Enter username: ");
    scanf("%s", username);

    FILE *f1 = fopen("passwords.txt", "r");
    if (f1 == NULL) {
        printf("Error opening passwords file.\n");
        return;
    }
    FILE *f2 = fopen("temp.txt", "w");
    if (f2 == NULL) {
        printf("Error creating temporary file.\n");
        fclose(f1);
        return;
    }

    Password p;
    int deleted = 0;
    while (fscanf(f1, "%s %s %s", p.website, p.username, p.password) != EOF) {
        if (strcmp(p.website, website) == 0 && strcmp(p.username, username) == 0) {
            printf("Password deleted successfully.\n");
            deleted = 1;
        } else {
            fprintf(f2, "%s %s %s\n", p.website, p.username, p.password);
        }
    }

    fclose(f1);
    fclose(f2);

    if (!deleted) {
        printf("No password found for website %s and username %s.\n", website, username);
        remove("temp.txt");
        return;
    }

    remove("passwords.txt");
    rename("temp.txt", "passwords.txt");
}

int main() {
    printf("Password Management System\n");

    while (1) {
        printf("\nMenu:\n  1. Add password\n  2. Delete password\n  3. Validate password\n  4. Exit\n");
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
            case 3: {
                char username[MAX_LENGTH];
                char password[MAX_LENGTH];
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                if (validate_password(username, password)) {
                    printf("Password is valid.\n");
                } else {
                    printf("Invalid username or password.\n");
                }
                break;
            }
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}