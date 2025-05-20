//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    int n, i, j;
    double x, y, z, a, b, c, d, e, f, g, h, k, l, m, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16, n17, n18, n19, n20;
    srand(time(NULL));
    printf("Welcome to C Math Exercise!\n");
    printf("This program will generate 20 random math problems for you to solve.\n");
    printf("Press any key to begin.\n");
    getchar();
    for (i = 0; i < 20; i++) {
        n = rand() % 4 + 1;
        switch (n) {
            case 1:
                x = rand() % 20 + 1;
                y = rand() % 20 + 1;
                printf("Problem %d: %d + %d = ", i + 1, x, y);
                scanf("%d", &a);
                if (a == x + y) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect.\n");
                }
                break;
            case 2:
                x = rand() % 20 + 1;
                y = rand() % 20 + 1;
                printf("Problem %d: %d - %d = ", i + 1, x, y);
                scanf("%d", &a);
                if (a == x - y) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect.\n");
                }
                break;
            case 3:
                x = rand() % 20 + 1;
                y = rand() % 20 + 1;
                printf("Problem %d: %d * %d = ", i + 1, x, y);
                scanf("%d", &a);
                if (a == x * y) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect.\n");
                }
                break;
            case 4:
                x = rand() % 20 + 1;
                y = rand() % 20 + 1;
                printf("Problem %d: %d / %d = ", i + 1, x, y);
                scanf("%d", &a);
                if (a == x / y) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect.\n");
                }
                break;
        }
    }
    printf("Congratulations! You have completed 20 math problems.\n");
    return 0;
}