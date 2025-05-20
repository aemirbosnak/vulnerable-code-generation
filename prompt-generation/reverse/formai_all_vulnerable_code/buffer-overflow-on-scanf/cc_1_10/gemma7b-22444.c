//Gemma-7B DATASET v1.0 Category: Educational ; Style: modular
#include <stdio.h>
#include <stdlib.h>

void display_menu();
void calculate_area(int);
void calculate_perimeter(int);

int main()
{
    int choice;

    display_menu();
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            calculate_area(0);
            break;
        case 2:
            calculate_perimeter(0);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}

void display_menu()
{
    printf("1. Calculate area\n");
    printf("2. Calculate perimeter\n");
    printf("Enter your choice:");
}

void calculate_area(int shape)
{
    int area;

    switch (shape)
    {
        case 1:
            area = 6 * 6;
            printf("The area of the square is: %d square units.\n", area);
            break;
        case 2:
            area = 2 * 2 * 2 + 4 * 4;
            printf("The area of the rectangle is: %d square units.\n", area);
            break;
        default:
            printf("Invalid shape.\n");
    }
}

void calculate_perimeter(int shape)
{
    int perimeter;

    switch (shape)
    {
        case 1:
            perimeter = 4 * 6;
            printf("The perimeter of the square is: %d units.\n", perimeter);
            break;
        case 2:
            perimeter = 2 * 2 + 2 * 4;
            printf("The perimeter of the rectangle is: %d units.\n", perimeter);
            break;
        default:
            printf("Invalid shape.\n");
    }
}