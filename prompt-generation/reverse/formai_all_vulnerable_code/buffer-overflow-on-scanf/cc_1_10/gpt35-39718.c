//FormAI DATASET v1.0 Category: Modern Encryption ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1000 // maximum length of input text
#define ENCRYPT_VALUE 5 // value used to encrypt the input text

int main() {
    char input[MAX_LENGTH], encrypted[MAX_LENGTH], decrypted[MAX_LENGTH];
    int i, j, length, option;
    srand(time(NULL)); // initialize random seed

    printf("Welcome to the futuristic encryption program!\n");
    printf("Select an option:\n");
    printf("1. Encrypt\n2. Decrypt\n");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Enter the text you want to encrypt: ");
            fflush(stdin);
            fgets(input, MAX_LENGTH, stdin);
            length = strlen(input);

            for (i = 0; i < length; i++) {
                encrypted[i] = input[i] + ENCRYPT_VALUE + rand() % 10; // randomly shift the characters
            }
            encrypted[i] = '\0';

            printf("Your encrypted text is: %s\n", encrypted);
            break;

        case 2:
            printf("Enter the text you want to decrypt: ");
            fflush(stdin);
            fgets(encrypted, MAX_LENGTH, stdin);
            length = strlen(encrypted);

            for (i = 0; i < length; i++) {
                decrypted[i] = encrypted[i] - ENCRYPT_VALUE - rand() % 10; // shift the characters back
            }
            decrypted[i] = '\0';

            printf("Your decrypted text is: %s\n", decrypted);
            break;

        default:
            printf("Invalid option selected.");
            break;
    }

    return 0;
}