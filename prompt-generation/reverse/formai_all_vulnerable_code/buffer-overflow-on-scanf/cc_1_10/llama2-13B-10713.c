//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MESSAGE_LENGTH 100
#define MAX_SHIFT 25

void encryption(char *message, int shift);

int main() {
    char message[MAX_MESSAGE_LENGTH];
    int shift;

    printf("Enter a message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    printf("Enter the shift (1-25): ");
    scanf("%d", &shift);

    encryption(message, shift);

    return 0;
}

void encryption(char *message, int shift) {
    int i, j;
    char c;
    char encrypted[MAX_MESSAGE_LENGTH];

    for (i = 0; i < strlen(message); i++) {
        c = message[i];
        if (c >= 'a' && c <= 'z') {
            j = (c - 'a') + shift;
            if (j > 'z') {
                j = j - 26;
            }
            encrypted[i] = j + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            j = (c - 'A') + shift;
            if (j > 'Z') {
                j = j - 26;
            }
            encrypted[i] = j + 'A';
        } else {
            encrypted[i] = c;
        }
    }

    printf("Encrypted message: %s\n", encrypted);
}