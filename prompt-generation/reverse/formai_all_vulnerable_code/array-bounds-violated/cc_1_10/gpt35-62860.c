//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: happy
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100], words[100][100];
    int i, j, count = 0, total_count = 0;
    
    printf("Welcome to the Happy Word Frequency Counter!\n");
    printf("Please enter a sentence or phrase (maximum 100 characters):\n");
    fgets(input, 100, stdin);
    
    for(i=0; i<strlen(input); i++)
    {
        if(input[i] == ' ') // if a space is detected
        {
            words[count][j] = '\0'; // add a null character at the end to mark the end of a word
            
            count++; // increase the word count
            j = 0; // reset the character count
        }
        else
        {
            words[count][j] = input[i]; // add the character to the current word
            j++; // increase the character count
        }
    }
    words[count][j] = '\0';
    
    total_count = count + 1; // total word count is the number of spaces plus one
    
    printf("\nThanks for your input! Here are the word frequencies:\n");
    printf("----------------------------------------------------\n");
    for(i=0; i<total_count; i++)
    {
        int freq = 1; // start with a frequency of 1 for each word
        if(strcmp(words[i], "") == 0) // if the word is empty, skip it
        {
            continue;
        }
        for(j=i+1; j<total_count; j++)
        {
            if(strcmp(words[i], words[j]) == 0) // if the word is the same as another word in the array
            {
                freq++; // increase the frequency count
                strcpy(words[j], ""); // replace the word with an empty string to mark it as counted
            }
        }
        printf("%s\t : %d\n", words[i], freq); // print the word and its frequency
    }
    printf("----------------------------------------------------\n");
    
    printf("\nThank you for using the Happy Word Frequency Counter! See you again soon!\n");
    
    return 0;
}