//FormAI DATASET v1.0 Category: Text Summarizer ; Style: excited
#include<stdio.h>
#include<string.h>

void summarize(char* text, int length)
{
    char summary[length];
    int i, j = 0;
    
    // Remove extra spaces and new lines
    for(i=0; text[i]!='\0'; i++)
    {
        if((text[i]==' ' || text[i]=='\n') && 
            (text[i+1]==' ' || text[i+1]=='\n'))
            continue;
        summary[j++] = text[i];
    }
    summary[j] = '\0';
    
    // Output the summarized text
    printf("The summary of the text is:\n");
    for(i=0; i<j; i++)
    {
        if(summary[i]=='.' && summary[i+1]==' ')
        {
            printf("%c", summary[i]);
            printf("\n");
            i+=2;
        }
        else
            printf("%c", summary[i]);
    }
}

int main()
{
    char text[10000];
    int length;
    
    printf("Welcome to the C Text Summarizer!\n");
    printf("Please enter the text to summarize:\n");
    fgets(text, 10000, stdin);
    length = strlen(text);
    
    // Check for empty input
    if(length==0)
    {
        printf("Error: Empty input!");
        return 0;
    }
    
    summarize(text, length);
    
    return 0;
}