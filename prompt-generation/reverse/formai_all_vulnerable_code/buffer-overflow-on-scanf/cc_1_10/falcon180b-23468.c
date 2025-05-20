//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j, k, l, m, o, p, q, r, s, t, u, v, w, x, y, z;
    char ch;

    srand(time(0));

    printf("Enter the number of arithmetic problems to solve: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nProblem %d:\n", i + 1);

        ch = rand() % 4 + 1;

        switch (ch) {
            case 1:
                printf("Solve the following addition problem:\n");
                printf("%d + %d = ", rand() % 100 + 1, rand() % 100 + 1);
                scanf("%d", &k);
                if (k == rand() % 100 + 1)
                    printf("Correct!\n");
                else
                    printf("Incorrect.\n");
                break;

            case 2:
                printf("Solve the following subtraction problem:\n");
                printf("%d - %d = ", rand() % 100 + 1, rand() % 100 + 1);
                scanf("%d", &l);
                if (l == rand() % 100 + 1)
                    printf("Correct!\n");
                else
                    printf("Incorrect.\n");
                break;

            case 3:
                printf("Solve the following multiplication problem:\n");
                printf("%d x %d = ", rand() % 100 + 1, rand() % 100 + 1);
                scanf("%d", &m);
                if (m == rand() % 100 + 1)
                    printf("Correct!\n");
                else
                    printf("Incorrect.\n");
                break;

            case 4:
                printf("Solve the following division problem:\n");
                printf("%d / %d = ", rand() % 100 + 1, rand() % 100 + 1);
                scanf("%d", &p);
                if (p == rand() % 100 + 1)
                    printf("Correct!\n");
                else
                    printf("Incorrect.\n");
                break;
        }
    }

    return 0;
}