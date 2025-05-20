//FormAI DATASET v1.0 Category: Pattern printing ; Style: curious
#include <stdio.h>

int main() {
    int rows;
    printf("How many rows should the pattern contain?: ");
    scanf("%d", &rows);
    
    printf("\n");
    if(rows < 3) {
        printf("Please enter a number greater than or equal to 3!\n");
    } else {
        printf("Ready? Here we go!\n");
        printf("\n");

        int i, j, k;
        for(i = 1; i <= rows; i++) {
            for(k = 1; k <= i; k++) {
                printf("* ");
            }
            for(j = i; j < rows; j++) {
                printf("  ");
            }
            for(j = i; j < rows; j++) {
                printf("  ");
            }
            for(k = 1; k <= i; k++) {
                printf("* ");
            }
            printf("\n");
        }

        for(i = rows-1; i >= 1; i--) {
            for(k = 1; k <= i; k++) {
                printf("* ");
            }
            for(j = rows; j > i; j--) {
                printf("  ");
            }
            for(j = rows; j > i; j--) {
                printf("  ");
            }
            for(k = 1; k <= i; k++) {
                printf("* ");
            }
            printf("\n");
        }
    }

    return 0;
}