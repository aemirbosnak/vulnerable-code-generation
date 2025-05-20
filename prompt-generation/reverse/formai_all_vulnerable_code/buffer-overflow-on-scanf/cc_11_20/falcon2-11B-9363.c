//Falcon2-11B DATASET v1.0 Category: Educational ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void print_shape(int shape, int n) {
    int i;

    switch (shape) {
        case 1:
            for (i = 1; i <= n; i++) {
                printf(" ");
            }
            printf("*\n");
            break;
        case 2:
            for (i = 1; i <= n; i++) {
                printf("*");
            }
            printf("\n");
            break;
        case 3:
            for (i = 1; i <= n; i++) {
                printf("*");
            }
            printf(" ");
            for (i = 1; i <= n; i++) {
                printf("*");
            }
            printf("\n");
            break;
        case 4:
            for (i = 1; i <= n; i++) {
                printf("*");
            }
            printf(" ");
            for (i = 1; i <= n; i++) {
                printf("*");
            }
            printf("*\n");
            break;
        case 5:
            for (i = 1; i <= n; i++) {
                printf("*");
            }
            printf(" ");
            for (i = 1; i <= n; i++) {
                printf("*");
            }
            printf("*\n");
            printf("*\n");
            break;
        case 6:
            for (i = 1; i <= n; i++) {
                printf("*");
            }
            printf(" ");
            for (i = 1; i <= n; i++) {
                printf("*");
            }
            printf("*\n");
            printf("*\n");
            printf("*\n");
            break;
        default:
            printf("Invalid shape number\n");
            break;
    }
}

int main() {
    int shape;
    int n;

    printf("Enter the shape number (1-6): ");
    scanf("%d", &shape);

    printf("Enter the number of stars (1-10): ");
    scanf("%d", &n);

    switch (shape) {
        case 1:
            printf("Shape 1: ");
            print_shape(shape, n);
            break;
        case 2:
            printf("Shape 2: ");
            print_shape(shape, n);
            break;
        case 3:
            printf("Shape 3: ");
            print_shape(shape, n);
            break;
        case 4:
            printf("Shape 4: ");
            print_shape(shape, n);
            break;
        case 5:
            printf("Shape 5: ");
            print_shape(shape, n);
            break;
        case 6:
            printf("Shape 6: ");
            print_shape(shape, n);
            break;
        default:
            printf("Invalid shape number\n");
            break;
    }

    return 0;
}