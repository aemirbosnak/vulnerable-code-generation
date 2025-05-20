//Falcon2-11B DATASET v1.0 Category: Pattern printing ; Style: sophisticated
#include <stdio.h>

int main() {
    int i, j, k, l;
    
    // Declare and initialize arrays
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    
    // Print 1st line of pattern
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            for (k = 0; k < 5; k++) {
                for (l = 0; l < 5; l++) {
                    printf("%d ", a[i + j + k + l]);
                }
                printf("\n");
            }
            printf("\n");
        }
        printf("\n");
    }
    
    // Print 2nd line of pattern
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            for (k = 0; k < 5; k++) {
                for (l = 0; l < 5; l++) {
                    printf("%d ", b[i + j + k + l]);
                }
                printf("\n");
            }
            printf("\n");
        }
        printf("\n");
    }
    
    // Print 3rd line of pattern
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            for (k = 0; k < 5; k++) {
                for (l = 0; l < 5; l++) {
                    printf("%d ", a[i + j + k + l]);
                }
                printf("\n");
            }
            printf("\n");
        }
        printf("\n");
    }
    
    // Print 4th line of pattern
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            for (k = 0; k < 5; k++) {
                for (l = 0; l < 5; l++) {
                    printf("%d ", b[i + j + k + l]);
                }
                printf("\n");
            }
            printf("\n");
        }
        printf("\n");
    }
    
    return 0;
}