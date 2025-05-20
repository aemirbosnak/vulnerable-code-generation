//Falcon2-11B DATASET v1.0 Category: Word Frequency Counter ; Style: shocked
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct word_freq
{
    char word[50];
    int count;
};

struct word_freq* new_word_freq(char word[], int count)
{
    struct word_freq* freq = (struct word_freq*)malloc(sizeof(struct word_freq));
    strcpy(freq->word, word);
    freq->count = count;
    return freq;
}

void free_word_freq(struct word_freq* freq)
{
    free(freq);
}

int main()
{
    struct word_freq* words[100];
    int word_count = 0;

    printf("Enter a word:\n");
    scanf("%s", words[word_count]->word);
    words[word_count]->count = 1;
    word_count++;

    while(1)
    {
        printf("Enter a word:\n");
        scanf("%s", words[word_count]->word);
        words[word_count]->count = 1;
        word_count++;

        if(word_count >= 100)
        {
            printf("Too many words.\n");
            break;
        }
    }

    printf("Word Frequency:\n");
    for(int i=0; i<word_count; i++)
    {
        printf("%s - %d times\n", words[i]->word, words[i]->count);
    }

    return 0;
}