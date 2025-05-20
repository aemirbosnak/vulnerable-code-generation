//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct word {
    char word[MAX_WORD_LENGTH];
} Word;

Word words[MAX_WORDS];
int num_words;

void generate_conspiracy_theory(int num_sentences) {
    srand(time(NULL));
    for (int i = 0; i < num_words; i++) {
        words[i].word[0] = '\0';
    }
    num_words = 0;

    FILE *fp = fopen("conspiracy_theory_words.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file conspiracy_theory_words.txt\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        if (num_words >= MAX_WORDS) {
            break;
        }
        strcpy(words[num_words].word, line);
        num_words++;
    }

    fclose(fp);

    for (int i = 0; i < num_sentences; i++) {
        printf("Sentence %d: ", i + 1);
        for (int j = 0; j < num_words; j++) {
            int word_index = rand() % num_words;
            printf("%s ", words[word_index].word);
        }
        printf("\n");
    }
}

int main() {
    int num_sentences;
    printf("Enter the number of sentences in the conspiracy theory: ");
    scanf("%d", &num_sentences);

    generate_conspiracy_theory(num_sentences);

    return 0;
}