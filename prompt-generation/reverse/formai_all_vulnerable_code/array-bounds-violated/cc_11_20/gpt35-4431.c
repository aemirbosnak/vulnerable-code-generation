//FormAI DATASET v1.0 Category: Robot movement control ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, x, y, i, j, k, r;
    printf("\nEnter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &m);
    int a[n][m];
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            printf("Enter the element of row %d and column %d: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nThe matrix you entered is:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter the starting point of robot in x and y cordinates respectively: ");
    scanf("%d %d", &x, &y);
    printf("\nEnter the number of steps you want robot to take: ");
    scanf("%d", &r);
    int b[r], c[r];
    for(i=0; i<r; i++)
    {
        printf("\nEnter the direction in which you want to move the robot in step %d (0 for up, 1 for down, 2 for left and 3 for right): ", i+1);
        scanf("%d", &b[i]);
        printf("Enter the distance in which you want to move the robot in step %d: ", i+1);
        scanf("%d", &c[i]);
    }
    printf("\nThe movements of robot are as follows:\n");
    for(i=0; i<r; i++)
    {
        if(b[i]==0)
        {
            x=x-c[i];
            if(x<0)
            {
                printf("Invalid movement request\n");
                exit(0);
            }
            printf("Robot moves up by %d steps and current position is (%d, %d)\n", c[i], x, y);
        }
        else if(b[i]==1)
        {
            x=x+c[i];
            if(x>=n)
            {
                printf("Invalid movement request\n");
                exit(0);
            }
            printf("Robot moves down by %d steps and current position is (%d, %d)\n", c[i], x, y);
        }
        else if(b[i]==2)
        {
            y=y-c[i];
            if(y<0)
            {
                printf("Invalid movement request\n");
                exit(0);
            }
            printf("Robot moves left by %d steps and current position is (%d, %d)\n", c[i], x, y);
        }
        else if(b[i]==3)
        {
            y=y+c[i];
            if(y>=m)
            {
                printf("Invalid movement request\n");
                exit(0);
            }
            printf("Robot moves right by %d steps and current position is (%d, %d)\n", c[i], x, y);
        }
        else
        {
            printf("Invalid direction request\n");
            exit(0);
        }
    }
    printf("\nThe final position of robot is (%d, %d) and its value is %d\n", x, y, a[x][y]);
    return 0;
}