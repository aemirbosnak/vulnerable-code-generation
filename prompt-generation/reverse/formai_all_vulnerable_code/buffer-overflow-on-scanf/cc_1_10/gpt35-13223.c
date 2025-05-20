//FormAI DATASET v1.0 Category: File Encyptor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input_file, char *output_file) {
    FILE *ifp, *ofp;
    int key = 3; // Caesar's Cipher key
    char ch;
    
    ifp = fopen(input_file, "r");
    ofp = fopen(output_file, "w");
    
    if (!ifp || !ofp) {
        printf("File could not be opened.\n");
        exit(1);
    }
    
    while ((ch = fgetc(ifp)) != EOF) {
        ch = ch + key; // encryption
        fputc(ch, ofp);
    }
    
    printf("Encryption successful!\n");
    fclose(ifp);
    fclose(ofp);
}

void decrypt(char *input_file, char *output_file) {
    FILE *ifp, *ofp;
    int key = 3;
    char ch;
    
    ifp = fopen(input_file, "r");
    ofp = fopen(output_file, "w");
    
    if (!ifp || !ofp) {
        printf("File could not be opened.\n");
        exit(1);
    }
    
    while ((ch = fgetc(ifp)) != EOF) {
        ch = ch - key; // decryption
        fputc(ch, ofp);
    }
    
    printf("Decryption successful!\n");
    fclose(ifp);
    fclose(ofp);
}

int main() {
    char input_file[50], output_file[50], choice;
    
    printf("Enter the name of the file to be encrypted:\n");
    scanf("%s", input_file);
    
    printf("Enter the name of the output file:\n");
    scanf("%s", output_file);
    
    encrypt(input_file, output_file);
    
    printf("Do you want to decrypt the file? (Y/N)\n");
    scanf(" %c", &choice);
    
    if (choice == 'Y' || choice == 'y') {
        decrypt(output_file, "decrypted.txt");
    }
    
    return 0;
}