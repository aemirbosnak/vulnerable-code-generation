//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>

#define MAX_WORDS 1000
#define MAX_CLUSTERS 10
#define MAX_LENGTH 100

typedef struct {
    char word[MAX_LENGTH];
    int count;
    int cluster;
} Word;

typedef struct {
    char cluster_center[MAX_LENGTH];
    int count;
} Cluster;

typedef struct {
    Word words[MAX_WORDS];
    Cluster clusters[MAX_CLUSTERS];
    int num_words;
    int num_clusters;
} Summarizer;

void init_summarizer(Summarizer *summarizer) {
    int i, j;

    for (i = 0; i < MAX_WORDS; i++) {
        strcpy(summarizer->words[i].word, " ");
        summarizer->words[i].count = 0;
        summarizer->words[i].cluster = -1;
    }

    for (i = 0; i < MAX_CLUSTERS; i++) {
        strcpy(summarizer->clusters[i].cluster_center, " ");
        summarizer->clusters[i].count = 0;
    }

    summarizer->num_words = 0;
    summarizer->num_clusters = 0;
}

void add_word(Summarizer *summarizer, const char *word) {
    int i, j;

    for (i = 0; i < summarizer->num_clusters; i++) {
        for (j = 0; j < MAX_CLUSTERS; j++) {
            if (strcmp(summarizer->clusters[i].cluster_center, word) == 0) {
                summarizer->clusters[i].count++;
                return;
            }
        }
    }

    if (summarizer->num_words >= MAX_WORDS) {
        printf("Error: Too many words in the text\n");
        exit(1);
    }

    for (i = 0; i < MAX_CLUSTERS; i++) {
        if (summarizer->clusters[i].count == 0) {
            strcpy(summarizer->clusters[i].cluster_center, word);
            summarizer->clusters[i].count = 1;
            break;
        }
    }

    strcpy(summarizer->words[summarizer->num_words].word, word);
    summarizer->words[summarizer->num_words].count = 1;
    summarizer->num_words++;
}

void summarize(Summarizer *summarizer, const char *text) {
    int i, j, k;
    char *word;
    int words_to_replace = 0;

    for (i = 0; i < summarizer->num_clusters; i++) {
        if (summarizer->clusters[i].count == 0) {
            continue;
        }

        for (j = 0; j < summarizer->num_words; j++) {
            if (summarizer->words[j].cluster == i) {
                word = strtok(text, " \t\n");
                while (word!= NULL) {
                    if (strcmp(summarizer->words[j].word, word) == 0) {
                        words_to_replace++;
                        word = strtok(NULL, " \t\n");
                        break;
                    }
                }
            }
        }
    }

    printf("Cluster centers:\n");
    for (i = 0; i < summarizer->num_clusters; i++) {
        printf("%s\t%d\n", summarizer->clusters[i].cluster_center, summarizer->clusters[i].count);
    }

    printf("Replacing words:\n");
    for (i = 0; i < summarizer->num_words; i++) {
        if (summarizer->words[i].count == 0) {
            continue;
        }

        for (j = 0; j < summarizer->num_clusters; j++) {
            if (summarizer->words[i].cluster == j) {
                for (k = 0; k < words_to_replace; k++) {
                    printf("%s -> %s\n", summarizer->words[i].word, summarizer->clusters[j].cluster_center);
                    strcpy(summarizer->words[i].word, summarizer->clusters[j].cluster_center);
                }
            }
        }
    }
}

int main() {
    char text[MAX_LENGTH];
    Summarizer summarizer;

    printf("Enter the text to summarize:\n");
    scanf("%s", text);

    init_summarizer(&summarizer);

    for (;;) {
        printf("Enter a word: ");
        fgets(text, MAX_LENGTH, stdin);
        add_word(&summarizer, text);
        if (strcmp(text, "done") == 0) {
            break;
        }
    }

    summarize(&summarizer, text);

    return 0;
}