//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100
#define KEY_SIZE 5

char key[KEY_SIZE];
char plaintext[MAX_LEN];
char ciphertext[MAX_LEN];
char encrypt_table[26][26] = { {0} };

void create_table(char *key)
{
    int i, j, k;
    for (i = 0; i < 26; i++) {
        for (j = 0; j < 26; j++) {
            if (i == j) {
                encrypt_table[i][j] = i + 65;
            } else {
                for (k = 0; k < KEY_SIZE; k++) {
                    if (key[k] == (i + 65) || key[k] == (j + 65)) {
                        encrypt_table[i][j] = j + 65;
                        encrypt_table[j][i] = i + 65;
                        break;
                    }
                }
            }
        }
    }
}

void encrypt(char *plaintext)
{
    int i, j, index;
    for (i = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            index = (int)plaintext[i] - 65;
            if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
                index = index % 26;
            }
            ciphertext[i] = encrypt_table[index][(int)plaintext[i + 1] - 65];
            i++;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[strlen(plaintext)] = '\0';
}

int main()
{
    printf("Enter your secret key (5 letters): ");
    scanf("%s", key);
    create_table(key);

    printf("Enter your love letter:\n");
    scanf("%s", plaintext);

    encrypt(plaintext);

    printf("\nYour encrypted love letter:\n%s\n", ciphertext);

    return 0;
}