//Falcon2-11B DATASET v1.0 Category: Sentiment analysis tool ; Style: irregular
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct Node
{
    char* word;
    int sentiment;
    struct Node* next;
};

struct Node* head = NULL;

void addWord(char* word, int sentiment)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->word, word);
    newNode->sentiment = sentiment;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    struct Node* current = head;
    while(current->next!= NULL)
    {
        current = current->next;
    }

    current->next = newNode;
}

void printSentiment(char* word)
{
    struct Node* current = head;
    while(current!= NULL)
    {
        if(strcmp(word, current->word) == 0)
        {
            printf("Sentiment: %d\n", current->sentiment);
            return;
        }
        current = current->next;
    }
    printf("Word not found\n");
}

int main()
{
    addWord("happy", 5);
    addWord("sad", -5);
    addWord("angry", -3);
    addWord("neutral", 0);

    printf("Enter word: ");
    char word[100];
    scanf("%s", word);

    printSentiment(word);

    return 0;
}