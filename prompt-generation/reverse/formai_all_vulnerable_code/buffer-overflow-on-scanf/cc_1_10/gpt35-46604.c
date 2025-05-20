//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[50];
    int len;
    int upper_case = 0, lower_case = 0, digits = 0, special_chars = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    len = strlen(password);

    // count number of character types
    for (int i=0; i<len; i++) {
        if (isupper(password[i])) {
            upper_case++;
        }
        else if (islower(password[i])) {
            lower_case++;
        }
        else if (isdigit(password[i])) {
            digits++;
        }
        else {
            special_chars++;
        }
    }

    // calculate score based on character types
    int score = upper_case * 2 + lower_case * 2 + digits * 3 + special_chars * 5;

    printf("\nPassword Strength Report\n");
    printf("-------------------------\n");
    printf("Password: %s\n", password);
    printf("Length: %d\n", len);
    printf("Upper case characters: %d\n", upper_case);
    printf("Lower case characters: %d\n", lower_case);
    printf("Digits: %d\n", digits);
    printf("Special characters: %d\n", special_chars);
    printf("Score: %d\n", score);

    // evaluate strength based on score
    if (score < 40) {
        printf("Weak password\n");
    }
    else if (score < 60) {
        printf("Moderate password\n");
    }
    else if (score < 80) {
        printf("Strong password\n");
    }
    else {
        printf("Very strong password\n");
    }

    return 0;
}