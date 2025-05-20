//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: Cryptic
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct { char str[100]; int len; } str_t;

#define SWAP(x, y) do{char tmp = (x).str[(x).len-1]; (x).str[(x).len-1] = (y).str[(y).len-1]; (y).str[(y).len-1] = tmp;}while(0)

#define IS_DUP(a, b, len) memmem((a).str, sizeof(b)-1, (b), len)

int main() {
    str_t input, *words, temp;
    int i, j, count, index, dup_len, word_len, len;

    scanf("%s", input.str);
    input.len = strlen(input.str);

    words = (str_t *)calloc(1, sizeof(str_t) * (input.len + 1));
    if (words == NULL) {
        printf("Out of memory.\n");
        return -1;
    }

    strcpy(words[0].str, input.str);
    words[0].len = input.len;
    count = 1;

    for (i = 0; i < input.len; i++) {
        if (isalpha(input.str[i])) {
            word_len = 1;
            j = i + 1;

            while (j < input.len && isalnum(input.str[j])) {
                word_len++;
                j++;
            }

            if (word_len > 0) {
                strncpy(words[count++].str, &input.str[i], word_len);
                words[count-1].len = word_len;
                i += word_len - 1;
            }
        }
    }

    for (i = 1; i < count; i++) {
        dup_len = words[i].len;
        index = 0;

        for (j = 0; j < i; j++) {
            if (dup_len == words[j].len) {
                if (!IS_DUP(words[i], words[j], dup_len)) continue;
                index = 1;
                break;
            }
            if (dup_len < words[j].len) break;
        }

        if (!index) {
            len = words[i].len;
            for (j = i; j > 0 && words[j-1].len > len; j--) {
                SWAP(words[j], words[j-1]);
                len++;
            }
            SWAP(words[j], words[i]);
            i--;
            count++;
        }
    }

    printf("Unique words: \n");
    for (i = 0; i < count; i++) printf("%s\n", words[i].str);

    free(words);
    return 0;
}