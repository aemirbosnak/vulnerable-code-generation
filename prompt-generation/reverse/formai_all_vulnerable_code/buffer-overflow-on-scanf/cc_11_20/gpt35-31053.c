//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {

    int length, num, choice, strength = 0;
    char password[50], character = 'a';

    printf("Welcome to Password Generator! \n");
    printf("Please enter the length of password you want to generate (maximum 50 characters): ");
    scanf("%d", &length);

    while (length > 50 || length <= 0) {
        printf("Invalid Input. Please enter a valid length for password (maximum 50 characters): ");
        scanf("%d", &length);
    }

    printf("\nNow please select what type of password you want to generate. \n");
    printf("1. Only Alphabets. \n");
    printf("2. Alphabets and Digits. \n");
    printf("3. Alphabets, Digits and Special Characters. \n");
    printf("Your choice: ");
    scanf("%d", &choice);

    while (choice <= 0 || choice > 3) {
        printf("Invalid Input. Please select a valid option: ");
        scanf("%d", &choice);
    }

    switch (choice) {

        case 1:

            for (int i = 0; i < length; ++i) {
                character = (rand() % 26) + 97;
                password[i] = character;
            }

            break;

        case 2:

            for (int i = 0; i < length; ++i) {

                num = rand() % 3;
                character = (rand() % 26) + 97;

                if (num == 0) {
                    password[i] = character;
                } else {
                    password[i] = (rand() % 10) + 48;
                }
            }

            break;

        case 3:

            for (int i = 0; i < length; ++i) {

                num = rand() % 4;

                if (num == 0) {
                    password[i] = (rand() % 16) + 33;
                } else if (num == 1) {
                    password[i] = (rand() % 26) + 97;
                } else if (num == 2) {
                    password[i] = (rand() % 26) + 65;     
                } else {
                    password[i] = (rand() % 10) + 48;
                }
            }

            break;

    }

    for (int i = 0; i < length; ++i) {

        if (isdigit(password[i])) {
            strength += 10;
        } else if (isupper(password[i])) {
            strength += 20;
        } else if (ispunct(password[i])) {
            strength += 30;
        } else {
            strength += 5;
        }

    }

    printf("\nYour Secure Password is: ");
    for (int i = 0; i < length; ++i) {
        printf("%c", password[i]);
    }

    printf("\n\nThe strength of your password is: %d/100 \n", strength);

    return 0;
}