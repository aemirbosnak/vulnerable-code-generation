//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: invasive
#include <stdio.h>
#include <string.h>

//function to calculate sentiment score of a sentence
int getSentimentScore(char sentence[])
{
    char positiveWords[10][20] = {"good", "great", "excellent", "awesome", "amazing", "love", "fantastic", "nice", "happy", "joyful"};
    char negativeWords[10][20] = {"bad", "terrible", "horrible", "awful", "hate", "dislike", "annoying", "sad", "unhappy", "depressed"};

    int sentimentScore = 0;

    //loop through words in the sentence
    char *word = strtok(sentence, " ");
    while(word != NULL)
    {
        //check if word is in positiveWords array
        for(int i=0; i<10; i++)
        {
            if(strcmp(word, positiveWords[i]) == 0)
            {
                sentimentScore++;
            }
        }

        //check if word is in negativeWords array
        for(int i=0; i<10; i++)
        {
            if(strcmp(word, negativeWords[i]) == 0)
            {
                sentimentScore--;
            }
        }

        word = strtok(NULL, " ");
    }

    return sentimentScore;
}

int main()
{
    char sentence[100];

    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);
    
    //remove newline character from the end of the sentence
    if(sentence[strlen(sentence)-1] == '\n')
    {
        sentence[strlen(sentence)-1] = '\0';
    }

    //calculate sentiment score of the sentence
    int sentimentScore = getSentimentScore(sentence);

    printf("Sentiment Score: %d\n", sentimentScore);

    if(sentimentScore > 0)
    {
        printf("This sentence has a positive sentiment.\n");
    }
    else if(sentimentScore < 0)
    {
        printf("This sentence has a negative sentiment.\n");
    }
    else
    {
        printf("This sentence has a neutral sentiment.\n");
    }

    return 0;
}