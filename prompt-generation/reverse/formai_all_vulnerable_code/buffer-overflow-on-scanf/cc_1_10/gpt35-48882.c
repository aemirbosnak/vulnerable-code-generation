//FormAI DATASET v1.0 Category: Spell checking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_PARANOID_LEVEL 10

int main() {
    char word[MAX_WORD_LENGTH];
    int paranoid_level;
    printf("Enter word to check: ");
    scanf("%s", word);
    printf("Enter paranoid level (1-10): ");
    scanf("%d", &paranoid_level);
    
    // Load dictionary
    FILE *dictionary_file = fopen("dictionary.txt", "r");
    if (dictionary_file == NULL) {
        printf("Error: could not open dictionary file\n");
        exit(1);
    }
    
    // Check word against dictionary
    int found = 0;
    char dict_word[MAX_WORD_LENGTH];
    while (fscanf(dictionary_file, "%s", dict_word) != EOF) {
        if (strcmp(word, dict_word) == 0) {
            found = 1;
            break;
        }
    }
    fclose(dictionary_file);
    
    if (found) {
        printf("%s is spelled correctly\n", word);
    } else {
        printf("%s is misspelled\n", word);
        int num_suggestions = paranoid_level / 2;
        if (num_suggestions == 0) {
            num_suggestions = 1;
        }
        printf("Suggestions:\n");
        for (int i = 0; i < num_suggestions; i++) {
            // Create suggestions based on paranoid level
            printf(" - %s%c\n", word, i + 'a');
        }
    }
    
    return 0;
}