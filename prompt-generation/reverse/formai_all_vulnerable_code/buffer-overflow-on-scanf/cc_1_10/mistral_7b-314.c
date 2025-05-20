//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_SIZE 21

void print_space(int num) {
    for (int i = 0; i < num; i++) {
        printf(" ");
    }
}

void print_star(int num) {
    for (int i = 0; i < num; i++) {
        printf("*");
    }
}

void print_diamond(int size) {
    int half_size = size / 2;

    for (int i = 0; i < half_size; i++) {
        print_space(half_size - i - 1);
        print_star(2 * i + 1);
        printf("\n");
    }

    for (int i = half_size; i <= size - half_size; i++) {
        print_space(half_size - i);
        print_star(2 * (size - i) - 1);
        printf("\n");
    }
}

int main() {
    int size;

    printf("Enter the size of the diamond: ");
    scanf("%d", &size);

    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid size! Expected size between 1 and %d\n", MAX_SIZE);
        return 1;
    }

    print_diamond(size);

    return 0;
}