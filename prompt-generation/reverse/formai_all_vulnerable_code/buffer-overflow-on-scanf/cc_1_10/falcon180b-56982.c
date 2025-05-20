//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int is_valid_password(char *password) {
    int length = strlen(password);
    if (length < 8 || length > MAX_LENGTH) {
        return 0;
    }

    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special = 0;

    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);
        if (isalpha(c)) {
            has_lowercase = 1;
        } else if (isdigit(c)) {
            has_digit = 1;
        } else if (strchr("!@#$%^&*()_+-=[]{}|;':\",.<>/?", c)!= NULL) {
            has_special = 1;
        }
    }

    if (has_uppercase && has_lowercase && has_digit && has_special) {
        return 1;
    } else {
        return 0;
    }
}

void generate_password(char *password, int length) {
    if (length == 0) {
        printf("%s\n", password);
        return;
    }

    char c = 'a';
    for (int i = 0; i < length; i++) {
        password[i] = c;
        generate_password(password + i + 1, length - 1);
    }
}

int main() {
    char password[MAX_LENGTH];

    printf("Enter the length of the password: ");
    scanf("%d", &password[0]);

    if (!is_valid_password(password)) {
        printf("Invalid password!\n");
        return 1;
    }

    generate_password(password, strlen(password));

    return 0;
}