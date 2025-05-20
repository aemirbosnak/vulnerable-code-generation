//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 1024
#define MAX_PATTERN_LEN 32

typedef struct {
    char *str;
    size_t len;
} pattern_t;

void init_patterns(pattern_t *pat) {
    pat[0].str = "ABC";
    pat[0].len = 3;

    pat[1].str = "XYZ";
    pat[1].len = 3;

    pat[2].str = "ABCD";
    pat[2].len = 4;
}

int match_pattern(char *str, pattern_t *pat) {
    size_t i, j;
    for (i = 0; i < pat[0].len; i++) {
        if (str[i] != pat[0].str[i]) {
            return 0;
        }
    }

    for (j = 1; j < sizeof(pat) / sizeof(pat[0]); j++) {
        if (strncmp(str + i, pat[j].str, pat[j].len) == 0) {
            return j;
        }
    }

    return -1;
}

int main() {
    pattern_t pat[3];
    init_patterns(pat);

    char str[MAX_STR_LEN];
    gets(str);

    int match_index = match_pattern(str, pat);
    if (match_index == -1) {
        printf("No match found\n");
    } else {
        printf("Match found at index %d\n", match_index);
    }

    return 0;
}