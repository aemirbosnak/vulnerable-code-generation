//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_PASSWORD_LENGTH 100
#define MIN_PASSWORD_LENGTH 8
#define MAX_NUM_DIGITS 4
#define MAX_NUM_UPPERCASE 4
#define MAX_NUM_LOWERCASE 4
#define MAX_NUM_SPECIAL 4

int is_valid_password(char* password) {
    int length = strlen(password);
    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        return 0;
    }
    int num_digits = 0, num_uppercase = 0, num_lowercase = 0, num_special = 0;
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            num_digits++;
        } else if (isupper(password[i])) {
            num_uppercase++;
        } else if (islower(password[i])) {
            num_lowercase++;
        } else if (!isalnum(password[i])) {
            num_special++;
        }
    }
    if (num_digits > MAX_NUM_DIGITS || num_uppercase > MAX_NUM_UPPERCASE ||
        num_lowercase > MAX_NUM_LOWERCASE || num_special > MAX_NUM_SPECIAL) {
        return 0;
    }
    return 1;
}

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    int length;
    do {
        printf("Enter password (minimum %d characters): ", MIN_PASSWORD_LENGTH);
        scanf("%s", password);
        length = strlen(password);
    } while (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH);
    if (is_valid_password(password)) {
        printf("Password is strong!\n");
    } else {
        printf("Password is weak!\n");
    }
    return 0;
}