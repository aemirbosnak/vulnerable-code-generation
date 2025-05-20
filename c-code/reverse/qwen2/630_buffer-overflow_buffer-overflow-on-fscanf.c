#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 256
#define MAX_WORDS 1000

int main() {
    FILE *file = fopen("words.txt", "r");
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int counts[MAX_WORDS] = {0};
    int count = 0;

    while (count < MAX_WORDS && fscanf(file, "%s", words[count]) != EOF) {
        for (int i = 0; i < count; i++) {
            if (strcmp(words[i], words[count]) == 0) {
                counts[i]++;
                goto next_word;
            }
        }
        strcpy(words[count], words[count]);
        counts[count]++;
        count++;
next_word:
        ;
    }

    fclose(file);

    // Sort words by frequency
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (counts[i] < counts[j]) {
                int temp_count = counts[i];
                char temp_word[MAX_WORD_LENGTH];
                strcpy(temp_word, words[i]);

                counts[i] = counts[j];
                strcpy(words[i], words[j]);

                counts[j] = temp_count;
                strcpy(words[j], temp_word);
            }
        }
    }

    // Print top 1000 words
    for (int i = 0; i < count && i < MAX_WORDS; i++) {
        printf("%s: %d\n", words[i], counts[i]);
    }

    return 0;
}
