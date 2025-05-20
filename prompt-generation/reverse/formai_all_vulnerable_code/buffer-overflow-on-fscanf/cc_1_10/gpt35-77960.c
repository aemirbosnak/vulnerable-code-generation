//FormAI DATASET v1.0 Category: Spell checking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_LINE_LENGTH 200

// Function prototypes
int readDictionary(char* fileName, char** dictionary);
char* checkSpelling(char* line, char** dictionary, int dictSize);
void toLowerCase(char* word);

int main(int argc, char* argv[])
{
    // Check that the correct number of arguments are passed in
    if (argc != 3)
    {
        printf("ERROR: Incorrect number of arguments\n");
        printf("Usage: ./spellcheck dictionaryFile inputFile\n");
        exit(1);
    }

    // Read in the dictionary
    char** dictionary = malloc(MAX_LINE_LENGTH * sizeof(char*));
    int dictSize = readDictionary(argv[1], dictionary);

    // Open the input file
    FILE* inputFile = fopen(argv[2], "r");

    // Check that the file was opened successfully
    if (inputFile == NULL)
    {
        printf("ERROR: Could not open input file\n");
        exit(1);
    }

    // Read each line in the input file
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, inputFile) != NULL)
    {
        // Check the spelling of each word in the line
        char* misspelledWord = checkSpelling(line, dictionary, dictSize);

        // Print any misspelled words
        if (misspelledWord != NULL)
        {
            printf("Misspelled word: %s\n", misspelledWord);
        }
    }

    // Close the input file
    fclose(inputFile);

    // Free memory allocated for dictionary
    for (int i = 0; i < dictSize; i++)
    {
        free(dictionary[i]);
    }
    free(dictionary);

    return 0;
}

// Reads in a dictionary file and populates an array of strings with its contents
int readDictionary(char* fileName, char** dictionary)
{
    // Open the dictionary file
    FILE* dictFile = fopen(fileName, "r");

    // Check that the file was opened successfully
    if (dictFile == NULL)
    {
        printf("ERROR: Could not open dictionary file\n");
        exit(1);
    }

    // Read each word in the file and add it to the dictionary array
    char word[MAX_WORD_LENGTH];
    int i = 0;
    while (fscanf(dictFile, "%s", word) == 1)
    {
        dictionary[i] = malloc(MAX_WORD_LENGTH * sizeof(char));
        strcpy(dictionary[i], word);
        i++;
    }

    // Close the dictionary file
    fclose(dictFile);

    return i;
}

// Checks the spelling of each word in a given line and returns any misspelled words
char* checkSpelling(char* line, char** dictionary, int dictSize)
{
    // Loop through each word in the line
    char* word = strtok(line, " ");
    while (word != NULL)
    {
        // Convert the word to lowercase
        toLowerCase(word);

        // Check if the word is in the dictionary
        int found = 0;
        for (int i = 0; i < dictSize; i++)
        {
            if (strcmp(word, dictionary[i]) == 0)
            {
                found = 1;
                break;
            }
        }

        // If the word is not in the dictionary, return it as misspelled
        if (!found)
        {
            return word;
        }

        // Move to the next word in the line
        word = strtok(NULL, " ");
    }

    // If all words in the line are found in the dictionary, return NULL
    return NULL;
}

// Converts a word to lowercase
void toLowerCase(char* word)
{
    for (int i = 0; i < strlen(word); i++)
    {
        word[i] = tolower(word[i]);
    }
}