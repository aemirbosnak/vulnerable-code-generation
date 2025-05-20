//FormAI DATASET v1.0 Category: Password management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold password data
typedef struct password {
    char website[50];
    char username[50];
    char password[50];
} password_t;

// Function to add a new password to file
void addPassword() {
    password_t pass;
    printf("Enter website name: ");
    scanf("%s", pass.website);
    printf("Enter username: ");
    scanf("%s", pass.username);
    printf("Enter password: ");
    scanf("%s", pass.password);
    FILE *file = fopen("passwords.dat", "ab");
    fwrite(&pass, sizeof(password_t), 1, file);
    fclose(file);
    printf("\nPassword added successfully!\n\n");
}

// Function to display all passwords
void listPasswords() {
    password_t pass;
    FILE *file = fopen("passwords.dat", "rb");
    if (file == NULL) {
        printf("\nNo passwords stored!\n\n");
        return;
    }
    printf("\nList of stored passwords:\n\n");
    while(fread(&pass, sizeof(password_t), 1, file))
        printf("Website: %s\nUsername: %s\nPassword: %s\n\n", pass.website, pass.username, pass.password);
    fclose(file);
}

// Function to search for a specific website's password
void searchPassword() {
    password_t pass;
    char website[50];
    printf("Enter website name: ");
    scanf("%s", website);
    FILE *file = fopen("passwords.dat", "rb");
    int found = 0;
    while (fread(&pass, sizeof(password_t), 1, file)) {
        if (strcmp(pass.website, website) == 0) {
            printf("\nWebsite: %s\nUsername: %s\nPassword: %s\n\n", pass.website, pass.username, pass.password);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("\nNo password for that website found!\n\n");
    fclose(file);
}

// Function to delete a website's password
void deletePassword() {
    password_t pass;
    char website[50];
    printf("Enter website name: ");
    scanf("%s", website);
    FILE *file = fopen("passwords.dat", "rb");
    if (file == NULL) {
        printf("\nNo passwords stored!\n\n");
        return;
    }
    FILE *tmp = fopen("temp.dat", "wb");
    while (fread(&pass, sizeof(password_t), 1, file))
        if (strcmp(pass.website, website) != 0)
            fwrite(&pass, sizeof(password_t), 1, tmp);
    fclose(file);
    fclose(tmp);
    remove("passwords.dat");
    rename("temp.dat", "passwords.dat");
    printf("\nPassword deleted successfully!\n\n");
}

// Main function
int main() {
    char choice;
    while (1) {
        printf("Welcome to Password Manager!\n\n");
        printf("Please choose an option:\n");
        printf("1. Add Password\n");
        printf("2. List Passwords\n");
        printf("3. Search Password\n");
        printf("4. Delete Password\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                addPassword();
                break;
            case '2':
                listPasswords();
                break;
            case '3':
                searchPassword();
                break;
            case '4':
                deletePassword();
                break;
            case '5':
                printf("\nThank you for using Password Manager!\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n\n");
        }
    }
    return 0;
}