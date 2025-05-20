//FormAI DATASET v1.0 Category: Modern Encryption ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 100
#define KEY_LEN 16

char key[KEY_LEN+1]; // 16 character key

void generate_key() {
    int i;
    srand(time(0)); // initialize random seed

    // generate random key using printable ASCII characters
    for (i = 0; i < KEY_LEN; i++) {
        key[i] = rand() % 94 + 32; // generate random number between 32 and 126
    }
    key[KEY_LEN] = '\0';
}

void encrypt(char *input_str, char *output_str) {
    int i;
    for (i = 0; i < strlen(input_str); i++) {
        output_str[i] = input_str[i] ^ key[i % KEY_LEN];
    }
    output_str[i] = '\0';
}

void decrypt(char *input_str, char *output_str) {
    int i;
    for (i = 0; i < strlen(input_str); i++) {
        output_str[i] = input_str[i] ^ key[i % KEY_LEN];
    }
    output_str[i] = '\0';
}

int main() {
    char input_str[MAX_STR_LEN+1], encrypted_str[MAX_STR_LEN+1], decrypted_str[MAX_STR_LEN+1];
    int choice;

    generate_key();

    printf("Enter input string: ");
    fgets(input_str, MAX_STR_LEN, stdin);
    input_str[strcspn(input_str, "\n")] = '\0'; // remove newline character from input string

    printf("Choose an option:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);
    getchar(); // to consume newline character left by scanf

    if (choice == 1) {
        encrypt(input_str, encrypted_str);
        printf("Encrypted string: %s\n", encrypted_str);
    } else if (choice == 2) {
        decrypt(input_str, decrypted_str);
        printf("Decrypted string: %s\n", decrypted_str);
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}