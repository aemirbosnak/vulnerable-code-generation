//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: Linus Torvalds
#ifdef LINUS_MODE
#define CALC_FILE_SIZE(f) do {                                   \
        struct stat st;                                            \
        if (!fstat(fileno(f), &st))                               \
                fsize = st.st_size;                              \
} while (0)
#define ALLOC_PRINT_LINE(line) do {                              \
        size_t sz = strlen(line) + 1;                              \
        if (sz > linesize)                                         \
                linesize = sz;                                     \
        lines = realloc(lines, linesize * (numlines+1));           \
        strcpy(&lines[numlines++], line);                          \
} while (0)
#define PRINT_LINES() do {                                      \
        size_t i;                                                \
        for (i = 0; i < numlines; ++i) {                           \
                size_t l = strlen(&lines[i]);                     \
                putchar('|');                                     \
                fwrite(&lines[i], sizeof(char), l, stdout);         \
                while (l++ < linesize)                             \
                        putchar(' ');                              \
                putchar('|\n');                                   \
        }                                                          \
        putchar('+');                                             \
        for (i = 0; i < linesize; ++i)                             \
                putchar('-');                                     \
        putchar('+');                                             \
        putchar('\n');                                           \
} while (0)

#define PRINT_WORD_COUNTS(ar) do {                               \
        size_t i;                                                \
        for (i = 0; i < MAX_WORDS; ++i) {                          \
                size_t e = strlen(&words[i][0]);                 \
                putchar('|');                                     \
                fwrite(&words[i][0], sizeof(char), e, stdout);     \
                while (e++ < linesize)                             \
                        putchar(' ');                              \
                printf(" %zu\t", ar[i]);                            \
        }                                                          \
        putchar('|');                                             \
        putchar('\n');                                           \
} while (0)

#else

#define CALC_FILE_SIZE(f) fseek(f, 0, SEEK_END); fsize = ftell(f); fseek(f, 0, SEEK_SET);
#define ALLOC_PRINT_LINE(line) lines = realloc(lines, ++numlines * linesize); strcpy(&lines[numlines-1], line);
#define PRINT_LINES() while (--numlines >= 0) { printf("| %s |\n", lines[numlines]); }
#define PRINT_WORD_COUNTS(ar) while (--numwords >= 0) { printf("| %s | %zu\t|\n", words[numwords], ar[numwords]); }

#endif

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
        FILE *f;
        char *linebuf;
        char *p, *tok;
        int fsize, linesize, numlines, numwords;
        size_t len, si = sizeof(char *);
        char **words, **lines;
        unsigned int *counts;
        unsigned int i, t;

        if (argc < 2) {
                fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
                return EXIT_FAILURE;
        }

        if ((f = fopen(argv[1], "r")) == NULL) {
                fprintf(stderr, "Error opening file: %s\n", strerror(errno));
                return EXIT_FAILURE;
        }

        CALC_FILE_SIZE(f);
        linebuf = malloc(fsize);
        if (linebuf == NULL) {
                fprintf(stderr, "Error allocating line buffer\n");
                return EXIT_FAILURE;
        }

        if (fread(linebuf, sizeof(char), fsize, f) != fsize) {
                fprintf(stderr, "Error reading file\n");
                return EXIT_FAILURE;
        }

        fclose(f);

        /* Get words */
        linesize = 0;
        numlines = 0;
        lines = NULL;

        numwords = 0;
        words = NULL;
        counts = NULL;

        len = 0;
        i = 0;
        p = linebuf;
        while (i < fsize) {
                if (*p == '\n' || *p == ' ' || *p == '\t') {
                        if (len > 0) {
                                ALLOC_PRINT_LINE(p-len);
                                if (numwords == 0) {
                                        words = malloc(si);
                                        words[numwords++] = malloc(len+1);
                                        strcpy(words[0], p-len);
                                } else {
                                        for (t = 0; t < numwords; ++t) {
                                                if (!strcmp(words[t], p-len))
                                                        break;
                                        }
                                        if (t == numwords) {
                                                words = realloc(words, (numwords+1) * si);
                                                words[numwords++] = malloc(len+1);
                                                strcpy(words[numwords-1], p-len);
                                        }
                                }
                                counts = realloc(counts, numwords * sizeof(unsigned int));
                                counts[numwords-1]++;
                                len = 0;
                        }
                        *p++;
                        i++;
                        continue;
                }
                p++;
                len++;
                i++;
        }

        if (len > 0)
                ALLOC_PRINT_LINE(p-len);

        free(linebuf);

        printf("Lines:\n");
        PRINT_LINES();
        printf("Words:\n");
        PRINT_WORD_COUNTS(counts);

        for (i = 0; i < numwords; ++i)
                free(words[i]);
        free(words);
        free(counts);
        free(lines);

        return EXIT_SUCCESS;
}