//FormAI DATASET v1.0 Category: Modern Encryption ; Style: satisfied
#include<stdio.h>
#include<string.h>

void encryption(char input[], int key){
    int i;
    for(i=0; i<strlen(input); i++){
        char ch= input[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            input[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            input[i] = ch;
        }
    }
}

void decryption(char input[], int key){
    int i;
    for(i=0; i<strlen(input); i++){
        char ch= input[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch - key;
            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            input[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;
            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }
            input[i] = ch;
        }
    }
}

int main(){
    char input[100], ch;
    int key, choice;
    
    printf("Select an option:\n");
    printf("1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);
    
    switch(choice){
        
        case 1:
            printf("Enter a string to encrypt: ");
            scanf(" %[^\n]s", input);
            printf("Enter a key value: ");
            scanf("%d", &key);
            encryption(input, key);
            printf("The encrypted string is: %s", input);
            break;
            
        case 2:
            printf("Enter a string to decrypt: ");
            scanf(" %[^\n]s", input);
            printf("Enter the key value: ");
            scanf("%d", &key);
            decryption(input, key);
            printf("The decrypted string is: %s", input);
            break;
            
        default:
            printf("Invalid input!");
    }
    
    return 0;
}