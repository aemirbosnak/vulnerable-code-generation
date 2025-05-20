//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 5000

int main()
{
    char filename[50];
    printf("Enter file name: ");
    scanf("%s", filename);

    FILE *file;
    file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int freq[MAX_WORDS];
    int num_words = 0;

    char temp_word[MAX_WORD_LENGTH];
    int temp_word_length = 0;
    char c;

    while((c = fgetc(file)) != EOF)
    {
        if(isalpha(c))
        {
            temp_word[temp_word_length++] = tolower(c);
        }
        else if(temp_word_length > 0)
        {
            temp_word[temp_word_length] = '\0';

            int i = 0;
            for(i = 0; i < num_words; i++)
            {
                if(strcmp(words[i], temp_word) == 0)
                {
                    freq[i]++;
                    break;
                }
            }

            if(i == num_words)
            {
                strcpy(words[num_words], temp_word);
                freq[num_words] = 1;
                num_words++;
            }

            temp_word_length = 0;
        }
    }

    fclose(file);

    printf("\nWord\tFrequency\n");

    int i = 0;
    for(i = 0; i < num_words; i++)
    {
        printf("%s\t%d\n", words[i], freq[i]);
    }

    return 0;
}