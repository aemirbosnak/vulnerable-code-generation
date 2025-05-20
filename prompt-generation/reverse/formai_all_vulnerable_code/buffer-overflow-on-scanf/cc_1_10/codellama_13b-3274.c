//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: intelligent
// Password strength checker

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16
#define MIN_NUMBERS 2
#define MIN_UPPERCASE 2
#define MIN_LOWERCASE 2
#define MIN_SPECIAL_CHARS 2

int main() {
    char password[MAX_LENGTH];
    int length, numbers, uppercase, lowercase, special_chars;

    printf("Enter a password: ");
    scanf("%s", password);

    length = strlen(password);
    numbers = 0;
    uppercase = 0;
    lowercase = 0;
    special_chars = 0;

    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            numbers++;
        } else if (isupper(password[i])) {
            uppercase++;
        } else if (islower(password[i])) {
            lowercase++;
        } else {
            special_chars++;
        }
    }

    if (length < MIN_LENGTH) {
        printf("Password is too short!\n");
    } else if (numbers < MIN_NUMBERS) {
        printf("Password must contain at least %d numbers!\n", MIN_NUMBERS);
    } else if (uppercase < MIN_UPPERCASE) {
        printf("Password must contain at least %d uppercase letters!\n", MIN_UPPERCASE);
    } else if (lowercase < MIN_LOWERCASE) {
        printf("Password must contain at least %d lowercase letters!\n", MIN_LOWERCASE);
    } else if (special_chars < MIN_SPECIAL_CHARS) {
        printf("Password must contain at least %d special characters!\n", MIN_SPECIAL_CHARS);
    } else {
        printf("Password is strong!\n");
    }

    return 0;
}