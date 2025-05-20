//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 20
#define MIN_LENGTH 6

void generateRandomString(char* str, int length) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*+-";
    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        str[i] = charset[rand() % (sizeof(charset) - 1)];
    }

    str[length] = '\0';
}

int main() {
    printf("Welcome to the Secure Password Generator!\n\n");

    int length;
    char password[MAX_LENGTH + 1];
    char isStrong[4];
    char* includeUpper;
    char* includeSpecial;

    printf("How long do you want your password to be? (Minimum %d characters)\n", MIN_LENGTH);
    scanf("%d", &length);

    if (length < MIN_LENGTH) {
        printf("Invalid input! Password length must be at least %d\n", MIN_LENGTH);
        exit(1);
    }

    printf("Do you want to include uppercase letters? (y/n)\n");
    scanf("%s", isStrong);

    if (strcmp(isStrong, "y") == 0) {
        includeUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    } else {
        includeUpper = "";
    }

    printf("Do you want to include special characters? (y/n)\n");
    scanf("%s", isStrong);

    if (strcmp(isStrong, "y") == 0) {
        includeSpecial = "!@#$%^&*+-";
    } else {
        includeSpecial = "";
    }

    strcat(includeUpper, includeSpecial);
    int numChars = strlen(includeUpper);
    int numUpper = strlen(includeUpper) - strlen(includeSpecial);

    if (numChars == 0 || numUpper == 0) {
        printf("Invalid input! Password must contain at least one uppercase letter or one special character.\n");
        exit(1);
    }

    generateRandomString(password, length);

    for (int i = 0; i < numUpper; i++) {
        int randomIndex = rand() % length;
        password[randomIndex] = toupper(password[randomIndex]);
    }

    for (int i = 0; i < strlen(includeSpecial); i++) {
        int randomIndex = rand() % length;
        password[randomIndex] = includeSpecial[i];
    }

    printf("\nYour secure password is: %s\n", password);
    return 0;
}