//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 50
#define MAX_COLS 100
#define MAX_PATTERNS 10

char patterns[MAX_PATTERNS][MAX_COLS] = {
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
    "abcdefghijklmnopqrstuvwxyz",
    "0123456789",
    "&*^%$#@!~`",
    "+-*/=()",
    "QWERTYUIOPASDFGHJKLZXCVBNM",
    "qwertyuiopasdfghjklzxcvbnm",
    "QWASDFGHJKLZXCVBNM",
    "qwasdfghjklzxcvbnm",
    "QWERTYUIOPASDFGHJKLZXCVBN"
};

int num_patterns;

void generate_patterns(char patterns[][MAX_COLS], int num_patterns) {
    int i, j;
    for (i = 0; i < num_patterns; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            patterns[i][j] = 'A' + i * MAX_COLS + j;
        }
    }
}

void print_patterns(char patterns[][MAX_COLS], int num_patterns, int num_rows) {
    int i, j;
    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < num_patterns; j++) {
            for (int k = 0; k < strlen(patterns[j]); k++) {
                printf("%c", patterns[j][k]);
            }
        }
        printf("\n");
    }
}

int main() {
    int num_rows, num_patterns;
    printf("Enter number of rows: ");
    scanf("%d", &num_rows);
    printf("Enter number of patterns: ");
    scanf("%d", &num_patterns);
    if (num_patterns > MAX_PATTERNS || num_patterns <= 0) {
        printf("Invalid number of patterns\n");
        return 1;
    }
    generate_patterns(patterns, num_patterns);
    print_patterns(patterns, num_patterns, num_rows);
    return 0;
}