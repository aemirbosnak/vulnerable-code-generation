//FormAI DATASET v1.0 Category: Spell checking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char word[100];
    printf("Enter a word: ");
    fgets(word, 100, stdin);

    int len = strlen(word);
    if(word[len-1] == '\n') {
        word[len-1] = '\0';
    }

    char dictionary[][100] = {
        "apple",
        "banana",
        "orange",
        "grape",
        "kiwi"
    };

    int match_found = 0;
    int dictionary_size = sizeof(dictionary) / sizeof(dictionary[0]);

    for(int i=0; i<dictionary_size; i++) {
        if(strcmp(dictionary[i], word) == 0) {
            printf("'%s' is spelled correctly!\n", word);
            match_found = 1;
            break;
        }
    }

    if(!match_found) {
        printf("'%s' is misspelled. Suggestions:\n", word);
        for(int i=0; i<dictionary_size; i++) {
            int wlen = strlen(dictionary[i]);
            if(abs(len - wlen) <= 2) {
                int mistakes = 0;
                for(int j=0; j<wlen; j++) {
                    if(tolower(word[j]) != tolower(dictionary[i][j])) {
                        mistakes++;
                    }
                }
                if(mistakes <= 2) {
                    printf("%s\n", dictionary[i]);
                }
            }
        }
    }
    return 0;
}