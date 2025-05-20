//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define MAX_LINE_LEN 1000

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LEN];
    char word[MAX_WORD_LEN];
    int len;
    int count = 0;
    int word_count = 0;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        len = strlen(line);
        line[len - 1] = '\0'; // remove newline character

        word[0] = '\0';
        strcat(word, " ");
        strcat(word, line);
        len = strlen(word);
        word_count = 0;

        for (int i = 0; i < len; i++) {
            if (isalpha(word[i])) {
                word_count++;
            }
        }

        count += word_count;
    }

    printf("Total number of words in the file: %d\n", count);

    fclose(fp);
    return 0;
}