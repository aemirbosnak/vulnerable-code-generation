//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: future-proof
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int length(char *pass){
    int i;
    for(i=0;*(pass+i)!='\0';i++);
    return i;
}
// returns length of the password string

int checkupper(char *pass){
    int i,count=0;
    for(i=0;*(pass+i)!='\0';i++){
        if(*(pass+i)>='A' && *(pass+i)<='Z')
            count++;
    }
    return count;
}
// returns count of uppercase characters in the password

int checklower(char *pass){
    int i,count=0;
    for(i=0;*(pass+i)!='\0';i++){
        if(*(pass+i)>='a' && *(pass+i)<='z')
            count++;
    }
    return count;
}
// returns count of lowercase characters in the password

int checkdigits(char *pass){
    int i,count=0;
    for(i=0;*(pass+i)!='\0';i++){
        if(*(pass+i)>='0' && *(pass+i)<='9')
            count++;
    }
    return count;
}
// returns count of digits in the password

int checkspecial(char *pass){
    int i,count=0;
    for(i=0;*(pass+i)!='\0';i++){
        if(!(*(pass+i)>='0' && *(pass+i)<='9') && !(*(pass+i)>='a' && *(pass+i)<='z') && !(*(pass+i)>='A' && *(pass+i)<='Z'))
            count++;
    }
    return count;
}
// returns count of special characters in the password

void main(){
    char *pass;
    pass=(char*)malloc(sizeof(char));
    int len,upp,low,dig,spec,i;
    printf("Enter the password: ");
    scanf("%s",pass);
    len=length(pass);
    upp=checkupper(pass);
    low=checklower(pass);
    dig=checkdigits(pass);
    spec=checkspecial(pass);
    if(len>=8 && len<=14 && upp>=1 && low>=1 && dig>=1 && spec>=1)
        printf("Strong Password!");
    else if(len>=6 && len<=14 && ((upp>=1 && low>=1 && dig>=1) || (upp>=1 && low>=1 && spec>=1) || (low>=1 && dig>=1 && spec>=1)))
        printf("Moderate Password!");
    else
        printf("Weak Password!");
    free(pass);
}