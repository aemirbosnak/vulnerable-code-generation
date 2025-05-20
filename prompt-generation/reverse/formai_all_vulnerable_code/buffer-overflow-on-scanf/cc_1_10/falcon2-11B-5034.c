//Falcon2-11B DATASET v1.0 Category: Alien Language Translator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 100

int main() {
    char words[MAX_WORDS][MAX_LENGTH];
    int num_words = 0;
    
    printf("Enter a sentence in English: ");
    scanf("%s", words[0]);
    num_words++;
    
    while (1) {
        printf("Enter a word in English: ");
        scanf("%s", words[num_words]);
        if (strcmp(words[num_words], "") == 0) {
            break;
        }
        num_words++;
    }
    
    char alien_words[MAX_WORDS][MAX_LENGTH];
    int num_alien_words = 0;
    
    printf("Enter a sentence in Alien Language: ");
    scanf("%s", alien_words[0]);
    num_alien_words++;
    
    while (1) {
        printf("Enter a word in Alien Language: ");
        scanf("%s", alien_words[num_alien_words]);
        if (strcmp(alien_words[num_alien_words], "") == 0) {
            break;
        }
        num_alien_words++;
    }
    
    int i = 0;
    while (i < num_words) {
        int j = 0;
        while (j < num_alien_words) {
            if (strcmp(words[i], alien_words[j]) == 0) {
                alien_words[j][0] = 'Z';
                j++;
            } else {
                j++;
            }
        }
        i++;
    }
    
    printf("Translated sentence in Alien Language: ");
    for (i = 0; i < num_alien_words; i++) {
        printf("%s ", alien_words[i]);
    }
    
    return 0;
}