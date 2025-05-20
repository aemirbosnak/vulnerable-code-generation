//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void encrypt_file(const char *input_file, const char *output_file);
void decrypt_file(const char *input_file, const char *output_file);
char simple_cipher(char c);

int main() {
    char choice;
    char input_file[256], output_file[256];

    // Welcome to the Funny File Encryptor
    printf("Welcome to the FUN-tastic File Encryptor! 🎉\n");
    printf("Are you ready to encrypt some top secret files? (Y/N): ");
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y') {
        printf("Enter the name of the file you want to encrypt (e.g., secret.txt): ");
        scanf("%s", input_file);
        printf("Enter the name for the encrypted file (e.g., secret_enc.txt): ");
        scanf("%s", output_file);
        encrypt_file(input_file, output_file);
        printf("The file %s has been encrypted to %s. 🤐\n", input_file, output_file);
    } else {
        printf("Okay! Maybe next time! 😢\n");
        return 0;
    }

    printf("Now, would you like to decrypt? (Y/N): ");
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y') {
        printf("Enter the name of the file you want to decrypt (e.g., secret_enc.txt): ");
        scanf("%s", input_file);
        printf("Enter the name for the decrypted file (e.g., secret_dec.txt): ");
        scanf("%s", output_file);
        decrypt_file(input_file, output_file);
        printf("The file %s has been decrypted to %s. 🎉 You did it! 🎊\n", input_file, output_file);
    } else {
        printf("No decryption? Well, good luck with the mystery! 🕵️‍♂️\n");
    }

    return 0;
}

// A simple encryption algorithm (or the worst one you’ve ever seen!)
void encrypt_file(const char *input_file, const char *output_file) {
    FILE *ifp, *ofp;
    char ch;

    ifp = fopen(input_file, "r");
    if (ifp == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    ofp = fopen(output_file, "w");
    if (ofp == NULL) {
        perror("Error opening output file");
        fclose(ifp);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(ifp)) != EOF) {
        fputc(simple_cipher(ch), ofp);
    }

    fclose(ifp);
    fclose(ofp);
}

// A simple decryption algorithm that is just as amusing
void decrypt_file(const char *input_file, const char *output_file) {
    FILE *ifp, *ofp;
    char ch;

    ifp = fopen(input_file, "r");
    if (ifp == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    ofp = fopen(output_file, "w");
    if (ofp == NULL) {
        perror("Error opening output file");
        fclose(ifp);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(ifp)) != EOF) {
        fputc(simple_cipher(ch), ofp);
    }

    fclose(ifp);
    fclose(ofp);
}

// A very silly cipher: it just adds 1 to the ASCII value.
char simple_cipher(char c) {
    // Turning our input into a jelly bean!
    return c + 1;
}