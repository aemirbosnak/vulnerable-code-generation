//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 2048

void generate_key(char *key, int key_len) {
    int i;
    for (i = 0; i < key_len; i++) {
        *(key+i) = rand() % 256;
    }
}

char* encrypt(char *data, int data_len, char *key, int key_len) {
    char *encrypted_data = (char*)malloc(MAX_LENGTH);
    memset(encrypted_data, '\0', MAX_LENGTH);
    int i, j;
    for (i = 0, j = 0; i < data_len; i++, j++) {
        if (j >= key_len) {
            j = 0;
        }
        *(encrypted_data+i) = (*(data+i)) ^ (*(key+j));
    }
    return encrypted_data;
}

char* decrypt(char *encrypted_data, int data_len, char *key, int key_len) {
    char *decrypted_data = (char*)malloc(MAX_LENGTH);
    memset(decrypted_data, '\0', MAX_LENGTH);
    int i, j;
    for (i = 0, j = 0; i < data_len; i++, j++) {
        if (j >= key_len) {
            j = 0;
        }
        *(decrypted_data+i) = (*(encrypted_data+i)) ^ (*(key+j));
    }
    return decrypted_data;
}

int main() {
    char data[MAX_LENGTH];
    char key[MAX_LENGTH];
    printf("Enter the data to encrypt: ");
    fgets(data, MAX_LENGTH, stdin);
    int data_len = strlen(data) - 1;
    printf("Enter the length of the key: ");
    int key_len;
    scanf("%d", &key_len);
    generate_key(key, key_len);
    printf("\n\nData to encrypt: %s\n\n", data);
    printf("Key: ");
    int i;
    for (i = 0; i < key_len; i++) {
        printf("%02x ", *(key+i));
    }
    printf("\n\n");
    char *encrypted_data = encrypt(data, data_len, key, key_len);
    printf("Encrypted data: ");
    for (i = 0; i < data_len; i++) {
        printf("%02x ", *(encrypted_data+i));
    }
    printf("\n\n");
    char *decrypted_data = decrypt(encrypted_data, data_len, key, key_len);
    printf("Decrypted data: %s\n\n", decrypted_data);
    free(encrypted_data);
    free(decrypted_data);
    return 0;
}