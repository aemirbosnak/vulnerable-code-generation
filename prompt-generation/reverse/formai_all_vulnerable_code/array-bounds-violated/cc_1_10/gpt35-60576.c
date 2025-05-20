//FormAI DATASET v1.0 Category: Text processing ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 100

// Function to process a word recursively
void processWord(char* word)
{
    int len = strlen(word);
    if (len == 0) return;

    // If first letter is uppercase, convert to lowercase
    if (word[0] >= 'A' && word[0] <= 'Z')
    {
        word[0] += 32;
    }

    // If last letter is lowercase, convert to uppercase
    if (word[len-1] >= 'a' && word[len-1] <= 'z')
    {
        word[len-1] -= 32;
    }

    // Recursive call on the remaining part of the word
    processWord(word+1);
}

// Function to process a line recursively
void processLine(char* line)
{
    // Base case: line is empty
    if (strlen(line) == 0)
    {
        return;
    }
    
    // Get the first word
    char* word = strtok(line, " ");
    processWord(word);

    // Process the rest of the line recursively
    processLine(line+strlen(word)+1);
}

// Main function
int main()
{
    // Input buffer
    char buffer[MAX_BUFFER_SIZE];

    // Read input from the user
    printf("Enter text to process:\n");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);
    buffer[strlen(buffer)-1] = '\0'; // Remove newline character from input

    // Process each line recursively
    char* line = strtok(buffer, "\n");
    while (line != NULL)
    {
        processLine(line);
        printf("%s\n", line);
        line = strtok(NULL, "\n");
    }

    return 0;
}