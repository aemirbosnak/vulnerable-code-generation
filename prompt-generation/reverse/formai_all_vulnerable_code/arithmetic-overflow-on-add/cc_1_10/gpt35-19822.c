//FormAI DATASET v1.0 Category: Password management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Password struct
typedef struct Password {
    char *site;
    char *username;
    char *password;
} Password;

// Function to generate random alphanumeric password
char *generate_password(int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    char *password = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        int r = rand() % strlen(charset);
        password[i] = charset[r];
    }
    password[length] = '\0';
    return password;
}

// Function to create a new password entry
Password *create_password_entry() {
    printf("Enter website: ");
    char site[100];
    fgets(site, 100, stdin);
    site[strcspn(site, "\n")] = 0;

    printf("Enter username: ");
    char username[100];
    fgets(username, 100, stdin);
    username[strcspn(username, "\n")] = 0;

    int password_length;
    printf("Enter password length: ");
    scanf("%d", &password_length);
    getchar();
    char *password = generate_password(password_length);

    Password *new_password = malloc(sizeof(Password));
    new_password->site = strdup(site);
    new_password->username = strdup(username);
    new_password->password = password;
    return new_password;
}

// Function to print list of all password entries
void print_password_list(Password **passwords, int num_passwords) {
    printf("WEBSITE\tUSERNAME\tPASSWORD\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t%s\t%s\n", passwords[i]->site, passwords[i]->username, passwords[i]->password);
    }
}

int main() {
    int num_passwords = 0;
    Password **passwords = malloc(10 * sizeof(Password*)); // Initialize passwords array with space for 10 password entries

    char option;
    printf("Welcome to Password Manager!\n");
    do {
        printf("\nMENU\n");
        printf("1. Add new password entry\n");
        printf("2. Print list of saved passwords\n");
        printf("3. Exit\n");
        printf("Enter option: ");
        scanf("%c", &option);
        getchar();

        switch(option) {
            case '1':
                passwords[num_passwords] = create_password_entry();
                num_passwords++;
                break;
            case '2':
                print_password_list(passwords, num_passwords);
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != '3');

    return 0;
}