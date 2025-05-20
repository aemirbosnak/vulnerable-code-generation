//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: puzzling
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 5
#define FIRST_CHAR 'A'
#define LAST_CHAR 'Z'
#define DELAY 500000

void print_pattern(int x, int y, char pattern) {
    int i, j;

    for (i = x; i <= x + SIZE; i++) {
        for (j = y; j <= y + SIZE; j++) {
            if (i >= x && i <= x + SIZE && j >= y && j <= y + SIZE) {
                printf("%c", pattern);
                fflush(stdout);
                usleep(DELAY);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (i = x + SIZE; i >= x; i--) {
        for (j = y; j <= y + SIZE; j++) {
            if (i >= x && i <= x + SIZE && j >= y && j <= y + SIZE) {
                printf("%c", pattern);
                fflush(stdout);
                usleep(DELAY);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (i = y; i <= y + SIZE; i++) {
        for (j = x; j <= x + SIZE; j++) {
            if (i >= y && i <= y + SIZE && j >= x && j <= x + SIZE) {
                printf("%c", pattern);
                fflush(stdout);
                usleep(DELAY);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (i = y; i >= y; i--) {
        for (j = x; j <= x + SIZE; j++) {
            if (i >= y && i <= y + SIZE && j >= x && j <= x + SIZE) {
                printf("%c", pattern);
                fflush(stdout);
                usleep(DELAY);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    char pattern;
    int x, y;

    printf("Enter the center of the pattern (x and y): ");
    scanf("%d %d", &x, &y);
    printf("Enter the pattern character: ");
    scanf(" %c", &pattern);

    printf("\nPrinting pattern...\n");
    print_pattern(x, y, pattern);
    printf("\nPattern printing complete.\n");

    return 0;
}