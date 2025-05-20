//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 1000
#define MAX_WORDS 100
#define MAX_LENGTH 50

struct sentence {
    char words[MAX_WORDS][MAX_LENGTH];
    int length;
};

struct summary {
    int num_sentences;
    struct sentence sentences[MAX_SENTENCES];
};

void read_file(char* filename, struct summary* summary) {
    FILE* file = fopen(filename, "r");
    char line[MAX_LENGTH];
    int sentence_index = 0;

    while (fgets(line, MAX_LENGTH, file)!= NULL) {
        if (line[0] == '.') {
            if (sentence_index > 0) {
                summary->sentences[sentence_index - 1].length = strlen(line);
            }
            sentence_index++;
        } else {
            int word_index = 0;
            char* word = strtok(line, " ");

            while (word!= NULL) {
                strcpy(summary->sentences[sentence_index - 1].words[word_index], word);
                word_index++;
                word = strtok(NULL, " ");
            }

            summary->sentences[sentence_index - 1].length = word_index;
        }
    }

    fclose(file);
}

void generate_summary(struct summary* summary, int num_sentences) {
    int i, j;
    for (i = 0; i < summary->num_sentences; i++) {
        for (j = 0; j < summary->sentences[i].length; j++) {
            printf("%s ", summary->sentences[i].words[j]);
        }
        printf("\n");
    }
}

int main() {
    char filename[MAX_LENGTH];
    printf("Enter the filename: ");
    scanf("%s", filename);

    struct summary summary;
    read_file(filename, &summary);

    int num_sentences = 3;

    generate_summary(&summary, num_sentences);

    return 0;
}