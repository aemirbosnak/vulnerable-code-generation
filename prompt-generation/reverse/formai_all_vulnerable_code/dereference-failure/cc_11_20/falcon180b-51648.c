//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 20

struct word {
    char *word;
    int count;
};

int main(int argc, char *argv[]) {
    FILE *fp;
    char ch, word[MAX_WORD_LEN];
    struct word *dict[MAX_WORDS], *curr_dict;
    int dict_size = 0, i, j, found;

    fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            strcpy(word, "");
            while (isalpha(ch)) {
                strcat(word, ch);
                ch = fgetc(fp);
            }
            dict[dict_size++] = (struct word *)malloc(sizeof(struct word));
            dict[dict_size - 1]->word = strdup(word);
            dict[dict_size - 1]->count = 0;
        }
    }

    fclose(fp);

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            strcpy(word, "");
            while (isalpha(ch)) {
                strcat(word, ch);
                ch = fgetc(fp);
            }

            found = 0;
            for (i = 0; i < dict_size; i++) {
                curr_dict = dict[i];
                if (strcmp(curr_dict->word, word) == 0) {
                    curr_dict->count++;
                    found = 1;
                    break;
                }
            }

            if (found == 0) {
                curr_dict = (struct word *)malloc(sizeof(struct word));
                curr_dict->word = strdup(word);
                curr_dict->count = 1;
                dict[dict_size++] = curr_dict;
            }
        }
    }

    fclose(fp);

    printf("Total words found: %d\n", dict_size);

    return 0;
}