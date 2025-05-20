//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: real-life
#include<stdio.h>
#include<string.h>

//Function to count the number of positive words in the input string
int countPositiveWords(char input[])
{
    int count=0;
    char positive_words[10][20]={"happy","good","great","awesome","fantastic","wonderful","amazing","excellent","joyful","superb"};
    
    char* word = strtok(input, " ");
    while (word != NULL)
    {
        for(int i=0;i<10;i++)
        {
            if(strcmp(word, positive_words[i])==0)
            {
                count++;
                break;
            }
        }
        word = strtok(NULL, " ");
    }
    return count;
}

//Function to count the number of negative words in the input string
int countNegativeWords(char input[])
{
    int count=0;
    char negative_words[10][20]={"sad","bad","terrible","unhappy","disappointing","awful","poor","horrible","miserable","lousy"};
    
    char* word = strtok(input, " ");
    while (word != NULL)
    {
        for(int i=0;i<10;i++)
        {
            if(strcmp(word, negative_words[i])==0)
            {
                count++;
                break;
            }
        }
        word = strtok(NULL, " ");
    }
    return count;
}

//Function to analyze the sentiment of the input string
void analyzeSentiment(char input[])
{
    int positive_count = countPositiveWords(input);
    int negative_count = countNegativeWords(input);
    
    if(positive_count > negative_count)
    {
        printf("The sentiment of the input is Positive.\n");
    }
    else if (positive_count < negative_count)
    {
        printf("The sentiment of the input is Negative.\n");
    }
    else
    {
        printf("The sentiment of the input is Neutral.\n");
    }
}

//Main Function
int main()
{
    char input[100];
    printf("Enter the string to analyze the sentiment: ");
    scanf("%[^\n]", input);
    
    analyzeSentiment(input);
    
    return 0;
}