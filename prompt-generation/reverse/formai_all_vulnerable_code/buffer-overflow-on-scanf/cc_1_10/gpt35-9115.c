//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 15
#define MIN_LENGTH 8
#define NUM_SPECIAL_CHARS 7
#define NUM_DIGITS 4

void generate_password(int password_length, char password[], char special_chars[], int num_special_chars);

int main() {
    srand(time(NULL));

    char password[MAX_LENGTH + 1];
    password[MAX_LENGTH] = '\0';

    char special_chars[NUM_SPECIAL_CHARS] = {'!', '@', '#', '$', '%', '^', '&'};

    while (1) {
        printf("How long would you like your password to be? (minimum %d, maximum %d): ", MIN_LENGTH, MAX_LENGTH);
        int password_length;
        scanf("%d", &password_length);

        if (password_length < MIN_LENGTH || password_length > MAX_LENGTH) {
            printf("Invalid length. ");
            continue;
        }

        char confirm;
        printf("Do you want to include special characters? (y/n): ");
        scanf(" %c", &confirm);

        int num_special_chars = 0;

        if (confirm == 'y' || confirm == 'Y') {
            num_special_chars = NUM_SPECIAL_CHARS;
        }

        generate_password(password_length, password, special_chars, num_special_chars);
        printf("\n Your password is: %s\n", password);

        char choice;
        printf("Do you want to regenerate a password? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    return 0;
}

void generate_password(int password_length, char password[], char special_chars[], int num_special_chars) {
    int num_digits = NUM_DIGITS;
    int num_letters = password_length - num_digits - num_special_chars;

    int i;

    for (i = 0; i < num_special_chars; i++) {
        password[i] = special_chars[rand() % num_special_chars];
    }

    for (i = num_special_chars; i < num_special_chars + num_digits; i++) {
        password[i] = '0' + rand() % 10;
    }

    for (i = num_special_chars + num_digits; i < password_length; i++) {
        if (rand() % 2 == 0) {
            password[i] = 'a' + rand() % 26;
        } else {
            password[i] = 'A' + rand() % 26;
        }
    }

    for (i = 0; i < password_length; i++) {
        int j = rand() % password_length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
}