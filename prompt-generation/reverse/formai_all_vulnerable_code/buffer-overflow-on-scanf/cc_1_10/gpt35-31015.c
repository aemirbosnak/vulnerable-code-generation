//FormAI DATASET v1.0 Category: File Encyptor ; Style: configurable
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
  
void encrypt(char* file_name, int key) 
{ 
    FILE* fp = fopen(file_name, "rb+"); 
    char ch; 
    while (fread(&ch, sizeof(char), 1, fp) == 1) 
    { 
        ch = ch + key; 
        fseek(fp, -1, SEEK_CUR); 
        fwrite(&ch, sizeof(char), 1, fp); 
        fseek(fp, 0, SEEK_CUR); 
    } 
    fclose(fp); 
} 
  
void decrypt(char* file_name, int key) 
{ 
    FILE* fp = fopen(file_name, "rb+"); 
    char ch; 
    while (fread(&ch, sizeof(char), 1, fp) == 1) 
    { 
        ch = ch - key; 
        fseek(fp, -1, SEEK_CUR); 
        fwrite(&ch, sizeof(char), 1, fp); 
        fseek(fp, 0, SEEK_CUR); 
    } 
    fclose(fp); 
} 
  
int main() 
{ 
    char file_name[20]; 
    int key; 
    int choice; 
  
    //Prompt user for input 
    printf("-------------FILE ENCRYPTOR/DECRYPTOR-------------\n"); 
    printf("Enter file name:"); 
    scanf("%s", file_name); 
    printf("Enter key:"); 
    scanf("%d", &key); 
    
    printf("1. Encrypt the file.\n"); 
    printf("2. Decrypt the file.\n"); 
    printf("Enter your choice:"); 
    scanf("%d", &choice); 
  
    switch (choice) 
    { 
        case 1: 
            encrypt(file_name, key); 
            printf("File encrypted successfully!\n"); 
            break; 
        
        case 2: 
            decrypt(file_name, key); 
            printf("File decrypted successfully!\n"); 
            break; 
        
        default: 
            printf("Invalid choice! Please try again.\n"); 
    } 
    return 0; 
}