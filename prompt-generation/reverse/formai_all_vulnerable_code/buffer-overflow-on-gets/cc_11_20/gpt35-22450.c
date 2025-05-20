//FormAI DATASET v1.0 Category: Text Summarizer ; Style: unmistakable
//Welcome to the C Text Summarizer program!
//This program takes a text input and generates a summarized version of the input.
//Let's get started.

#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, k, n, count, flag;
    char text[500], summary[100];
    
    printf("Enter the text:\n");
    gets(text); //takes the input from user
    
    n=strlen(text); //finds the length of input
    
    summary[0]='S'; summary[1]='u'; summary[2]='m'; summary[3]='m'; //initializes summary with the string "Summ"
    k=4; //points to the first empty index of summary
    
    for(i=0; i<n; ) //iterates through each character of the input
    {
        count=0; flag=0; //initializes count and flag to zero
        
        for(j=i; j<n; j++) //iterates through the remaining characters of the input
        {
            if(text[j]=='.' || text[j]=='?' || text[j]=='!') //checks for end of sentence
            {
                count++; //increments count
                if(count==2) //if count is 2, a sentence has been found
                {
                    flag=1; //sets flag to 1, indicating a sentence has been found
                    break; //exits inner for loop
                }
            }
        }
        
        if(flag==0) //if no sentence is found, exits the program
        {
            printf("Error: Not enough sentences in the input.\n");
            return 0;
        }
        
        for(j=i; j<=k; j++) //copies the sentence to the summary
        {
            summary[j]=text[j];
        }
        
        i=j+1; //updates i to the next sentence
        
        if(k>=96) //if the summary reaches its maximum allowed length of 100 characters, exits the program
        {
            printf("Summary:\n");
            for(j=0; j<k; j++) //prints the summary
            {
                printf("%c", summary[j]);
            }
            printf("\n");
            return 0; //exits the program
        }
        
        k++; //updates k, pointing to the next empty index of summary
        summary[k]=' '; //adds a space after each sentence
    }
    
    printf("Summary:\n");
    for(i=0; i<k; i++) //prints the summary
    {
        printf("%c", summary[i]);
    }
    printf("\n");
    
    return 0; //exits the program
}