//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main() {
    char password[100];
    int length, i, j, has_uppercase = 0, has_lowercase = 0, has_number = 0, has_special_char = 0, has_consecutive_chars = 0;
    char *uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", *lowercase = "abcdefghijklmnopqrstuvwxyz", *numbers = "0123456789", *special_chars = "!@#$%^&*()_+";

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        }
        else if (islower(password[i])) {
            has_lowercase = 1;
        }
        else if (isdigit(password[i])) {
            has_number = 1;
        }
        else if (strchr(special_chars, password[i])!= NULL) {
            has_special_char = 1;
        }
        else if (i > 0 && password[i] == password[i-1]) {
            has_consecutive_chars = 1;
            break;
        }
    }

    if (length < 8) {
        printf("Password is too short.\n");
    }
    else if (length > 20) {
        printf("Password is too long.\n");
    }
    else if (!has_uppercase) {
        printf("Password must contain at least one uppercase letter.\n");
    }
    else if (!has_lowercase) {
        printf("Password must contain at least one lowercase letter.\n");
    }
    else if (!has_number) {
        printf("Password must contain at least one number.\n");
    }
    else if (!has_special_char) {
        printf("Password must contain at least one special character.\n");
    }
    else if (has_consecutive_chars) {
        printf("Password must not contain consecutive characters.\n");
    }
    else {
        printf("Password is strong.\n");
    }

    return 0;
}