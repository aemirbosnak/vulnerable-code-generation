//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{

    char password[100];
    int len, i, upper_count = 0, lower_count = 0, num_count = 0, special_count = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    len = strlen(password);

    if (len < 8) {
        printf("The password must be at least 8 characters long.");
        return 0;
    }

    for (i = 0; i < len; i++) {
        if (isupper(password[i])) {
            upper_count++;
        } else if (islower(password[i])) {
            lower_count++;
        } else if (isdigit(password[i])) {
            num_count++;
        } else {
            special_count++;
        }
    }

    if (upper_count == 0) {
        printf("The password must contain at least one uppercase letter.");
        return 0;
    }

    if (lower_count == 0) {
        printf("The password must contain at least one lowercase letter.");
        return 0;
    }

    if (num_count == 0) {
        printf("The password must contain at least one number.");
        return 0;
    }

    if (special_count == 0) {
        printf("The password must contain at least one special character.");
        return 0;
    }

    printf("The password is strong!");

    return 0;

}