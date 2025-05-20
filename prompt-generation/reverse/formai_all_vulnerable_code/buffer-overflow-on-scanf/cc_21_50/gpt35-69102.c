//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: synchronous
#include <stdio.h>
#include <string.h>

int main() {
    char password[100];
    int length, i, uppercase, lowercase, digit, symbol, strength;

    printf("Enter Password: ");
    scanf("%s", password);

    length = strlen(password);

    uppercase = lowercase = digit = symbol = strength = 0;

    for (i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            uppercase++;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            lowercase++;
        } else if (password[i] >= '0' && password[i] <= '9') {
            digit++;
        } else {
            symbol++;
        }
    }

    if (uppercase > 0 && lowercase > 0 && digit > 0 && symbol > 0) {
        strength = 4;
    } else if ((uppercase > 0 && lowercase > 0 && digit > 0) ||
               (lowercase > 0 && digit > 0 && symbol > 0) ||
               (uppercase > 0 && digit > 0 && symbol > 0) ||
               (uppercase > 0 && lowercase > 0 && symbol > 0)) {
        strength = 3;
    } else if ((uppercase > 0 && lowercase > 0) ||
               (lowercase > 0 && digit > 0) ||
               (digit > 0 && symbol > 0) ||
               (uppercase > 0 && symbol > 0)) {
        strength = 2;
    } else if (uppercase > 0 || lowercase > 0 || digit > 0 || symbol > 0) {
        strength = 1;
    }

    switch(strength) {
        case 4:
            printf("The password is a Strong Password.\n");
            break;
        case 3:
            printf("The password is a Medium Password.\n");
            break;
        case 2:
            printf("The password is a Weak Password.\n");
            break;
        case 1:
            printf("The password is a Very Weak Password.\n");
            break;
        default:
            printf("Invalid Password.\n");
            break;
    }

    return 0;
}