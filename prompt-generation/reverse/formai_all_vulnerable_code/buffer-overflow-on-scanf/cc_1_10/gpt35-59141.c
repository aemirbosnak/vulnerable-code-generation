//FormAI DATASET v1.0 Category: Funny ; Style: synchronous
/* 
This program generates a secret code that can be used to unlock a safe. 
The user must input a code, which will be checked for accuracy against the secret code. 
If the correct code is entered, the safe will open. 
If the incorrect code is entered too many times, the program will lock the user out.
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CODE_LENGTH 20
#define MAX_ATTEMPTS 3

int main() {
    char secret_code[MAX_CODE_LENGTH + 1] = {0};
    char user_code[MAX_CODE_LENGTH + 1] = {0};
    int num_attempts = 0;
    int code_length = 0;
    int i = 0;
    int j = 0;

    srand(time(NULL)); // seed random number generator

    printf("Welcome to the safe-cracking program!\n\n");

    // generate a random secret code
    code_length = rand() % MAX_CODE_LENGTH + 1; // code length can be from 1 to MAX_CODE_LENGTH
    for (i = 0; i < code_length; i++) {
        secret_code[i] = rand() % 94 + 33; // character range is from 33 to 126
    }
    printf("A secret code has been generated. It has %d characters.\n\n", code_length);

    // prompt user to enter a code
    while (num_attempts < MAX_ATTEMPTS) {
        printf("Please enter the secret code (%d characters): ", code_length);
        scanf("%s", user_code);

        if (strcmp(secret_code, user_code) == 0) {
            printf("Congratulations, you have cracked the safe!\n");
            return 0;
        }
        else {
            printf("Incorrect code. Please try again.\n");
            num_attempts++;
        }
    }

    printf("Too many incorrect attempts. The program will now lock you out.\n");
    return 0;
}