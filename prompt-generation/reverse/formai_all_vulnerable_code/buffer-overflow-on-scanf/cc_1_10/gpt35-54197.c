//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 100

// Function to perform XOR encryption
void xor_encrypt(char *key, char *input_string) {
    int key_length = strlen(key);
    int input_length = strlen(input_string);
    int index = 0;

    for(int i = 0; i < input_length; i++) {
        input_string[i] = input_string[i] ^ key[index];
        index++;
        if(index == key_length)
            index = 0;
    }
}

// Function to perform Caesar cipher encryption
void caesar_encrypt(char *input_string, int shift) {
    int input_length = strlen(input_string);

    for(int i = 0; i < input_length; i++) {
        if(input_string[i] >= 'a' && input_string[i] <= 'z')
            input_string[i] = (input_string[i] + shift - 'a') % 26 + 'a';
        else if(input_string[i] >= 'A' && input_string[i] <= 'Z')
            input_string[i] = (input_string[i] + shift - 'A') % 26 + 'A';
    }
}

int main(void) {
    char input_string[MAX_STRING_LENGTH];
    char key[MAX_STRING_LENGTH];
    int shift;
    bool is_valid_shift = false;

    printf("Hello and welcome to the cheerful cryptography program!\n");
    printf("Please enter a string to encrypt: ");
    fgets(input_string, MAX_STRING_LENGTH, stdin);

    printf("Please enter a key to use for XOR encryption: ");
    fgets(key, MAX_STRING_LENGTH, stdin);

    xor_encrypt(key, input_string);

    // loop through until a valid shift value is entered
    while(!is_valid_shift) {
        printf("Please enter a shift value for Caesar cipher encryption (1-25): ");
        scanf("%d", &shift);
        getchar();

        if(shift >= 1 && shift <= 25)
            is_valid_shift = true;
        else
            printf("Invalid shift value entered. Please try again.\n");
    }

    caesar_encrypt(input_string, shift);

    printf("The encrypted string is: %s", input_string);

    return 0;
}