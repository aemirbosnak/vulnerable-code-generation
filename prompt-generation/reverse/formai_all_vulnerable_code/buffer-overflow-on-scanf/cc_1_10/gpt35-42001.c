//FormAI DATASET v1.0 Category: Spam Detection System ; Style: active
#include <stdio.h>
#include <string.h>

#define WORD_LENGTH 20
#define MAX_SPAM_WORDS 30
#define MAX_CHAT_SIZE 1000

int main()
{
    char spamList[MAX_SPAM_WORDS][WORD_LENGTH];
    int numSpamWords = 0;
    char chat[MAX_CHAT_SIZE];
    printf("Enter words to be considered as spam (max 30 words, %d character limit): \n", WORD_LENGTH);
    printf("When finished, type 'exit'\n");

    while(numSpamWords < MAX_SPAM_WORDS)
    {
        char newSpam[WORD_LENGTH];
        printf("Enter word %d: ", numSpamWords + 1);
        scanf("%s", newSpam);
        if(strcmp(newSpam, "exit") == 0)
            break;
        strcpy(spamList[numSpamWords], newSpam);
        printf("\"%s\" added to the spam list\n", newSpam);
        numSpamWords++;
    }

    printf("\nEnter chat (max %d characters): \n", MAX_CHAT_SIZE);
    scanf(" %[^\n]s ", chat);

    int numSpamOccurrences = 0;
    char* token = strtok(chat, " ");
    while(token != NULL)
    {
        for(int i = 0; i < numSpamWords; i++)
        {
            if(strcmp(token, spamList[i]) == 0)
            {
                numSpamOccurrences++;
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    if(numSpamOccurrences > 0)
    {
        printf("\nSPAM DETECTED: %d occurrences of spam in chat\n", numSpamOccurrences);
    }
    else
    {
        printf("\nNO SPAM DETECTED in chat\n");
    }

    return 0;
}