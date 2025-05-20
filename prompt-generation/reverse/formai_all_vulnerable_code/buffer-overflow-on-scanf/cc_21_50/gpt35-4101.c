//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: detailed
#include<stdio.h>
#include<string.h>

int main(){
    char password[30];
    int score=0, length, i;
    printf("Enter Password: ");
    scanf("%s",password);
    length=strlen(password);

    //Checking password length
    if(length>=8){
        score=score+10;
    }
    else{
        printf("Password should be atleast 8 characters long\n");
        return 0;
    }

    //Checking if password contains digits or not
    for(i=0;i<length;i++){
        if(password[i]>='0' && password[i]<='9'){
            score=score+10;
            break;
        }
    }
    if(i==length){
        printf("Password should contain atleast one digit\n");
        return 0;
    }

    //Checking if password contains uppercase letters or not
    for(i=0;i<length;i++){
        if(password[i]>='A' && password[i]<='Z'){
            score=score+10;
            break;
        }
    }
    if(i==length){
        printf("Password should contain atleast one uppercase letter\n");
        return 0;
    }

    //Checking if password contains lowercase letters or not
    for(i=0;i<length;i++){
        if(password[i]>='a' && password[i]<='z'){
            score=score+10;
            break;
        }
    }
    if(i==length){
        printf("Password should contain atleast one lowercase letter\n");
        return 0;
    }

    //Checking if password contains special characters or not
    for(i=0;i<length;i++){
        if((password[i]>='!' && password[i]<='/') || (password[i]>=':' && password[i]<='@') || (password[i]>='[' && password[i]<='`') || (password[i]>='{' && password[i]<='~')){
            score=score+10;
            break;
        }
    }
    if(i==length){
        printf("Password should contain atleast one special character\n");
        return 0;
    }

    //Final output and decision
    if(score==50){
        printf("Password is very strong\n");
    }
    else if(score==40){
        printf("Password is strong\n");
    }
    else if(score==30){
        printf("Password is average\n");
    }
    else{
        printf("Password is weak\n");
    }

    return 0;
}