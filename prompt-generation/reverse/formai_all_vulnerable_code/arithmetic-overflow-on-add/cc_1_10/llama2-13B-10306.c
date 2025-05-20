//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#define MAX_LINE_LEN 1024
#define MAX_WORD_LEN 64
#define MAX_CHAR_LEN 64

typedef struct {
    int line_count;
    int word_count;
    int char_count;
} stats_t;

stats_t get_stats(const char *filename) {
    stats_t stats;
    FILE *file = fopen(filename, "r");
    if (!file) {
        errno = EINVAL;
        perror("Failed to open file");
        return stats;
    }

    char line[MAX_LINE_LEN];
    char word[MAX_WORD_LEN];
    char char_buffer[MAX_CHAR_LEN];
    int line_num = 0;
    int word_num = 0;
    int char_num = 0;

    while (fgets(line, MAX_LINE_LEN, file)) {
        line_num++;
        word_num = 0;
        char_num = 0;
        char *p = line;
        while ((p = strchr(p, ' ')) != NULL) {
            word_num++;
            char_num += (p - line) + 1;
            p++;
        }
        if (p == NULL) {
            word_num++;
            char_num += (strlen(line) - 1);
        }
        stats.line_count++;
        stats.word_count += word_num;
        stats.char_count += char_num;
    }
    fclose(file);
    return stats;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    stats_t stats = get_stats(argv[1]);
    printf("File %s contains:\n", argv[1]);
    printf("  Lines: %d\n", stats.line_count);
    printf("  Words: %d\n", stats.word_count);
    printf("  Characters: %d\n", stats.char_count);
    return 0;
}