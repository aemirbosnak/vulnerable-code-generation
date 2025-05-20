//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char *source_code;
    char *token;
    int i = 0;
    int state = 0;

    source_code = malloc(MAX_BUFFER_SIZE);
    printf("Enter C Syntax code: ");
    fgets(source_code, MAX_BUFFER_SIZE, stdin);

    token = strtok(source_code, " ");

    while (token)
    {
        printf("Token: %s\n", token);

        switch (state)
        {
            case 0:
                if (strcmp(token, "if") == 0)
                {
                    state = 1;
                }
                else if (strcmp(token, "else") == 0)
                {
                    state = 2;
                }
                else if (strcmp(token, "for") == 0)
                {
                    state = 3;
                }
                else if (strcmp(token, "while") == 0)
                {
                    state = 4;
                }
                else if (strcmp(token, "switch") == 0)
                {
                    state = 5;
                }
                else
                {
                    printf("Syntax error: unexpected token.\n");
                }
                break;

            case 1:
                if (strcmp(token, "else") == 0)
                {
                    state = 2;
                }
                else
                {
                    printf("Syntax error: unexpected token.\n");
                }
                break;

            case 2:
                if (strcmp(token, "}") == 0)
                {
                    state = 0;
                }
                else
                {
                    printf("Syntax error: unexpected token.\n");
                }
                break;

            case 3:
                if (strcmp(token, ")") == 0)
                {
                    state = 0;
                }
                else
                {
                    printf("Syntax error: unexpected token.\n");
                }
                break;

            case 4:
                if (strcmp(token, ")") == 0)
                {
                    state = 0;
                }
                else
                {
                    printf("Syntax error: unexpected token.\n");
                }
                break;

            case 5:
                if (strcmp(token, ":)") == 0)
                {
                    state = 0;
                }
                else
                {
                    printf("Syntax error: unexpected token.\n");
                }
                break;
        }

        token = strtok(NULL, " ");
    }

    free(source_code);

    return 0;
}