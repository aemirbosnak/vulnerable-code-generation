//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_DEPTH 10

void print_tree(int depth) {
    int i;

    if (depth <= 0) {
        printf("\n");
        return;
    }

    for (i = depth; i >= 1; i--) {
        printf(" ");
    }

    printf("/\\");

    for (i = depth - 1; i >= 1; i--) {
        printf("/  ");
    }

    print_tree(depth - 1);

    for (i = depth; i >= 1; i--) {
        printf(" \\/");
    }
}

int main() {
    int depth;
    char str[128];

    srand(time(NULL));

    printf("Enter tree depth (1-%d): ", MAX_DEPTH);
    scanf("%d", &depth);

    if (depth < 1 || depth > MAX_DEPTH) {
        printf("Invalid depth! Exiting...\n");
        return 1;
    }

    printf("\nGenerating tree of depth %d...\n", depth);
    sleep(1);

    print_tree(depth);

    return 0;
}