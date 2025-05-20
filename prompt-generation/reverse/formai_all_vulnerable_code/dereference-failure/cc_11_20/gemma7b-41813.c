//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOKEN_MAX 100

typedef struct Token {
    char type;
    char value[TOKEN_MAX];
    struct Token* next;
} Token;

Token* yy_scan(char* str)
{
    Token* head = NULL;
    Token* tail = NULL;

    for (int i = 0; str[i] != '\0'; i++)
    {
        switch (str[i])
        {
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'g':
            case 'h':
            case 'i':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'o':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'u':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
                tail = head ? head->next = malloc(sizeof(Token)) : (head = tail = malloc(sizeof(Token)));
                tail->type = 'V';
                strcpy(tail->value, str + i);
                break;
            default:
                tail = head ? head->next = malloc(sizeof(Token)) : (head = tail = malloc(sizeof(Token)));
                tail->type = 'O';
                tail->value[0] = str[i];
                tail->value[1] = '\0';
                break;
        }
    }

    return head;
}

int main()
{
    char str[] = "Absurd syntax, a feast for the eyes!";
    Token* tokens = yy_scan(str);

    for (Token* token = tokens; token; token = token->next)
    {
        printf("%c: %s\n", token->type, token->value);
    }

    return 0;
}