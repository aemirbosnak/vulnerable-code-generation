//FormAI DATASET v1.0 Category: File Encyptor ; Style: interoperable
//This program is a simple file encryptor using a Caesar Cipher encryption algorithm.
#include <stdio.h>
#include <stdlib.h>

//Function for encrypting the file using Caesar Cipher.
void encrypt(char* file_path, int key){
    //Define variables for file handling.
    FILE *file_ptr;
    FILE *encrypted_file_ptr;
    char ch;
    
    //Open the original file for reading.
    file_ptr = fopen(file_path, "r");
    
    //Open a new file for writing the encrypted contents.
    encrypted_file_ptr = fopen("encrypted_file.txt", "w");
    
    //Iterate through each character of the original file.
    while((ch = fgetc(file_ptr)) != EOF){
        //Encrypt the character using the Caesar Cipher algorithm.
        if(ch >= 'a' && ch <= 'z'){
            ch = (ch + key - 'a') % 26 + 'a';
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = (ch + key - 'A') % 26 + 'A';
        }
        
        //Write the encrypted character to the new file.
        fputc(ch, encrypted_file_ptr);
    }
    
    //Close both files.
    fclose(file_ptr);
    fclose(encrypted_file_ptr);
}

//Function for decrypting the file using Caesar Cipher.
void decrypt(char* file_path, int key){
    //Define variables for file handling.
    FILE *enc_file_ptr;
    FILE *decrypted_file_ptr;
    char ch;
    
    //Open the encrypted file for reading.
    enc_file_ptr = fopen(file_path, "r");
    
    //Open a new file for writing the decrypted contents.
    decrypted_file_ptr = fopen("decrypted_file.txt", "w");
    
    //Iterate through each character of the encrypted file.
    while((ch = fgetc(enc_file_ptr)) != EOF){
        //Decrypt the character using the Caesar Cipher algorithm.
        if(ch >= 'a' && ch <= 'z'){
            ch = (ch - key - 'a' + 26) % 26 + 'a';
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = (ch - key - 'A' + 26) % 26 + 'A';
        }
        
        //Write the decrypted character to the new file.
        fputc(ch, decrypted_file_ptr);
    }
    
    //Close both files.
    fclose(enc_file_ptr);
    fclose(decrypted_file_ptr);
}

int main(){
    char file_path[100];
    int key;

    //Get the file path and encryption key from user.
    printf("Enter the file path: ");
    scanf("%s", file_path);
    printf("Enter the encryption key: ");
    scanf("%d", &key);
    
    //Encrypt the file and display the encrypted contents.
    printf("Encrypted file contents:\n");
    encrypt(file_path, key);
    FILE* encrypted_file_ptr = fopen("encrypted_file.txt", "r");
    char ch;
    while((ch = fgetc(encrypted_file_ptr)) != EOF){
        printf("%c", ch);
    }
    printf("\n");
    fclose(encrypted_file_ptr);
    
    //Decrypt the file and display the decrypted contents.
    printf("Decrypted file contents:\n");
    decrypt("encrypted_file.txt", key);
    FILE* decrypted_file_ptr = fopen("decrypted_file.txt", "r");
    while((ch = fgetc(decrypted_file_ptr)) != EOF){
        printf("%c", ch);
    }
    printf("\n");
    fclose(decrypted_file_ptr);
    
    return 0;
}