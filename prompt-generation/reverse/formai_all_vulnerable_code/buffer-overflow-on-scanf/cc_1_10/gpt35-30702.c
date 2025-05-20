//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: statistical
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_NUM_WORDS 10

void get_input(char *input);
int process_input(char *input, char *output);
void print_output(char *output);

int main()
{
    char input[MAX_WORD_LENGTH];
    char output[MAX_NUM_WORDS][MAX_WORD_LENGTH];
    int num_words;
    
    get_input(input);
    
    num_words = process_input(input, output);
    
    print_output(output);
    
    return 0;
}

void get_input(char *input)
{
    printf("Enter the alien language word or sentence: ");
    scanf("%s", input);
}

int process_input(char *input, char *output)
{
    int i = 0;
    char temp[MAX_WORD_LENGTH];
    int temp_index = 0;
    int output_index = 0;
    int num_words = 0;
    
    // Loop over each character in the input string
    while (input[i] != '\0')
    {
        // Add the current character to the temporary word
        temp[temp_index] = input[i];
        temp_index++;
        
        // If we've reached the end of a word, add it to the output array
        if (input[i+1] == ' ' || input[i+1] == '\0')
        {
            temp[temp_index] = '\0';
            strcpy(output[output_index], temp);
            output_index++;
            num_words++;
            temp_index = 0;
        }
        
        i++;
    }
    
    return num_words;
}

void print_output(char *output)
{
    printf("Translated as: ");
    printf("%s", output);
}