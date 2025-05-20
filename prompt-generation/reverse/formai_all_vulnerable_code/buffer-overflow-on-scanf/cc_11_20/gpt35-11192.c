//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LEN 50
#define MIN_LEN 8

int main(void) {
    char password[MAX_LEN + 1];
    int length, i;
    time_t t;
    int uppercase, lowercase, digits, special;

    printf("Enter the length of the password (minimum of %d characters): ", MIN_LEN);
    scanf("%d", &length);

    if (length < MIN_LEN) {
        printf("Password length must be at least %d characters.\n", MIN_LEN);
        return 1;
    }

    // Initialize random number generator
    srand((unsigned)time(&t));

    // Initialize count of each character type
    uppercase = lowercase = digits = special = 0;

    while(1) {
        // Generate random characters until password is of the desired length and contains at least one of each character type
        for (i = 0; i < length; i++) {
            int r = rand() % 4;
            switch (r) {
                case 0:
                    // Generate a random uppercase letter
                    password[i] = 'A' + rand() % 26;
                    uppercase++;
                    break;
                case 1:
                    // Generate a random lowercase letter
                    password[i] = 'a' + rand() % 26;
                    lowercase++;
                    break;
                case 2:
                    // Generate a random digit
                    password[i] = '0' + rand() % 10;
                    digits++;
                    break;
                case 3:
                    // Generate a random special character
                    password[i] = '!' + rand() % 15;
                    special++;
                    break;
            }
        }

        // Check if password contains at least one of each character type
        if (uppercase == 0 || lowercase == 0 || digits == 0 || special == 0) {
            // Reset count of each character type
            uppercase = lowercase = digits = special = 0;
            continue;
        } else {
            password[length] = '\0';
            printf("Your new password is: %s\n", password);
            return 0;
        }
    }
}