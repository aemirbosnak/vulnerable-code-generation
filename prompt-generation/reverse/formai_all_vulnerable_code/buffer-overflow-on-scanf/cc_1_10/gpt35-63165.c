//FormAI DATASET v1.0 Category: File Encyptor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 256
#define MAX_KEY_SIZE 256
#define BUFFER_SIZE 1024

void encryptFile(FILE* inputFile, FILE* outputFile, char* key) {
    int i = 0;
    int keyLength = strlen(key);

    char buffer[BUFFER_SIZE];
    
    while (fgets(buffer, BUFFER_SIZE, inputFile) != NULL) {
        int bufferLength = strlen(buffer);
        
        for (i = 0; i < bufferLength; i++) {
            buffer[i] = buffer[i] ^ key[i % keyLength];
        }
        
        fputs(buffer, outputFile);
    }
}

int main() {
    char inputFilename[MAX_FILENAME_SIZE];
    char outputFilename[MAX_FILENAME_SIZE];
    char key[MAX_KEY_SIZE];
    char confirmation = 'n';
    
    printf("Enter the filename to encrypt: ");    
    scanf("%s", inputFilename);
    
    FILE* inputFile = fopen(inputFilename, "r");
    
    if (inputFile == NULL) {
        printf("Could not open file for reading.\n");
        return -1;
    }
    
    printf("Enter the filename to save the encrypted content: ");
    scanf("%s", outputFilename);
    
    FILE* outputFile = fopen(outputFilename, "w");
    
    if (outputFile == NULL) {
        printf("Could not open file for writing.\n");
        fclose(inputFile);
        return -1;
    }
    
    printf("Enter the encryption key: ");
    scanf("%s", key);
    
    printf("Are you sure you want to encrypt %s with key '%s'? (y/n): ", inputFilename, key);
    scanf(" %c", &confirmation);
    
    if (confirmation != 'y' && confirmation != 'Y') {
        fclose(inputFile);
        fclose(outputFile);
        
        return 0;
    }
    
    encryptFile(inputFile, outputFile, key);
    
    printf("Encryption complete.\n");
    
    fclose(inputFile);
    fclose(outputFile);
    
    return 0;
}