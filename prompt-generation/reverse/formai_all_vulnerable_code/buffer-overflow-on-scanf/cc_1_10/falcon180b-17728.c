//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to generate a random password
void generatePassword(char* password, int length) {
    //Declare variables
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i;

    //Initialize password to empty string
    password[0] = '\0';

    //Loop through the desired length of the password
    for(i = 0; i < length; i++) {
        //Get a random character from the charset
        int randomChar = rand() % (sizeof(charset) - 1);

        //Append the random character to the password
        strncat(password, &charset[randomChar], 1);
    }
}

//Function to get user input for password length
int getPasswordLength() {
    int length;

    //Loop until a valid length is entered
    do {
        printf("Enter the desired length of the password: ");
        scanf("%d", &length);
    } while(length <= 0);

    return length;
}

int main() {
    //Declare variables
    char password[100];
    int length;

    //Get password length from user
    length = getPasswordLength();

    //Generate password
    generatePassword(password, length);

    //Print generated password
    printf("Your secure password is: %s\n", password);

    return 0;
}