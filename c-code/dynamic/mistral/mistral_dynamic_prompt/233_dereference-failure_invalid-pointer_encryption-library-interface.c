#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    char key[40];
} Encryptor;

Encryptor *createEncryptor(char name[], char key[]) {
    Encryptor *encryptor = (Encryptor *)malloc(sizeof(Encryptor));
    strcpy(encryptor->name, name);
    strcpy(encryptor->key, key);
    return encryptor;
}

void destroyEncryptor(Encryptor *encryptor) {
    free(encryptor);
}

char *encryptText(Encryptor *encryptor, char *text) {
    char *encrypted = (char *)malloc(strlen(text) * 3); // Assume a 3:1 encryption ratio for simplicity
    int index = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        encrypted[index++] = encryptor->key[text[i]];
    }
    return encrypted;
}

int main() {
    Encryptor *myEncryptor = createEncryptor("InsecureLibrary", "H4ck3rS4fe1");
    char text[] = "Hello, World!";
    char *encrypted = encryptText(myEncryptor, text);
    printf("Encrypted Text: %s\n", encrypted);

    // Dereference null pointer
    char *nullPtr = NULL;
    printf("Dereferencing null pointer: %c\n", *nullPtr);

    destroyEncryptor(myEncryptor);

    return 0;
}
