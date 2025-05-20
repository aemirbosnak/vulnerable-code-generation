//FormAI DATASET v1.0 Category: Password management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10

struct Password {
    char title[50];
    char username[50];
    char password[50];
};

/* function prototypes */
void add_password(struct Password[], int);
void view_passwords(struct Password[], int);
void encrypt_password(char[]);
void decrypt_password(char[]);

int main() {
    /* initialize variables */
    int choice;
    int num_passwords = 0;
    struct Password passwords[MAX_PASSWORDS];

    do {
        /* display menu */
        printf("Password Management System\n\n");
        printf("1. Add a password\n");
        printf("2. View passwords\n");
        printf("3. Quit\n\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_password(passwords, num_passwords);
                num_passwords++;
                break;
            case 2:
                view_passwords(passwords, num_passwords);
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 3);

    return 0;
}

/* function to add a password to the system */
void add_password(struct Password passwords[], int num_passwords) {
    /* make sure there is room for another password */
    if (num_passwords >= MAX_PASSWORDS) {
        printf("\nSorry, no more passwords can be added.\n");
        return;
    }

    /* get user input */
    printf("Enter the title of the password: ");
    scanf("%s", passwords[num_passwords].title);
    printf("Enter the username: ");
    scanf("%s", passwords[num_passwords].username);
    printf("Enter the password: ");
    scanf("%s", passwords[num_passwords].password);

    /* encrypt password */
    encrypt_password(passwords[num_passwords].password);

    /* confirm addition of password */
    printf("Password added successfully.\n");
}

/* function to view all passwords in the system */
void view_passwords(struct Password passwords[], int num_passwords) {
    /* make sure there are passwords to view */
    if (num_passwords == 0) {
        printf("\nNo passwords to view.\n");
        return;
    }

    /* display password information for each password */
    printf("%-25s%-25s%-25s\n", "Title", "Username", "Password");
    printf("----------------------------------------------\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%-25s%-25s", passwords[i].title, passwords[i].username);
        decrypt_password(passwords[i].password);
        printf("%-25s\n", passwords[i].password);
    }
}

/* function to encrypt a password */
void encrypt_password(char password[]) {
    /* encryption algorithm */
    for (int i = 0; i < strlen(password); i++) {
        password[i] = password[i] + 3;
    }
}

/* function to decrypt a password */
void decrypt_password(char password[]) {
    /* decryption algorithm */
    for (int i = 0; i < strlen(password); i++) {
        password[i] = password[i] - 3;
    }
}