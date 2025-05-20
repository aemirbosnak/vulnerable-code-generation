//FormAI DATASET v1.0 Category: Syntax parsing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parseExpression(char* str, int* index);

int parsePrimary(char* str, int* index)
{
    int num = 0;
    int i = *index;
    while(str[i] >= '0' && str[i] <= '9') {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    *index = i;
    return num;
}

int parseFactor(char* str, int* index)
{
    int left = parsePrimary(str, index);
    while(str[*index] == '*' || str[*index] == '/') {
        char op = str[*index];
        (*index)++;
        int right = parsePrimary(str, index);
        if(op == '*') {
            left *= right;
        } else {
            left /= right;
        }
    }
    return left;
}

int parseExpression(char* str, int* index)
{
    int left = parseFactor(str, index);
    while(str[*index] == '+' || str[*index] == '-') {
        char op = str[*index];
        (*index)++;
        int right = parseFactor(str, index);
        if(op == '+') {
            left += right;
        } else {
            left -= right;
        }
    }
    return left;
}

int main()
{
    char str[100];
    int index = 0;
    printf("Enter an expression: ");
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);
    str[len-1] = '\0';
    int result = parseExpression(str, &index);
    printf("Result: %d\n", result);
    return 0;
}