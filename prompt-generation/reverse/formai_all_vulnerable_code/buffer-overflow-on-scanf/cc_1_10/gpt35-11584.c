//FormAI DATASET v1.0 Category: File Encyptor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
This program is a C File Encryptor that uses XOR encryption.
It takes the name of the input file and a password from the user
and produces the encrypted file with a .enc extension in the same directory.
*/

void encrypt(FILE *inputFile, FILE *outputFile, char *password) {
    int passwordLength = strlen(password);
    int i = 0;
    char byte;
    
    while (fread(&byte, 1, 1, inputFile)) {
        byte = byte ^ password[i % passwordLength];
        fwrite(&byte, 1, 1, outputFile);
        i++;
    }
}

int main() {
    char inputFile[100];
    char outputFile[100];
    char password[100];
    
    printf("Enter the name of the input file: ");
    scanf("%s", inputFile);
    
    FILE *input = fopen(inputFile, "rb");
    if (input == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    
    printf("Enter the password: ");
    scanf("%s", password);
    
    printf("Enter the name of the output file: ");
    scanf("%s", outputFile);
    
    strcat(outputFile, ".enc");
    
    FILE *output = fopen(outputFile, "wb");
    if (output == NULL) {
        fclose(input);
        printf("Error opening output file.\n");
        return 1;
    }
    
    encrypt(input, output, password);
    
    fclose(input);
    fclose(output);
    
    printf("Encryption complete. Output file: %s\n", outputFile);
    
    return 0;
}