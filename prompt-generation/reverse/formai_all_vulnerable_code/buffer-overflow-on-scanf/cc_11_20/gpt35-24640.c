//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main()
{
    int length, i, randomNum;
    char password[100];

    srand(time(NULL));

    printf("Welcome to the Secure Password Generator!\n\n");

    printf("How long do you want your password to be? (Enter a number between 8-20)\n");
    scanf("%d", &length);

    if (length < 8 || length > 20) {
        printf("\nInvalid input. Password length must be between 8-20.\n");
        return 0;
    }

    for (i = 0; i < length; i++) {
        randomNum = rand() % 94 + 33; // ASCII values between 33-126 are printable characters
        password[i] = (char)randomNum;
    }

    password[length] = '\0';

    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) { // ensure at least one digit is present
            break;
        }
        if (i == length - 1) { // if one isn't found, add one randomly
            password[rand() % length] = rand() % 10 + '0';
        }
    }

    for (i = 0; i < length; i++) {
        if (islower(password[i])) { // ensure at least one lowercase letter is present
            break;
        }
        if (i == length - 1) { // if one isn't found, add one randomly
            password[rand() % length] = rand() % 26 + 'a';
        }
    }

    for (i = 0; i < length; i++) {
        if (isupper(password[i])) { // ensure at least one uppercase letter is present
            break;
        }
        if (i == length - 1) { // if one isn't found, add one randomly
            password[rand() % length] = rand() % 26 + 'A';
        }
    }

    printf("\nYour new password is: %s\n", password);
    printf("Please make sure to save it in a safe place!\n");

    return 0;
}