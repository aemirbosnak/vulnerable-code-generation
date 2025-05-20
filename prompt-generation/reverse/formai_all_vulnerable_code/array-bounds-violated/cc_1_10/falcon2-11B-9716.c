//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char book[100];
    int i, j, n;
    char word[100];
    char last_word[100];
    char first_word[100];
    char middle_word[100];
    char previous_word[100];
    char next_word[100];
    
    printf("Please enter the name of the ebook: ");
    scanf("%s", book);
    
    FILE *file = fopen(book, "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    
    fseek(file, 0, SEEK_END);
    n = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    for (i = 0; i < n; i++)
    {
        fread(&word, sizeof(char), 1, file);
        word[strlen(word) - 1] = '\0';
        
        if (i == 0)
        {
            strcpy(first_word, word);
            strcpy(middle_word, word);
            strcpy(last_word, word);
        }
        else
        {
            if (strcmp(word, last_word)!= 0)
            {
                strcpy(last_word, word);
            }
            
            if (strcmp(word, middle_word)!= 0)
            {
                strcpy(middle_word, word);
            }
            
            if (strcmp(word, first_word)!= 0)
            {
                strcpy(first_word, word);
            }
        }
        
        if (i > 0)
        {
            strcpy(previous_word, word);
        }
        
        if (i < n - 1)
        {
            strcpy(next_word, word);
        }
    }
    
    fclose(file);
    
    printf("The ebook is as follows:\n");
    printf("First word: %s\n", first_word);
    printf("Middle word: %s\n", middle_word);
    printf("Last word: %s\n", last_word);
    printf("Previous word: %s\n", previous_word);
    printf("Next word: %s\n", next_word);
    
    return 0;
}