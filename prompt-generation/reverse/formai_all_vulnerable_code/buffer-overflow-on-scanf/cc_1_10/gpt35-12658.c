//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: irregular
#include<stdio.h>
#include<string.h>

//functions to check password strength
int isInRange(int x, int lower, int upper){
   return ((x>=lower) && (x<=upper));
}

int countDigits(char str[]){
    int i, count=0;
    for(i=0; i<strlen(str); i++){
        if(isdigit(str[i])){
            count++;
        }
    }
    return count;
}

int countUppercase(char str[]){
    int i, count=0;
    for(i=0; i<strlen(str); i++){
        if(isupper(str[i])){
            count++;
        }
    }
    return count;
}

int countLowercase(char str[]){
    int i, count=0;
    for(i=0; i<strlen(str); i++){
        if(islower(str[i])){
            count++;
        }
    }
    return count;
}

int countSpecial(char str[]){
    int i, count=0;
    for(i=0; i<strlen(str); i++){
        if(ispunct(str[i])){
            count++;
        }
    }
    return count;
}

int checkPasswordStrength(char str[]){
    int len = strlen(str);
    int count_d = countDigits(str);
    int count_u = countUppercase(str);
    int count_l = countLowercase(str);
    int count_s = countSpecial(str);
    int score=0;
    if(isInRange(len, 8, 15)){   //checking length of password
        score++;
    }
    if(count_d >= 2){   //checking number of digits 
        score++;
    }
    if(count_u >= 1){   //checking number of uppercase letters
        score++;
    }
    if(count_l >= 1){   //checking number of lowercase letters
        score++;
    }
    if(count_s >= 1){   //checking number of special characters
        score++;
    }
    if(score == 5){   //returning the strength of password
        return 5;
    }else if(score == 4){
        return 4;
    }else if(score == 3){
        return 3;
    }else if(score == 2){
        return 2;
    }else if(score == 1){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    char password[20];
    printf("Enter password to check its strength: ");
    scanf("%s", password);
    int strength = checkPasswordStrength(password);
    switch(strength){
        case 0:
            printf("Password is weak, Please select a strong password!\n");
            break;
        case 1:
            printf("Password is of average strength, Please try to make it stronger!\n");
            break;
        case 2:
            printf("Password is moderately strong, Good job!\n");
            break;
        case 3:
            printf("Password is strong, Keep it up!\n");
            break;
        case 4:
            printf("Password is very strong, Awesome job!\n");
            break;
        case 5:
            printf("Password is extremely strong, You are a password guru!\n");
            break;
    }
    return 0;
}