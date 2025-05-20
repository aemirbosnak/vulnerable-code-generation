//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50

struct word {
    char word[MAX_WORD_LEN];
    int frequency;
};

int compare_words(const void *a, const void *b) {
    struct word *word_a = (struct word *) a;
    struct word *word_b = (struct word *) b;

    return strcmp(word_a->word, word_b->word);
}

void print_word_frequency(struct word *word_list, int num_words) {
    qsort(word_list, num_words, sizeof(struct word), compare_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_list[i].word, word_list[i].frequency);
    }
}

int main() {
    FILE *resume_file;
    char line[MAX_WORD_LEN];
    char word[MAX_WORD_LEN];
    struct word word_list[MAX_WORDS];
    int num_words = 0;

    resume_file = fopen("resume.txt", "r");

    if (resume_file == NULL) {
        printf("Error: could not open resume file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LEN, resume_file)!= NULL) {
        int word_count = 0;

        for (int i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                word[word_count++] = tolower(line[i]);
            } else {
                if (word_count > 0) {
                    word[word_count] = '\0';
                    strcpy(word_list[num_words].word, word);
                    word_list[num_words].frequency++;
                    num_words++;
                    word_count = 0;
                }
            }
        }

        if (word_count > 0) {
            word[word_count] = '\0';
            strcpy(word_list[num_words].word, word);
            word_list[num_words].frequency++;
            num_words++;
        }
    }

    fclose(resume_file);

    print_word_frequency(word_list, num_words);

    return 0;
}