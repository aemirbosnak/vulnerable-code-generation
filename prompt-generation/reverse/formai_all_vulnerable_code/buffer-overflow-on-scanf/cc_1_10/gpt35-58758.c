//FormAI DATASET v1.0 Category: Spell checking ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 50

int main() {
    char *dictionary[MAX_NUM_WORDS] = {"apple", "banana", "cherry", "durian", "eggplant"};
    int num_words = 5;
    char input[MAX_WORD_LENGTH];

    printf("Enter a word to check: ");
    scanf("%s", input);

    //Remove punctuation from input string
    for(int i = 0; i < strlen(input); i++) {
        if(ispunct(input[i])) {
            memmove(&input[i], &input[i + 1], strlen(input) - i);
        }
    }

    //Convert input to lowercase
    for(int i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }

    //Check if input is in dictionary
    int found = 0;
    for(int i = 0; i < num_words; i++) {
        if(strcmp(input, dictionary[i]) == 0) {
            found = 1;
            printf("The word \"%s\" is spelled correctly.\n", input);
            break;
        }
    }

    //If not in dictionary, suggest possible corrections
    if(!found) {
        printf("The word \"%s\" is spelled incorrectly. Possible corrections:\n", input);
        for(int i = 0; i < num_words; i++) {
            int distance = levenshtein_distance(input, dictionary[i], strlen(input), strlen(dictionary[i]));
            if(distance <= 2) {
                printf("%s\n", dictionary[i]);
            }
        }
    }

    return 0;
}

//Calculate Levenshtein distance between two strings
int levenshtein_distance(char *s1, char *s2, int len1, int len2) {
    int matrix[len1 + 1][len2 + 1];
    for(int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for(int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }
    for(int i = 1; i <= len1; i++) {
        for(int j = 1; j <= len2; j++) {
            int cost = (tolower(s1[i - 1]) == tolower(s2[j - 1])) ? 0 : 1;
            int deletion = matrix[i - 1][j] + 1;
            int insertion = matrix[i][j - 1] + 1;
            int substitution = matrix[i - 1][j - 1] + cost;
            matrix[i][j] = min(deletion, min(insertion, substitution));
        }
    }
    return matrix[len1][len2];
}

//Find minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}