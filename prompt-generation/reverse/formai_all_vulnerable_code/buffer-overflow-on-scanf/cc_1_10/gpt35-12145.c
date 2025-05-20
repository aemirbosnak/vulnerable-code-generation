//FormAI DATASET v1.0 Category: Modern Encryption ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char *generate_key();
char *encrypt(char *plain_text, char *key);
char *decrypt(char *cipher_text, char *key);

int main(){

    char plain_text[1000],cipher_text[1000],key[50];
    int choice;

    while(1){
        printf("\n1. Encrypt Message\n");
        printf("2. Decrypt Message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        getchar();

        switch(choice){

            case 1:
            printf("\nEnter the Message to be encrypted:\n");
            scanf("%[^\n]s",plain_text);
            getchar();

            strcpy(key,generate_key());
            printf("Key for Encryption: %s\n",key);
            strcpy(cipher_text,encrypt(plain_text,key));
            printf("Encrypted Message: %s\n",cipher_text);
            break;

            case 2:
            printf("\nEnter the Message to be decrypted:\n");
            scanf("%[^\n]s",cipher_text);
            getchar();

            printf("Enter the Key for Decryption: ");
            scanf("%s",key);

            strcpy(plain_text,decrypt(cipher_text,key));
            printf("Decrypted Message: %s\n",plain_text);
            break;

            case 3:
            printf("Exiting..");
            exit(0);

            default:
            printf("Invalid choice!");
            break;
        }
    }
    return 0;
}

char *generate_key(){
    char *key = (char*)malloc(25*sizeof(char));

    srand(time(NULL));

    for(int i=0; i<25; i++){
        key[i] = (char)(rand()%26+65);
    }
    return key;
}

char *encrypt(char *plain_text, char *key){
    int len = strlen(plain_text);
    char *cipher_text = (char*)malloc((len+1)*sizeof(char));

    for(int i=0; i<len; i++){
        char c = plain_text[i];
        int shift = ((int)key[i])-65;
        char new_char;

        if(c>=65 && c<=90){
            new_char = (char) ((((int)c - 65 + shift) % 26) + 65);
        }
        else if(c>=97 && c<=122){
            new_char = (char) ((((int)c - 97 + shift) % 26) + 97);
        }
        else{
            new_char = c;
        }
        cipher_text[i] = new_char;
    }
    cipher_text[len] = '\0';
    return cipher_text;
}

char *decrypt(char *cipher_text, char *key){
    int len = strlen(cipher_text);
    char *plain_text = (char*)malloc((len+1)*sizeof(char));

    for(int i=0; i<len; i++){
        char c = cipher_text[i];
        int shift = ((int)key[i])-65;
        char new_char;

        if(c>=65 && c<=90){
            new_char = (char) ((((int)c - 65 - shift +26) % 26) + 65);
        }
        else if(c>=97 && c<=122){
            new_char = (char) ((((int)c - 97 - shift + 26) % 26) + 97);
        }
        else{
            new_char = c;
        }
        plain_text[i] = new_char;
    }
    plain_text[len] = '\0';
    return plain_text;
}