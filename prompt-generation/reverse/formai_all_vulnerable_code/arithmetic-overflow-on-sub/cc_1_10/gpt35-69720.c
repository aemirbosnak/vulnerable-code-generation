//FormAI DATASET v1.0 Category: Text Summarizer ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char text[5000]; // Maximum length of the text
    printf("Welcome to the Happy Text Summarizer! \n");
    printf("Enter the text you want to summarize: \n");
    fgets(text, 5000, stdin); // Taking input from user
    printf("\nGreat! I am now summarizing your text... \n");

    size_t len = strlen(text);
    if (len > 0 && text[len-1] == '\n') // Removing the newline character at the end
        text[--len] = '\0';

    char *ptr = strtok(text, " "); // Breaking the text into words
    int count = 0;

    // Counting the number of words in the text
    while(ptr != NULL)
    {
        count++;
        ptr = strtok(NULL, " ");
    }

    printf("Your text has a total of %d words. \n", count);

    int summary_length; // Length of the summary
    printf("Enter the length of the summary you want (in words): \n");
    scanf("%d", &summary_length);

    // Checking if the summary length is valid or not
    if(summary_length > count)
    {
        printf("Error: Summary length is greater than total number of words in the text. Please enter a valid summary length. \n");
        return 0;
    }

    int words_remaining = count - summary_length; // Number of words that will remain after summarization
    char *summary = malloc(summary_length * 10); // Allocating memory for the summary
    int i = 0;
    ptr = strtok(text, " ");

    // Creating the summary
    while(i < summary_length)
    {
        strcat(summary, ptr);
        strcat(summary, " ");
        ptr = strtok(NULL, " ");
        i++;
    }

    // Checking whether there are any words remaining after summarization
    if(words_remaining > 0)
    {
        printf("Here's your happy summary: \n%s...Isn't that amazing?\n", summary);
    }
    else
    {
        printf("Here's your happy summary: \n%s\n", summary);
    }

    printf("Thank you for using the Happy Text Summarizer. Have a nice day! \n");

    return 0;
}