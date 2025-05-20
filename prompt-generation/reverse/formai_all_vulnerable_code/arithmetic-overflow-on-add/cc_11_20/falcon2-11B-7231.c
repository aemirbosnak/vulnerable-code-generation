//Falcon2-11B DATASET v1.0 Category: Text processing ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 20

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Cannot open file");
        exit(EXIT_FAILURE);
    }

    char word[MAX_LENGTH];
    int word_count[MAX_WORDS];
    int word_freq[MAX_WORDS];
    int i, j;

    while (fgets(word, MAX_LENGTH, fp)) {
        word[strcspn(word, "\n")] = 0; // remove trailing newline
        if (strlen(word) > 0) {
            word_count[i]++;
            word_freq[i] = word_count[i];
        }
        i++;
    }
    fclose(fp);

    int max_freq = 0;
    int max_index = 0;
    for (i = 0; i < MAX_WORDS; i++) {
        if (word_freq[i] > max_freq) {
            max_freq = word_freq[i];
            max_index = i;
        }
    }

    char *most_common_words[MAX_WORDS];
    int most_common_freq[MAX_WORDS];
    for (i = 0; i < max_index; i++) {
        most_common_words[i] = NULL;
        most_common_freq[i] = 0;
    }
    for (i = 0; i < max_index; i++) {
        if (word_freq[i] > 0) {
            most_common_words[i] = strdup(word_freq[i] > 1? word_freq[i] : "word");
            most_common_freq[i] = word_freq[i];
        }
    }
    printf("The 10 most common words are:\n");
    for (i = 0; i < max_index; i++) {
        printf("%s: %d\n", most_common_words[i], most_common_freq[i]);
    }

    return 0;
}