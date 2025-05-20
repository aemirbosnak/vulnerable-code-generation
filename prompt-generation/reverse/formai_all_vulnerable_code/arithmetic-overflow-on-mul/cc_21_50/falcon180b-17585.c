//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, m, k, i, j, count = 0;
    int **grid;
    int top, bottom, left, right;
    int choice;

    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &m);

    grid = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        grid[i] = (int *)malloc(m * sizeof(int));

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    do {
        system("clear");
        printf("Percolation Simulator\n");
        printf("---------------------\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    printf("* ");
                else
                    printf("- ");
            }
            printf("\n");
        }
        printf("Number of Sites: %d\n", count);
        printf("Percentage of Sites: %.2f%%\n", (float)count / (n * m) * 100);
        printf("Enter your choice:\n");
        printf("1. Add a site\n");
        printf("2. Remove a site\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the row and column of the new site: ");
            scanf("%d %d", &i, &j);
            if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 0) {
                grid[i][j] = 1;
                count++;
            }
            break;
        case 2:
            printf("Enter the row and column of the site to remove: ");
            scanf("%d %d", &i, &j);
            if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1) {
                grid[i][j] = 0;
                count--;
            }
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}