//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 101
#define MAX_INPUT_LENGTH 51

void print_pyramid(char (*arr)[MAX_CHARS], int base, char c) {
    int i, j, space_count;

    for (i = base; i > 0; i--) {
        for (j = 0; j < base - i; j++)
            printf(" ");

        for (space_count = 0; space_count < 2 * i - 1; space_count++)
            printf("%c", c);

        printf("\n");
    }

    for (i = 0; i < base; i++) {
        for (j = 0; j < base - i - 1; j++)
            printf(" ");

        for (space_count = 0; space_count < 2 * i + 1; space_count++)
            printf("%c", arr[i][space_count]);

        printf("\n");
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char arr[MAX_CHARS][MAX_CHARS];
    int base, i;

    printf("Enter the base of the pyramid: ");
    scanf("%d", &base);

    printf("Enter %d characters for the pyramid: ", base * 2);
    scanf("%s", input);

    for (i = 0; i < base; i++) {
        strncpy(arr[i], input, base);
        arr[i][base] = '\0';
    }

    printf("\nPyramid of Characters:\n");
    print_pyramid(arr, base, input[0]);

    return 0;
}