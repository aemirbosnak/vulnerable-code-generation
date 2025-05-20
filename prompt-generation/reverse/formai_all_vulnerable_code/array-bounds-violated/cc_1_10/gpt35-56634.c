//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void count_frequency(char *filename) {
    int i, j, count = 0;
    char input[1000], *word;
    FILE *fp;
    static char *words[1000];
    int frequencies[1000] = {0};

    fp = fopen(filename, "r");

    if (!fp) {
        printf("Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fgets(input, 1000, fp)) {
        word = strtok(input, " ,.!?\n");

        while (word != NULL) {
            for (i = 0; i < count; i++) {
                if (!strcmp(words[i], word)) {
                    frequencies[i] += 1;
                    break;
                }
            }

            if (i == count) {
                words[count] = strdup(word);
                frequencies[count] += 1;
                count++;
            }

            word = strtok(NULL, " ,.!?\n");
        }
    }

    for (i = 0; i < count; i++) {
        printf("%s: %d\n", words[i], frequencies[i]);
    }

    fclose(fp);    
}

int main(void) {
    char filename[100];

    printf("Enter filename: ");
    fgets(filename, 100, stdin);

    // remove newline character from filename
    int len = strlen(filename);
    if (filename[len-1] == '\n') {
        filename[len-1] = '\0';
    }

    count_frequency(filename);

    return 0;
}