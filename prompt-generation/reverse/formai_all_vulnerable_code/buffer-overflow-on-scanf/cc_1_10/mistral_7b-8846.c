//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: Alan Turing
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY 5

void encryptDate(char* date) {
    for (int i = 0; date[i] != '\0'; i++) {
        if (isdigit(date[i])) {
            int value = date[i] - '0';
            int newValue;

            if (isdigit(date[i + 1])) {
                newValue = (value + KEY) % 10;
                if (newValue == 0) newValue = 10;
                date[i] = newValue + '0';
                date[i + 1] = date[i + 1] - 1;
            } else {
                newValue = value + KEY;
                if (newValue > 'Z' && newValue < 'A') newValue += 26;
                date[i] = newValue;
            }
        }
    }
}

void decryptDate(char* date) {
    for (int i = 0; date[i] != '\0'; i++) {
        if (isdigit(date[i])) {
            int value = date[i] - '0';
            int newValue;

            if (isdigit(date[i + 1])) {
                newValue = value - KEY;
                if (newValue < 0) newValue += 10;
                date[i] = newValue + '0';
                date[i + 1] = date[i + 1] + 1;
            } else {
                newValue = value - KEY;
                if (newValue < 'A') newValue += 26;
                date[i] = newValue;
            }
        }
    }
}

void printDate(char* date) {
    for (int i = 0; date[i] != '\0'; i++) {
        if (isdigit(date[i])) {
            printf("%c%c", date[i], i == strlen(date) - 1 ? '\n' : ' ');
        } else {
            printf("%c", date[i]);
        }
    }
}

int main() {
    char date[9];
    char encryptedDate[9];

    printf("Enter a date (DDMMYYYY): ");
    scanf("%s", date);

    encryptDate(date);
    strcpy(encryptedDate, date);

    printf("Encrypted date (EELLSSSS): ");
    printDate(encryptedDate);

    decryptDate(encryptedDate);

    printf("Decrypted date (DDMMYYYY): ");
    printDate(encryptedDate);

    return 0;
}