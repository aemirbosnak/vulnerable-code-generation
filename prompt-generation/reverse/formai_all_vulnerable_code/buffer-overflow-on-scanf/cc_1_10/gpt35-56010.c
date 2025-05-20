//FormAI DATASET v1.0 Category: Encryption ; Style: curious
#include<stdio.h>
#include<string.h>

// function to encrypt the string
void encrypt(char message[]){
    int i, length=strlen(message);
    for(i=0; i<length; i++){
        if(message[i]>=65 && message[i]<=90){
            message[i]=90-message[i]+65;
        }
        else if(message[i]>=97 && message[i]<=122){
            message[i]=122-message[i]+97;
        }
    }
}

// function to decrypt the string
void decrypt(char message[]){
    int i, length=strlen(message);
    for(i=0; i<length; i++){
        if(message[i]>=65 && message[i]<=90){
            message[i]=90-message[i]+65;
        }
        else if(message[i]>=97 && message[i]<=122){
            message[i]=122-message[i]+97;
        }
    }
}

// main function
int main(){
    char message[100];
    printf("Enter the message to encrypt:");
    scanf("%[^\n]s",message);
    encrypt(message);
    printf("Encrypted Message: %s\n",message);

    printf("Do you want to decrypt this message? (y/n) : ");
    char choice;
    scanf(" %c",&choice);
    if(choice=='y' || choice=='Y'){
        decrypt(message);
        printf("Decrypted Message: %s\n",message);
    }
    else{
        printf("Okay, goodbye!\n");
    }

    return 0;
}