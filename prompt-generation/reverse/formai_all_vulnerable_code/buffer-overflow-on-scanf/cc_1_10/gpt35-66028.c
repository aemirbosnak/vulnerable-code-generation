//FormAI DATASET v1.0 Category: Password management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_FILE "passwords.txt"
#define MAX_PASSWORD_LENGTH 50
#define MAX_WEBSITE_LENGTH 50
#define MAX_USERNAME_LENGTH 50

typedef struct {
    char website[MAX_WEBSITE_LENGTH];
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_entry;

/* function declarations */
void add_password();
void display_passwords();
void search_password();
void update_password();

int main() {
    int choice;

    while (1) {
        printf("1. Add a password\n");
        printf("2. Display all passwords\n");
        printf("3. Search for a password\n");
        printf("4. Update a password\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                display_passwords();
                break;
            case 3:
                search_password();
                break;
            case 4:
                update_password();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void add_password() {
    password_entry password;

    printf("Enter the website name: ");
    scanf("%s", password.website);

    printf("Enter the username: ");
    scanf("%s", password.username);

    printf("Enter the password: ");
    scanf("%s", password.password);

    FILE *file = fopen(PASSWORD_FILE, "a");

    if (file) {
        fprintf(file, "%s,%s,%s\n", password.website, password.username, password.password);
        fclose(file);
        printf("Password added successfully.\n");
    } else {
        printf("Error opening file.\n");
    }
}

void display_passwords() {
    FILE *file = fopen(PASSWORD_FILE, "r");

    if (file) {
        printf("Website\t\tUsername\tPassword\n");
        printf("---------------------------------------------------------\n");

        char line[150];

        while (fgets(line, 150, file)) {
            char *website = strtok(line, ",");
            char *username = strtok(NULL, ",");
            char *password = strtok(NULL, ",");

            printf("%s\t\t%s\t%s\n", website, username, password);
        }

        fclose(file);
    } else {
        printf("Error opening file.\n");
    }
}

void search_password() {
    char website[MAX_WEBSITE_LENGTH];

    printf("Enter the website name: ");
    scanf("%s", website);

    FILE *file = fopen(PASSWORD_FILE, "r");

    if (file) {
        char line[150];
        int found = 0;

        while (fgets(line, 150, file)) {
            char *website_in_file = strtok(line, ",");
            char *username = strtok(NULL, ",");
            char *password = strtok(NULL, ",");

            if (strcmp(website_in_file, website) == 0) {
                printf("Website\t\tUsername\tPassword\n");
                printf("---------------------------------------------------------\n");
                printf("%s\t\t%s\t%s\n", website_in_file, username, password);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("No password found for website: %s\n", website);
        }

        fclose(file);
    } else {
        printf("Error opening file.\n");
    }
}

void update_password() {
    char website[MAX_WEBSITE_LENGTH];

    printf("Enter the website name: ");
    scanf("%s", website);

    FILE *file = fopen(PASSWORD_FILE, "r");

    if (file) {
        char line[150];
        int found = 0;
        long int current_position = ftell(file);
        FILE *temp_file = fopen("temp.txt", "w");

        while (fgets(line, 150, file)) {
            char *website_in_file = strtok(line, ",");
            char *username = strtok(NULL, ",");
            char *password = strtok(NULL, ",");

            if (strcmp(website_in_file, website) == 0) {
                char new_password[MAX_PASSWORD_LENGTH];
                printf("Enter the new password: ");
                scanf("%s", new_password);

                fprintf(temp_file, "%s,%s,%s\n", website_in_file, username, new_password);
                found = 1;
            } else {
                fprintf(temp_file, "%s,%s,%s", website_in_file, username, password);
            }
        }

        if (!found) {
            printf("No password found for website: %s\n", website);
        } else {
            fclose(file);
            fclose(temp_file);
            remove(PASSWORD_FILE);
            rename("temp.txt", PASSWORD_FILE);
            printf("Password updated successfully.\n");
        }
    } else {
        printf("Error opening file.\n");
    }
}