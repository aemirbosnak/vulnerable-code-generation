//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 1000

// Function prototypes
void loadDictionary(char dictionary[][MAX_WORD_LENGTH], int *wordCount);
int calculateEditDistance(const char *s1, const char *s2);
void findSuggestions(const char *input, char dictionary[][MAX_WORD_LENGTH], int wordCount);

int main() {
    char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int wordCount = 0;
    char input[MAX_WORD_LENGTH];

    // Load the dictionary of words from a file
    loadDictionary(dictionary, &wordCount);

    printf("Enter a word to check its spelling: ");
    scanf("%s", input);
    
    // Convert input to lowercase
    for(int i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }

    // Check if the word is in the dictionary
    int found = 0;
    for(int i = 0; i < wordCount; i++) {
        if(strcmp(input, dictionary[i]) == 0) {
            found = 1;
            break;
        }
    }

    // If not found, suggest corrections
    if(!found) {
        printf("The word '%s' is not found in the dictionary.\n", input);
        findSuggestions(input, dictionary, wordCount);
    } else {
        printf("The word '%s' is spelled correctly!\n", input);
    }

    return 0;
}

void loadDictionary(char dictionary[][MAX_WORD_LENGTH], int *wordCount) {
    FILE *file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open dictionary file.\n");
        exit(EXIT_FAILURE);
    }

    while(fscanf(file, "%s", dictionary[*wordCount]) != EOF) {
        (*wordCount)++;
        if (*wordCount >= DICTIONARY_SIZE) {
            fprintf(stderr, "Dictionary size limit reached.\n");
            break;
        }
    }
    fclose(file);
}

int calculateEditDistance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int **dist = (int **)malloc((len1 + 1) * sizeof(int *));
    
    for(int i = 0; i <= len1; i++) {
        dist[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    for(int i = 0; i <= len1; i++) {
        for(int j = 0; j <= len2; j++) {
            if(i == 0) {
                dist[i][j] = j; // Deletion
            } else if(j == 0) {
                dist[i][j] = i; // Insertion
            } else if(s1[i - 1] == s2[j - 1]) {
                dist[i][j] = dist[i - 1][j - 1]; // No operation
            } else {
                dist[i][j] = 1 + (dist[i - 1][j - 1] < dist[i][j - 1] 
                             ? (dist[i - 1][j - 1] < dist[i - 1][j] 
                             ? dist[i - 1][j] : dist[i][j - 1]) 
                             : dist[i][j - 1]);
            }
        }
    }

    int distance = dist[len1][len2];
    
    for(int i = 0; i <= len1; i++)
        free(dist[i]);
    free(dist);
    
    return distance;
}

void findSuggestions(const char *input, char dictionary[][MAX_WORD_LENGTH], int wordCount) {
    printf("Did you mean:\n");
    
    for(int i = 0; i < wordCount; i++) {
        int distance = calculateEditDistance(input, dictionary[i]);
        
        // Show suggestions with edit distance less than or equal to 2
        if(distance <= 2) {
            printf("- %s\n", dictionary[i]);
        }
    }
}