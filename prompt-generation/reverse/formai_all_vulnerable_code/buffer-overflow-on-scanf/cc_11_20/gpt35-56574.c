//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: funny
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char password[50];
    int length, i, upper=0, lower=0, digit=0, special=0;

    printf("Welcome to the Password Strength Checker!\n");
    printf("Please enter your password:\n");
    scanf("%s", password);

    length = strlen(password);

    if (length < 8) {
        printf("Your password is weak like a kitten. Please try again with at least 8 characters.\n");
    }
    else {
        for (i=0; i<length; i++) {
            if (isupper(password[i])) {
                upper++;
            }
            else if (islower(password[i])) {
                lower++;
            }
            else if (isdigit(password[i])) {
                digit++;
            }
            else {
                special++;
            }
        }
        if (upper && lower && digit && special) {
            printf("Wow, your password is as strong as Hulk!\n");
        }
        else {
            printf("Your password is weak like a wet noodle. It needs:\n");
            if (!upper) {
                printf("- At least one uppercase letter\n");
            }
            if (!lower) {
                printf("- At least one lowercase letter\n");
            }
            if (!digit) {
                printf("- At least one number\n");
            }
            if (!special) {
                printf("- At least one special character\n");
            }
        }
    }

    return 0;
}