//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PATTERN_LENGTH 100
#define MAX_PATTERN_COUNT 100

typedef struct {
    char pattern[MAX_PATTERN_LENGTH];
    int count;
} Pattern;

int main() {
    int numPatterns = 0;
    Pattern patterns[MAX_PATTERN_COUNT];
    char input[MAX_PATTERN_LENGTH];

    // Get number of patterns from user
    printf("Enter the number of patterns: ");
    scanf("%d", &numPatterns);

    // Get patterns from user
    for (int i = 0; i < numPatterns; i++) {
        printf("Enter pattern %d: ", i+1);
        scanf("%s", patterns[i].pattern);
        patterns[i].count = 0;
    }

    // Read input string
    printf("Enter input string: ");
    fgets(input, MAX_PATTERN_LENGTH, stdin);

    // Count occurrences of patterns in input string
    for (int i = 0; i < numPatterns; i++) {
        char *pattern = strtok(input, patterns[i].pattern);
        while (pattern!= NULL) {
            patterns[i].count++;
            pattern = strtok(NULL, patterns[i].pattern);
        }
    }

    // Print results
    printf("\nPattern\t\tCount\n");
    for (int i = 0; i < numPatterns; i++) {
        printf("%s\t\t%d\n", patterns[i].pattern, patterns[i].count);
    }

    return 0;
}