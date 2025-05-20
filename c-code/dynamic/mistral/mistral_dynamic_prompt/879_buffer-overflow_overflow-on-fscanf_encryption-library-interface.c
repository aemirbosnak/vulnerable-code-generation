#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

// Simulated encryption library function
char* encrypt(char* plaintext, int key) {
    char* ciphertext = (char*) malloc((strlen(plaintext) + 1) * sizeof(char));
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = plaintext[i] + key;
    }
    return ciphertext;
}

int main() {
    char input[10];
    int key;
    printf("Enter encryption key: ");
    scanf("%d", &key);
    printf("Enter plaintext: ");
    fscanf(stdin, "%s", input);
    char* ciphertext = encrypt(input, key);
    printf("Ciphertext: %s\n", ciphertext);
    free(ciphertext);
    return 0;
}
