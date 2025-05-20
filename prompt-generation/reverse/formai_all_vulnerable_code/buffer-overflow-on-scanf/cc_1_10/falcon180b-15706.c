//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PATTERN_LENGTH 1000
#define MAX_STRING_LENGTH 1000
#define MAX_NUM_PATTERNS 1000

struct pattern {
    char *pattern;
    int index;
};

int num_patterns = 0;
struct pattern patterns[MAX_NUM_PATTERNS];

void add_pattern(char *pattern) {
    if (num_patterns >= MAX_NUM_PATTERNS) {
        printf("Error: Maximum number of patterns reached.\n");
        exit(1);
    }
    patterns[num_patterns].pattern = strdup(pattern);
    patterns[num_patterns].index = num_patterns;
    num_patterns++;
}

void print_patterns(char *string) {
    int i = 0;
    while (i < num_patterns) {
        char *pattern = patterns[i].pattern;
        int index = patterns[i].index;
        int j = 0;
        while (j < strlen(pattern)) {
            if (isalpha(pattern[j])) {
                char c = toupper(string[index + j]);
                if (c!= pattern[j]) {
                    break;
                }
            } else {
                char c = toupper(string[index + j]);
                if (c!= pattern[j]) {
                    break;
                }
            }
            j++;
        }
        if (j == strlen(pattern)) {
            printf("%s\n", patterns[i].pattern);
        }
        i++;
    }
}

int main() {
    char string[MAX_STRING_LENGTH];
    printf("Enter a string:\n");
    fgets(string, MAX_STRING_LENGTH, stdin);
    string[strcspn(string, "\n")] = '\0';

    printf("Enter patterns (max %d):\n", MAX_NUM_PATTERNS - 1);
    int i = 0;
    while (i < MAX_NUM_PATTERNS - 1 && scanf("%s", string)!= EOF) {
        add_pattern(string);
        i++;
    }

    print_patterns(string);

    return 0;
}