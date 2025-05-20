//Code Llama-13B DATASET v1.0 Category: Spell checking ; Style: accurate
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 32
#define MAX_DISTANCE 2

void spellCheck(char *word, char **dictionary, int numWords) {
    int i, j, dist = 0;
    char *closestWord = NULL;

    for (i = 0; i < numWords; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            printf("Correct spelling: %s\n", dictionary[i]);
            return;
        }

        dist = editDistance(word, dictionary[i]);
        if (dist <= MAX_DISTANCE) {
            if (closestWord == NULL || dist < editDistance(closestWord, dictionary[i])) {
                closestWord = dictionary[i];
            }
        }
    }

    if (closestWord != NULL) {
        printf("Did you mean: %s (%d edit distance)\n", closestWord, dist);
    } else {
        printf("No correct spelling found.\n");
    }
}

int editDistance(char *word1, char *word2) {
    int i, j, dist = 0;
    char *tmp1 = malloc(strlen(word1) + 1);
    char *tmp2 = malloc(strlen(word2) + 1);

    strcpy(tmp1, word1);
    strcpy(tmp2, word2);

    for (i = 0; i < strlen(tmp1); i++) {
        for (j = 0; j < strlen(tmp2); j++) {
            if (tmp1[i] != tmp2[j]) {
                dist++;
            }
        }
    }

    free(tmp1);
    free(tmp2);

    return dist;
}

int main() {
    char *dictionary[] = {"hello", "world", "goodbye", "cruel", "world"};
    char word[MAX_WORD_LEN];
    int numWords = sizeof(dictionary) / sizeof(dictionary[0]);

    printf("Enter a word: ");
    scanf("%s", word);

    spellCheck(word, dictionary, numWords);

    return 0;
}