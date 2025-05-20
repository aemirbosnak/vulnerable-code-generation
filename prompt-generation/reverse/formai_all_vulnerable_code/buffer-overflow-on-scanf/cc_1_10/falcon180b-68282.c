//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_pattern(int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if ((i + j) % 2 == 0)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the size of the pattern: ");
    scanf("%d", &n);
    srand(time(NULL));
    int pattern = rand() % 4;

    switch (pattern) {
        case 0:
            printf("\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    printf("* ");
                }
                printf("\n");
            }
            break;

        case 1:
            printf("\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if ((i + j) % 2 == 0)
                        printf("* ");
                    else
                        printf("  ");
                }
                printf("\n");
            }
            break;

        case 2:
            printf("\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if ((i + j) % 2!= 0)
                        printf("* ");
                    else
                        printf("  ");
                }
                printf("\n");
            }
            break;

        case 3:
            printf("\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if ((i + j) % 3 == 0)
                        printf("* ");
                    else
                        printf("  ");
                }
                printf("\n");
            }
            break;
    }

    return 0;
}