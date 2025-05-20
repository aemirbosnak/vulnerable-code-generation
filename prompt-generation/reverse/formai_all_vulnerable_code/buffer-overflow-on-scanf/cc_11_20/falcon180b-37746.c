//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Alan Turing
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int main(){
    int length,lowercase,uppercase,digit,special;
    char password[100];
    printf("Enter password: ");
    scanf("%s",password);
    length=strlen(password);
    lowercase=0;
    uppercase=0;
    digit=0;
    special=0;
    for(int i=0;i<length;i++){
        if(isalpha(password[i])){
            if(islower(password[i])){
                lowercase=1;
            }else if(isupper(password[i])){
                uppercase=1;
            }
        }else if(isdigit(password[i])){
            digit=1;
        }else{
            special=1;
        }
    }
    int strength=0;
    if(length>=8){
        strength++;
    }
    if(lowercase){
        strength++;
    }
    if(uppercase){
        strength++;
    }
    if(digit){
        strength++;
    }
    if(special){
        strength++;
    }
    if(strength==0){
        printf("Very weak password\n");
    }else if(strength==1){
        printf("Weak password\n");
    }else if(strength==2){
        printf("Moderate password\n");
    }else if(strength==3){
        printf("Strong password\n");
    }else{
        printf("Very strong password\n");
    }
    return 0;
}