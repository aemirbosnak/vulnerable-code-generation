//FormAI DATASET v1.0 Category: File Encyptor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the input file
void encrypt(FILE* inputFile, FILE* outputFile, char* password) {
    // Initialize variables
    int i = 0, j = 0;
    char c, p;
    int passwordLen = strlen(password);

    // Read the file character by character
    while(fscanf(inputFile, "%c", &c) != EOF) {
        // Get the password character
        p = password[j];
        
        // XOR the file character with the password character
        c ^= p;

        // Write the encrypted character to the output file
        fprintf(outputFile, "%c", c);

        // Move to the next character in the password
        j++;
        if(j == passwordLen) {
            j = 0;
        }
    }
}

int main() {
    // Declare variables
    char inputFile[100], outputFile[100], password[100];
    FILE *input, *output;

    // Get the input file name from the user
    printf("Enter input file name: ");
    scanf("%s", inputFile);

    // Open the input file in read mode
    input = fopen(inputFile, "r");
    if(input == NULL) {
        printf("Could not open input file!\n");
        exit(1);
    }

    // Get the output file name from the user
    printf("Enter output file name: ");
    scanf("%s", outputFile);

    // Open the output file in write mode
    output = fopen(outputFile, "w");
    if(output == NULL) {
        printf("Could not open output file!\n");
        exit(1);
    }

    // Get the password from the user
    printf("Enter encryption password: ");
    scanf("%s", password);

    // Encrypt the input file and write the result to the output file
    encrypt(input, output, password);

    // Close the files
    fclose(input);
    fclose(output);

    printf("Encryption successful!\n");

    return 0;
}