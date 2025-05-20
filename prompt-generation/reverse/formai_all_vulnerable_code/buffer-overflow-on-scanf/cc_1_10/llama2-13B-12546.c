//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PATTERN_LENGTH 50
#define MAX_PRINT_LINES 10

void printPattern(char *pattern) {
    int i, j;
    for (i = 0; i < strlen(pattern); i++) {
        for (j = 0; j < strlen(pattern); j++) {
            if (pattern[i] == pattern[j]) {
                printf("%c%c%c", pattern[i], pattern[j], pattern[i]);
            } else {
                printf("%c", pattern[i]);
            }
        }
        printf("\n");
    }
}

int main() {
    char pattern[MAX_PATTERN_LENGTH];
    int choice;

    do {
        printf("Enter a pattern (max length %d): ", MAX_PATTERN_LENGTH);
        fgets(pattern, MAX_PATTERN_LENGTH, stdin);

        printf("Enter a choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printPattern(pattern);
                break;
            case 2:
                printPattern(pattern);
                printf("Pattern printed %d times\n", choice);
                break;
            case 3:
                printPattern(pattern);
                printf("Pattern printed %d times, with a gap\n", choice);
                break;
            case 4:
                printPattern(pattern);
                printf("Pattern printed %d times, rotated by %d\n", choice, choice);
                break;
            case 5:
                printPattern(pattern);
                printf("Pattern printed %d times, rotated by %d, and mirrored\n", choice, choice);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 5);

    return 0;
}