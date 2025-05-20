//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOWERCASE_MIN 97
#define LOWERCASE_MAX 122
#define UPPERCASE_MIN 65
#define UPPERCASE_MAX 90
#define NUMBER_MIN 48
#define NUMBER_MAX 57
#define SYMBOLS "!@#$%^&*"

// Function to generate a random number within a given range
int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a password of given length
void generate_password(int length) {
    char password[length + 1];
    int i, random_num, choice;

    srand(time(NULL));      // Set the seed for random number generation

    for(i = 0; i < length; i++) {
        // Choose a random character from a set of predefined choices
        choice = get_random_number(1, 4);
        switch(choice) {
            case 1: // Lowercase letters
                random_num = get_random_number(LOWERCASE_MIN, LOWERCASE_MAX);
                password[i] = (char) random_num;
                break;
            case 2: // Uppercase letters
                random_num = get_random_number(UPPERCASE_MIN, UPPERCASE_MAX);
                password[i] = (char) random_num;
                break;
            case 3: // Numbers
                random_num = get_random_number(NUMBER_MIN, NUMBER_MAX);
                password[i] = (char) random_num;
                break;
            case 4: // Symbols
                random_num = get_random_number(0, 8);
                password[i] = SYMBOLS[random_num];
                break;
        }
    }
    password[length] = '\0';  // Add the null termination character at the end
    printf("Your password is: %s", password);
}

// Driver code
int main() {
    int length;

    printf("Enter the length of password you want: ");
    scanf("%d", &length);

    if(length < 8) {
        printf("Password length should be at least 8 characters.\n");
    }
    else {
        generate_password(length);
    }

    return 0;
}