//FormAI DATASET v1.0 Category: Text Summarizer ; Style: excited
// Welcome to the Amazing Text Summarizer! This program will make your life easier!
// With a few lines of code, you can summarize any lengthy text into a concise and meaningful summary. 

#include <stdio.h>
#include <string.h>

int main()
{
    char text[100000], summary[1000], keyword[100];
    int i, j, flag, len, k, count=0, score, max_score=0, max_index=0;
    
    printf("Are you ready to summarize your text? Let's get started!\n");
    printf("Please enter your text: \n");
    fgets(text, 100000, stdin);
    
    printf("Please enter a keyword to summarize your text: ");
    scanf("%s", keyword);
    
    len = strlen(text);
    
    for (i=0; i<len; i++)
    {
        if (text[i] == '.')
        {
            count++;
        }
    }
    
    for (k=0; k<count/3; k++)
    {
        max_score = 0;
        for (i=0; i<len; i++)
        {
            flag = 1;
            if (text[i] == '.')
            {
                score = 0;
                for (j=i-1; j>=0; j--)
                {
                    if (text[j] == ' ')
                    {
                        break;
                    }
                    if (text[j] == keyword[0])
                    {
                        for (int m=0; m<strlen(keyword); m++)
                        {
                            if (text[j+m] != keyword[m])
                            {
                                flag = 0;
                                break;
                            }
                            else
                            {
                                flag = 1;
                            }
                        }
                    }
                    if (flag == 1)
                    {
                        score++;
                    }
                }
                if (score > max_score)
                {
                    max_score = score;
                    max_index = i;
                }
            }
        }
        for (i=0; i<max_index; i++)
        {
            summary[i] = text[i];
        }
        summary[i] = '\0';
        for (i=max_index; i<len; i++)
        {
            text[i-max_index] = text[i];
        }
        len = len - max_index;
        
    }
    
    printf("\n\nHere is your summarized text:\n\n%s\n\n", summary);
    
    printf("Thanks for using the Amazing Text Summarizer! Hope to see you again!\n");
    
    return 0;
}