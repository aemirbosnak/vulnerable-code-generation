//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to generate secure random password
void generatePassword() {
    int passwordLength, i;
    char password[100];
    srand(time(NULL)); //initialize random seed
    
    printf("How many characters do you want in your password? (Minimum 8): \n");
    scanf("%d", &passwordLength);
    
    //check if password length is less than 8
    if(passwordLength < 8) {
        printf("Password length should be minimum 8 characters. Please try again.\n");
        generatePassword();
        return;
    }

    //generate random password characters
    for (i = 0; i < passwordLength; i++) {
        int randomNum = rand() % 94 + 33;
        password[i] = (char) randomNum;
    }

    //null terminate the password string
    password[i] = '\0';

    //check if password contains at least one capital letter, one small letter and one number
    int capital = 0, small = 0, number = 0;
    for(i = 0; i < passwordLength; i++) {
        if(password[i] >= 'A' && password[i] <= 'Z') {
            capital++;
        }
        else if(password[i] >= 'a' && password[i] <= 'z') {
            small++;
        }
        else if(password[i] >= '0' && password[i] <= '9') {
            number++;
        }
    }
    //if password does not contain required characters, regenerate the password
    if(capital < 1 || small < 1 || number < 1) {
        printf("Generated password is not secure. Please try again.\n");
        generatePassword();
        return;
    }

    //print the generated secure password
    printf("\nYour secure password is: \n%s\n", password);
}

int main() {
    printf("\nWelcome to the Secure Password Generator!\n");
    generatePassword();
    return 0;
}