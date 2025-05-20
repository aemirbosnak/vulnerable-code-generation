//FormAI DATASET v1.0 Category: Modern Encryption ; Style: curious
//Greetings Traveler! Welcome to my unique encryption program!
//This program is designed to encrypt a string using a simple but effective encryption method.
//I hope you find it interesting!
#include <stdio.h>
#include <string.h>

//Function to perform Encryption
char* encrypt(char* message, int key) {
    int i;
    char ch;
    for (i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        //Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }

        //Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
    }
    return message;
}

//Main function to run the program
int main() {
    printf("Hello there! Please enter the message you want to encrypt: \n");
    char message[100];
    fgets(message, 100, stdin);

    printf("And what should be the encryption key? \n");
    int key;
    scanf("%d", &key);

    //Encrypting the message
    char* encrypted_message = encrypt(message, key);

    //Printing the Encrypted message
    printf("The Encrypted message is: %s\n", encrypted_message);

    return 0;
}