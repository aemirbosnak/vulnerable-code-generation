//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Cryptic
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int main(){

char pass[100];
int len,i,j,k,l,count=0,flag=0;
char ch;

printf("Enter the password to check its strength:\n");
scanf("%s",pass);

len=strlen(pass);

for(i=0;i<len;i++){

if(isalpha(pass[i])){

count++;

}

else if(isdigit(pass[i])){

count++;

}

else if(pass[i]=='!' || pass[i]=='@' || pass[i]=='#' || pass[i]=='$' || pass[i]=='%' || pass[i]=='^' || pass[i]=='&' || pass[i]=='*'){

count++;

}

else{

flag=1;

break;

}

}

if(count>0){

if(flag==0){

printf("Password is strong.\n");

}

else{

printf("Password is weak.\n");

}

}

else{

printf("Password should contain at least one alphabet, one digit and one special character.\n");

}

return 0;
}