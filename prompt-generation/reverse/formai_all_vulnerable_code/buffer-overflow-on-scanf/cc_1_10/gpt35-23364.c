//FormAI DATASET v1.0 Category: Syntax parsing ; Style: shape shifting
#include<stdio.h>
#include<ctype.h>

void parse_integer(char* str);
void parse_operator(char* str);
void parse_keyword(char* str);
void parse_identifier(char* str);

int main(){
    char input[50];
    printf("Enter the C statement to be parsed: \n");
    scanf("%[^\n]", input);

    int i=0;
    while(input[i]!='\0'){

        if(isdigit(input[i])){
            parse_integer(input+i);
        }
        else if(isalpha(input[i])){
            char temp[50];
            int j=i;
            while(isalpha(input[j]) || isdigit(input[j])){
                temp[j-i] = input[j];
                j++;
            }
            temp[j-i]='\0';
            i=j-1;

            if(strcmp(temp,"if")==0 || strcmp(temp,"else")==0 || strcmp(temp,"while")==0){
                parse_keyword(temp);
            }else{
                parse_identifier(temp);
            }
        }
        else{
            parse_operator(input+i);
        }
        i++;
    }

    return 0;
}

void parse_integer(char* str){
    int num = atoi(str);
    printf("[%d] : Integer\n", num);
}

void parse_operator(char* str){
    switch(str[0]){
        case '+':
            printf("[+] : Addition Operator\n");
            break;
        case '-':
            printf("[-] : Subtraction Operator\n");
            break;
        case '*':
            printf("[*] : Multiplication Operator\n");
            break;
        case '/':
            printf("[/] : Division Operator\n");
            break;
        case '%':
            printf("[%%] : Modulus Operator\n");
            break;
        case '=':
            printf("[=] : Assignment Operator\n");
            break;
        case '<':
            printf("[%c] : Less Than Operator\n", str[0]);
            if(str[1]=='='){
                printf("[<=] : Less Than or Equal To Operator\n");
            }
            break;
        case '>':
            printf("[%c] : Greater Than Operator\n", str[0]);
            if(str[1]=='='){
                printf("[>=] : Greater Than or Equal To Operator\n");
            }
            break;
        case '!':
            printf("[!] : Not Operator\n");
            break;
        case '&':
            printf("[&] : Bitwise AND Operator\n");
            if(str[1]=='&'){
                printf("[&&] : Logical AND Operator\n");
            }
            break;
        case '|':
            printf("[|] : Bitwise OR Operator\n");
            if(str[1]=='|'){
                printf("[||] : Logical OR Operator\n");
            }
            break;
        default:
            printf("[%c] : Unknown Operator\n", str[0]);
    }
}

void parse_keyword(char* str){
    printf("[%s] : Keyword\n", str);
}

void parse_identifier(char* str){
    printf("[%s] : Identifier\n", str);
}