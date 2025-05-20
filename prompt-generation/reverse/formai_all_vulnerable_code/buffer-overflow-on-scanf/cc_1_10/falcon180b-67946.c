//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOWERCASE_CHARS "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMERIC_CHARS "0123456789"
#define SPECIAL_CHARS "!@#$%^&*()_+-=[]{}|;:,.<>?"

int main() {
    int length;
    char *password;
    char charset[3];
    int i;

    printf("Enter the desired password length (between 8 and 32): ");
    scanf("%d", &length);

    if (length < 8 || length > 32) {
        printf("Error: Password length must be between 8 and 32 characters.\n");
        return 1;
    }

    printf("Choose the character set for your password:\n");
    printf("1. Lowercase letters only\n");
    printf("2. Uppercase letters only\n");
    printf("3. Lowercase and uppercase letters\n");
    printf("4. Lowercase letters, uppercase letters, and numbers\n");
    printf("5. Lowercase letters, uppercase letters, numbers, and special characters\n");

    scanf("%d", &i);

    switch (i) {
        case 1:
            strcpy(charset, LOWERCASE_CHARS);
            break;
        case 2:
            strcpy(charset, UPPERCASE_CHARS);
            break;
        case 3:
            strcpy(charset, LOWERCASE_CHARS);
            strcat(charset, UPPERCASE_CHARS);
            break;
        case 4:
            strcpy(charset, LOWERCASE_CHARS);
            strcat(charset, UPPERCASE_CHARS);
            strcat(charset, NUMERIC_CHARS);
            break;
        case 5:
            strcpy(charset, LOWERCASE_CHARS);
            strcat(charset, UPPERCASE_CHARS);
            strcat(charset, NUMERIC_CHARS);
            strcat(charset, SPECIAL_CHARS);
            break;
        default:
            printf("Error: Invalid character set.\n");
            return 1;
    }

    password = (char *)malloc(length + 1);
    if (password == NULL) {
        printf("Error: Unable to allocate memory for password.\n");
        return 1;
    }

    srand(time(NULL));

    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }

    printf("Your password is: %s\n", password);

    free(password);
    return 0;
}