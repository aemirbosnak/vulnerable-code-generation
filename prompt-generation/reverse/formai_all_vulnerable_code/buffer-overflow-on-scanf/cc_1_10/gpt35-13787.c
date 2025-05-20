//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to check password strength
int checkStrength(char* password)
{
    int len = strlen(password);

    // password length should be more than 8 characters
    if (len < 8) {
        return 0;
    }

    // password should contain atleast one uppercase letter, one lowercase letter and one special character
    int upper = 0, lower = 0, special = 0;
    for (int i = 0; i < len; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            upper = 1;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            lower = 1;
        } else if (password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
            special = 1;
        }
    }

    if (upper && lower && special) {
        return 1; // password strength is good
    } else {
        return 0; // password is weak
    }
}

int main()
{
    char password[50];

    printf("Welcome to Password Strength Checker...\n\n");
    
    while(1) {
        printf("Enter the password to check its strength (enter exit to terminate): ");
        scanf("%s", password);

        if(strcmp(password, "exit") == 0)
            break;

        int strength = checkStrength(password);

        if(strength) {
            printf("Good job! Your password is strong.\n\n");
        } else {
            printf("Your password is weak. Please choose a stronger one.\n\n");
        }
    }

    printf("Thank you for using Password Strength Checker. Have a nice day!\n");

    return 0;
}