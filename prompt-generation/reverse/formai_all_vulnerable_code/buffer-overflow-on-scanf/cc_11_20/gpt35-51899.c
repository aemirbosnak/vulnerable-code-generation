//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: systematic
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){

    char password[25];
    int length,flag=0,digit=0,upper=0,lower=0,symbol=0,i;
    printf("Enter the password: ");
    scanf("%s",password);
    length=strlen(password);
    
    if(length<8)
        flag--;

    for(i=0;i<length;i++){
        if(isdigit(password[i]))
            digit++;
        if(isupper(password[i]))
            upper++;
        if(islower(password[i]))
            lower++;
        if(!isdigit(password[i]) && !isalpha(password[i]))
            symbol++;
    }

    if(digit<1)
        flag--;
    if(upper<1)
        flag--;
    if(lower<1)
        flag--;
    if(symbol<1)
        flag--;

    switch(flag){
        case 0:
            printf("\nThis password is very weak.");
            break;
        case 1:
            printf("\nThis password is weak.");
            break;
        case 2:
            printf("\nThis password is moderately strong.");
            break;
        case 3:
            printf("\nThis password is strong.");
            break;
        case 4:
            printf("\nThis password is very strong.");
            break;
        default:
            printf("\nInvalid Password!!!");
            break;
    }
    return 0;
}