//FormAI DATASET v1.0 Category: File Encyptor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// encrypt function
void encrypt(char filename[], char key[]) {
    FILE *fpin, *fpout;
    char ch;
    int i = 0, j = 0, k = 0;
    int length = strlen(key);
    
    fpin = fopen(filename, "r");
    if(fpin == NULL) {
        printf("Error: cannot open file.\n");
        exit(1);
    }
    
    // create output file
    char outputFilename[50];
    strcpy(outputFilename, "encrypted_");
    strcat(outputFilename, filename);
    fpout = fopen(outputFilename, "w+");
    if(fpout == NULL) {
        printf("Error: cannot create output file.\n");
        fclose(fpin);
        exit(1);
    }
    
    // encrypt file
    while((ch = fgetc(fpin)) != EOF) {
        if(j == length) {
            j = 0;
            k++;
        }
        i = (int)ch ^ (int)key[j];
        fprintf(fpout, "%c", (char)i);
        j++;
    }
    
    // close files
    fclose(fpin);
    fclose(fpout);
    
    printf("Encryption complete.\n");
}

int main() {
    // file to encrypt
    char filename[50];
    printf("Enter filename to encrypt: ");
    scanf("%s", filename);
    
    // encryption key
    char key[50];
    printf("Enter encryption key: ");
    scanf("%s", key);
    
    encrypt(filename, key);
    
    return 0;
}