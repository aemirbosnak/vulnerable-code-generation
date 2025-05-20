//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: thoughtful
#include<stdio.h>

void triangle(int rows)
{
    int i, j;
    for(i=1;i<=rows;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

void rectangle(int rows, int columns)
{
    int i, j;
    for(i=1;i<=rows;i++)
    {
        for(j=1;j<=columns;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

void square(int rows)
{
    rectangle(rows, rows);
}

int main()
{
    int choice, rows, columns;
    printf("Enter your choice:\n");
    printf("1. Triangle\n");
    printf("2. Rectangle\n");
    printf("3. Square\n");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            printf("Enter the number of rows: ");
            scanf("%d", &rows);
            triangle(rows);
            break;
        case 2:
            printf("Enter the number of rows: ");
            scanf("%d", &rows);
            printf("Enter the number of columns: ");
            scanf("%d", &columns);
            rectangle(rows, columns);
            break;
        case 3:
            printf("Enter the number of rows: ");
            scanf("%d", &rows);
            square(rows);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    return 0;
}