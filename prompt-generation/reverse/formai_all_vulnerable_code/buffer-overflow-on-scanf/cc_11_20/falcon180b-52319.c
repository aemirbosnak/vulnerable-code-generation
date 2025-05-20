//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    if (length < 8) {
        printf("Weak password\n");
        return 0;
    }

    int upper_case_count = 0;
    int lower_case_count = 0;
    int digit_count = 0;
    int special_char_count = 0;

    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);
        if (isalpha(c)) {
            if (isupper(c)) {
                upper_case_count++;
            } else {
                lower_case_count++;
            }
        } else if (isdigit(c)) {
            digit_count++;
        } else if (isalnum(c)) {
            special_char_count++;
        }
    }

    if (upper_case_count >= 2 && lower_case_count >= 2 && digit_count >= 2 && special_char_count >= 2) {
        printf("Strong password\n");
    } else {
        printf("Weak password\n");
    }

    return 0;
}