//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: real-life
#include<stdio.h>
#include<string.h>

int main(){
    char password[100];
    int length, upper_count=0, lower_count=0, digit_count=0, special_count=0, score=0;
    printf("Enter your password: ");
    scanf("%s", password);
    length=strlen(password);

    //Checking Length
    if(length>=8 && length<=16){
        score+=10;
    }

    //Checking UpperCase, LowerCase, Digits and SpecialChars
    for(int i=0; i<length; i++){
        if(password[i]>='A' && password[i]<='Z'){
            upper_count++;
        }
        else if(password[i]>='a' && password[i]<='z'){
            lower_count++;
        }
        else if(password[i]>='0' && password[i]<='9'){
            digit_count++;
        }
        else{
            special_count++;   
        }
    }

    //Score Calculation
    if(upper_count>0) score+=10;
    if(lower_count>0) score+=10;
    if(digit_count>0) score+=10;
    if(special_count>0) score+=10;

    //Checking if Password contains all four types
    if(upper_count>0 && lower_count>0 && digit_count>0 && special_count>0){
        score+=20;
    }

    //Printing Score and Strength
    printf("Score: %d\n", score);
    if(score>=70){
        printf("Strong Password\n");
    }
    else if(score>=50){
        printf("Moderate Password\n");
    }
    else{
        printf("Weak Password\n");
    }
    return 0;
}