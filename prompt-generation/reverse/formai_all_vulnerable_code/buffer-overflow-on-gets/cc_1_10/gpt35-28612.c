//FormAI DATASET v1.0 Category: Encryption ; Style: content
#include<stdio.h>
#include<string.h>

//function to encrypt the given string
void encrypt(char *str){
    //length of string
    int len = strlen(str);
    //loop to iterate over each character of the string
    for(int i=0; i<len; i++){
        //if the current character is a lowercase letter
        if(str[i]>='a' && str[i]<='z'){
            //shift the character by 3 places to the right
            str[i] = (char)(((int)str[i] - 97 + 3) % 26 + 97);
        }
        //if the current character is an uppercase letter
        else if(str[i]>='A' && str[i]<='Z'){
            //shift the character by 3 places to the right
            str[i] = (char)(((int)str[i] - 65 + 3) % 26 + 65);
        }
        //if the current character is a digit
        else if(str[i]>='0' && str[i]<='9'){
            //shift the character by 3 places to the right
            str[i] = (char)(((int)str[i] - 48 + 3) % 10 + 48);
        }
    }
}

//function to decrypt the given string
void decrypt(char *str){
    //length of string
    int len = strlen(str);
    //loop to iterate over each character of the string
    for(int i=0; i<len; i++){
        //if the current character is a lowercase letter
        if(str[i]>='a' && str[i]<='z'){
            //shift the character by 3 places to the left
            str[i] = (char)(((int)str[i] - 97 - 3 + 26) % 26 + 97);
        }
        //if the current character is an uppercase letter
        else if(str[i]>='A' && str[i]<='Z'){
            //shift the character by 3 places to the left
            str[i] = (char)(((int)str[i] - 65 - 3 + 26) % 26 + 65);
        }
        //if the current character is a digit
        else if(str[i]>='0' && str[i]<='9'){
            //shift the character by 3 places to the left
            str[i] = (char)(((int)str[i] - 48 - 3 + 10) % 10 + 48);
        }
    }
}

int main(){
    //input string to be encrypted
    char str[100];
    printf("Enter a string to be encrypted: ");
    gets(str);
    //encrypt the given string
    encrypt(str);
    printf("Encrypted string is: %s\n", str);
    //decrypt the given string
    decrypt(str);
    printf("Decrypted string is: %s\n", str);
    return 0;
}