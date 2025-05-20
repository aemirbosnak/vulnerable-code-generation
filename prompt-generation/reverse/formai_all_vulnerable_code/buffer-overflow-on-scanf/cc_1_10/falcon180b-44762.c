//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define SIZE 1000
#define ALPHABET_SIZE 26

int main() {
    FILE *file;
    char *filename = "message.txt";
    char message[SIZE];
    char alphabet[ALPHABET_SIZE] = "abcdefghijklmnopqrstuvwxyz";
    int key;
    int i, j, k;
    char ciphertext[SIZE];

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: file not found.\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    int length = ftell(file);
    rewind(file);

    fread(message, sizeof(char), length, file);

    printf("Enter the key: ");
    scanf("%d", &key);

    for (i = 0; i < length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = tolower(message[i]);
            }
            j = 0;
            while (alphabet[j]!= message[i]) {
                j++;
            }
            k = (j + key) % ALPHABET_SIZE;
            ciphertext[i] = alphabet[k];
        } else {
            ciphertext[i] = message[i];
        }
    }

    fclose(file);

    file = fopen("ciphertext.txt", "w");
    if (file == NULL) {
        printf("Error: unable to create file.\n");
        exit(1);
    }

    fwrite(ciphertext, sizeof(char), strlen(ciphertext), file);

    printf("Ciphertext saved to ciphertext.txt.\n");

    return 0;
}