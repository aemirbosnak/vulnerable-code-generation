//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 8
#define KEY "mysecretkey"

void encrypt(char* message, char* result) {
    int i, j, n = strlen(message);
    int k = strlen(KEY);
    int m = 0;

    for (i = 0; i < n; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                result[m] = (message[i] + 13 - 65) % 26 + 65;
            } else {
                result[m] = (message[i] + 13 - 97) % 26 + 97;
            }
            m++;
        } else {
            result[m] = message[i];
            m++;
        }
    }

    for (i = 0; i < k; i++) {
        for (j = 0; j < n; j++) {
            if (message[j] == KEY[i]) {
                result[j] = '*';
            }
        }
    }
}

void decrypt(char* message, char* result) {
    int i, j, n = strlen(message);
    int k = strlen(KEY);
    int m = 0;

    for (i = 0; i < n; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                result[m] = (message[i] - 13 - 65 + 26) % 26 + 65;
            } else {
                result[m] = (message[i] - 13 - 97 + 26) % 26 + 97;
            }
            m++;
        } else {
            result[m] = message[i];
            m++;
        }
    }

    for (i = 0; i < k; i++) {
        for (j = 0; j < n; j++) {
            if (message[j] == '*') {
                result[j] = KEY[i];
            }
        }
    }
}

int main() {
    char message[100], result[100];
    int choice;

    printf("Enter your message: ");
    scanf("%s", message);

    printf("Enter your choice:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encrypt(message, result);
            printf("Encrypted message: %s\n", result);
            break;
        case 2:
            decrypt(message, result);
            printf("Decrypted message: %s\n", result);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}