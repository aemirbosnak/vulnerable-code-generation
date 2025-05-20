//FormAI DATASET v1.0 Category: Password management ; Style: Ada Lovelace
/*
 * Password Manager in Ada Lovelace Style!
 * This program helps you store and manage your passwords
 * in an encrypted file.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of password
#define MAX_PASSWORD_LENGTH 20

// Define the maximum number of passwords that can be stored
#define MAX_PASSWORDS 100

// Define the encryption key
#define ENCRYPTION_KEY 13

// Define the file name where passwords are stored
#define PASSWORDS_FILE "passwords.dat"

// Define the structure to store the password entry
typedef struct {
    char website[50];
    char username[50];
    char password[MAX_PASSWORD_LENGTH + 1];
} PasswordEntry;

// Define the function to encrypt the password
void encrypt(char *password) {
    int i;
    for(i = 0; password[i] != '\0'; i++) {
        password[i] = password[i] + ENCRYPTION_KEY;
    }
}

// Define the function to decrypt the password
void decrypt(char *password) {
    int i;
    for(i = 0; password[i] != '\0'; i++) {
        password[i] = password[i] - ENCRYPTION_KEY;
    }
}

// Define the function to add a new password entry
void add_password_entry(PasswordEntry password_entries[], int *num_passwords) {
    char website[50], username[50], password[MAX_PASSWORD_LENGTH + 1];
    printf("\nEnter website: ");
    scanf("%s", website);
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    encrypt(password);
    strcpy(password_entries[*num_passwords].website, website);
    strcpy(password_entries[*num_passwords].username, username);
    strcpy(password_entries[*num_passwords].password, password);
    (*num_passwords)++;
    printf("\nPassword added successfully!\n");
}

// Define the function to display all password entries
void display_password_entries(PasswordEntry password_entries[], int num_passwords) {
    int i;
    printf("\nWebsite\t\tUsername\tPassword\n");
    printf("----------------------------------------------\n");
    for(i = 0; i < num_passwords; i++) {
        printf("%s\t\t%s\t\t", password_entries[i].website, password_entries[i].username);
        decrypt(password_entries[i].password);
        printf("%s\n", password_entries[i].password);
        encrypt(password_entries[i].password);
    }
}

// Define the main function
int main() {
    PasswordEntry password_entries[MAX_PASSWORDS];
    int num_passwords = 0, choice;
    // Load passwords from file (if exists)
    FILE *fp;
    fp = fopen(PASSWORDS_FILE, "rb");
    if(fp != NULL) {
        fread(&num_passwords, sizeof(int), 1, fp);
        fread(password_entries, sizeof(PasswordEntry), num_passwords, fp);
        fclose(fp);
    }
    do {
        // Display main menu
        printf("\n\nPassword Manager in Ada Lovelace Style\n");
        printf("----------------------------------------\n");
        printf("1. Add Password Entry\n");
        printf("2. Display Password Entries\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                // Add a new password entry
                add_password_entry(password_entries, &num_passwords);
                // Save passwords to file
                fp = fopen(PASSWORDS_FILE, "wb");
                fwrite(&num_passwords, sizeof(int), 1, fp);
                fwrite(password_entries, sizeof(PasswordEntry), num_passwords, fp);
                fclose(fp);
                break;
            case 2:
                // Display all password entries
                display_password_entries(password_entries, num_passwords);
                break;
            case 3:
                // Exit the program
                printf("\nBye!\n");
                break;
            default:
                // Display error message for invalid choice
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    } while(choice != 3);
    return 0;
}