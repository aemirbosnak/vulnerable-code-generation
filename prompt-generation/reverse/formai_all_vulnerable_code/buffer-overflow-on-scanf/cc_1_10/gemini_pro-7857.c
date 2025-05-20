//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a word is in the dictionary
int check_word(char *word, char **dictionary, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(word, dictionary[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

// Function to find the closest word in the dictionary
char *find_closest_word(char *word, char **dictionary, int size)
{
    int min_distance = strlen(word);
    char *closest_word = NULL;

    for (int i = 0; i < size; i++)
    {
        int distance = levenshtein_distance(word, dictionary[i]);
        if (distance < min_distance)
        {
            min_distance = distance;
            closest_word = dictionary[i];
        }
    }

    return closest_word;
}

// Function to calculate the Levenshtein distance between two words
int levenshtein_distance(char *word1, char *word2)
{
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    int matrix[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++)
    {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++)
    {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            int cost = (word1[i - 1] == word2[j - 1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + cost);
        }
    }

    return matrix[len1][len2];
}

// Function to find the minimum of three numbers
int min(int a, int b, int c)
{
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

// Main function
int main()
{
    // Create a dictionary of words
    char *dictionary[] = {"apple", "banana", "cherry", "dog", "elephant", "fish", "grape", "house", "ice cream", "juice"};
    int size = sizeof(dictionary) / sizeof(dictionary[0]);

    // Get the word to check from the user
    char word[100];
    printf("Enter a word: ");
    scanf("%s", word);

    // Check if the word is in the dictionary
    if (check_word(word, dictionary, size))
    {
        printf("The word is in the dictionary.\n");
    }
    else
    {
        // Find the closest word in the dictionary
        char *closest_word = find_closest_word(word, dictionary, size);

        // Print the closest word
        printf("The closest word in the dictionary is: %s\n", closest_word);
    }

    return 0;
}