//FormAI DATASET v1.0 Category: Spell checking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_DICT_ENTRIES 10000
#define MAX_SUGGESTIONS 3

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} DictEntry;

// Global variables
DictEntry dictionary[MAX_DICT_ENTRIES];
int num_entries = 0;

// Function prototypes
void readDictionaryFile(char *filename);
int isWordInDictionary(char *word);
int levenshteinDistance(char *s1, char *s2);
void suggestCorrectSpelling(char *word);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [input_file]\n", argv[0]);
        return 1;
    }
    
    readDictionaryFile("dictionary.txt");
    
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    while ((read = getline(&line, &len, fp)) != -1) {
        // Remove newline character
        if (line[read-1] == '\n') {
            line[read-1] = '\0';
        }
        
        // Split line into individual words
        char *word = strtok(line, " ");
        while (word != NULL) {
            // Convert word to lowercase
            for (int i = 0; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
            }
            
            if (!isWordInDictionary(word)) {
                suggestCorrectSpelling(word);
            }
            
            word = strtok(NULL, " ");
        }
    }
    
    fclose(fp);
    if (line) {
        free(line);
    }
    
    return 0;
}

// Read dictionary file into an array of DictEntry structs
void readDictionaryFile(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening dictionary file");
        exit(1);
    }
    
    char line[MAX_WORD_LEN];
    while (fgets(line, MAX_WORD_LEN, fp) != NULL) {
        // Remove newline character
        int len = strlen(line);
        if (line[len-1] == '\n') {
            line[len-1] = '\0';
        }
        
        // Add word to dictionary
        strcpy(dictionary[num_entries].word, line);
        dictionary[num_entries].count = 0;
        num_entries++;
    }
    
    fclose(fp);
}

// Check if a word is in the dictionary
int isWordInDictionary(char *word) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            // Increment count for word
            dictionary[i].count++;
            return 1;
        }
    }
    return 0;
}

// Calculate Levenshtein distance between two strings
int levenshteinDistance(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);
    int d[m+1][n+1];
    
    for (int i = 0; i <= m; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        d[0][j] = j;
    }
    
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            int substitutionCost;
            if (s1[i-1] == s2[j-1]) {
                substitutionCost = 0;
            } else {
                substitutionCost = 1;
            }
            
            int deletion = d[i-1][j] + 1;
            int insertion = d[i][j-1] + 1;
            int substitution = d[i-1][j-1] + substitutionCost;
            
            d[i][j] = deletion;
            if (insertion < d[i][j]) {
                d[i][j] = insertion;
            }
            if (substitution < d[i][j]) {
                d[i][j] = substitution;
            }
        }
    }
    
    return d[m][n];
}

// Suggest correct spelling for a misspelled word
void suggestCorrectSpelling(char *word) {
    printf("%s is not in the dictionary. Did you mean:\n", word);
    
    // Find closest matches to misspelled word
    int distances[num_entries];
    for (int i = 0; i < num_entries; i++) {
        distances[i] = levenshteinDistance(word, dictionary[i].word);
    }
    
    // Print up to three closest matches
    int num_suggestions = 0;
    while (num_suggestions < MAX_SUGGESTIONS) {
        int min_distance = MAX_WORD_LEN;
        int min_index;
        for (int i = 0; i < num_entries; i++) {
            if (distances[i] < min_distance && distances[i] >= 0) {
                min_distance = distances[i];
                min_index = i;
            }
        }
        
        if (min_distance == 0) {
            // Word is already in dictionary
            return;
        } else if (min_distance > MAX_WORD_LEN/2) {
            // Minimum distance is too large for a reasonable suggestion
            return;
        } else {
            printf("- %s\n", dictionary[min_index].word);
            distances[min_index] = -1;
            num_suggestions++;
        }
    }
}