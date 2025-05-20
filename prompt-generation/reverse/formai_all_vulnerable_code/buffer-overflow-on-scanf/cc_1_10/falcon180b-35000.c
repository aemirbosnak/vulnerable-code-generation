//Falcon-180B DATASET v1.0 Category: Encryption ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"

void encrypt(char* input, char* output) {
    int i, j, k;
    char temp;

    for (i = 0, j = 0; input[i]; i++) {
        if (isalpha(input[i])) {
            output[j] = input[i] + (KEY[j % strlen(KEY)] - 'a');
            j++;
        } else {
            output[j] = input[i];
            j++;
        }
    }
    output[j] = '\0';
}

void decrypt(char* input, char* output) {
    int i, j, k;
    char temp;

    for (i = 0, j = 0; input[i]; i++) {
        if (isalpha(input[i])) {
            temp = input[i] - (KEY[j % strlen(KEY)] - 'a');
            if (temp < 'a' || temp > 'z') {
                output[j] = input[i];
            } else {
                output[j] = temp;
            }
            j++;
        } else {
            output[j] = input[i];
            j++;
        }
    }
    output[j] = '\0';
}

int main() {
    char input[100], output[100];
    int choice, i;

    printf("Enter a string to encrypt/decrypt: ");
    scanf("%s", input);

    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encrypt(input, output);
            printf("Encrypted string: %s\n", output);
            break;
        case 2:
            decrypt(input, output);
            printf("Decrypted string: %s\n", output);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}