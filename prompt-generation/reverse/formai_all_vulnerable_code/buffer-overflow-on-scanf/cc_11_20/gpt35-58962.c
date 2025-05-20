//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

int main() {

    char password[20];
    int i, length, upperCase = 0, lowerCase = 0, digit = 0, specialChar = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    length = strlen(password);

    for (i = 0; i < length; i++) {
        char c = password[i];

        if (c >= 'A' && c <= 'Z') {
            upperCase++;
        }
        else if (c >= 'a' && c <= 'z') {
            lowerCase++;
        }
        else if (c >= '0' && c <= '9') {
            digit++;
        }
        else {
            specialChar++;
        }
    }

    printf("\nPassword Statistics:");
    printf("\n-------------------");
    printf("\nNumber of Upper Case characters: %d", upperCase);
    printf("\nNumber of Lower Case characters: %d", lowerCase);
    printf("\nNumber of Digits: %d", digit);
    printf("\nNumber of Special Characters: %d", specialChar);
    printf("\nPassword Length: %d", length);

    if (length >= 8 && upperCase >= 1 && lowerCase >= 1 && digit >= 1 && specialChar >= 1) {
        printf("\n\nPassword is Strong!");
    }
    else if (length >= 6 && length < 8 && upperCase >= 1 && lowerCase >= 1 && digit >= 1 && specialChar > 0) {
        printf("\n\nPassword is Medium.");
    }
    else {
        printf("\n\nPassword is Weak.");
    }

    return 0;
}