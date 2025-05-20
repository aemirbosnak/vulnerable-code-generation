//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 16

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    int password_length, i, choice;
    srand(time(0));

    printf("Welcome to Secure Password Generator\n");
    printf("Please choose a password length between %d and %d: ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%d", &password_length);

    while (password_length < MIN_PASSWORD_LENGTH || password_length > MAX_PASSWORD_LENGTH) {
        printf("Error! Please choose a password length between %d and %d: ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        scanf("%d", &password_length);
    }

    printf("Please choose a password type.\n");
    printf("1: Lowercase letters only\n");
    printf("2: Uppercase letters only\n");
    printf("3: Numbers only\n");
    printf("4: Mixed case letters and numbers\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    while (choice < 1 || choice > 4) {
        printf("Error! Please choose a valid option: ");
        scanf("%d", &choice);
    }

    switch (choice) {
        case 1:
            for (i = 0; i < password_length; i++) {
                password[i] = 'a' + rand() % 26;
            }
            break;
        case 2:
            for (i = 0; i < password_length; i++) {
                password[i] = 'A' + rand() % 26;
            }
            break;
        case 3:
            for (i = 0; i < password_length; i++) {
                password[i] = '0' + rand() % 10;
            }
            break;
        case 4:
            for (i = 0; i < password_length; i++) {
                int random = rand() % 3;
                if (random == 0) {
                    password[i] = 'a' + rand() % 26;
                } else if (random == 1) {
                    password[i] = 'A' + rand() % 26;
                } else {
                    password[i] = '0' + rand() % 10;
                }
            }
            break;
    }

    password[password_length] = '\0';

    printf("Your generated password is: %s", password);

    return 0;
}