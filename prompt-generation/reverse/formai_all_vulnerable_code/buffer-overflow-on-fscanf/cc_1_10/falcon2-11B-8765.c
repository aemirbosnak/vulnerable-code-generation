//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a string using Caesar cipher
char* encrypt(char* str, int shift) {
    int len = strlen(str);
    char* encrypted = (char*)malloc(sizeof(char) * (len + 1));
    encrypted[len] = '\0';
    for (int i = 0; i < len; i++) {
        int index = (str[i] - 'a' + shift) % 26;
        encrypted[i] = (char)('a' + index);
    }
    return encrypted;
}

int main() {
    char* fileName = "myfile.txt";
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Unable to open file: %s\n", fileName);
        return 1;
    }

    char* encrypted = (char*)malloc(sizeof(char) * (strlen(fileName) + 1));
    encrypted[strlen(fileName)] = '\0';

    char* temp = (char*)malloc(sizeof(char) * (strlen(fileName) + 1));
    temp[strlen(fileName)] = '\0';

    char c;
    while (fscanf(fp, "%c", &c)!= EOF) {
        encrypted[strlen(encrypted)] = c;
        temp[strlen(temp)] = c;
    }
    fclose(fp);

    printf("File encrypted: %s\n", encrypted);

    int shift = 3;
    encrypted = encrypt(encrypted, shift);

    printf("Encrypted file: %s\n", encrypted);

    char* decrypted = (char*)malloc(sizeof(char) * (strlen(encrypted) + 1));
    decrypted[strlen(decrypted)] = '\0';

    for (int i = 0; i < strlen(encrypted); i++) {
        int index = (encrypted[i] - 'a' + shift) % 26;
        decrypted[i] = (char)('a' + index);
    }

    printf("Decrypted file: %s\n", decrypted);

    free(encrypted);
    free(temp);
    free(decrypted);
    return 0;
}