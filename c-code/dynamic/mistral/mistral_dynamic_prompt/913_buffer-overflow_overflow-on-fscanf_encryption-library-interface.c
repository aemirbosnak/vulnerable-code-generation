#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void encrypt(char *input, char *output) {
    char key[] = "secret_key1234";
    int i, j;

    for (i = 0, j = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            output[j] = (char)((input[i] - 'A' + key[i % sizeof(key)] - 'A') % 26 + 'A');
            j++;
        } else if (input[i] >= 'a' && input[i] <= 'z') {
            output[j] = (char)((input[i] - 'a' + key[i % sizeof(key)] - 'a') % 26 + 'a');
            j++;
        } else {
            output[j] = input[i];
            j++;
        }
    }
    output[j] = '\0';
}

int main() {
    char input[1000], output[1000];
    printf("Enter plaintext:\n");
    fscanf(stdin, "%s", input);
    encrypt(input, output);
    printf("Encrypted text:\n%s\n", output);
    return 0;
}
