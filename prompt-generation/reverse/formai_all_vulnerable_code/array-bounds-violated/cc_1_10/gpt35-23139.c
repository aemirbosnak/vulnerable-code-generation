//FormAI DATASET v1.0 Category: Syntax parsing ; Style: active
// This program parses C syntax to check for correct syntax structure in code
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Variable Declaration
char str[100];
int i,len,flag,temp=0;

// Function declaration
int checkSyntax();

// Main function
int main(){

    printf("Enter a C statement to be checked for syntax: \n");
    // Taking input from the user
    fgets(str, 100, stdin);
    len=strlen(str);
    str[len-1]='\0';//deleting extra newline character from the input string
    
    // Calling the checkSyntax function
    flag=checkSyntax();
    
    if(flag==0){
        printf("\n%s is a valid C statement\n",str);
    }
    else{
        printf("\n%s is an invalid C statement\n",str);
    }
    return 0;
}

// Function to check for correct syntax
int checkSyntax(){
    // Checking first character
    if(isalpha(str[0])||str[0]=='_'){
        for(i=1;i<len;i++){
            if(!(isalnum(str[i])||str[i]=='_'||str[i]=='['||str[i]==']'||str[i]=='-'||str[i]=='.'||str[i]=='>')){
                flag=1;
                break;
            }
            else if(str[i]=='('){
                temp++;
            }
            else if(str[i]==')'){
                temp--;
                if(temp<0){
                    flag=1;
                    break;
                }
            }
        }
        if(temp!=0)
            return 1;
        else if(flag==1)
            return 1;
        else
            return 0;
    }
    else{
        return 1;
    }
}