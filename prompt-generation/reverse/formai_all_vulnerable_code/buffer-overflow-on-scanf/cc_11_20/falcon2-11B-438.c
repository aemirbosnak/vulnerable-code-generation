//Falcon2-11B DATASET v1.0 Category: Password Strength Checker ; Style: interoperable
#include <stdio.h>
#include <string.h>

int main() {
    char password[50];
    printf("Enter password: ");
    scanf("%s", password);

    int len = strlen(password);

    if (len < 8) {
        printf("Password too short. Minimum length is 8.\n");
        return 0;
    }

    if (strlen(password) == 8 && strncmp(password, "password", 8) == 0) {
        printf("Password is too common.\n");
        return 0;
    }

    int uppercase = 0;
    int lowercase = 0;
    int digit = 0;
    int special = 0;

    for (int i = 0; i < len; i++) {
        if (isupper(password[i])) {
            uppercase++;
        } else if (islower(password[i])) {
            lowercase++;
        } else if (isdigit(password[i])) {
            digit++;
        } else {
            special++;
        }
    }

    if (uppercase < 1 || lowercase < 1 || digit < 1 || special < 1) {
        printf("Password must contain at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
        return 0;
    }

    int strong = uppercase + lowercase + digit + special;
    int weak = len - strong;

    if (weak > 0) {
        printf("Password is weak, it has %d weak characters.\n", weak);
    } else {
        printf("Password is strong.\n");
    }

    return 0;
}