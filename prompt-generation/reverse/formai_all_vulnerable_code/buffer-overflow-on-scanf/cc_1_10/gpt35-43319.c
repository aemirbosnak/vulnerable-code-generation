//FormAI DATASET v1.0 Category: Encryption ; Style: expert-level
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

//Function to perform encryption
void encrypt(char *text, int key){
    char encrypted_text[1000]; //define encrypted text array
    int k = strlen(text);
    for(int i=0;i<k;i++){
        if(isalpha(text[i])){ //check if character is alphabetical
            if(isupper(text[i])){ //check if character is uppercase
                encrypted_text[i] = (text[i] + key - 65) % 26 + 65;
            }
            else{ //if character is lowercase
                encrypted_text[i] = (text[i] + key - 97) % 26 + 97;
            }
        }
        else{ //if character is not alphabetical
            encrypted_text[i] = text[i];
        }
    }
    printf("\nEncrypted Text: ");
    for(int i=0;i<k;i++){
        printf("%c",encrypted_text[i]);
    }
}

int main(){
    char text[1000]; //define text array
    int key;
    
    printf("Enter text: ");
    fgets(text,1000,stdin); //read input string
    
    //Removing trailing newline character added by fgets()
    int pos = strlen(text)-1; 
    if(text[pos]=='\n'){
        text[pos] = '\0';
    }
    
    printf("\nEnter key: ");
    scanf("%d",&key); //read encryption key
    
    //Calling encryption function
    encrypt(text,key);
    
    return 0;
}