//FormAI DATASET v1.0 Category: Password management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

// Function prototypes
void add_password();
void view_passwords();
void delete_password();
void change_master_password();
void encrypt(char[], int);
void decrypt(char[], int);

// Global variables
char master_password[MAX];
char passwords[MAX][MAX];
int counter = 0;

int main()
{
    int choice;
    printf("Welcome to Password Manager!\n");

    // Get master password from user
    printf("Please enter your master password: ");
    fgets(master_password, MAX, stdin);
    master_password[strcspn(master_password, "\n")] = '\0'; // Remove trailing newline from fgets

    // Encrypt master password using Caesar Cipher
    encrypt(master_password, 3);
    printf("\n");

    // Menu loop
    while (1) {
        printf("Choose an option:\n");
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Delete password\n");
        printf("4. Change master password\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n");
                add_password();
                break;
            case 2:
                printf("\n");
                view_passwords();
                break;
            case 3:
                printf("\n");
                delete_password();
                break;
            case 4:
                printf("\n");
                change_master_password();
                break;
            case 5:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}

void add_password()
{
    char new_password[MAX];

    // Get new password from user
    printf("Enter the new password: ");
    scanf("%s", new_password);

    // Encrypt new password using Caesar Cipher
    encrypt(new_password, 3);

    // Add new password to global password array
    strcpy(passwords[counter], new_password);
    counter++;

    printf("Password added successfully!\n");
}

void view_passwords()
{
    if (counter == 0) {
        printf("No passwords saved.\n");
        return;
    }

    // Decrypt and print all saved passwords
    printf("Saved passwords:\n");
    for (int i = 0; i < counter; i++) {
        decrypt(passwords[i], 3);
        printf("- %s\n", passwords[i]);
        encrypt(passwords[i], 3); // Encrypt password again for storage
    }
}

void delete_password()
{
    if (counter == 0) {
        printf("No passwords saved.\n");
        return;
    }

    char delete_password[MAX];
    int found = 0;

    // Get password to delete from user
    printf("Enter the password to delete: ");
    scanf("%s", delete_password);

    // Decrypt all saved passwords and check for match
    for (int i = 0; i < counter; i++) {
        decrypt(passwords[i], 3);
        if (strcmp(passwords[i], delete_password) == 0) {
            // Password found, shift all following passwords back one index in array
            found = 1;
            for (int j = i; j < counter - 1; j++) {
                strcpy(passwords[j], passwords[j + 1]);
            }
            counter--;
        }
        encrypt(passwords[i], 3); // Encrypt password again for storage
    }

    if (found) {
        printf("Password deleted successfully!\n");
    } else {
        printf("Password not found.\n");
    }
}

void change_master_password()
{
    char new_master_password[MAX];

    // Get new master password from user
    printf("Enter your new master password: ");
    fgets(new_master_password, MAX, stdin);
    new_master_password[strcspn(new_master_password, "\n")] = '\0'; // Remove trailing newline from fgets

    // Encrypt new master password using Caesar Cipher
    encrypt(new_master_password, 3);

    // Update global master password variable
    strcpy(master_password, new_master_password);

    printf("Master password changed successfully!\n");
}

void encrypt(char message[], int key)
{
    for (int i = 0; message[i] != '\0'; i++) {
        // Shift each character in message by key places
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A') + key) % 26 + 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a') + key) % 26 + 'a';
        }
    }
}

void decrypt(char message[], int key)
{
    for (int i = 0; message[i] != '\0'; i++) {
        // Shift each character in message backwards by key places
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A') - key + 26) % 26 + 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a') - key + 26) % 26 + 'a';
        }
    }
}