//FormAI DATASET v1.0 Category: Pattern printing ; Style: medieval
#include <stdio.h>
int main() {

    int size, i, j, space, count = 1, k;

    printf("Enter the size of the pattern: ");
    scanf("%d", &size);

    space = size - 1;

    for(i = 1; i <= size; i++) {

        for (j = 1; j <= space; j++) {
            printf("   ");
        }

        count = i;

        for (k = 1; k <= i; k++) {
            printf(" %2d", count--);
        }

        count = 2;

        for (k = 1; k < i; k++) {
            printf(" %2d", count++);
        }

        printf("\n");

        space--;
    }
    space = 1;

    for(i = 1; i <= size-1; i++) {

        for (j = 1; j <= space; j++) {
            printf("   ");
        }
        count = size - i;

        for (k = 1; k <= size-i; k++) {
            printf(" %2d", count--);
        }

        count = 2;

        for (k = 1; k < size-i; k++) {
            printf(" %2d", count++);
        }

        printf("\n");

        space++;
    }

    return 0;
}