//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define LETTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMBERS "0123456789"
#define SYMBOLS "!@#$%^&*()_-+={}[]|\:;\"<>,.?/"

char* generatePassword(int length);

int main(){
    int length;
    printf("Enter the length of your desired password: ");
    scanf("%d", &length);
    printf("Your new secure password is: %s\n", generatePassword(length));
    return 0;
}

char* generatePassword(int length){
    char* password = malloc((length+1)* sizeof(char));
    int i;
    int randIndex;
    srand(time(0)); //seed random generator with current time

    //add a random letter
    randIndex = rand() % strlen(LETTERS);
    password[0] = LETTERS[randIndex];

    //add a random number
    randIndex = rand() % strlen(NUMBERS);
    password[1] = NUMBERS[randIndex];

    //add a random symbol
    randIndex = rand() % strlen(SYMBOLS);
    password[2] = SYMBOLS[randIndex];

    //fill the rest of the password with random characters
    for(i = 3; i < length; i++){
        int randCat = rand() % 3;
        switch (randCat){
            case 0: //add a random letter
                randIndex = rand() % strlen(LETTERS);
                password[i] = LETTERS[randIndex];
                break;
            case 1: //add a random number
                randIndex = rand() % strlen(NUMBERS);
                password[i] = NUMBERS[randIndex];
                break;
            case 2: //add a random symbol
                randIndex = rand() % strlen(SYMBOLS);
                password[i] = SYMBOLS[randIndex];
                break;
        }
    }
    password[length] = '\0'; //add null terminator
    return password; //return the generated password
}