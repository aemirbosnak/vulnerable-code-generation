//FormAI DATASET v1.0 Category: modern Encryption ; Style: content
/*
 * This is a simple implementation of Caesar Cipher Encryption algorithm
 * in C programming language.
 * 
 * In Caesar Cipher, each alphabet in the message is shifted a certain
 * number of places down the alphabet and replaced by the corresponding
 * alphabet from the shifted alphabet.
 * 
 * For example, with a shift of 1, 'A' would be replaced by 'B', 'B' would
 * become 'C', and so on.
 * 
 * In this example, the user enters a string message and the program reads
 * the shift value from the user and then applies Caesar Cipher algorithm
 * on the message.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 100

void encrypt(char *msg, int shift);

int main()
{
    char message[MAX_MSG_LEN];
    int shift;

    printf("Enter message: ");
    fgets(message, MAX_MSG_LEN, stdin);
    message[strcspn(message, "\n")] = '\0'; // remove newline character from fgets()

    printf("Enter shift: ");
    scanf("%d", &shift);

    encrypt(message, shift);

    printf("Encrypted message: %s\n", message);

    return 0;
}

void encrypt(char *msg, int shift)
{
    int i;

    for (i = 0; msg[i] != '\0'; i++) {
        if (msg[i] >= 'A' && msg[i] <= 'Z') {
            msg[i] = ((msg[i] - 'A' + shift) % 26) + 'A';
        } else if (msg[i] >= 'a' && msg[i] <= 'z') {
            msg[i] = ((msg[i] - 'a' + shift) % 26) + 'a';
        }
    }
}