//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: Romeo and Juliet
/*
 * A Romeo and Juliet-style password strength checker
 *
 * Usage:
 *     password_strength <password>
 *
 * Output:
 *     "Pass" if the password is strong,
 *     "Fail" if the password is weak.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PASSWORD_LEN 100

int main(int argc, char *argv[]) {
    char password[PASSWORD_LEN];
    int length, uppercase, lowercase, numbers, special;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <password>\n", argv[0]);
        return 1;
    }

    strcpy(password, argv[1]);
    length = strlen(password);
    uppercase = 0;
    lowercase = 0;
    numbers = 0;
    special = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase++;
        } else if (islower(password[i])) {
            lowercase++;
        } else if (isdigit(password[i])) {
            numbers++;
        } else {
            special++;
        }
    }

    if (length < 8) {
        printf("Fail: Password too short\n");
        return 1;
    } else if (uppercase == 0 || lowercase == 0 || numbers == 0 || special == 0) {
        printf("Fail: Password too weak\n");
        return 1;
    } else {
        printf("Pass: Password is strong\n");
        return 0;
    }
}