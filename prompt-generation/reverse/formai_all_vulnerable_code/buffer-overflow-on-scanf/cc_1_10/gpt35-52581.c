//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// configuration variables
int minLength = 8;
int maxLength = 16;
int minUpperCase = 1;
int minLowerCase = 1;
int minDigits = 1;
int minSpecialChars = 1;
char specialChars[] = "!@#$%^&*()_+{}[];':\"<>,.?/";

// function to count the number of occurrences of a character in a string
int countChar(char* str, char c) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == c) {
            count++;
        }
    }
    return count;
}

// function to check if a character is a special character
int isSpecialChar(char c) {
    for (int i = 0; i < strlen(specialChars); i++) {
        if (c == specialChars[i]) {
            return 1;
        }
    }
    return 0;
}

// main function to check the strength of a password
int checkPassword(char* password) {
    int length = strlen(password);
    int upperCaseCount = countChar(password, 'A') + countChar(password, 'B') + countChar(password, 'C') + countChar(password, 'D') + countChar(password, 'E') + countChar(password, 'F') + countChar(password, 'G') + countChar(password, 'H') + countChar(password, 'I') + countChar(password, 'J') + countChar(password, 'K') + countChar(password, 'L') + countChar(password, 'M') + countChar(password, 'N') + countChar(password, 'O') + countChar(password, 'P') + countChar(password, 'Q') + countChar(password, 'R') + countChar(password, 'S') + countChar(password, 'T') + countChar(password, 'U') + countChar(password, 'V') + countChar(password, 'W') + countChar(password, 'X') + countChar(password, 'Y') + countChar(password, 'Z');
    int lowerCaseCount = countChar(password, 'a') + countChar(password, 'b') + countChar(password, 'c') + countChar(password, 'd') + countChar(password, 'e') + countChar(password, 'f') + countChar(password, 'g') + countChar(password, 'h') + countChar(password, 'i') + countChar(password, 'j') + countChar(password, 'k') + countChar(password, 'l') + countChar(password, 'm') + countChar(password, 'n') + countChar(password, 'o') + countChar(password, 'p') + countChar(password, 'q') + countChar(password, 'r') + countChar(password, 's') + countChar(password, 't') + countChar(password, 'u') + countChar(password, 'v') + countChar(password, 'w') + countChar(password, 'x') + countChar(password, 'y') + countChar(password, 'z');
    int digitCount = countChar(password, '0') + countChar(password, '1') + countChar(password, '2') + countChar(password, '3') + countChar(password, '4') + countChar(password, '5') + countChar(password, '6') + countChar(password, '7') + countChar(password, '8') + countChar(password, '9');
    int specialCharCount = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isSpecialChar(password[i])) {
            specialCharCount++;
        }
    }
    if (length < minLength) {
        return 0;
    } else if (length > maxLength) {
        return -1;
    } else if (upperCaseCount < minUpperCase) {
        return -2;
    } else if (lowerCaseCount < minLowerCase) {
        return -3;
    } else if (digitCount < minDigits) {
        return -4;
    } else if (specialCharCount < minSpecialChars) {
        return -5;
    } else {
        return 1;
    }
}

int main() {
    char password[100];
    printf("Enter your password: \n");
    scanf("%s", password);
    int result = checkPassword(password);
    if (result == 1) {
        printf("Password is strong.\n");
    } else if (result == 0) {
        printf("Password is too short.\n");
    } else if (result == -1) {
        printf("Password is too long.\n");
    } else if (result == -2) {
        printf("Password must contain at least %d uppercase letter(s).\n", minUpperCase);
    } else if (result == -3) {
        printf("Password must contain at least %d lowercase letter(s).\n", minLowerCase);
    } else if (result == -4) {
        printf("Password must contain at least %d digit(s).\n", minDigits);
    } else if (result == -5) {
        printf("Password must contain at least %d special character(s).\n", minSpecialChars);
    }
    return 0;
}