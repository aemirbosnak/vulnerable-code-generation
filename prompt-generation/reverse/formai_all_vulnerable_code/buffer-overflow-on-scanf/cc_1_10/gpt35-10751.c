//FormAI DATASET v1.0 Category: Password management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10

struct Password {
    int id;
    char website[30];
    char username[30];
    char password[30];
};

void print_password(struct Password p);
void print_all_passwords(struct Password passwords[], int num_passwords);
void generate_password(char password[], int length);

int main() {
    struct Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    while (1) {
        printf("\nWelcome to the Password Manager! What would you like to do?\n");
        printf("1. Add a new password\n");
        printf("2. View all passwords\n");
        printf("3. Quit\n");
        printf("Your choice: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nPlease enter the website: ");
            char website[30];
            scanf("%s", website);

            printf("Please enter the username: ");
            char username[30];
            scanf("%s", username);

            printf("Would you like a randomly generated password? (y/n): ");
            char generate_choice;
            scanf(" %c", &generate_choice);

            char password[30];
            if (generate_choice == 'y' || generate_choice == 'Y') {
                generate_password(password, 10);
            } else {
                printf("Please enter the password: ");
                scanf("%s", password);
            }

            struct Password new_password = {
                .id = num_passwords + 1,
                .website = website,
                .username = username,
                .password = password
            };

            passwords[num_passwords] = new_password;
            num_passwords++;

            printf("\nNew password added successfully!\n");
        } else if (choice == 2) {
            if (num_passwords == 0) {
                printf("\nYou have not added any passwords yet!\n");
            } else {
                print_all_passwords(passwords, num_passwords);
            }
        } else if (choice == 3) {
            printf("\nThanks for using the Password Manager!\n");
            return 0;
        } else {
            printf("\nInvalid choice!\n");
        }
    }
}

void print_password(struct Password p) {
    printf("\nPassword ID: %d\n", p.id);
    printf("Website: %s\n", p.website);
    printf("Username: %s\n", p.username);
    printf("Password: %s\n", p.password);
}

void print_all_passwords(struct Password passwords[], int num_passwords) {
    printf("\nAll Passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        print_password(passwords[i]);
    }
}

void generate_password(char password[], int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < length; i++) {
        int index = rand() % strlen(charset);
        password[i] = charset[index];
    }
    password[length] = '\0';
}