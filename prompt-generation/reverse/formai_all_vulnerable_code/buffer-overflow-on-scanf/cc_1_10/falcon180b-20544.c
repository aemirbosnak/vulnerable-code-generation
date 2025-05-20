//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: happy
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define SIZE 26

void key_gen(char key[], int key_size) {
    int i;
    printf("Enter the key: ");
    scanf("%s", key);
    if(strlen(key)!= key_size) {
        printf("Invalid key size!\n");
        exit(0);
    }
    for(i=0; i<strlen(key); i++) {
        if(!isalpha(key[i])) {
            printf("Invalid key!\n");
            exit(0);
        }
    }
}

void encrypt(char text[], char key[], int key_size, char cipher_text[]) {
    int i, j;
    for(i=0; i<strlen(text); i++) {
        if(isalpha(text[i])) {
            if(isupper(text[i])) {
                cipher_text[i] = ((text[i] - 65 + key[i % key_size] - 65) % 26) + 65;
            }
            else {
                cipher_text[i] = ((text[i] - 97 + key[i % key_size] - 97) % 26) + 97;
            }
        }
        else {
            cipher_text[i] = text[i];
        }
    }
    cipher_text[strlen(text)] = '\0';
}

void decrypt(char cipher_text[], char key[], int key_size, char text[]) {
    int i, j;
    for(i=0; i<strlen(cipher_text); i++) {
        if(isalpha(cipher_text[i])) {
            if(isupper(cipher_text[i])) {
                text[i] = ((cipher_text[i] - 65 - key[i % key_size] - 65 + 26) % 26) + 65;
            }
            else {
                text[i] = ((cipher_text[i] - 97 - key[i % key_size] - 97 + 26) % 26) + 97;
            }
        }
        else {
            text[i] = cipher_text[i];
        }
    }
    text[strlen(cipher_text)] = '\0';
}

int main() {
    char text[100], key[100], cipher_text[100];
    int key_size;
    printf("Enter the text to be encrypted: ");
    scanf("%s", text);
    printf("Enter the key: ");
    scanf("%s", key);
    key_gen(key, strlen(key));
    encrypt(text, key, strlen(key), cipher_text);
    printf("Encrypted text: %s\n", cipher_text);
    printf("Enter the key: ");
    scanf("%s", key);
    key_gen(key, strlen(key));
    decrypt(cipher_text, key, strlen(key), text);
    printf("Decrypted text: %s\n", text);
    return 0;
}