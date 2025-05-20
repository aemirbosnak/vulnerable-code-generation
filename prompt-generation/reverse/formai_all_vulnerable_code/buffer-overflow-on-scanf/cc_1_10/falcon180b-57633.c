//Falcon-180B DATASET v1.0 Category: Password management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void generatePassword(Password *pw) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int charset_length = strlen(charset);
    int i;

    pw->length = rand() % MAX_PASSWORD_LENGTH + 1;
    for (i = 0; i < pw->length; i++) {
        pw->password[i] = charset[rand() % charset_length];
    }

    pw->password[pw->length] = '\0';
}

void displayPasswords() {
    int i;

    printf("Passwords:\n");
    for (i = 0; i < num_passwords; i++) {
        printf("%s\n", passwords[i].password);
    }
}

int main() {
    int choice, password_index;

    srand(time(NULL));

    while (1) {
        printf("1. Generate new password\n");
        printf("2. Display passwords\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_passwords >= MAX_PASSWORDS) {
                printf("Maximum number of passwords reached.\n");
            } else {
                generatePassword(&passwords[num_passwords]);
                num_passwords++;
                printf("Password generated successfully.\n");
            }
            break;

        case 2:
            displayPasswords();
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}