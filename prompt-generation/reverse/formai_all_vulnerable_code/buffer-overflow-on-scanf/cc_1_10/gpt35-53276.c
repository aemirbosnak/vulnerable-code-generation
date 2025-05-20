//FormAI DATASET v1.0 Category: Text Summarizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 50
#define MAX_LENGTH 1000

int main(void){

    char input[MAX_LENGTH+1];
    char sentences[MAX_SENTENCES][MAX_LENGTH+1];
    int sentenceCount = 0;

    printf("Welcome to the C Text Summarizer Multiplayer Game!\n");
    printf("Please enter the text you want to summarize (max length %d, end with '.' or '!'): \n", MAX_LENGTH);

    fgets(input, MAX_LENGTH+1, stdin);
    input[strcspn(input, "\n")] = '\0';

    char *token = strtok(input, ".!");
    while (token != NULL && sentenceCount < MAX_SENTENCES) {
        strcpy(sentences[sentenceCount], token);
        sentenceCount++;
        token = strtok(NULL, ".!");
    }

    printf("\n--- Summary ---\n");

    int playerCount = 0, i = 0;
    printf("How many players want to summarize the text? \n");
    scanf("%d", &playerCount);
    fflush(stdin);

    for(i = 0; i < playerCount; i++){
        char summary[MAX_LENGTH+1];
        printf("\nPlayer %d, please enter your summary (max length %d): \n", i+1, MAX_LENGTH);
        fgets(summary, MAX_LENGTH+1, stdin);
        summary[strcspn(summary, "\n")] = '\0';

        printf("\n--- Player %d's summary ---\n", i+1);
        
        token = strtok(summary, ".!");
        while (token != NULL) {
            printf("%s. ", token);
            token = strtok(NULL, ".!");
        }
        printf("\n");
    }

    printf("\n--- Final summary ---\n");

    int j, k;
    for(j = 0; j < sentenceCount; j++){
        int points = 0;
        for(k = 0; k < playerCount; k++){
            char summary[MAX_LENGTH+1];

            printf("\nPlayer %d, how many points does sentence #%d deserve (1~10)? \n", k+1, j+1);
            scanf("%d", &points);

            fflush(stdin);

            if(points < 1) points = 1;
            if(points > 10) points = 10;
        }
        if(points > 5)
            printf("%s. ", sentences[j]);
    }
    printf("\n");

    return 0;
}