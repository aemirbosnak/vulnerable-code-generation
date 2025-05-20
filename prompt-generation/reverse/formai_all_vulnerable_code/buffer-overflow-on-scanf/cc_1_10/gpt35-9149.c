//FormAI DATASET v1.0 Category: Password management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 20   // Maximum password length
#define MAX_NUM_PASSWORDS 5      // Maximum number of passwords the user can add
#define PASSWORD_FILE "passwords.txt"  // File name to save the passwords

typedef struct {
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
} Password;

// Function to add a password to the password list
void add_password(Password *passwords, int *num_passwords) {
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    if (*num_passwords < MAX_NUM_PASSWORDS) {
        strcpy(passwords[*num_passwords].username, username);
        strcpy(passwords[*num_passwords].password, password);
        *num_passwords += 1;
        printf("\nPassword added successfully!\n");
    } else {
        printf("\nSorry, you have reached the maximum number of passwords that can be added!\n");
    }
}

// Function to print all the passwords in the password list
void print_passwords(Password *passwords, int num_passwords) {
    if (num_passwords == 0) {
        printf("\nSorry, no passwords found!\n");
    } else {
        printf("\n%-20s%-20s\n", "Username", "Password");
        printf("----------------------------------------\n");
        for (int i = 0; i < num_passwords; i++) {
            printf("%-20s%-20s\n", passwords[i].username, passwords[i].password);
        }
    }
}

// Function to generate a random password
void generate_password(char *password) {
    char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=";
    srand(time(NULL));
    int length = rand() % MAX_PASSWORD_LENGTH + 8;
    for (int i = 0; i < length; i++) {
        password[i] = characters[rand() % strlen(characters)];
    }
    password[length] = '\0';
}

int main() {
    Password passwords[MAX_NUM_PASSWORDS];
    int num_passwords = 0;
    int option = 0;

    printf("Welcome to the Password Manager!\n");

    while (option != 4) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a password\n");
        printf("2. Print all passwords\n");
        printf("3. Generate a password\n");
        printf("4. Quit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_password(passwords, &num_passwords);
                break;
            case 2:
                print_passwords(passwords, num_passwords);
                break;
            case 3:
                printf("\nGenerated password: ");
                char password[MAX_PASSWORD_LENGTH];
                generate_password(password);
                printf("%s\n", password);
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid option!\n");
                break;
        }
    }

    // Save the passwords to file
    FILE *fp;
    fp = fopen(PASSWORD_FILE, "w");
    if (fp == NULL) {
        printf("Error saving passwords to file!\n");
        return 1;
    }
    for (int i = 0; i < num_passwords; i++) {
        fprintf(fp, "%s %s\n", passwords[i].username, passwords[i].password);
    }
    fclose(fp);

    printf("\nPasswords saved to file %s successfully!\n", PASSWORD_FILE);

    return 0;
}