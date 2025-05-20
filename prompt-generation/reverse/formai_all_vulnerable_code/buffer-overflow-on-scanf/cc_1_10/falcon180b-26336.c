//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

//Function to encrypt the file
void encrypt(FILE *fp) {
    char ch, key = 'k';
    int i;

    //Reading file character by character
    while ((ch = fgetc(fp))!= EOF) {
        //Encrypting uppercase characters
        if (isupper(ch)) {
            ch = ch + key;
        }
        //Encrypting lowercase characters
        else if (islower(ch)) {
            ch = ch - key;
        }
        else {
            ch = ch;
        }
        //Writing encrypted character to file
        fputc(ch, fp);
    }
}

//Function to decrypt the file
void decrypt(FILE *fp) {
    char ch, key = 'k';
    int i;

    //Reading file character by character
    while ((ch = fgetc(fp))!= EOF) {
        //Decrypting uppercase characters
        if (isupper(ch)) {
            ch = ch - key;
        }
        //Decrypting lowercase characters
        else if (islower(ch)) {
            ch = ch + key;
        }
        else {
            ch = ch;
        }
        //Writing decrypted character to file
        fputc(ch, fp);
    }
}

//Function to open file
FILE *openFile(char *filename) {
    FILE *fp;

    //Opening file in read mode
    fp = fopen(filename, "r");

    //Checking if file is opened successfully
    if (fp == NULL) {
        printf("Error in opening file\n");
        exit(1);
    }

    return fp;
}

//Function to close file
void closeFile(FILE *fp) {
    fclose(fp);
}

int main() {
    char filename[SIZE], choice;
    FILE *fp;

    //Taking input from user
    printf("Enter the filename: ");
    scanf("%s", filename);

    //Opening file in read mode
    fp = openFile(filename);

    //Encrypting the file
    printf("Enter 1 to encrypt the file\n");
    scanf("%c", &choice);

    if (choice == '1') {
        encrypt(fp);
        printf("File encrypted successfully\n");
    }

    //Decrypting the file
    printf("Enter 2 to decrypt the file\n");
    scanf("%c", &choice);

    if (choice == '2') {
        rewind(fp);
        decrypt(fp);
        printf("File decrypted successfully\n");
    }

    //Closing file
    closeFile(fp);

    return 0;
}