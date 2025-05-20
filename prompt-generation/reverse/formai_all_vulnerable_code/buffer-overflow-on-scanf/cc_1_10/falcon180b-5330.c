//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define N 5
#define M 3

int matrix[N][M];
int i, j, k;

void print_matrix(int arr[][10])
{
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

void robot_movement(int start_pos[], int end_pos[], int pos[])
{
    int i;
    for (i = 0; i < N; i++) {
        pos[i] = start_pos[i];
    }

    while (pos[0]!= end_pos[0] || pos[1]!= end_pos[1]) {
        if (pos[0] > end_pos[0]) {
            pos[0]--;
        } else if (pos[0] < end_pos[0]) {
            pos[0]++;
        }

        if (pos[1] > end_pos[1]) {
            pos[1]--;
        } else if (pos[1] < end_pos[1]) {
            pos[1]++;
        }

        if (matrix[pos[0]][pos[1]] == 1) {
            printf("\nObstacle found at (%d, %d)", pos[0], pos[1]);
            break;
        }
    }
}

void main()
{
    int i, j, start_pos[N], end_pos[N], pos[N];

    printf("\nEnter the start position (x y): ");
    for (i = 0; i < N; i++) {
        scanf("%d", &start_pos[i]);
    }

    printf("\nEnter the end position (x y): ");
    for (i = 0; i < N; i++) {
        scanf("%d", &end_pos[i]);
    }

    printf("\nMatrix:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    robot_movement(start_pos, end_pos, pos);

    printf("\nFinal position: (%d, %d)", pos[0], pos[1]);
}