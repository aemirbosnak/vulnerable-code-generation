//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32
#define NUM_SPECIAL_CHARS 5

char specialChars[] = "!@#$%^&*()_+-=[]\\{}|;':\",./<>?";
char password[MAX_PASSWORD_LENGTH + 1];

void generatePassword(int length) {
    int uppercase = 0, lowercase = 0, digits = 0, special = 0;
    int i, index;
    password[length] = '\0';
    for (i = 0; i < length; i++) {
        index = rand() % NUM_SPECIAL_CHARS;
        if (uppercase < 2) {
            password[i] = 'A' + rand() % 26;
            uppercase++;
        } else if (lowercase < 2) {
            password[i] = 'a' + rand() % 26;
            lowercase++;
        } else if (digits < 2) {
            password[i] = '0' + rand() % 10;
            digits++;
        } else if (special < 2) {
            password[i] = specialChars[index];
            special++;
        } else {
            password[i] = 'A' + rand() % 26;
            uppercase++;
        }
    }
    printf("Your new password is: %s\n", password);
}

int main() {
    int length;
    printf("Welcome to the password generator!\n");
    printf("How long would you like your password to be? (min %d, max %d)\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%d", &length);
    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        printf("Invalid password length entered. Must be between %d and %d.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        return 0;
    }
    srand(time(NULL));
    generatePassword(length);
    return 0;
}