//FormAI DATASET v1.0 Category: Text processing ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);  // Get input sentence from user
    
    int len = strlen(sentence);  // Get length of sentence
    for(int i = 0; i < len; i++)
    {
        if(sentence[i] >= 'A' && sentence[i] <= 'Z')
        {
            sentence[i] = sentence[i] + 32; // Convert capital letters to small letters
        }
    }
    printf("\nTransformed sentence: %s\n", sentence);
    
    int space_count = 0;
    for(int i = 0; i < len; i++)
    {
        if(sentence[i] == ' ')
        {
            space_count++; // Count spaces in sentence
        }
    }
    printf("\nNumber of spaces in the sentence: %d\n", space_count);
    
    char* words[20];  // Maximum 20 words allowed in sentence
    int word_index = 0, word_start = 0;
    for(int i = 0; i < len; i++)
    {
        if(sentence[i] == ' ')
        {
            // Extract a word from sentence
            char* word = (char*) malloc(sizeof(char) * (i - word_start + 1));
            for(int j = word_start, k = 0; j < i; j++, k++)
            {
                word[k] = sentence[j];
            }
            word[i - word_start] = '\0';
            words[word_index++] = word;
            
            word_start = i + 1;
        }
    }
    // Extract last word from sentence
    char* word = (char*) malloc(sizeof(char) * (len - word_start + 1));
    for(int j = word_start, k = 0; j < len; j++, k++)
    {
        word[k] = sentence[j];
    }
    word[len - word_start] = '\0';
    words[word_index++] = word;
    
    printf("\nWords in the sentence: ");
    for(int i = 0; i < word_index; i++)
    {
        printf("%s ", words[i]);
    }
    
    // Free dynamically allocated memory
    for(int i = 0; i < word_index; i++)
    {
        free(words[i]);
    }
    
    return 0;
}