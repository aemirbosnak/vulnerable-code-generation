//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: authentic
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool isSmallLetter(char ch){
    return (ch >= 'a' && ch <= 'z');
}

bool isCapitalLetter(char ch){
    return (ch >= 'A' && ch <= 'Z');
}

bool isDigit(char ch){
    return (ch >= '0' && ch <= '9');
}

bool isSpecialChar(char ch){
    return ((ch >= '!' && ch <= '/') || (ch >= ':' && ch <= '@')
            || (ch >= '[' && ch <= '`') || (ch >= '{' && ch <= '~'));
}

int passwordStrength(char* password){
    int length = strlen(password);
    int score = 0, smallLet = 0, capLet = 0, dig = 0, splChar = 0;

    for(int i=0; i<length; i++){
        if(isSmallLetter(password[i]))
            smallLet++;
        else if(isCapitalLetter(password[i]))
            capLet++;
        else if(isDigit(password[i]))
            dig++;
        else if(isSpecialChar(password[i]))
            splChar++;
    }

    if(smallLet > 0 && capLet > 0)
        score += 2;
    if(dig > 0 && splChar > 0)
        score += 2;
    if(length >= 8)
        score += 2;
    if(score == 6)
        return 4;
    else if(score >= 4)
        return 3;
    else if(score >= 2)
        return 2;
    else
        return 1;
}

int main(){
    char password[100];
    printf("Enter password: ");
    scanf("%s", &password);

    int strength = passwordStrength(password);

    if(strength == 1)
        printf("Weak password\n");
    else if(strength == 2)
        printf("Moderate password\n");
    else if(strength == 3)
        printf("Strong password\n");
    else
        printf("Very Strong password\n");
    return 0;
}