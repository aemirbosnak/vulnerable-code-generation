//FormAI DATASET v1.0 Category: Data validation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isAlphabet(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

int isValidName(char name[]) {
    int len = strlen(name);
    int i;
    for (i = 0; i < len; i++) {
        if (!isAlphabet(name[i])) {
            return 0;
        }
    }
    return 1;
}

int isValidPhoneNumber(char phoneNumber[]) {
    int len = strlen(phoneNumber);
    int i;
    if (len != 10) {
        return 0;
    }
    for (i = 0; i < len; i++) {
        if (!isDigit(phoneNumber[i])) {
            return 0;
        }
    }
    return 1;
}

int isValidEmail(char email[]) {
    int len = strlen(email);
    int i, atCount = 0, dotCount = 0;
    for (i = 0; i < len; i++) {
        if (email[i] == '@') {
            atCount++;
        } else if (email[i] == '.') {
            dotCount++;
        }
    }
    return (atCount == 1 && dotCount >= 1 && atCount + dotCount < len);
}

int main() {
    char name[50], phoneNumber[15], email[50];
    int isValid;

    printf("Enter your name: ");
    scanf("%s", name);
    isValid = isValidName(name);
    if (!isValid) {
        printf("Invalid name.\n");
        return 0;
    }

    printf("Enter your phone number: ");
    scanf("%s", phoneNumber);
    isValid = isValidPhoneNumber(phoneNumber);
    if (!isValid) {
        printf("Invalid phone number.\n");
        return 0;
    }

    printf("Enter your email address: ");
    scanf("%s", email);
    isValid = isValidEmail(email);
    if (!isValid) {
        printf("Invalid email address.\n");
        return 0;
    }

    printf("Name: %s\nPhone Number: %s\nEmail: %s\n", name, phoneNumber, email);

    return 0;
}