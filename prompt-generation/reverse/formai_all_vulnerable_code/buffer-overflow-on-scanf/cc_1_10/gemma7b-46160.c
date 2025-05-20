//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 10

typedef struct CatWord
{
    char *word;
    struct CatWord *next;
} CatWord;

CatWord *createWord(char *word)
{
    CatWord *newWord = malloc(sizeof(CatWord));
    newWord->word = strdup(word);
    newWord->next = NULL;

    return newWord;
}

void translateWord(CatWord *word)
{
    switch (word->word[0])
    {
        case 'a':
            printf("Meow\n");
            break;
        case 'e':
            printf("Purr\n");
            break;
        case 'i':
            printf("Meow-purr\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
}

int main()
{
    CatWord *head = NULL;
    char word[MAX_WORDS];

    printf("Enter a word: ");
    scanf("%s", word);

    head = createWord(word);
    translateWord(head);

    return 0;
}