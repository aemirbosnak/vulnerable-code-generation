//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char* pattern;
    int pattern_len;
    int count;
} pattern_t;

int main(int argc, char** argv) {
    int fd;
    char* filename;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    FILE* fp;
    pattern_t* patterns = NULL;
    int num_patterns = 0;
    int match_count = 0;

    // Check if the correct number of arguments are provided
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <filename> <pattern1> [pattern2...]\n", argv[0]);
        exit(1);
    }

    // Open the file for reading
    filename = argv[1];
    if ((fd = open(filename, O_RDONLY)) == -1) {
        perror("open");
        exit(1);
    }

    // Read the file into memory
    if ((fp = fdopen(fd, "r")) == NULL) {
        perror("fdopen");
        exit(1);
    }

    // Parse command line arguments for patterns
    while (argc > 2) {
        patterns = realloc(patterns, sizeof(pattern_t) * ++num_patterns);
        patterns[num_patterns - 1].pattern = argv[2];
        patterns[num_patterns - 1].pattern_len = strlen(argv[2]);
        patterns[num_patterns - 1].count = 0;
        argv++;
        argc--;
    }

    // Loop through the file line by line
    while ((read = getline(&line, &len, fp))!= -1) {
        // Reset match count for each line
        match_count = 0;

        // Check if the line matches any of the patterns
        for (int i = 0; i < num_patterns; i++) {
            if (strstr(line, patterns[i].pattern)!= NULL) {
                patterns[i].count++;
                match_count++;
            }
        }

        // Free memory allocated for the line
        free(line);
        line = NULL;
        len = 0;
    }

    // Close the file
    if (fp!= NULL) {
        fclose(fp);
    }

    // Print the results
    for (int i = 0; i < num_patterns; i++) {
        printf("Pattern '%s' found %d times.\n", patterns[i].pattern, patterns[i].count);
    }

    return 0;
}