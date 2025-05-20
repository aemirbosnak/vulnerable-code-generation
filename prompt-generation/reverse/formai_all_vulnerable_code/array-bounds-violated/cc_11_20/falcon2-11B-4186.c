//Falcon2-11B DATASET v1.0 Category: Log analysis ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LEN 100

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LEN];
    int count[MAX_LINE_LEN], i, j, nlines;
    char *words[MAX_LINE_LEN];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return 2;
    }

    nlines = 0;
    while (fgets(line, MAX_LINE_LEN, fp)) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }
        nlines++;
    }
    fclose(fp);

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return 3;
    }

    for (i = 0; i < nlines; i++) {
        words[i] = strtok(line, " \t\n");
        count[i] = 0;
    }

    for (i = 0; i < nlines; i++) {
        j = 0;
        while (words[i][j]!= '\0') {
            count[i]++;
            j++;
        }
    }

    for (i = 0; i < nlines; i++) {
        if (count[i] > 0) {
            printf("%s: %d\n", line, count[i]);
        }
    }

    fclose(fp);
    return 0;
}