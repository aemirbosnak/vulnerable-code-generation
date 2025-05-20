//FormAI DATASET v1.0 Category: Modern Encryption ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char message[100], encrypted[100], decrypted[100], ch;
    int i, key;

    printf("Enter message: ");
    fgets(message, 100, stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    /* Encryption */
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
    
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            
            encrypted[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            
            encrypted[i] = ch;
        }
        else{
            encrypted[i] = ch;
        }
    }
    
    encrypted[i] = '\0';
    
    printf("Encrypted message: %s\n", encrypted);
    
    /* Decryption */
    for(i = 0; encrypted[i] != '\0'; ++i){
        ch = encrypted[i];
        
        if(ch >= 'a' && ch <= 'z'){
            ch = ch - key;
            
            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            
            decrypted[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;
            
            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }
            
            decrypted[i] = ch;
        }
        else{
            decrypted[i] = ch;
        }
    }
    
    decrypted[i] = '\0';
    
    printf("Decrypted message: %s\n", decrypted);
    
    return 0;
}