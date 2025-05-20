//FormAI DATASET v1.0 Category: Spell checking ; Style: futuristic
#include <stdio.h>
#include <string.h>

int main() {
    char input_word[100];
    printf("Enter a word to spell check: ");
    scanf("%s", input_word);
    
    // create dictionary array
    char dictionary[][100] = {"algorithm", "cybersecurity", "neuroscience", "virtualization", "augmented", "reality", "quantum", "computing", "nanotechnology", "blockchain", "biotechnology", "machine", "learning", "artificial", "intelligence", "genomics"};
    
    int num_words = sizeof(dictionary)/sizeof(dictionary[0]);
    int correct = 0;
    
    // check if input word matches a word in the dictionary
    for(int i=0; i<num_words; i++) {
        if(strcmp(input_word, dictionary[i]) == 0) {
            printf("Correct spelling!\n");
            correct = 1;
            break;
        }
    }
    
    // if input word does not match any dictionary words, suggest possible corrections
    if(!correct) {
        printf("Incorrect spelling. Possible corrections:\n");
        for(int i=0; i<num_words; i++) {
            // check for words within 2 edit distances using Levenshtein distance algorithm
            if(levenshtein_distance(input_word, dictionary[i]) <= 2) {
                printf("- %s\n", dictionary[i]);
            }
        }
    }
    
    return 0;
}

int levenshtein_distance(char *word1, char *word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int matrix[len1+1][len2+1];
    
    for(int i=0; i<=len1; i++) {
        matrix[i][0] = i;
    }
    
    for(int i=0; i<=len2; i++) {
        matrix[0][i] = i;
    }
    
    for(int i=1; i<=len1; i++) {
        for(int j=1; j<=len2; j++) {
            int cost = (word1[i-1] == word2[j-1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i-1][j]+1, min(matrix[i][j-1]+1, matrix[i-1][j-1]+cost));
        }
    }
    
    return matrix[len1][len2];
}

int min(int x, int y) {
    return (x > y) ? y : x;
}