//LLAMA2-13B DATASET v1.0 Category: Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_DEPTH 5
#define MAGIC_NUMBER 42

void recursive_function(int depth);
void print_triangle(int depth);

int main() {
    int choice;

    do {
        printf("Choose an option (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                recursive_function(1);
                break;
            case 2:
                recursive_function(2);
                break;
            case 3:
                recursive_function(3);
                break;
        }
    } while (choice != 4);

    return 0;
}

void recursive_function(int depth) {
    if (depth == 0) {
        printf("You have reached the end of the recursive function!\n");
        return;
    }

    printf("Depth: %d\n", depth);

    if (depth % 2 == 0) {
        printf("I am sorry, you have reached a dead end. Please try again.\n");
    } else {
        print_triangle(depth - 1);
    }

    recursive_function(depth - 1);
}

void print_triangle(int depth) {
    int i, j;

    for (i = 1; i <= depth; i++) {
        for (j = 1; j <= i; j++) {
            printf(" ");
        }

        for (j = i + 1; j <= depth; j++) {
            printf("*");
        }

        printf("\n");
    }
}