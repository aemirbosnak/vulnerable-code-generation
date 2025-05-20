//FormAI DATASET v1.0 Category: Pattern printing ; Style: ephemeral
#include <stdio.h>

int main() {
    int rows, i, j, k, space = 1;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for(i = 1; i <= rows; i++) {

        // printing the first section of the pattern
        for(j = i; j <= rows; j++) {
            printf("%d ", j);
        }

        // printing the spaces between the sections
        for(k = 1; k <= space; k++) {
            printf("  ");
        }

        // printing the second section of the pattern
        for(j = rows; j >= i; j--) {
            printf("%d ", j);
        }

        // add spaces before the next row
        space += 2;
        printf("\n");
    }

    space -= 4;

    for(i = rows; i >= 1; i--) {

        // printing the first section of the pattern
        for(j = i; j <= rows; j++) {
            printf("%d ", j);
        }

        // printing the spaces between the sections
        for(k = 1; k <= space; k++) {
            printf("  ");
        }

        // printing the second section of the pattern
        for(j = rows; j >= i; j--) {
            printf("%d ", j);
        }

        // subtract spaces to get closer to the center of the pattern
        space -= 2;
        printf("\n");
    }

    return 0;
}