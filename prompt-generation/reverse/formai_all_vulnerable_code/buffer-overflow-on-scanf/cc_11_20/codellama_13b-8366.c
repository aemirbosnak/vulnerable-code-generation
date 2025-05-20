//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: Ken Thompson
/*
 * Password Strength Checker
 *
 * By Ken Thompson
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16

#define LOWER_CASE_CHARS "abcdefghijklmnopqrstuvwxyz"
#define UPPER_CASE_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMBERS "0123456789"
#define SPECIAL_CHARS "!@#$%^&*()_+-=[]{}|;:,./<>?"

int main(void) {
    char password[MAX_LENGTH + 1];
    int length;
    int has_lower_case = 0;
    int has_upper_case = 0;
    int has_number = 0;
    int has_special_char = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    length = strlen(password);
    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Invalid length\n");
        return 1;
    }

    for (int i = 0; i < length; i++) {
        if (strchr(LOWER_CASE_CHARS, password[i])) {
            has_lower_case = 1;
        }
        if (strchr(UPPER_CASE_CHARS, password[i])) {
            has_upper_case = 1;
        }
        if (strchr(NUMBERS, password[i])) {
            has_number = 1;
        }
        if (strchr(SPECIAL_CHARS, password[i])) {
            has_special_char = 1;
        }
    }

    if (!has_lower_case || !has_upper_case || !has_number || !has_special_char) {
        printf("Password is too weak\n");
        return 1;
    }

    printf("Password is strong\n");
    return 0;
}