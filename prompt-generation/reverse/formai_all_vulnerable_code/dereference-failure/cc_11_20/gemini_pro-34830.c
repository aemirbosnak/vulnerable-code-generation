//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include <limits.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define abs(a) ((a) < 0 ? -(a) : (a))

// paranoia-level constants
#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1024

// paranoia-level types
typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef  int8_t  i8;
typedef  int16_t i16;
typedef  int32_t i32;
typedef  int64_t i64;
typedef float    f32;
typedef double   f64;

// paranoia-level macros
#define unlikely(expr) __builtin_expect(!!(expr), 0)
#define likely(expr)   __builtin_expect(!!(expr), 1)

// paranoia-level functions
static i32 paranoia_main(i32 argc, char **argv)
{
    i32 line_count = 0;
    char *lines[MAX_NUM_LINES];
    u32 line_lengths[MAX_NUM_LINES];

    // paranoia: check for too many arguments
    if (argc > 3) {
        fprintf(stderr, "Error: too many arguments\n");
        return EXIT_FAILURE;
    }

    // paranoia: check for no arguments
    if (argc < 3) {
        fprintf(stderr, "Error: too few arguments\n");
        return EXIT_FAILURE;
    }

    // paranoia: allocate memory for each pointer
    for (i32 i = 0; i < MAX_NUM_LINES; i++) {
        lines[i] = malloc(MAX_LINE_LENGTH);
        if (lines[i] == NULL) {
            fprintf(stderr, "Error: could not allocate memory\n");
            return EXIT_FAILURE;
        }
    }

    // paranoia: do everything you possibly can to avoid buffer overflows
    while (fgets(lines[line_count], MAX_LINE_LENGTH, stdin) != NULL) {
        // check for error
        if (ferror(stdin)) {
            fprintf(stderr, "Error: could not read from stdin\n");
            return EXIT_FAILURE;
        }
        // check for too long a line
        if (strlen(lines[line_count]) >= MAX_LINE_LENGTH) {
            fprintf(stderr, "Error: line too long\n");
            return EXIT_FAILURE;
        }
        // check for too many lines
        if (line_count >= MAX_NUM_LINES) {
            fprintf(stderr, "Error: too many lines\n");
            return EXIT_FAILURE;
        }
        // paranoia: compute line length (avoiding strlen)
        {
            i32 i = 0;
            while (lines[line_count][i] != '\0' && lines[line_count][i] != '\n') {
                i++;
            }
            line_lengths[line_count] = i;
        }
        line_count++;
    }

    // paranoia: check for empty input
    if (line_count == 0) {
        fprintf(stderr, "Error: empty input\n");
        return EXIT_FAILURE;
    }

    // paranoia: check for identical inputs
    for (i32 i = 0; i < line_count - 1; i++) {
        if (strcmp(lines[i], lines[i + 1]) == 0) {
            fprintf(stderr, "Error: identical inputs\n");
            return EXIT_FAILURE;
        }
    }

    // paranoia: compute Levenshtein distance
    u32 lev_dist[line_count][line_count];
    for (i32 i = 0; i < line_count; i++) {
        for (i32 j = 0; j < line_count; j++) {
            if (i == 0) {
                lev_dist[i][j] = j;
            } else if (j == 0) {
                lev_dist[i][j] = i;
            } else {
                lev_dist[i][j] = min(min(lev_dist[i-1][j] + 1, lev_dist[i][j-1] + 1),
                                      lev_dist[i-1][j-1] + (lines[i][j-1] != lines[j][j-1]));
            }
        }
    }

    // paranoia: handle output
    {
        u32 min_lev_dist = UINT_MAX;
        i32 min_lev_dist_i = 0;
        i32 min_lev_dist_j = 0;
        for (i32 i = 0; i < line_count; i++) {
            for (i32 j = 0; j < line_count; j++) {
                if (lev_dist[i][j] < min_lev_dist) {
                    min_lev_dist = lev_dist[i][j];
                    min_lev_dist_i = i;
                    min_lev_dist_j = j;
                }
            }
        }

        if (min_lev_dist == 0) {
            fprintf(stdout, "The inputs are identical\n");
        } else {
            fprintf(stdout, "The Levenshtein distance between \"%s\" and \"%s\" is %u\n",
                lines[min_lev_dist_i], lines[min_lev_dist_j], min_lev_dist);
        }
    }

    // paranoia: free memory
    for (i32 i = 0; i < MAX_NUM_LINES; i++) {
        free(lines[i]);
    }

    return EXIT_SUCCESS;
}

int main(int argc, char **argv)
{
    return paranoia_main(argc, argv);
}