//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PATTERN_LENGTH 100
#define MAX_ROW_LENGTH 100
#define MAX_COLUMN_LENGTH 100

typedef struct {
    char pattern[MAX_PATTERN_LENGTH];
    int row;
    int column;
} Pattern;

Pattern* createPattern(char* pattern, int row, int column) {
    Pattern* p = (Pattern*)malloc(sizeof(Pattern));
    strcpy(p->pattern, pattern);
    p->row = row;
    p->column = column;
    return p;
}

void printPattern(Pattern* p, int row, int column) {
    int i, j;
    for (i = 0; i < strlen(p->pattern); i++) {
        if (p->pattern[i] == '*') {
            for (j = 0; j < row; j++) {
                printf("%c", '*');
            }
        } else {
            printf("%c", p->pattern[i]);
        }
    }
    printf("\n");
}

void freePattern(Pattern* p) {
    free(p);
}

int main() {
    char pattern[MAX_PATTERN_LENGTH];
    int row, column;
    printf("Enter the pattern: ");
    scanf("%s", pattern);
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &column);
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            Pattern* p = createPattern(pattern, i, j);
            printPattern(p, row, column);
            freePattern(p);
        }
    }
    return 0;
}