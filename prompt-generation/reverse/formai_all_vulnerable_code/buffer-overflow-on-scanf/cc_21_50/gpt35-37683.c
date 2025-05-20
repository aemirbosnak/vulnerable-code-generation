//FormAI DATASET v1.0 Category: Syntax parsing ; Style: innovative
#include<stdio.h>
#include<stdlib.h>

int main() {
    printf("Enter a C program:\n");
    char *program = (char*) malloc(1000 * sizeof(char)); //allocate memory for the program
    scanf("%[^\n]", program); //Read the program until newline character
    
    //Removing comments from the C program
    char *program_without_comments = (char*) malloc(1000 * sizeof(char));
    int in_comment = 0;
    int j = 0;
    for(int i=0; i<strlen(program); i++) {
        if(program[i] == '/' && program[i+1] == '*') {
            in_comment = 1;
            i++;
        } else if(program[i] == '*' && program[i+1] == '/') {
            in_comment = 0;
            i++;
        } else if(!in_comment) {
            program_without_comments[j] = program[i];
            j++;
        }
    }
    program_without_comments[j] = '\0';
    printf("Code without comments:\n%s\n", program_without_comments);
    
    //Parsing the C program for syntax errors
    int parentheses_count = 0;
    int curly_braces_count = 0;
    int square_brackets_count = 0;
    for(int i=0; i<strlen(program_without_comments); i++) {
        if(program_without_comments[i] == '(') {
            parentheses_count++;
        } else if(program_without_comments[i] == ')') {
            parentheses_count--;
            if(parentheses_count < 0) {
                printf("Syntax error: Extra closing parenthesis\n");
                return 0;
            }
        } else if(program_without_comments[i] == '{') {
            curly_braces_count++;
        } else if(program_without_comments[i] == '}') {
            curly_braces_count--;
            if(curly_braces_count < 0) {
                printf("Syntax error: Extra closing curly brace\n");
                return 0;
            }
        } else if(program_without_comments[i] == '[') {
            square_brackets_count++;
        } else if(program_without_comments[i] == ']') {
            square_brackets_count--;
            if(square_brackets_count < 0) {
                printf("Syntax error: Extra closing square bracket\n");
                return 0;
            }
        }
    }
    
    if(parentheses_count > 0) {
        printf("Syntax error: Extra open parenthesis\n");
    } else if(parentheses_count < 0) {
        printf("Syntax error: Extra closing parenthesis\n");
    } else if(curly_braces_count > 0) {
        printf("Syntax error: Extra open curly brace\n");
    } else if(curly_braces_count < 0) {
        printf("Syntax error: Extra closing curly brace\n");
    } else if(square_brackets_count > 0) {
        printf("Syntax error: Extra open square bracket\n");
    } else if(square_brackets_count < 0) {
        printf("Syntax error: Extra closing square bracket\n");
    } else {
        printf("No syntax errors found!\n");
    }
    
    free(program);
    free(program_without_comments);
    return 0;
}