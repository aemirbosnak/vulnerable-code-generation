//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: decentralized
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool hasUpperCase(char *password){
    while(*password){
        if(isupper((unsigned char)*password))
            return true;
        password++;
    }
    return false;
}

bool hasLowerCase(char *password){
    while(*password){
        if(islower((unsigned char)*password))
            return true;
        password++;
    }
    return false;
}

bool hasNumbers(char *password){
    while(*password){
        if(isdigit((unsigned char)*password))
            return true;
        password++;
    }
    return false;
}

bool hasSpecialChar(char *password){
    while(*password){
        if(!isalnum((unsigned char)*password))
            return true;
        password++;
    }
    return false;
}

int getPasswordStrength(char *password){
    int strength = 0;
    if(hasUpperCase(password) && hasLowerCase(password))
        strength ++;
    if(hasNumbers(password))
        strength ++;
    if(hasSpecialChar(password))
        strength ++;
    if(strength == 3 && strlen(password) >= 8)
        return 4;   // Strong password
    else if(strength >= 2 && strlen(password) >= 6)
        return 3;   // Moderate password
    else if(strength >= 1 && strlen(password) >= 4)
        return 2;   // Weak password
    else
        return 1;   // Very weak password
}

int main(){
    char password[100];
    printf("Enter password: ");
    scanf("%s", password);
    int strength = getPasswordStrength(password);
    printf("Password strength: ");
    switch(strength){
        case 1:
            printf("Very weak\n");
            break;
        case 2:
            printf("Weak\n");
            break;
        case 3:
            printf("Moderate\n");
            break;
        case 4:
            printf("Strong\n");
            break;
    }
    return 0;
}