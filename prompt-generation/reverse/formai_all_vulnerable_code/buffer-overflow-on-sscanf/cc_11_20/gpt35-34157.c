//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char input[255];
    char command[255];
    double num1, num2, result;
    bool running = true;

    while (running)
    {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%s", command);
        if (strcmp(command, "quit") == 0)
        {
            running = false;
            continue;
        }
        if (strcmp(command, "add") == 0 || strcmp(command, "+") == 0)
        {
            sscanf(input, "%s %lf %lf", command, &num1, &num2);
            result = num1 + num2;
            printf("%.2lf\n", result);
        }
        else if (strcmp(command, "subtract") == 0 || strcmp(command, "-") == 0)
        {
            sscanf(input, "%s %lf %lf", command, &num1, &num2);
            result = num1 - num2;
            printf("%.2lf\n", result);
        }
        else if (strcmp(command, "multiply") == 0 || strcmp(command, "*") == 0)
        {
            sscanf(input, "%s %lf %lf", command, &num1, &num2);
            result = num1 * num2;
            printf("%.2lf\n", result);
        }
        else if (strcmp(command, "divide") == 0 || strcmp(command, "/") == 0)
        {
            sscanf(input, "%s %lf %lf", command, &num1, &num2);
            if (num2 == 0)
            {
                printf("Error: Division by 0\n");
            }
            else
            {
                result = num1 / num2;
                printf("%.2lf\n", result);
            }
        }
        else
        {
            printf("Error: Invalid input\n");
        }
    }

    return 0;
}