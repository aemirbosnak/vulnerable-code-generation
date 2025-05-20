//FormAI DATASET v1.0 Category: Syntax parsing ; Style: active
#include <stdio.h>

// A function that determines if a given string is a valid C syntax
int isValidSyntax(char* syntax) {
    int i = 0, openParenthesis = 0, closeParenthesis = 0, openBrace = 0, closeBrace = 0, openBracket = 0, closeBracket = 0;
    char prevChar = ' ';

    while (syntax[i]) {
        char currChar = syntax[i];

        // Count the number of opening and closing parentheses, braces and brackets
        if (currChar == '(') openParenthesis++;
        else if (currChar == ')') closeParenthesis++;
        else if (currChar == '{') openBrace++;
        else if (currChar == '}') closeBrace++;
        else if (currChar == '[') openBracket++;
        else if (currChar == ']') closeBracket++;

        // Check if the current character is a valid C syntax character
        if ((currChar >= 'A' && currChar <= 'Z') || (currChar >= 'a' && currChar <= 'z')
            || (currChar >= '0' && currChar <= '9') || currChar == ' ' || currChar == ',' || currChar == ';' ||
            currChar == '(' || currChar == ')' || currChar == '{' || currChar == '}' || currChar == '[' || currChar == ']') {
            //check for consecutive arithmetic operators
            if(prevChar && ((prevChar == '+' && currChar == '+') || (prevChar == '-' && currChar == '-') ||
                (prevChar == '+' && currChar == '-') || (prevChar == '-' && currChar == '+'))){
                    printf("\nInvalid syntax: operator %c followed by operator %c.", prevChar, currChar);
                    return 0;
                }
            prevChar = currChar;
            i++;
        } 
        else {
            printf("\nInvalid syntax: unexpected character %c.", currChar);
            return 0;
        }
    }

    // Check if the number of opening and closing parentheses, braces and brackets match
    if (openParenthesis == closeParenthesis && openBrace == closeBrace && openBracket == closeBracket) {
        printf("\nValid C syntax: %s", syntax);
        return 1;
    } 
    else {
        printf("\nInvalid syntax: The number of opening and closing parentheses, braces and/or brackets do not match.");
        return 0;
    }
}

int main() {
    char syntax[100];

    printf("Enter a C syntax: ");
    scanf("%[^\n]s", syntax);

    isValidSyntax(syntax);

    return 0;
}