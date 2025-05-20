//FormAI DATASET v1.0 Category: Encryption ; Style: Sherlock Holmes
//The Case of the Cryptic Code - A Sherlock Holmes Style Encryption Program

#include<stdio.h>
#include<string.h>
#include<ctype.h>

//Function to encrypt the message using a modified Caesar Cipher
char* encryptMessage(char* message, int shift){
    int i;
    char encryptedMessage[1000];

    //Shifting each alphabet by the specified shift value
    for(i=0; message[i]!='\0'; i++){
        if(isalpha(message[i])){
            if(isupper(message[i])) //For Upper-case alphabets
                encryptedMessage[i] = ((message[i] - 'A') + shift) % 26 + 'A';
            else  //For Lower-case alphabets
                encryptedMessage[i] = ((message[i] - 'a') + shift) % 26 + 'a';
        }
        else  //For all other characters
            encryptedMessage[i] = message[i];
    }
    encryptedMessage[i] = '\0';

    //Printing the encrypted message
    printf("The encrypted message is: %s\n", encryptedMessage);

    //Returning the encrypted message
    return encryptedMessage;
}

//Function to decrypt the message using the same shift value
void decryptMessage(char* message, int shift){
    int i;
    char decryptedMessage[1000];

    //Shifting each alphabet in the opposite direction
    for(i=0; message[i]!='\0'; i++){
        if(isalpha(message[i])){
            if(isupper(message[i])) //For Upper-case alphabets
                decryptedMessage[i] = ((message[i] - 'A') - shift + 26) % 26 + 'A';
            else  //For Lower-case alphabets
                decryptedMessage[i] = ((message[i] - 'a') - shift + 26) % 26 + 'a';
        }
        else  //For all other characters
            decryptedMessage[i] = message[i];
    }
    decryptedMessage[i] = '\0';

    //Printing the decrypted message
    printf("The decrypted message is: %s\n", decryptedMessage);
}

int main(){
    char message[1000];
    int shift;

    printf("Welcome to the case of the cryptic code!\n");

    //Prompting the user to input the message
    printf("\nPlease enter the message you want to encrypt: ");
    fgets(message, sizeof(message), stdin);

    //Prompting the user to input the shift value
    printf("Please enter the shift value for encryption: ");
    scanf("%d", &shift);

    //Calling the encryption function
    char* encrypted_message = encryptMessage(message, shift);

    //Prompting the user to decrypt the message
    printf("\nWould you like to decrypt the message? [y/n]: ");
    char choice;
    scanf(" %c", &choice);

    //If user wants to decrypt the message
    if(tolower(choice) == 'y')
        decryptMessage(encrypted_message, shift);

    printf("\nThank you for using the Cryptography Program!\n");

    return 0;  
}