//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Cryptic
#include <stdio.h>
#include <string.h>

// Function to detect spam words in a given sentence
void spamDetector(char sentence[])
{
    char spamWords[][20] = {"buy", "discount", "free", "money", "offer", 
                            "win", "prize", "limited", "opportunity", "cash"};

    int count = 0;

    // Removing punctuations and converting the sentence to lowercase
    for(int i = 0; i < strlen(sentence); i++)
    {
        if(sentence[i] == ',' || sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?')
        {
            sentence[i] = ' ';
        }

        else
        {
            sentence[i] = tolower(sentence[i]);
        }
    }

    // Counting the number of spam words present in the sentence
    char *token = strtok(sentence, " ");

    while(token != NULL)
    {
        for(int i = 0; i < 10; i++)
        {
            if(strcmp(token, spamWords[i]) == 0)
            {
                count++;
            }
        }

        token = strtok(NULL, " ");
    }

    // Printing the result based on the number of spam words
    if(count == 0)
    {
        printf("No spam detected.\n");
    }

    else if(count == 1)
    {
        printf("1 spam word detected.\n");
    }

    else
    {
        printf("%d spam words detected.\n", count);
    }
}

int main()
{
    char str[100];

    printf("Enter a sentence: ");
    fgets(str, 100, stdin);

    // Removing the newline character at the end of the sentence
    str[strlen(str)-1] = '\0';

    spamDetector(str);

    return 0;
}