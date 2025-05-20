//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 1024

typedef struct {
    char *pattern;
    int count;
} pattern_t;

void analyze_log(char *filename, pattern_t *patterns, int num_patterns, int depth) {
    FILE *fp;
    char buf[MAX_BUF_SIZE];
    int i;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    while (fgets(buf, MAX_BUF_SIZE, fp)!= NULL) {
        for (i = 0; i < num_patterns; i++) {
            if (strstr(buf, patterns[i].pattern)!= NULL) {
                patterns[i].count++;
            }
        }
    }

    fclose(fp);

    if (depth > 0) {
        for (i = 0; i < num_patterns; i++) {
            printf("Pattern %s occurs %d times\n", patterns[i].pattern, patterns[i].count);
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s logfile pattern1 [pattern2...]\n", argv[0]);
        exit(1);
    }

    int num_patterns = argc - 2;
    pattern_t patterns[num_patterns];

    for (int i = 0; i < num_patterns; i++) {
        patterns[i].pattern = argv[i + 2];
        patterns[i].count = 0;
    }

    int depth = 1;
    while (depth > 0) {
        analyze_log(argv[1], patterns, num_patterns, depth);
        if (depth > 1) {
            printf("Enter 1 to analyze the log file again or any other key to exit: ");
            scanf("%d", &depth);
        }
    }

    return 0;
}