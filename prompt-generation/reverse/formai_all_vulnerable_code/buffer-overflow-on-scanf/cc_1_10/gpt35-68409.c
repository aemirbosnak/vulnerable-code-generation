//FormAI DATASET v1.0 Category: Modern Encryption ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input, char *key){
    int i, j = 0, k, m = 0, p, q;
    int len = strlen(input);
    int key_len = strlen(key);
    int mod = len % key_len;
    char new_input[len + (key_len - mod)];
    char encrypted[len + (key_len - mod)];
    for (i = 0; i < len; i++){
        if (input[i] != ' '){
            new_input[m] = input[i];
            m++;
        } 
    }
    for (i = 0; i < key_len; i++){
        for (k = 0; k < m/key_len; k++){
            encrypted[j] = key[i];
            j++;
        }
        if (i < mod){
            encrypted[j] = key[i];
            j++;
        }
    }
    for (p = 0; p < m; p++){
        encrypted[p] ^= new_input[p];
    }
    printf("The encrypted message is: %s\n", encrypted);
}

void decrypt(char *encrypted, char *key){
    int i, j = 0, k, m = 0, p, q;
    int len = strlen(encrypted);
    int key_len = strlen(key);
    int mod = len % key_len;
    char decrypted[len + (key_len - mod)];
    char original[len + (key_len - mod)];
    for (i = 0; i < key_len; i++){
        for (k = 0; k < len/key_len; k++){
            original[m] = key[i];
            m++;
        }
        if (i < mod){
            original[m] = key[i];
            m++;
        }
    }
    for (p = 0; p < len; p++){
        decrypted[p] = encrypted[p] ^ original[p];
    }
    printf("The decrypted message is: %s\n", decrypted);
}

int main(void){
    char input[1000];
    char key[100];
    int choice;
    printf("Choose your option.\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);
    getchar();
    switch(choice){
        case 1:
            printf("Enter the message to be encrypted: ");
            fgets(input, 1000, stdin);
            printf("Enter the key: ");
            fgets(key, 100, stdin);
            encrypt(input, key);
            break;
        case 2:
            printf("Enter the message to be decrypted: ");
            fgets(input, 1000, stdin);
            printf("Enter the key: ");
            fgets(key, 100, stdin);
            decrypt(input, key);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}