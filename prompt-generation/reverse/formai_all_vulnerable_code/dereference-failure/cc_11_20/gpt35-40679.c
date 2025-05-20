//FormAI DATASET v1.0 Category: HTML beautifier ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 100000 // maximum size of the input buffer
#define BEAUTIFY_TAB_SIZE 4     // size of tabs for layout

int main()
{
    char *input = (char *)malloc(sizeof(char) * MAX_BUFFER_SIZE); // allocate memory for input
    scanf("%[^\n]s", input); // read input
    getchar(); // clear buffer

    int input_length = strlen(input); // get the length of the input
    int beautify_tab = 0; // track current level of indentation
    int inside_tag = 0; // check if we are inside an HTML tag
    char *output = (char *)malloc(sizeof(char) * MAX_BUFFER_SIZE); // allocate memory for output
    int output_index = 0; // index of next character to be written to output

    // loop through each character of input
    for (int i = 0; i < input_length; i++)
    {
        char current_char = input[i]; // get current character

        // check if we are entering or exiting an HTML tag
        if (current_char == '<')
        {
            inside_tag = 1;
        }
        else if (current_char == '>')
        {
            inside_tag = 0;
        }

        // check if we need to add a tab or newline for indentation
        if (current_char == '\n')
        {
            output[output_index++] = current_char; // add new line character to output
            beautify_tab = 0; // reset tab counter
        }
        else if (!inside_tag)
        {
            if (current_char == '{')
            {
                output[output_index++] = current_char; // add current character to output
                output[output_index++] = '\n'; // add new line character to output
                beautify_tab++; // add 1 to tab counter
                for (int t = 0; t < beautify_tab * BEAUTIFY_TAB_SIZE; t++)
                {
                    output[output_index++] = ' '; // add tabs to output
                }
            }
            else if (current_char == '}')
            {
                beautify_tab--; // decrease tab counter
                output[output_index++] = '\n'; // add new line character to output
                for (int t = 0; t < beautify_tab * BEAUTIFY_TAB_SIZE; t++)
                {
                    output[output_index++] = ' '; // add tabs to output
                }
                output[output_index++] = current_char; // add current character to output
                
            }
            else if (current_char == ';')
            {
                output[output_index++] = current_char; // add current character to output
                output[output_index++] = '\n'; // add new line character to output
                for (int t = 0; t < beautify_tab * BEAUTIFY_TAB_SIZE; t++)
                {
                    output[output_index++] = ' '; // add tabs to output
                }
            }
            else
            {
                output[output_index++] = current_char; // add current character to output
            }
        }
        else
        {
            if (current_char == '/')
            {
                beautify_tab--; // decrease tab counter
            }

            output[output_index++] = current_char; // add current character to output

            if (current_char == '<' && input[i + 1] == '/')
            {
                beautify_tab--; // decrease tab counter
            }
            else if (current_char == '<' && input[i + 1] != '/')
            {
                beautify_tab++; // increase tab counter
                output[output_index++] = '\n'; // add new line character to output
                for (int t = 0; t < beautify_tab * BEAUTIFY_TAB_SIZE; t++)
                {
                    output[output_index++] = ' '; // add tabs to output
                }
            }
        }
    }

    printf("%s", output); // print output

    // free allocated memory
    free(input);
    free(output);

    return 0;
}