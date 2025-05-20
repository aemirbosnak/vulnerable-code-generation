//Falcon-180B DATASET v1.0 Category: Recursive ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 1000

int count_words_sentences_paragraphs(char* str);
int count_words_sentences_paragraphs_helper(char* str, int* count);

int main()
{
    char str[MAX_SIZE];
    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);
    int count_words, count_sentences, count_paragraphs;
    count_words_sentences_paragraphs_helper(str, &count_words);
    printf("Number of words: %d\n", count_words);
    printf("Number of sentences: %d\n", count_sentences);
    printf("Number of paragraphs: %d\n", count_paragraphs);
    return 0;
}

int count_words_sentences_paragraphs(char* str)
{
    int count_words = 0, count_sentences = 0, count_paragraphs = 0;
    char* word = strtok(str, " ");
    while(word!= NULL)
    {
        count_words++;
        if(isalpha(word[0]))
        {
            count_sentences++;
        }
        word = strtok(NULL, " ");
    }
    count_paragraphs = count_sentences / 4;
    return count_words_sentences_paragraphs_helper(str, &count_words);
}

int count_words_sentences_paragraphs_helper(char* str, int* count)
{
    char* word = strtok(str, " ");
    while(word!= NULL)
    {
        (*count)++;
        word = strtok(NULL, " ");
    }
    return 0;
}