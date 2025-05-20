//FormAI DATASET v1.0 Category: Spell checking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_LENGTH 200

void toLowerCase(char *word) {
    int i;
    for(i=0; i<strlen(word); i++) {
        word[i] = tolower(word[i]);
    }
}

int spellCheck(char *word, char dict[MAX_DICTIONARY_LENGTH][MAX_WORD_LENGTH], int numWords) {
    int i;
    toLowerCase(word);

    for(i=0; i<numWords; i++) {
        if(strcmp(word, dict[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char dictionary[MAX_DICTIONARY_LENGTH][MAX_WORD_LENGTH];
    char inputWord[MAX_WORD_LENGTH];
    char c;
    int count = 0, i = 0;

    // Read in dictionary file
    FILE *file = fopen("dictionary.txt", "r");
    if(file == NULL) {
        printf("Dictionary file not found!\n");
        exit(1);
    }

    printf("Dictionary:\n");

    // Store dictionary words
    while((c = fgetc(file)) != EOF) {
        if(c == '\n') {
            dictionary[count][i] = '\0';
            count++;
            i=0;
        } else {
            dictionary[count][i] = c;
            i++;
        }
    }

    fclose(file);

    // Ask for input word and check if spelled correctly
    printf("Enter a word to spell check (or q to quit): ");
    scanf("%s", inputWord);

    while(strcmp(inputWord, "q") != 0) {
        if(spellCheck(inputWord, dictionary, count)) {
            printf("\n%s is spelled correctly!\n", inputWord);
        } else {
            printf("\n%s is spelled incorrectly. Suggestions:\n", inputWord);
            // Generate suggestions for incorrectly spelled word
            int j, k, numSuggestions=0;
            char suggestions[10][MAX_WORD_LENGTH];
            for(j=0; j<count && numSuggestions<10; j++) {
                int distance = 0;
                for(k=0; k<strlen(inputWord); k++) {
                    if(inputWord[k] != dictionary[j][k]) {
                        distance++;
                    }
                    if(distance > 1) {
                        break;
                    }
                }

                if(distance == 1) {
                    strcpy(suggestions[numSuggestions], dictionary[j]);
                    numSuggestions++;
                }
            }

            // Print suggestions
            if(numSuggestions > 0) {
                for(j=0; j<numSuggestions; j++) {
                    printf("%d. %s\n", j+1, suggestions[j]);
                }
            } else {
                printf("Sorry, no suggestions found.\n");
            }
        }

        // Ask for next input word
        printf("\nEnter a word to spell check (or q to quit): ");
        scanf("%s", inputWord);
    }

    return 0;
}