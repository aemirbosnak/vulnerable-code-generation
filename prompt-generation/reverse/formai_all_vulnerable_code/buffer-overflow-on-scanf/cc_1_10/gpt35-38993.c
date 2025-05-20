//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16

int main() {
    int length;
    printf("Enter the length of the password you want to generate (between %d and %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Sorry, the length you entered is not within the allowed range.\n");
        exit(1);
    }

    // Set up the characters that can be used in the password
    const char UPPER_LETTERS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char LOWER_LETTERS[] = "abcdefghijklmnopqrstuvwxyz";
    const char NUMBERS[] = "0123456789";
    const char SPECIAL[] = "!@#$%^&*()_+{}:\"<>?,./;'[]-=`\\|";

    // Create an array that will hold the characters of the password
    char password[MAX_LENGTH + 1];
    password[length] = '\0'; // Set the end of the array to a null terminator

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a password
    int i, j;
    for (i = 0; i < length; i++) {
        // Choose the type of character to use
        int type = rand() % 4;
        char c;
        switch (type) {
            case 0:
                // Choose a random upper case letter
                j = rand() % 26;
                c = UPPER_LETTERS[j];
                break;
            case 1:
                // Choose a random lower case letter
                j = rand() % 26;
                c = LOWER_LETTERS[j];
                break;
            case 2:
                // Choose a random number
                j = rand() % 10;
                c = NUMBERS[j];
                break;
            case 3:
                // Choose a random special character
                j = rand() % 28;
                c = SPECIAL[j];
                break;
        }
        password[i] = c;
    }

    // Print the generated password
    printf("\nYour generated password is: %s\n", password);

    return 0;
}