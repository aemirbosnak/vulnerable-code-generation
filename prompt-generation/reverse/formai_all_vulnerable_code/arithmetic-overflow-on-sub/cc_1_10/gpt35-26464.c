//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random string
void generateString(char *str, int len)
{
    int i;
    char ch;

    for (i = 0; i < len; i++) 
    {
        ch = 'a' + rand() % 26;
        str[i] = ch;
    }

    str[len] = '\0';
}

int main()
{
    char inputString[100];
    char generatedString[100];
    int len = 50, i, j, k, mistakes = 0, timeTaken;
    clock_t start, end;

    printf("Ready to start typing speed test. Press any key to begin...\n");
    getchar();

    generateString(generatedString, len);
    printf("Type the following: %s\n", generatedString);

    start = clock();
    fgets(inputString, 100, stdin);

    // Compare the two strings
    for (i = 0; generatedString[i] != '\0'; i++)
    {
        if (generatedString[i] != inputString[i])
        {
            mistakes++;
        }
    }

    end = clock();
    timeTaken = (int)(end - start) / CLOCKS_PER_SEC;
    printf("You had %d mistakes in %d seconds\n", mistakes, timeTaken);

    return 0;
}