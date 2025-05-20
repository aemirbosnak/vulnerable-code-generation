//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: authentic
#include<stdio.h>
#include<string.h>

//function to check the sentiment of a given string
int sentimentAnalysis(char input[])
{
    int posWordsCount = 0, negWordsCount = 0, score = 0;

    //list of positive and negative words
    char positiveWords[10][20] = {"happy", "good", "awesome", "fantastic", "great", "excellent", "love", "like", "admire", "enjoy"};
    char negativeWords[10][20] = {"sad", "bad", "awful", "terrible", "poor", "hate", "dislike", "detest", "unhappy", "disgusting"};

    //splitting the input string into words using delimiter " "
    char *word = strtok(input, " ");

    while(word != NULL)
    {
        //comparing each word with positive and negative word list
        for(int i = 0; i < 10; i++)
        {
            //if the word is found in positive list, increment positive word count
            if(strcmp(word, positiveWords[i]) == 0)
            {
                posWordsCount++;
                break;
            }
            //if the word is found in negative list, increment negative word count
            else if(strcmp(word, negativeWords[i]) == 0)
            {
                negWordsCount++;
                break;
            }
        }
        //get the next word
        word = strtok(NULL, " ");
    }

    //calculate the score
    score = posWordsCount - negWordsCount;

    //return the sentiment score
    return score;
}

int main()
{
    char input[100];

    printf("Enter a sentence: ");
    gets(input);

    //get the sentiment score of the input string
    int score = sentimentAnalysis(input);

    //print the sentiment score and the sentiment of the input string
    if(score > 0)
        printf("The sentiment score of the sentence is %d. The sentence is positive.\n", score);
    else if(score < 0)
        printf("The sentiment score of the sentence is %d. The sentence is negative.\n", score);
    else
        printf("The sentiment score of the sentence is %d. The sentence is neutral.\n", score);

    return 0;
}