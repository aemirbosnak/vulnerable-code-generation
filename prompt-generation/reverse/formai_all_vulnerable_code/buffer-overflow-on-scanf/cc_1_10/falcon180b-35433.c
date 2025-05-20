//Falcon-180B DATASET v1.0 Category: Password management ; Style: random
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

void generate_password(Password *password) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>/?";
    int charset_len = strlen(charset);
    int i;

    for (i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        password->password[i] = charset[rand() % charset_len];
    }

    password->length = MAX_PASSWORD_LENGTH;
}

void add_password() {
    Password password;
    generate_password(&password);
    passwords[num_passwords++] = password;
}

void print_passwords() {
    int i;

    for (i = 0; i < num_passwords; i++) {
        printf("%s\n", passwords[i].password);
    }
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("1. Generate password\n2. Print passwords\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                print_passwords();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}