//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_LENGTH 25

char generateRandomChar(){
    char c;

    int type = rand() % 4;

    switch(type){
        case 0:
            // uppercase letter
            c = rand() % 26 + 'A';
            break;
        case 1:
            // lowercase letter
            c = rand() % 26 + 'a';
            break;
        case 2:
            // number
            c = rand() % 10 + '0';
            break;
        case 3:
            // symbol
            c = "!@#$%^&*()_+-=,./?><~`"[rand() % 22];
            break;
    }

    return c;
}

void generatePassword(char* password, int length){
    // seed the random number generator
    srand(time(NULL));

    // generate random characters and add them to the password
    for(int i = 0; i < length; i++){
        password[i] = generateRandomChar();
    }

    // null-terminate the password string
    password[length] = '\0';
}

int main(){
    int length;
    char password[MAX_LENGTH];

    printf("Enter password length (max %d): ", MAX_LENGTH);

    scanf("%d", &length);

    // make sure password length is valid
    if(length < 1 || length > MAX_LENGTH){
        printf("Invalid password length!\n");
        return 1;
    }

    generatePassword(password, length);

    printf("Your password is: %s\n", password);

    return 0;
}