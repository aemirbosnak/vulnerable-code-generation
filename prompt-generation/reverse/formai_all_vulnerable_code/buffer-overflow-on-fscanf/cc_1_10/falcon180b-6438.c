//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: Sherlock Holmes
#include <stdio.h>

int main()
{
    char input[100];
    char output[100];
    int i, j, k;
    FILE *fp;

    // Open the file
    fp = fopen("dictionary.txt", "r");

    // Check if the file exists
    if (fp == NULL)
    {
        printf("Error: File not found.\n");
        return 0;
    }

    // Read the contents of the file into an array
    char dictionary[1000];
    fscanf(fp, "%s", dictionary);
    fclose(fp);

    // Get user input
    printf("Enter a sentence to translate:\n");
    scanf("%s", input);

    // Convert the sentence to lowercase
    for (i = 0; i < strlen(input); i++)
    {
        if (input[i] >= 'A' && input[i] <= 'Z')
        {
            input[i] += 32;
        }
    }

    // Convert the input to an array of words
    char *word = strtok(input, " ");
    while (word!= NULL)
    {
        // Check if the word is in the dictionary
        for (j = 0; j < strlen(dictionary); j++)
        {
            if (strcmp(word, dictionary[j]) == 0)
            {
                // Replace the word with its Cat equivalent
                strcpy(output, dictionary[j]);
                break;
            }
        }

        // Append the translated word to the output
        strcat(output, " ");
        strcat(output, word);

        // Get the next word
        word = strtok(NULL, " ");
    }

    // Output the translated sentence
    printf("The translated sentence is:\n%s\n", output);

    return 0;
}