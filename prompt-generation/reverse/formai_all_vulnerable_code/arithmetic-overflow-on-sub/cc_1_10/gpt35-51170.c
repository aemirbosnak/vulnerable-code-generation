//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: enthusiastic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 50
#define MAX_WORD_SIZE 15
#define TIME_LIMIT 30

char* words[MAX_WORDS] = {"programming", "typing", "speed", "test", "challenge", "algorithm", "computer", "language", "keyboard", "debugging", "syntax", "variable", "function", "recursion", "loop", "pointer", "array", "structure", "file", "printf", "scanf", "data", "type", "operator", "conditional", "break", "continue", "random", "number", "ascii", "code", "math", "library", "header", "memory", "output", "input", "error", "handling", "iteration", "increment", "decrement", "logic", "while", "for", "do", "switch", "case"};

int main()
{
    int i, count = 0, correct = 0, wrong = 0, time_left = TIME_LIMIT;
    char input_word[MAX_WORD_SIZE];
    
    printf("\nWelcome to Typing Speed Test Challenge! You have %d seconds to type as many words as possible.\n\n", time_left);
    
    srand(time(0));
    
    while(time_left > 0)
    {
        i = rand() % MAX_WORDS;
        printf("%s ", words[i]);
        
        time_t start = time(NULL);
        scanf("%s", input_word);
        time_t end = time(NULL);
        
        if(isalpha(input_word[0]))
        {
            count++;
            if(strcmp(input_word, words[i]) == 0)
            {
                correct++;
            }
            else
            {
                wrong++;
            }
        }
        
        time_left -= (int)(end - start);
    }
    
    printf("\n\nTime's up! You typed %d words. Accuracy: %d%%", count, (int)((float)correct/count*100));
    printf("\n%d words correct, %d words wrong. \n\n", correct, wrong);
    
    return 0;
}