//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to shuffle the characters of a given string
void shuffle(char *str)
{
    int n = strlen(str);
    for (int i = 0; i < n; i++)
    {
        int j = rand() % n;
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main()
{
    // Array of words to be typed
    char *words[5] = {"programming", "algorithm", "datastructure", "computer", "keyboard"};

    // Random seed value
    srand(time(NULL));

    // Loop to allow user to play multiple times
    while(1)
    {
        // Randomly select a word from the array
        int idx = rand() % 5;
        char *word = words[idx];

        // Shuffle the characters of the word
        shuffle(word);

        // Print the shuffled word and prompt for input
        printf("Type the word: %s\n", word);
        char input[50];
        scanf("%s", input);

        // Check if the input matches the original word
        if(strcmp(input,words[idx]) == 0)
        {
            printf("Great job!\n");
        }
        else
        {
            printf("Sorry, try again!\n");
        }

        // Prompt for continuation
        printf("Type 'exit' to quit or 'continue' to play again.\n");
        char choice[10];
        scanf("%s", choice);

        if(strcmp(choice,"exit") == 0)
        {
            break;
        }
    }

    return 0;
}