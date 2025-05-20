//FormAI DATASET v1.0 Category: File Encyptor ; Style: innovative
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

// Function to encrypt a character
char encryptChar(char c, int key){
    if(isalpha(c)){
        if(isupper(c)){
            return ((c-'A'+key)%26)+'A';
        }else{
            return ((c-'a'+key)%26)+'a';
        }
    }else{
        return c;
    }
}

// Function to encrypt a file
void encryptFile(FILE* inputFile, FILE* outputFile, int key){
    char c;
    while((c = fgetc(inputFile)) != EOF){
        fputc(encryptChar(c, key), outputFile);
    }
}

int main(){
    FILE *inputFile, *outputFile;
    char inputName[50], outputName[50];
    int key;
    
    // Take input file and output file names
    printf("Enter input file name: ");
    scanf("%s", inputName);
    printf("\nEnter output file name: ");
    scanf("%s", outputName);
    
    // Open files in read and write mode
    inputFile = fopen(inputName, "r");
    if(inputFile == NULL){
        printf("Error opening input file.");
        exit(0);
    }
    
    outputFile = fopen(outputName, "w");
    if(outputFile == NULL){
        fclose(inputFile);
        printf("Error opening output file.");
        exit(0);
    }
    
    // Take encryption key input
    printf("\nEnter encryption key: ");
    scanf("%d", &key);
    
    // Encrypt the file and close the files
    encryptFile(inputFile, outputFile, key);
    fclose(inputFile);
    fclose(outputFile);
    
    printf("\nFile encrypted successfully!");
    return 0;
}