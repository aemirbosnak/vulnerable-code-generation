//FormAI DATASET v1.0 Category: Modern Encryption ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 100

void encrypt(char *input, char *output, int shift) {
    int i;
    for(i = 0; i < strlen(input); i++) {
        int asc = (int) input[i];
        if(asc >= 65 && asc <= 90) {
            asc = asc + shift % 26;
            if(asc < 65) {
                asc = asc + 26;
            }
            if(asc > 90) {
                asc = asc - 26;
            }
            output[i] = (char) asc;
        } else if(asc >= 97 && asc <= 122) {
            asc = asc + shift % 26;
            if(asc < 97) {
                asc = asc + 26;
            }
            if(asc > 122) {
                asc = asc - 26;
            }
            output[i] = (char) asc;
        } else {
            output[i] = input[i];
        }
    }
}

int main() {
    char input[MAX_STR], output[MAX_STR];
    int shift;

    printf("Enter a string: ");
    fgets(input, MAX_STR, stdin);
    input[strcspn(input, "\n")] = '\0';

    printf("Enter a shift value: ");
    scanf("%d", &shift);

    encrypt(input, output, shift);

    printf("Original string: %s\n", input);
    printf("Encrypted string: %s\n", output);

    return 0;
}