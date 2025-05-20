//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_SIZE 1024

int main()
{
    char input_buffer[MAX_LINE_SIZE];
    char *input_line = NULL;
    size_t input_line_size = 0;

    while(1)
    {
        printf("Enter a temperature value (e.g. 20C or 68F): ");
        if(fgets(input_buffer, MAX_LINE_SIZE, stdin) == NULL)
        {
            printf("Error: Unable to read input.\n");
            exit(EXIT_FAILURE);
        }

        input_line = strtok(input_buffer, " ");
        if(input_line == NULL)
        {
            printf("Error: Invalid input.\n");
            continue;
        }

        input_line_size = strlen(input_line);
        if(input_line_size < 3)
        {
            printf("Error: Invalid input.\n");
            continue;
        }

        if(input_line[input_line_size - 2] == 'C' || input_line[input_line_size - 2] == 'c')
        {
            double celsius = strtod(input_line, NULL);
            double fahrenheit = celsius * 1.8 + 32;

            printf("%.2fC = %.2fF\n", celsius, fahrenheit);
        }
        else if(input_line[input_line_size - 2] == 'F' || input_line[input_line_size - 2] == 'f')
        {
            double fahrenheit = strtod(input_line, NULL);
            double celsius = (fahrenheit - 32) / 1.8;

            printf("%.2fF = %.2fC\n", fahrenheit, celsius);
        }
        else
        {
            printf("Error: Invalid input.\n");
        }
    }

    return 0;
}