//Falcon2-11B DATASET v1.0 Category: Word Frequency Counter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

void count_word_frequency(char* filename, int* frequency) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char word[MAX_WORD_LENGTH];
    int count = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (strlen(word) > 0) {
            int i;
            for (i = 0; i < strlen(word); i++) {
                if (word[i] >= 'a' && word[i] <= 'z') {
                    frequency[count]++;
                }
            }
            count++;
        }
    }

    fclose(file);
    printf("Word frequency:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", frequency[i], word[i]? word : "null");
    }
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char filename[100];
    strcpy(filename, argv[1]);
    int frequency[MAX_WORD_LENGTH];
    memset(frequency, 0, sizeof(frequency));

    count_word_frequency(filename, frequency);

    return 0;
}