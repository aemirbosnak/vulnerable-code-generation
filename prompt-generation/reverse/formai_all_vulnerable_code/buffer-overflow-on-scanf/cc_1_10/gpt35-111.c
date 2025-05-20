//FormAI DATASET v1.0 Category: Password management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PASSWORD_LENGTH 20
#define MAX_ACCOUNTS 10

// Struct for password and account information
typedef struct {
    char account_name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} PasswordInfo;

// Function prototypes
void show_menu();
void add_password(PasswordInfo [], int *);
void view_passwords(PasswordInfo [], int);
void delete_password(PasswordInfo [], int *);

int main() {
    PasswordInfo password_array[MAX_ACCOUNTS]; // Array to hold password information
    int num_passwords = 0; // Variable to keep track of number of passwords stored

    int input; // Variable to hold user input
    do {
        show_menu(); // Display menu options to user
        scanf("%d", &input); // Get user input

        switch (input) {
            case 1:
                add_password(password_array, &num_passwords); // Call function to add password
                break;
            case 2:
                view_passwords(password_array, num_passwords); // Call function to view passwords
                break;
            case 3:
                delete_password(password_array, &num_passwords); // Call function to delete password
                break;
            case 4:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid input. Try again.\n");
                break;
        }
    } while (input != 4);

    return 0;
}

// Function to display menu options to user
void show_menu() {
    printf("\nMenu:\n");
    printf("1. Add password\n");
    printf("2. View passwords\n");
    printf("3. Delete password\n");
    printf("4. Exit program\n");
    printf("Enter choice: ");
}

// Function to add password to password array
void add_password(PasswordInfo password_array[], int *num_passwords) {
    if (*num_passwords >= MAX_ACCOUNTS) {
        printf("Maximum number of passwords reached.\n");
        return;
    }

    char account_name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    // Get account name from user
    printf("Enter account name (max %d characters): ", MAX_PASSWORD_LENGTH-1);
    scanf("%s", account_name);

    // Get password from user
    printf("Enter password (max %d characters): ", MAX_PASSWORD_LENGTH-1);
    scanf("%s", password);

    // Create new password info struct with user input
    PasswordInfo new_password = { account_name, password };

    // Add new password info struct to password array
    password_array[*num_passwords] = new_password;

    // Increment number of passwords stored
    (*num_passwords)++;

    printf("Password added successfully.\n");
}

// Function to view all passwords stored in array
void view_passwords(PasswordInfo password_array[], int num_passwords) {
    if (num_passwords == 0) {
        printf("No passwords stored.\n");
        return;
    }

    printf("\nAll stored passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%d. Account name: %s, Password: %s\n", i+1, password_array[i].account_name, password_array[i].password);
    }
}

// Function to delete a password from password array
void delete_password(PasswordInfo password_array[], int *num_passwords) {
    if (*num_passwords == 0) {
        printf("No passwords stored.\n");
        return;
    }

    printf("Enter the number of the password to delete (1-%d): ", *num_passwords);
    int delete_index;
    scanf("%d", &delete_index);
    delete_index--; // Decrement by 1 to account for 0-based indexing of array

    // Move all passwords after deleted password back one index
    for (int i = delete_index + 1; i < *num_passwords; i++) {
        password_array[i-1] = password_array[i];
    }

    // Decrement number of passwords stored
    (*num_passwords)--;

    printf("Password deleted successfully.\n");
}