//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Cryptic
#include<stdio.h>
#include<string.h>

int main()
{
    char sentence[500], word[20], adj1[20], adj2[20], positivity[20];
    int i, j, posCount = 0, negCount = 0;

    printf("Enter a sentence: ");
    fgets(sentence, 500, stdin); //get user input

    printf("Enter the positive adjective: ");
    scanf("%s", adj1);
    printf("Enter synonyms for %s: ", adj1);
    scanf("%s", adj2);

    //check for positivity adjective or synonyms
    if (strstr(sentence, adj1) || strstr(sentence, adj2))
    {
        strcpy(positivity, "POSITIVE");
        posCount++;
    }
    else
    {
        strcpy(positivity, "NEGATIVE");
        negCount++;
    }

    //check for negativity adjective or synonyms
    char negative[20];
    printf("\nEnter the negative adjective: ");
    scanf("%s", negative);
    printf("Enter synonyms for %s: ", negative);
    scanf("%s", word);

    //check for negativity adjective or synonyms
    if (strstr(sentence, negative) || strstr(sentence, word))
    {
        strcpy(positivity, "NEGATIVE");
        negCount++;
    }
    else
    {
        strcpy(positivity, "POSITIVE");
        posCount++;
    }

    //output results
    printf("\nSentiment Analysis Result:\n");
    printf("-------------------------\n");
    printf("Sentence: %s", sentence);
    printf("\nOverall Sentiment: %s\n", positivity);
    printf("%s words count: %d\n", adj1, posCount);
    printf("%s words count: %d\n", negative, negCount);

    return 0;
}