//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int x, y, n;
    float d, total = 0;

    printf("Enter the number of locations: ");
    scanf("%d", &n);

    int arrX[n], arrY[n];

    printf("\nEnter the coordinates(x, y) of the locations: ");

    for(int i=0; i<n; i++)
    {
        scanf("%d %d", &arrX[i], &arrY[i]);
    }

    printf("\nEnter the distance covered in each location:\n");

    for(int i=0; i<n; i++)
    {
        printf("\nDistance covered from location %d to location %d is: ", i, i+1);
        scanf("%f", &d);
        total += d;
    }

    printf("\nTotal Distance covered is: %.2f\n", total);

    printf("\nEnter your current location(x, y):\n");
    scanf("%d %d", &x, &y);

    float distance = 1000000;
    int pos = 0;

    for(int i=0; i<n; i++)
    {
        float temp = sqrt(pow(arrX[i]-x, 2) + pow(arrY[i]-y, 2));
        if(distance > temp)
        {
            distance = temp;
            pos = i;
        }
    }

    printf("\nThe nearest location to you is location %d with distance %.2f\n", pos+1, distance);

    return 0;
}