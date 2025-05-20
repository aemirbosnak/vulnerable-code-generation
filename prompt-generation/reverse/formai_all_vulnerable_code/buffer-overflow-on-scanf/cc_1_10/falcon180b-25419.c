//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 20
#define LOWERCASE_CHARS "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMBERS "0123456789"
#define SPECIAL_CHARS "!@#$%^&*()-_+={}[]\\|:;\"'<>,.?/~`"

void generate_password(int length, char *password) {
    char charset[4] = {0};
    int i, j;

    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        printf("Error: Password length must be between %d and %d characters.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        exit(1);
    }

    if (length == 8) {
        strcpy(charset, LOWERCASE_CHARS);
    } else if (length == 12) {
        strcpy(charset, LOWERCASE_CHARS);
        strcat(charset, UPPERCASE_CHARS);
        strcat(charset, NUMBERS);
    } else {
        strcpy(charset, LOWERCASE_CHARS);
        strcat(charset, UPPERCASE_CHARS);
        strcat(charset, NUMBERS);
        strcat(charset, SPECIAL_CHARS);
    }

    srand(time(NULL));

    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }

    password[length] = '\0';
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length;

    printf("Enter password length (between %d and %d characters): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%d", &length);

    generate_password(length, password);

    printf("Generated password: %s\n", password);

    return 0;
}