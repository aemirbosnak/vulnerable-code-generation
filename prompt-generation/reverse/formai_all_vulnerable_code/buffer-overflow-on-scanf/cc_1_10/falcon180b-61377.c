//Falcon-180B DATASET v1.0 Category: Password management ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char password[MAX_PASSWORD_LENGTH + 1];
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords;

void generate_password(Password *password) {
    const char lowercase_chars[] = "abcdefghijklmnopqrstuvwxyz";
    const char uppercase_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char numbers[] = "0123456789";
    const char special_chars[] = "!@#$%^&*()_+-=[]{}|;:,.<>?/";

    char *chars = (char *) malloc(sizeof(char) * 4);
    strcat(chars, lowercase_chars);
    strcat(chars, uppercase_chars);
    strcat(chars, numbers);
    strcat(chars, special_chars);

    password->length = rand() % 10 + 8;
    char *password_chars = (char *) malloc(sizeof(char) * (password->length + 1));

    for (int i = 0; i < password->length; i++) {
        int rand_index = rand() % strlen(chars);
        password_chars[i] = chars[rand_index];
    }

    password_chars[password->length] = '\0';
    strcpy(password->password, password_chars);

    free(chars);
    free(password_chars);
}

void print_passwords() {
    printf("Passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
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
            if (num_passwords >= MAX_PASSWORDS) {
                printf("Maximum number of passwords reached.\n");
            } else {
                generate_password(&passwords[num_passwords]);
                num_passwords++;
            }
            break;

        case 2:
            print_passwords();
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}