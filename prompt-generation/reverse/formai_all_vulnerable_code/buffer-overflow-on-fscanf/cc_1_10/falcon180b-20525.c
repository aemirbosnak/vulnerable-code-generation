//Falcon-180B DATASET v1.0 Category: File handling ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14159265358979323846

int main()
{
    double radius, area, perimeter;
    char filename[100];
    FILE *fp;
    int choice;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("File does not exist.\n");
        exit(0);
    }

    printf("\nEnter your choice:\n");
    printf("1. Calculate area of circle\n");
    printf("2. Calculate perimeter of circle\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            while(fscanf(fp, "%lf", &radius)!= EOF)
            {
                area = PI * radius * radius;
                printf("\nThe area of circle with radius %.2lf is %.2lf\n", radius, area);
            }
            break;

        case 2:
            while(fscanf(fp, "%lf", &radius)!= EOF)
            {
                perimeter = 2 * PI * radius;
                printf("\nThe perimeter of circle with radius %.2lf is %.2lf\n", radius, perimeter);
            }
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    fclose(fp);
    return 0;
}