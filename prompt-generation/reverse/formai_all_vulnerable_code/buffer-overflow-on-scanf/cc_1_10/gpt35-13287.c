//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {

    /* Delightful message */
    printf("Welcome to the Secure Password Generator!\n");
    printf("Surprise! This program will generate a password for you that is impossible to forget!\n\n");

    /* Declaration of variables */
    int num_digits = 0;
    int num_uppercase = 0;
    int num_lowercase = 0;
    int num_special = 0;
    int total_length = 0;
    char password[100];

    srand(time(NULL));
    /* Getting the desired length from user */
    printf("To start, please enter the total password length you desire: ");
    scanf("%d", &total_length);
    printf("\n");

    /* Generating password based on desired length */
    while (total_length > 0) {

        int random_digit = rand() % 10;
        int random_letter = rand() % 26;
        int random_special = rand() % 15;

        if (random_digit % 2 == 0 && total_length > 0) {
            password[strlen(password)] = random_digit + '0';
            total_length--;
            num_digits++;
        }
        if (random_letter % 2 == 0 && total_length > 0) {
            password[strlen(password)] = random_letter + 'A';
            total_length--;
            num_uppercase++;
        }
        if (random_letter % 2 != 0 && total_length > 0) {
            password[strlen(password)] = random_letter + 'a';
            total_length--;
            num_lowercase++;
        }
        if (random_special <= 5 && total_length > 0) {
            password[strlen(password)] = random_special + 33;
            total_length--;
            num_special++;
        }
    }

    /* Printing the Secure Password */
    printf("Your Secure Password is: %s\n", password);
    printf("Number of Digits: %d\n", num_digits);
    printf("Number of Uppercase Letters: %d\n",num_uppercase);
    printf("Number of Lowercase Letters: %d\n", num_lowercase);
    printf("Number of Special Characters: %d\n", num_special);

    /* Final message */
    printf("\nCongrats! You now have a Secure Password that only you know!\n");

    return 0;
}