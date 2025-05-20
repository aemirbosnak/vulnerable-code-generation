//FormAI DATASET v1.0 Category: Modern Encryption ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<math.h> 

void encrypt(char* str, int key) 
{ 
    int len = strlen(str), i; 
    int rows = key, columns = ceil(len/(float)key), k = 0; 
    char matrix[rows][columns]; 
  
    for (i = 0; i < columns; i++) 
        for (int j = 0; j < rows; j++) 
            matrix[j][i] = str[k++]; 
  
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < columns; j++) 
            if (matrix[i][j]) 
                printf("%c", matrix[i][j]); 
            else
                printf(" "); 
} 

void decrypt(char* cipher, int key) 
{ 
    int len = strlen(cipher), i; 
    int rows = key, columns = ceil(len/(float)key), k = 0; 
    char matrix[rows][columns]; 
  
    for (i = 0; i < rows; i++) 
        for (int j = 0; j < columns; j++) 
            matrix[i][j] = cipher[k++]; 
  
    for (int i = 0; i < columns; i++) 
        for (int j = 0; j < rows; j++) 
            if (matrix[j][i]) 
                printf("%c", matrix[j][i]); 
} 

int main() 
{ 
    char str[100], cipher[100]; 
    int key;

    printf("Enter the string to be encrypted: ");
    scanf("%[^\n]s", str);
    printf("Enter the key to encrypt: ");
    scanf("%d", &key);

    printf("Encrypted text: ");
    encrypt(str, key);

    printf("\n\nEnter the text to be decrypted: ");
    scanf(" %[^\n]s", cipher);
    printf("Enter the key to decrypt: ");
    scanf("%d", &key);

    printf("Decrypted text: ");
    decrypt(cipher, key);

    return 0; 
}