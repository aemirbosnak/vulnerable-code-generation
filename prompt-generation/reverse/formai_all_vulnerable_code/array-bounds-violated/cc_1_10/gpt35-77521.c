//FormAI DATASET v1.0 Category: Spell checking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100 // Maximum word length
 
int check_spelling(char *word);
int min(int a, int b, int c);
int edit_distance(char *word1, char *word2);
 
int main()
{
    char input_word[MAXLEN];
    printf("Enter a word to check spelling:\n");
    fgets(input_word, MAXLEN, stdin); // Read user input
 
    // Remove newline character from input, if present
    int word_len = strlen(input_word);
    if (input_word[word_len-1] == '\n')
        input_word[word_len-1] = '\0';
 
    // Lowercase the input word
    int i;
    for (i = 0; input_word[i]; i++)
        input_word[i] = tolower(input_word[i]);
 
    // Check spelling of input word
    int result = check_spelling(input_word);
    if (result == 1)
        printf("%s is spelled correctly.\n", input_word);
    else
        printf("%s is spelled incorrectly.\n", input_word);
 
    return 0;
}
 
// Check if a given word is spelled correctly (returns 1 if correct, 0 if incorrect)
int check_spelling(char *word)
{
    FILE *fp;
    char dict_word[MAXLEN];
    int i, dist;
    fp = fopen("dictionary.txt", "r"); // Open dictionary file
    if (fp == NULL) // Check if file opened successfully
    {
        printf("Error: could not open dictionary file\n");
        exit(1);
    }
 
    while (fgets(dict_word, MAXLEN, fp) != NULL) // Loop through dictionary words
    {
        // Remove newline character from dictionary word, if present
        int dict_len = strlen(dict_word);
        if (dict_word[dict_len-1] == '\n')
            dict_word[dict_len-1] = '\0';
 
        // Lowercase the dictionary word
        for (i = 0; dict_word[i]; i++)
            dict_word[i] = tolower(dict_word[i]);
 
        // Check if dictionary word equals input word (spelled correctly)
        if (strcmp(dict_word, word) == 0)
        {
            fclose(fp); // Close dictionary file
            return 1;
        }
 
        // Check if dictionary word has an edit distance of 1 from input word
        dist = edit_distance(dict_word, word);
        if (dist == 1)
        {
            fclose(fp); // Close dictionary file
            return 0;
        }
    }
 
    fclose(fp); // Close dictionary file
    return 0;
}
 
// Calculate minimum of three integers
int min(int a, int b, int c)
{
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b <= c)
        return b;
    else
        return c;
}
 
// Calculate Levenshtein edit distance between two words
int edit_distance(char *word1, char *word2)
{
    int m = strlen(word1);
    int n = strlen(word2);
    int i, j, d[m+1][n+1];
 
    for (i = 0; i <= m; i++)
        d[i][0] = i;
    for (j = 0; j <= n; j++)
        d[0][j] = j;
 
    for (j = 1; j <= n; j++)
    {
        for (i = 1; i <= m; i++)
        {
            if (word1[i-1] == word2[j-1])
                d[i][j] = d[i-1][j-1];
            else
                d[i][j] = min(d[i-1][j] + 1, d[i][j-1] + 1, d[i-1][j-1] + 1);
        }
    }
 
    return d[m][n];
}