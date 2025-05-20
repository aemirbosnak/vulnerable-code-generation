//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

// Function to encrypt the file
void encrypt(FILE* input, FILE* output) {
    char line[MAX_LINE_LENGTH];
    int key = 13; // The key used for encryption (Romeo and Juliet's lucky number)

    while (fgets(line, MAX_LINE_LENGTH, input)!= NULL) {
        int i = 0;
        while (line[i]!= '\0') {
            if (isalpha(line[i])) {
                if (isupper(line[i])) {
                    line[i] = (line[i] + key - 65) % 26 + 65;
                } else {
                    line[i] = (line[i] + key - 97) % 26 + 97;
                }
            }
            i++;
        }
        fputs(line, output);
    }
}

// Function to decrypt the file
void decrypt(FILE* input, FILE* output) {
    char line[MAX_LINE_LENGTH];
    int key = 13; // The key used for decryption (Romeo and Juliet's lucky number)

    while (fgets(line, MAX_LINE_LENGTH, input)!= NULL) {
        int i = 0;
        while (line[i]!= '\0') {
            if (isalpha(line[i])) {
                if (isupper(line[i])) {
                    line[i] = (line[i] - key - 65) % 26 + 65;
                } else {
                    line[i] = (line[i] - key - 97) % 26 + 97;
                }
            }
            i++;
        }
        fputs(line, output);
    }
}

int main() {
    char inputFile[100];
    char outputFile[100];
    printf("Enter the name of the input file: ");
    scanf("%s", inputFile);
    printf("Enter the name of the output file: ");
    scanf("%s", outputFile);

    FILE* input = fopen(inputFile, "r");
    if (input == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    FILE* output = fopen(outputFile, "w");
    if (output == NULL) {
        printf("Error opening output file.\n");
        fclose(input);
        exit(1);
    }

    int choice;
    printf("Enter 1 to encrypt the file or 2 to decrypt the file: ");
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt(input, output);
        printf("File encrypted successfully.\n");
    } else if (choice == 2) {
        decrypt(input, output);
        printf("File decrypted successfully.\n");
    } else {
        printf("Invalid choice.\n");
    }

    fclose(input);
    fclose(output);

    return 0;
}