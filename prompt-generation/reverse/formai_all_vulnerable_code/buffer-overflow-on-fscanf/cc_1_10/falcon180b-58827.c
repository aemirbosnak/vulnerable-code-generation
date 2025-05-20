//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

struct word {
    char word[MAX_WORD_LEN];
    int count;
};

int main() {
    FILE *fp;
    char line[1000];
    char word[MAX_WORD_LEN];
    struct word dict[MAX_WORDS];
    int i, j, len, found, count;

    fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: Dictionary file not found.\n");
        exit(1);
    }

    count = 0;
    while (fscanf(fp, "%s", word)!= EOF) {
        strcpy(dict[count].word, word);
        dict[count].count = 1;
        count++;
    }
    fclose(fp);

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: Input file not found.\n");
        exit(2);
    }

    while (fgets(line, 1000, fp)!= NULL) {
        len = strlen(line);
        for (i = 0; i < len; i++) {
            if (isalpha(line[i])) {
                found = 0;
                for (j = 0; j < count; j++) {
                    if (strcasecmp(line + i, dict[j].word) == 0) {
                        found = 1;
                        dict[j].count++;
                        break;
                    }
                }
                if (!found) {
                    printf("Possible spelling error: %s\n", line + i);
                }
            }
        }
    }

    fclose(fp);

    return 0;
}