//FormAI DATASET v1.0 Category: Text Summarizer ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#define MAX 1000

int main()
{
    char summary[MAX], text[MAX];
    int i, j, count = 0;
    float percent;
    printf("Welcome to the Text Summarizer!\n\n");
    
    printf("Please enter your text (up to 1000 characters):\n");
    fgets(text, MAX, stdin);    // capturing inputted text
    
    printf("Enter the percentage of text you want in summary (up to 100):\n");
    scanf("%f", &percent);     // capturing percentage

    if(percent > 100 || percent < 0)    // checking if entered input is valid
    {
        printf("Error! Invalid percentage entered.");
        return 0;
    }

    for(i = 0; text[i] != '\0'; i++)     // counting the number of words
    {
        if(text[i] == ' ' || text[i] == '\n' || text[i] == '\t')
        {
            count++;
        }
    }
    
    int words = (int)(count * (percent / 100));    // calculating number of words in summary
    
    count = 0;
    for(i = 0; text[i] != '\0'; i++)     // replacing new lines and tabs with space
    {
        if(text[i] == '\n' || text[i] == '\t')
        {
            text[i] = ' ';
        }
    }
    
    for(i = 0; text[i] != '\0'; i++)     // removing extra space
    {
        while(text[i] == ' ' && text[i+1] == ' ')
        {
            for(j = i; text[j] != '\0'; j++)
            {
                text[j] = text[j+1];
            }
        }
    }

    for(i = 0; i < words + 1; i++)       // forming summary
    {
        summary[i] = text[i];
        if(text[i] == ' ')
        {
            count++;                         // counting number of words in summary
        }
    }

    summary[i] = '\0';                 // ending summary with null character

    printf("\n\n");
    printf("The summary for your text is as follows:\n");
    printf("%s\n\n", summary);
    printf("Number of words in summary: %d\n", count);

    return 0;
}