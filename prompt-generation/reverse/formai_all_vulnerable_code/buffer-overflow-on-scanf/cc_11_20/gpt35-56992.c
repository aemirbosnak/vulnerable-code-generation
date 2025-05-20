//FormAI DATASET v1.0 Category: Syntax parsing ; Style: secure
#include<stdio.h>

/* Function to check if given character is an alphabet or not */
int isAlpha(char c){
    if((c>='a' && c<='z') || (c>='A' && c<='Z'))
        return 1;
    else
        return 0;
}

/* Function to check if given character is a digit or not */
int isDigit(char c){
    if(c>='0' && c<='9')
        return 1;
    else
        return 0;
}

/* Function to check if given character is valid special character or not */
int isValidSpecialChar(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='%' || c=='=' || c=='<' || c=='>' || c=='!' || c=='&' || c=='|' || c=='^' || c=='~' || c=='(' || c==')' || c=='{' || c=='}' || c==';' || c==':' || c==',' || c=='.' || c=='[' || c==']')
        return 1;
    else
        return 0;
}

/* Main Function */
int main(){
    char c[1000];
    int i=0, j, isAlphaFlag=0, isDigitFlag=0, isValidSpecialCharFlag=0;

    printf("Enter a C program: ");
    scanf("%[^\n]s",c);

    while(c[i]!='\0'){

        /* If it is alphabet */
        if(isAlpha(c[i])){
            isAlphaFlag=1;
            isDigitFlag=0;
            isValidSpecialCharFlag=0;
            i++;
        }

        /* If it is digit */
        else if(isDigit(c[i])){
            isAlphaFlag=0;
            isDigitFlag=1;
            isValidSpecialCharFlag=0;
            i++;
        }

        /* If it is a valid special character */
        else if(isValidSpecialChar(c[i])){
            isAlphaFlag=0;
            isDigitFlag=0;
            isValidSpecialCharFlag=1;
            i++;
        }

        /* If it is a whitespace or newline character */
        else if(c[i]==' ' || c[i]=='\n'){
            isAlphaFlag=0;
            isDigitFlag=0;
            isValidSpecialCharFlag=0;
            i++;
        }

        /* If it is not alphanumeric or a valid special character */
        else{
            printf("\nInvalid character '%c' in the input",c[i]);
            return 0;
        }

        /* Check for syntax errors */
        if((isAlphaFlag || isDigitFlag) && isValidSpecialCharFlag){
            printf("\nSyntax Error: AlphaNumeric '%c' cannot be together with Special Charater(s)",c[i-1]);
            return 0;
        }
        else if(isValidSpecialCharFlag && (c[i-1]=='+' || c[i-1]=='-' || c[i-1]=='*' || c[i-1]=='/' || c[i-1]=='%' || c[i-1]=='=')){
            if(c[i]==c[i-1]){
                printf("\nSyntax Error: '%c' cannot be followed by another '%c'",c[i-1],c[i]);
                return 0;
            }
        }
        else if(c[i-1]=='&' && c[i]!='&'){
            printf("\nSyntax Error: '&%c' is an invalid expression",c[i]);
            return 0;
        }
        else if(c[i-1]=='|' && c[i]!='|'){
            printf("\nSyntax Error: '|%c' is an invalid expression",c[i]);
            return 0;
        }
        else if(c[i-1]=='<' && c[i]!='='){
            printf("\nSyntax Error: '<%c' is an invalid expression",c[i]);
            return 0;
        }
        else if(c[i-1]=='>' && c[i]!='='){
            printf("\nSyntax Error: '>%c' is an invalid expression",c[i]);
            return 0;
        }
        else if(c[i-1]=='=' && c[i]!='='){
            printf("\nSyntax Error: '=%c' is an invalid expression",c[i]);
            return 0;
        }       
    }

    /* If program runs successfully without any syntax errors */
    printf("\nThe input C program is valid\n");
    return 0;
}