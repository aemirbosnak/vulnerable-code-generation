//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_STR_LEN 1024
#define MAX_ARGS 10

struct arg_info {
    char *name;
    int count;
};

struct format_info {
    char *format;
    int len;
    int args_used;
};

int main(void) {
    char *strings[MAX_ARGS];
    struct arg_info args[MAX_ARGS];
    struct format_info formats[10];
    int i, j, k;

    // Populate the strings and args arrays
    for (i = 0; i < MAX_ARGS; i++) {
        strings[i] = (char *)malloc(MAX_STR_LEN);
        args[i].name = (char *)malloc(MAX_STR_LEN);
        scanf("%s", strings[i]);
        args[i].count = 0;
    }

    // Populate the formats array
    for (i = 0; i < 10; i++) {
        formats[i].format = (char *)malloc(MAX_STR_LEN);
        scanf("%s", formats[i].format);
        formats[i].len = strlen(formats[i].format);
        formats[i].args_used = 0;
    }

    // Analyze the usage of the printf function
    for (i = 0; i < MAX_ARGS; i++) {
        for (j = 0; j < 10; j++) {
            if (strstr(strings[i], formats[j].format) != NULL) {
                // Check if the format string is present in the current string
                k = strlen(strings[i]) - strlen(formats[j].format);
                if (k > 0) {
                    // Check if the format string is used correctly
                    if (k == formats[j].len && args[i].count == formats[j].args_used) {
                        // Yes, the format string is used correctly, increment the count
                        args[i].count++;
                    }
                }
            }
        }
    }

    // Print the analysis results
    for (i = 0; i < MAX_ARGS; i++) {
        printf("String %d: %s\n", i, strings[i]);
        for (j = 0; j < 10; j++) {
            if (args[i].count > 0) {
                printf("Format %d: %s\n", j, formats[j].format);
                printf("  Used correctly: %d times\n", args[i].count);
            }
        }
    }

    // Free the memory allocated for the arrays
    for (i = 0; i < MAX_ARGS; i++) {
        free(strings[i]);
    }
    for (i = 0; i < MAX_ARGS; i++) {
        free(args[i].name);
    }
    for (i = 0; i < 10; i++) {
        free(formats[i].format);
    }

    return 0;
}