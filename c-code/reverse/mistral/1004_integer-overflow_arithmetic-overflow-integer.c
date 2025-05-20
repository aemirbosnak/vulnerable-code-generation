#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char input[100];
    char summary[10];
    int i, len, summary_len = 10;

    if (argc != 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    strcpy(input, argv[1]);
    len = strlen(input);

    for (i = 0; i < len; i++) {
        if (!isalpha(input[i])) {
            input[i] = ' ';
        }
    }

    for (i = 0; i < len; i++) {
        if (!isalpha(input[i])) {
            int j;
            for (j = i + 1; isalpha(input[j]); j++) {
                if (summary_len >= 100) {
                    break;
                }
                summary[summary_len++] = toupper(input[j]);
            }
            summary[summary_len++] = ' ';
            i = j - 1;
        }
    }

    summary[summary_len] = '\0';
    printf("Summary: %s\n", summary);

    return 0;
}
