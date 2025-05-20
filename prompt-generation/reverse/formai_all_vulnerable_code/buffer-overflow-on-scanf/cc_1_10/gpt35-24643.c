//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_password_strength(char* password){
    int len = strlen(password);
    int strength = 0;
    int uppercase = 0;
    int lowercase = 0;
    int digits = 0;
    int special_chars = 0;

    for(int i=0; i<len; i++){
        char ch = password[i];

        if(ch >= 'A' && ch <= 'Z'){
            uppercase++;
        }
        else if(ch >= 'a' && ch <= 'z'){
            lowercase++;
        }
        else if(ch >= '0' && ch <= '9'){
            digits++;
        }
        else{
            special_chars++;
        }
    }

    // check overall strength
    strength += (uppercase > 0) ? 1 : 0;
    strength += (lowercase > 0) ? 1 : 0;
    strength += (digits > 0) ? 1 : 0;
    strength += (special_chars > 0) ? 1 : 0;

    // check length and add strength points accordingly
    if(len >= 8){
        strength += 2;
    }
    else if(len >= 6){
        strength += 1;
    }

    // provide feedback based on the strength
    if(strength >= 4){
        printf("The password '%s' is a formidable one indeed! Very few could hope to breach it's defenses.\n", password);
    }
    else if(strength >= 2){
        printf("The password '%s' is moderately secure, but a determined individual could still crack it.\n", password);
    }
    else{
        printf("The password '%s' is woefully inadequate. Any common criminal could crack it with ease.\n", password);
    }
}

int main(){
    printf("Welcome to Sherlock's password strength checker. Let's see how secure your password really is...\n");

    char password[50];

    printf("Please enter your password: ");
    scanf("%s", password);

    check_password_strength(password);

    return 0;
}