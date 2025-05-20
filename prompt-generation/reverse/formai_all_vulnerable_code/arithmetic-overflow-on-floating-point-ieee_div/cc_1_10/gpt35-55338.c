//FormAI DATASET v1.0 Category: Text processing ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main()
{
    char text[1000];
    printf("Enter text: ");
    fgets(text, 1000, stdin);

    int length = strlen(text);
    int word_count = 0;
    int char_count = 0;
    int upper_count = 0;
    int digit_count = 0;

    for(int i = 0; i < length; i++)
    {
        if(isalpha(text[i]))
        {
            char_count++;
            if(isupper(text[i]))
            {   
                upper_count++;
            }
        }

        if(isdigit(text[i]))
        {
            digit_count++;
        }

        if(isspace(text[i]) || text[i] == '\n')
        {
            word_count++;
        }
    }

    float avg_word_length = (float) char_count / word_count;
    float percentage_upper = (float) upper_count / char_count * 100;
    float percentage_digit = (float) digit_count / char_count * 100;

    printf("Analysis of text: \n");
    printf("Total number of characters: %d\n", char_count);
    printf("Total number of words: %d\n", word_count);
    printf("Average word length: %.2f\n", avg_word_length);
    printf("Percentage of uppercase letters: %.2f%%\n", percentage_upper);
    printf("Percentage of digits: %.2f%%\n", percentage_digit);

    return 0;
}