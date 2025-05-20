//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    int pass_length, option, i;
    char password[50];
    time_t t;
    const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char digits[] = "0123456789";
    const char special[] = "!@#$%^&*()_+={}[]|;:<>,.?/";

    srand((unsigned) time(&t));

    printf("Welcome to Brave Pass - The Secure Password Generator!\n");
    printf("1 - Generate a Random Password\n");
    printf("2 - Generate a Custom Password\n");
    printf("Please select an option: ");
    scanf("%d", &option);

    if (option == 1) {
        printf("\nHow long do you want your password to be? (minimum 8 characters): ");
        scanf("%d", &pass_length);
        if (pass_length < 8) {
            printf("Password length must be at least 8 characters. Try again.\n");
            return 0;
        }

        for (i = 0; i < pass_length; i++) {
            int rand_choice = rand() % 4;
            if (rand_choice == 0) {
                password[i] = lowercase[rand() % strlen(lowercase)];
            }
            else if (rand_choice == 1) {
                password[i] = uppercase[rand() % strlen(uppercase)];
            }
            else if (rand_choice == 2) {
                password[i] = digits[rand() % strlen(digits)];
            }
            else if (rand_choice == 3) {
                password[i] = special[rand() % strlen(special)];
            }
        }

        printf("Your new password is: %s", password);
    }
    else if (option == 2) {
        printf("\nEnter your desired password: ");
        scanf("%s", password);
        pass_length = strlen(password);

        int has_lowercase = 0, has_uppercase = 0, has_digit = 0, has_special = 0;
        for (i = 0; i < pass_length; i++) {
            if (strchr(lowercase, password[i]) != NULL) {
                has_lowercase = 1;
            }
            else if (strchr(uppercase, password[i]) != NULL) {
                has_uppercase = 1;
            }
            else if (strchr(digits, password[i]) != NULL) {
                has_digit = 1;
            }
            else if (strchr(special, password[i]) != NULL) {
                has_special = 1;
            }
        }

        if (pass_length < 8) {
            printf("Password length must be at least 8 characters. Try again.\n");
            return 0;
        }
        else if (has_lowercase == 0 || has_uppercase == 0 || has_digit == 0 || has_special == 0) {
            printf("Your password must contain at least one of each of the following: a lowercase letter, an uppercase letter, a digit, and a special character.\n");
            return 0;
        }

        printf("You have successfully set your password to: %s", password);
    }
    else {
        printf("Invalid option. Try again.\n");
    }

    return 0;
}