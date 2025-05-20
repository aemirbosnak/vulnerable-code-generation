//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 20

void generatePassword(char* password, int length) {
    // define the characters that can be used in the password
    char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-={}[]|\\:;\"'<>,.?/";
    int numChars = sizeof(chars) - 1;

    // initialize the password with random characters
    for (int i = 0; i < length; i++) {
        password[i] = chars[rand() % numChars];
    }

    // add some additional characters for extra security
    int numSpecialChars = rand() % 3 + 1;
    for (int i = 0; i < numSpecialChars; i++) {
        int index = rand() % numChars;
        char specialChar = chars[index];
        int j;
        for (j = 0; j < length; j++) {
            if (password[j] == specialChar) {
                break;
            }
        }
        if (j == length) {
            password[length] = specialChar;
            length++;
        }
    }

    // shuffle the password to make it more random
    for (int i = 0; i < length; i++) {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
}

int main() {
    srand(time(NULL));

    int length;
    printf("Enter the length of the password: ");
    scanf("%d", &length);

    if (length < 8 || length > MAX_PASSWORD_LENGTH) {
        printf("Invalid password length.\n");
        return 1;
    }

    char password[MAX_PASSWORD_LENGTH + 1];
    generatePassword(password, length);

    printf("Generated password: %s\n", password);

    return 0;
}