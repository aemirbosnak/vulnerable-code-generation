//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: sophisticated
#include <stdio.h>
#include <string.h>

//This program translates C Cat language to English.

int main() {
    char c_cat[100]; //declaring string variable to store input from user
    int i=0; //for iteration of loop
    
    printf("Enter C Cat language:\n");
    scanf("%[^\n]", c_cat); //getting input with whitespace from user
    
    while(c_cat[i] != '\0') { //looping through each character in string
        
        //if the character is '@', translating to 'if'
        if(c_cat[i] == '@') {
            printf("if ");
        }
        
        //if the character is '%', translating to 'else'
        else if(c_cat[i] == '%') {
            printf("else ");
        }
        
        //if the character is '!', translating to 'not'
        else if(c_cat[i] == '!') {
            printf("not ");
        }
        
        //if the character is '#', translating to 'and'
        else if(c_cat[i] == '#') {
            printf("and ");
        }
        
        //if the character is '$', translating to 'or'
        else if(c_cat[i] == '$') {
            printf("or ");
        }
        
        //if the character is '^', translating to 'true'
        else if(c_cat[i] == '^') {
            printf("true ");
        }
        
        //if the character is '&', translating to 'false'
        else if(c_cat[i] == '&') {
            printf("false ");
        }
        
        //if the character is '*', translating to 'multiply'
        else if(c_cat[i] == '*') {
            printf("multiply ");
        }
        
        //if the character is '+', translating to 'add'
        else if(c_cat[i] == '+') {
            printf("add ");
        }
        
        //if the character is '-', translating to 'subtract'
        else if(c_cat[i] == '-') {
            printf("subtract ");
        }
        
        //if the character is '/', translating to 'divide'
        else if(c_cat[i] == '/') {
            printf("divide ");
        }
        
        //if the character is '<', translating to 'less than'
        else if(c_cat[i] == '<') {
            printf("less than ");
        }
        
        //if the character is '>', translating to 'greater than'
        else if(c_cat[i] == '>') {
            printf("greater than ");
        }
        
        //if the character is '=', translating to 'equal to'
        else if(c_cat[i] == '=') {
            printf("equal to ");
        }
        
        //if the character is '~', translating to 'not equal to'
        else if(c_cat[i] == '~') {
            printf("not equal to ");
        }
        
        //if the character is '?', translating to 'print'
        else if(c_cat[i] == '?') {
            printf("print ");
        }
        
        //if the character is '_', translating to 'input'
        else if(c_cat[i] == '_') {
            printf("input ");
        }
        
        //if none of the above, printing the character as it is
        else {
            printf("%c", c_cat[i]);
        }
        
        i++; //incrementing index for next character
    }
    
    return 0;
}