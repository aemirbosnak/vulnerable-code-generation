//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DICT_SIZE 10000
#define MAX_CODE_SIZE 4096

typedef struct {
    char *word;
    int code;
} DictEntry;

typedef struct {
    int size;
    int next_code;
    DictEntry *dict;
} Dict;

typedef struct {
    char *text;
    int pos;
    int len;
} TextBuf;

static Dict *dict = NULL;
static TextBuf text_buf;

static void init_dict() {
    dict = malloc(sizeof(Dict));
    dict->size = 0;
    dict->next_code = 256;
    dict->dict = calloc(MAX_DICT_SIZE, sizeof(DictEntry));
}

static void add_dict_entry(char *word, int code) {
    DictEntry *entry = dict->dict + dict->size;
    entry->word = strdup(word);
    entry->code = code;
    dict->size++;
}

static int get_dict_code(char *word) {
    DictEntry *entry = dict->dict;
    int i = 0;
    while (i < dict->size) {
        if (strcmp(entry->word, word) == 0) {
            return entry->code;
        }
        i++;
        entry++;
    }
    return -1;
}

static void encode_text(FILE *out) {
    int i, j;
    char ch;
    int code;

    for (i = 0; i < text_buf.len; i++) {
        ch = text_buf.text[i];
        if (isalpha(ch)) {
            code = get_dict_code(text_buf.text + i);
            if (code == -1) {
                fprintf(out, "%c", ch);
            } else {
                fprintf(out, "%c", code & 0xFF);
                fprintf(out, "%c", (code >> 8) & 0xFF);
            }
        } else {
            fprintf(out, "%c", ch);
        }
    }
}

static void decode_text(FILE *in) {
    int i, j;
    char ch;
    int code;

    while ((ch = fgetc(in))!= EOF) {
        if (ch >= 0 && ch <= 0xFF) {
            fprintf(stdout, "%c", ch);
        } else if ((ch & 0xFF) == 0xFF) {
            code = 0;
            for (j = 0; j < 2; j++) {
                if ((ch >> (8 * j)) & 0xFF) {
                    code |= 1 << j;
                }
            }
            fprintf(stdout, "%c", code + 'A');
        } else {
            fprintf(stdout, "%c", ch);
        }
    }
}

int main(int argc, char **argv) {
    FILE *in, *out;
    char ch;
    int i = 0;

    init_dict();

    in = fopen(argv[1], "rb");
    out = fopen(argv[2], "wb");

    while ((ch = fgetc(in))!= EOF) {
        if (isalpha(ch)) {
            text_buf.text[i++] = ch;
        }
    }
    text_buf.len = i;

    encode_text(out);

    fclose(in);
    fclose(out);

    in = fopen(argv[2], "rb");
    out = fopen(argv[3], "wb");

    decode_text(in);

    fclose(in);
    fclose(out);

    return 0;
}