//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char** argv)
{
    int c, i = 0, j = 0, l = 0, n = 0;
    char* s = NULL;
    char** t = NULL;

    if (argc == 2) s = argv[1];
    else {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE* f = fopen(s, "r");
    if (f == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    while ((c = fgetc(f)) != EOF) {
        if (c == '\n') {
            l++;
            n = 0;
        } else if (c == ',') {
            n++;
        }
    }

    fclose(f);

    f = fopen(s, "r");
    if (f == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    t = malloc((l + 1) * sizeof(char*));
    for (i = 0; i < l + 1; i++) {
        t[i] = malloc((n + 1) * sizeof(char));
    }

    i = 0;
    j = 0;
    l = 0;
    while ((c = fgetc(f)) != EOF) {
        if (c == '\n') {
            t[i][j] = '\0';
            j = 0;
            l++;
            i++;
            n = 0;
        } else if (c == ',') {
            t[i][j] = '\0';
            j = 0;
            n++;
        } else {
            t[i][j++] = c;
        }
    }

    t[i][j] = '\0';

    for (i = 0; i < l; i++) {
        for (j = 0; j < n; j++) {
            printf("%s ", t[i][j]);
        }
        printf("\n");
    }

    fclose(f);

    for (i = 0; i < l; i++) {
        free(t[i]);
    }
    free(t);

    return 0;
}