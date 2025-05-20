//Falcon-180B DATASET v1.0 Category: Data mining ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100
#define MIN_WORD_LENGTH 2
#define STOP_WORDS_FILE "stop_words.txt"
#define DATA_FILE "data.txt"
#define OUTPUT_FILE "output.txt"

char stop_words[MAX_WORDS][MAX_WORD_LENGTH];
int num_stop_words = 0;

void load_stop_words() {
    FILE *fp = fopen(STOP_WORDS_FILE, "r");
    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        strcpy(stop_words[num_stop_words], word);
        num_stop_words++;
    }
    fclose(fp);
}

void load_data() {
    FILE *fp = fopen(DATA_FILE, "r");
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (strlen(word) >= MIN_WORD_LENGTH && strlen(word) <= MAX_WORD_LENGTH) {
                if (isalpha(word[0])) {
                    int i;
                    for (i = 0; i < num_stop_words; i++) {
                        if (strcmp(word, stop_words[i]) == 0) {
                            break;
                        }
                    }
                    if (i == num_stop_words) {
                        printf("%s\n", word);
                    }
                }
            }
            word = strtok(NULL, ",.?!;:");
        }
    }
    fclose(fp);
}

void save_output() {
    FILE *fp = fopen(OUTPUT_FILE, "w");
    int i;
    for (i = 0; i < num_stop_words; i++) {
        fprintf(fp, "%s\n", stop_words[i]);
    }
    fclose(fp);
}

int main() {
    load_stop_words();
    load_data();
    save_output();
    return 0;
}