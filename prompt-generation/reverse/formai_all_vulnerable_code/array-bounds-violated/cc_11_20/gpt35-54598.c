//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Alan Touring
#include<stdio.h>
#include<string.h>

int main()
{
    char text[1000];
    int i,j,l=0,sum=0;
    float avg;
    printf("Enter text for sentiment analysis:\n");
    fgets(text, 1000, stdin); // reading input from user
    l=strlen(text);
    
    // Removing new line character
    if(text[l-1] == '\n')
    {
        text[l-1] = '\0';
    }
    
    // Converting all alphabets to lower case
    for(i=0;i<strlen(text);i++)
    {
        if(text[i]>='A' && text[i]<='Z')
        {
            text[i]=text[i]+32;
        }
    }
    
    //Calculating sentiment score
    for(j=0;j<strlen(text);j++)
    {
        if(text[j]=='a' || text[j]=='e' || text[j]=='i' || text[j]=='o' || text[j]=='u')
        {
            sum++;
        }
        else if(text[j]=='!' || text[j]=='?' || text[j]=='.')
        {
            sum=sum+2;
        }
    }
    
    //Calculating the average sentiment score
    avg=(float)sum/strlen(text);
    
    //Determining the sentiment of the text
    if(avg<1)
    {
        printf("\nThe sentiment of the text is Negative.\n");
    }
    else if(avg>1 && avg<2)
    {
        printf("\nThe sentiment of the text is Neutral.\n");
    }
    else if(avg>=2)
    {
        printf("\nThe sentiment of the text is Positive.\n");
    }
    return 0;
}