//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: mind-bending
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <string.h> 

#define MAX_LEN 100

int main() 
{ 
    
    char key[MAX_LEN]={0}, plain_text[MAX_LEN]={0}, cipher_text[MAX_LEN]={0};
    srand(time(0));
    
    printf("Enter key: ");
    scanf("%[^\n]s", key); 
  
    int key_len = strlen(key);
    int plain_text_len;
    
    printf("Enter plain text: ");
    scanf("%*c%[^\n]s", plain_text);
    
    plain_text_len = strlen(plain_text);
    
    int random_choice;
    int temp;
    int i = 0;
    
    for(int k = 0; k< key_len; k++)
    {
        random_choice = rand() % key_len;
        temp = key[k];
        key[k] = key[random_choice];
        key[random_choice] = temp;
    }
    
    printf("\n\nRandomized key: \n");
    
    for(int j=0; j < key_len; j++)
    {
        printf("%c", key[j]);
    }
    
    printf("\n\nEncrypting...\n\n");
    
    for(i=0;i<plain_text_len;++i)
    {
        if(plain_text[i] != ' ')
        {
            int j = i % key_len;
            
            int ascii = (plain_text[i] + key[j]) % 26 + 'a';          
            cipher_text[i] = ascii;
        }
        else
        {
            cipher_text[i] = ' ';
        }        
    }
    
    printf("Cipher text: %s\n\n", cipher_text);
    
    printf("\n\nDecrypting...\n\n");
    
    for(i=0;i<plain_text_len;++i)
    {
        if(cipher_text[i] != ' ')
        {
            int j = i % key_len;
            int ascii = ((cipher_text[i] - key[j] + 26) % 26) + 'a';   
            
            plain_text[i] = ascii;
        }
        else
        {
            plain_text[i] = ' ';
        }        
    }
    
    printf("Plain text: %s\n\n", plain_text);
    
    return 0; 
}