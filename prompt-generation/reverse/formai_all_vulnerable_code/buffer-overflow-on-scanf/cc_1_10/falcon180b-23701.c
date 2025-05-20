//Falcon-180B DATASET v1.0 Category: Password management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

struct password {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void generate_password(char* password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[length] = '\0';
}

int main() {
    struct password passwords[MAX_PASSWORDS];
    int num_passwords = 0;
    char choice;

    do {
        printf("Password Manager\n");
        printf("1. Add Password\n");
        printf("2. Generate Password\n");
        printf("3. View Passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            if (num_passwords >= MAX_PASSWORDS) {
                printf("Maximum number of passwords reached.\n");
            } else {
                printf("Enter website name: ");
                scanf("%s", passwords[num_passwords].name);
                generate_password(passwords[num_passwords].password, MAX_PASSWORD_LENGTH);
                num_passwords++;
                printf("Password added successfully.\n");
            }
            break;
        case '2':
            printf("Enter website name: ");
            scanf("%s", passwords[num_passwords - 1].name);
            generate_password(passwords[num_passwords - 1].password, MAX_PASSWORD_LENGTH);
            printf("Password generated successfully.\n");
            break;
        case '3':
            for (int i = 0; i < num_passwords; i++) {
                printf("Website: %s\nPassword: %s\n\n", passwords[i].name, passwords[i].password);
            }
            break;
        case '4':
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice!= '4');

    return 0;
}