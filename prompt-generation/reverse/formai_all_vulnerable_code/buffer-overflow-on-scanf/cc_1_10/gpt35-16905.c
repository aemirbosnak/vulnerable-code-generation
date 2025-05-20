//FormAI DATASET v1.0 Category: Text Summarizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int main()
{
    char input[MAX_LEN];
    char *ptr;
    char summary[MAX_LEN];
    int num_players;

    printf("Welcome to the Text Summarizer game! How many players are there?\n");
    scanf("%d", &num_players);

    while (num_players <= 0)
    {
        printf("Invalid input! Please enter a number greater than 0.\n");
        scanf("%d", &num_players);
    }

    printf("Great! Let's begin.\n");

    for (int i = 0; i < num_players; i++)
    {
        printf("Player %d, please enter the text you would like to summarize:\n", i+1);
        getchar(); // flush buffer
        fgets(input, MAX_LEN, stdin);

        ptr = strstr(input, "Summary:");
        if (ptr != NULL)
        {
            printf("Sorry, you cannot include the word 'Summary' in your input. Please try again.\n");
            i--;
            continue;
        }

        // Text summarization algorithm
        int len = strlen(input);
        if (len > 140)
        {
            input[140] = '\0';
            strcat(input, "...");
        }
        sprintf(summary, "Summary: %s", input);

        printf("Player %d, your text summary is:\n%s\n", i+1, summary);
    }

    printf("Thanks for playing! Goodbye.\n");

    return 0;
}