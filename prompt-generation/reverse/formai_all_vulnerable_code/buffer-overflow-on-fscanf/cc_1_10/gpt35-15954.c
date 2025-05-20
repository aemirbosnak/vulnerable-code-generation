//FormAI DATASET v1.0 Category: Password management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a struct to hold password information
struct Password {
    char website[50];
    char username[50];
    char password[50];
};

// Function to encrypt password using a simple mathematical operation
char* encrypt_password(char* password) {
    int i;
    for (i = 0; password[i]; ++i) {
        password[i] = password[i] + 3; // Shift each character by 3 places to the right
    }
    return password;
}

// Function to add a new password to the password file
void add_password() {
    struct Password password;

    printf("Enter website: ");
    scanf("%s", password.website);

    printf("Enter username: ");
    scanf("%s", password.username);

    printf("Enter password: ");
    scanf("%s", password.password);

    // Encrypt password before storing it
    char* encrypted_password = encrypt_password(password.password);
    strncpy(password.password, encrypted_password, sizeof(password.password));

    // Add password to file
    FILE* fp = fopen("passwords.txt", "a");
    fprintf(fp, "%s,%s,%s\n", password.website, password.username, password.password);
    fclose(fp);

    printf("Password added successfully!\n");
}

// Function to display all stored passwords
void display_passwords() {
    FILE* fp = fopen("passwords.txt", "r");

    if(fp == NULL) {
        printf("No passwords have been stored yet.\n");
        return;
    }

    printf("Website\t\tUsername\t\tPassword\n");
    printf("----------------------------------------------\n");

    char website[50], username[50], password[50];
    while(fscanf(fp, "%[^,],%[^,],%[^\n]\n", website, username, password) != EOF) {
        // Decrypt password before displaying it
        char* decrypted_password = encrypt_password(password);
        strncpy(password, decrypted_password, sizeof(password));

        printf("%s\t\t%s\t\t%s\n", website, username, password);
    }

    fclose(fp);
}

// Function to search for a password by website
void search_password() {
    printf("Enter website to search for password: ");
    char website[50];
    scanf("%s", website);

    FILE* fp = fopen("passwords.txt", "r");

    if(fp == NULL) {
        printf("No passwords have been stored yet.\n");
        return;
    }

    char website_check[50], username[50], password[50];
    while(fscanf(fp, "%[^,],%[^,],%[^\n]\n", website_check, username, password) != EOF) {
        if(strcmp(website_check, website) == 0) {
            // Decrypt password before displaying it
            char* decrypted_password = encrypt_password(password);
            strncpy(password, decrypted_password, sizeof(password));

            printf("Website\t\tUsername\t\tPassword\n");
            printf("----------------------------------------------\n");
            printf("%s\t\t%s\t\t%s\n", website, username, password);
            fclose(fp);
            return;
        }
    }

    fclose(fp);

    printf("No password found for website %s\n", website);
}

int main() {
    int choice;

    while (1) {
        printf("Password Management Program\n");
        printf("----------------------------\n");
        printf("1. Add a new password\n");
        printf("2. Display all passwords\n");
        printf("3. Search for a password\n");
        printf("4. Exit\n");
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
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}