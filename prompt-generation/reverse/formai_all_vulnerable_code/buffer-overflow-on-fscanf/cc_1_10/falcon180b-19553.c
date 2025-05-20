//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DICT_SIZE 100000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int freq;
    int code;
} dict_entry;

dict_entry dict[MAX_DICT_SIZE];
int dict_size = 0;

int get_code(char *word) {
    int i;
    for (i = 0; i < dict_size; i++) {
        if (strcmp(dict[i].word, word) == 0) {
            return dict[i].code;
        }
    }
    return -1;
}

void generate_codes() {
    int i;
    for (i = 0; i < dict_size; i++) {
        dict[i].code = i;
    }
}

void encode(FILE *in, FILE *out) {
    char word[MAX_WORD_LENGTH];
    char *p = fgets(word, MAX_WORD_LENGTH, in);
    while (p!= NULL) {
        int code = get_code(word);
        if (code == -1) {
            fprintf(out, "%s ", word);
        } else {
            fprintf(out, "%d ", code);
        }
        p = fgets(word, MAX_WORD_LENGTH, in);
    }
}

void decode(FILE *in, FILE *out) {
    int code;
    char word[MAX_WORD_LENGTH];
    while (fscanf(in, "%d", &code)!= EOF) {
        if (code >= 0 && code < dict_size) {
            fprintf(out, "%s ", dict[code].word);
        } else {
            fprintf(out, "%d ", code);
        }
    }
}

int main() {
    FILE *in, *out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");

    int i, j;
    char word[MAX_WORD_LENGTH];
    while (fscanf(in, "%s", word)!= EOF) {
        int len = strlen(word);
        for (i = 0; i < len; i++) {
            if (isalpha(word[i])) {
                word[i] = tolower(word[i]);
            }
        }
        if (dict_size >= MAX_DICT_SIZE) {
            break;
        }
        int freq = 1;
        for (j = 0; j < dict_size; j++) {
            if (strcmp(dict[j].word, word) == 0) {
                freq = dict[j].freq + 1;
                break;
            }
        }
        if (j == dict_size) {
            dict[dict_size].word = strdup(word);
            dict[dict_size].freq = freq;
            dict_size++;
        } else {
            dict[j].freq = freq;
        }
    }

    generate_codes();

    rewind(in);
    encode(in, out);

    rewind(out);
    decode(out, out);

    fclose(in);
    fclose(out);

    return 0;
}