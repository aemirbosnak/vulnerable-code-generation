//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to encrypt the file
void encryptFile(FILE *file){
    char ch;
    int key = 3;
    while((ch = fgetc(file))!= EOF){
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            if(ch > 'z'){
                ch = ch - 26;
            }
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            if(ch > 'Z'){
                ch = ch - 26;
            }
        }
        fputc(ch, file);
    }
}

int main(){
    FILE *file;
    char filename[100];
    printf("Enter the name of the file to be encrypted: ");
    scanf("%s", filename);

    // Open the file in read-write mode
    file = fopen(filename, "r+");

    if(file == NULL){
        printf("File not found\n");
        exit(0);
    }

    // Seek to the beginning of file
    fseek(file, 0, SEEK_SET);

    // Encrypt the file
    encryptFile(file);

    // Close the file
    fclose(file);

    printf("File encrypted successfully\n");
    return 0;
}