//FormAI DATASET v1.0 Category: Text Summarizer ; Style: shape shifting
#include<stdio.h>
#include<string.h>

// Function to remove extra spaces from the string
void remove_extra_spaces(char* string)
{
    int count = 0;
    for (int i = 0; string[i]; i++)
    {
        if (string[i] != ' ')
            string[count++] = string[i];
        if (string[i] == ' ' && string[i + 1] != ' ')
            string[count++] = string[i];
    }
    string[count] = '\0';
}

// Function to extract the summary from the string
void extract_summary(char *string, int length)
{
    int count = 0;
    char summary[300];
    for (int i=0; i<strlen(string); i++)
    {
        if (string[i] == '.')
        {
            summary[count] = string[i];
            count++;
            if (count >= length)
            {
                break;
            }
        }
        else
        {
            summary[count] = string[i];
            count++;
        }
    }
    printf("\nSummary: %s", summary);
}

int main()
{
    char input_string[1000]; // Variable to store the input string
    printf("Enter the text to summarize: ");
    fgets(input_string, 1000, stdin); // Get input text from user
    remove_extra_spaces(input_string); // Remove extra spaces from the input string
    int summary_length;
    printf("Enter the length of the summary: ");
    scanf("%d", &summary_length); // Get the desired length of the summary from the user
    extract_summary(input_string, summary_length); // Extract the summary and print it
    return 0;
}