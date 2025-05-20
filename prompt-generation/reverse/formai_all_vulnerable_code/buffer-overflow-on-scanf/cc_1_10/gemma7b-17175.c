//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct Word
{
    char *word;
    struct Word *next;
} Word;

Word *insertWord(Word *head, char *word)
{
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->next = NULL;

    if (head == NULL)
    {
        head = newWord;
    }
    else
    {
        head->next = insertWord(head->next, word);
    }

    return head;
}

int main()
{
    Word *head = NULL;
    char word[20];

    printf("Enter a word: ");
    scanf("%s", word);

    insertWord(head, word);

    printf("Words in the list:\n");
    Word *current = head;
    while (current)
    {
        printf("%s ", current->word);
        current = current->next;
    }

    return 0;
}