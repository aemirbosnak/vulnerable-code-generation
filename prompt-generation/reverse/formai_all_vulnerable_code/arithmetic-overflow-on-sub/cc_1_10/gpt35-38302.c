//FormAI DATASET v1.0 Category: File Encyptor ; Style: relaxed
// Welcome to our unique C File Encryptor program!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key constant
#define KEY 10

// function to encrypt the text file
void encrypt(FILE* input, FILE* output) {
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        ch = ch + KEY;
        fputc(ch, output);
    }
}

// function to decrypt the text file
void decrypt(FILE* input, FILE* output) {
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        ch = ch - KEY;
        fputc(ch, output);
    }
}

int main() {
    char filename[100];
    FILE *fp1, *fp2;
    int choice;
    
    printf("Welcome to our File Encryptor program!\n");
    printf("Please enter the filename: ");
    scanf("%s", filename);
    
    fp1 = fopen(filename, "r");
    if (fp1 == NULL) {
        printf("Error: Unable to open the file.\n");
        exit(0);
    }

    fp2 = fopen("encrypted.txt", "w");
    encrypt(fp1, fp2);
    fclose(fp1);
    fclose(fp2);
    
    printf("File has been encrypted!\n");
    printf("Do you want to decrypt the file? (1 for yes/0 for no) ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        fp1 = fopen("encrypted.txt", "r");
        fp2 = fopen("decrypted.txt", "w");
        decrypt(fp1, fp2);
        fclose(fp1);
        fclose(fp2);
        printf("File has been decrypted!\n");
    }
    
    printf("Thank you for using our program!\n");
    
    return 0;
}