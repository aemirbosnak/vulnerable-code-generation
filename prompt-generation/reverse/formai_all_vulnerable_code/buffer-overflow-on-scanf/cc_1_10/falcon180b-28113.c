//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define KEY_LENGTH 16

void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_LENGTH] = '\0';
}

void encrypt(char *message, char *key) {
    int i, j;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = tolower(message[i]);
            j = (int) message[i] - 97;
            j = (j + (int) key[i % KEY_LENGTH]) % 26;
            message[i] = j + 'a';
        }
    }
}

void decrypt(char *message, char *key) {
    int i, j;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = tolower(message[i]);
            j = (int) message[i] - 97;
            j = (26 - j - (int) key[i % KEY_LENGTH]) % 26;
            message[i] = j + 'a';
        }
    }
}

int main() {
    FILE *input_file, *output_file;
    char message[MAX_LINE_LENGTH];
    char key[KEY_LENGTH];
    char choice;
    int i;

    printf("Welcome to the C File Encryptor!\n");

    printf("Enter the name of the input file: ");
    scanf("%s", message);

    input_file = fopen(message, "r");

    if (input_file == NULL) {
        printf("Error: Input file not found.\n");
        return 1;
    }

    printf("Enter the name of the output file: ");
    scanf("%s", message);

    output_file = fopen(message, "w");

    if (output_file == NULL) {
        printf("Error: Output file could not be created.\n");
        return 1;
    }

    printf("Do you want to encrypt or decrypt the file? (E/D): ");
    scanf(" %c", &choice);

    if (choice == 'E' || choice == 'e') {
        generate_key(key);
        printf("Encryption key: %s\n", key);

        while (fgets(message, MAX_LINE_LENGTH, input_file)!= NULL) {
            encrypt(message, key);
            fprintf(output_file, "%s", message);
        }
    } else if (choice == 'D' || choice == 'd') {
        printf("Enter the encryption key: ");
        scanf("%s", key);

        while (fgets(message, MAX_LINE_LENGTH, input_file)!= NULL) {
            decrypt(message, key);
            fprintf(output_file, "%s", message);
        }
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    fclose(input_file);
    fclose(output_file);

    printf("File encrypted/decrypted successfully!\n");

    return 0;
}