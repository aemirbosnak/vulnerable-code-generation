//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: all-encompassing
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

bool isWordChar(char c)
{
    return isalpha(c) || c == '\''; // Allow apostrophes in words
}

int getNextWord(char* buffer, FILE* file)
{
    char c;
    int i = 0;
    while((c = fgetc(file)) != EOF)
    {
        if(!isWordChar(c))
        {
            if(i == 0) // Skip non-words until we find a word character
            {
                continue;
            }
            else
            {
                break;
            }
        }

        if(i < MAX_WORD_LENGTH)
        {
            buffer[i++] = tolower(c); // Convert to lowercase and add to buffer
        }
    }

    buffer[i] = '\0';

    return i;
}

typedef struct wordCount
{
    char word[MAX_WORD_LENGTH + 1];
    int count;
} wordCount;

void addWordToList(wordCount* list, int* size, char* word)
{
    if(*size < MAX_WORDS)
    {
        bool added = false;
        for(int i = 0; i < *size; i++)
        {
            if(strcmp(list[i].word, word) == 0)
            {
                list[i].count++;
                added = true;
                break;
            }
        }

        if(!added) // Word not in list, add it and set count to 1
        {
            strcpy(list[*size].word, word);
            list[*size].count = 1;
            (*size)++;
        }
    }
}

int compareWordCounts(const void* a, const void* b)
{
    const wordCount* wcA = (wordCount*)a;
    const wordCount* wcB = (wordCount*)b;

    return wcB->count - wcA->count; // Sort descending by count
}

void printWordCounts(wordCount* list, int size)
{
    printf("Word Frequencies:\n");
    for(int i = 0; i < size; i++)
    {
        printf("%20s %5d\n", list[i].word, list[i].count);
    }
}

int main()
{
    printf("Enter file name: ");
    char fileName[100];
    scanf("%s", fileName);

    FILE* file = fopen(fileName, "r");
    if(file == NULL)
    {
        printf("File not found!\n");
        return 1;
    }

    wordCount list[MAX_WORDS];
    int listSize = 0;
    char word[MAX_WORD_LENGTH + 1];

    while(getNextWord(word, file) > 0)
    {
        addWordToList(list, &listSize, word);
    }

    fclose(file);

    qsort(list, listSize, sizeof(wordCount), compareWordCounts);

    printWordCounts(list, listSize);

    return 0;
}