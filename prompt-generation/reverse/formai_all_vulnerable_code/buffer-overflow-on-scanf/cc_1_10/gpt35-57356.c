//FormAI DATASET v1.0 Category: Data mining ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void data_mine();

int main()
{
    printf("Welcome to the Data mining program!\n");
    data_mine();

    return 0;
}

void data_mine()
{
    int n, i;
    float arr[50], min, max, sum = 0, avg;

    printf("\nEnter the number of data points to be mined (Max 50): ");
    scanf("%d", &n);

    printf("\nEnter the data points separated by space: ");
    for(i=0; i<n; i++)
    {
        scanf("%f", &arr[i]);

        //Finding maximum value
        if(i==0)
            max = arr[i];
        else
        {
            if(arr[i]>max)
                max = arr[i];
        }

        //Finding minimum value
        if(i==0)
            min = arr[i];
        else
        {
            if(arr[i]<min)
                min = arr[i];
        }

        //Finding sum of all values
        sum += arr[i];
    }

    //Finding average value
    avg = sum/n;

    printf("\nMaximum value: %f", max);
    printf("\nMinimum value: %f", min);
    printf("\nSum of all values: %f", sum);
    printf("\nAverage value: %f", avg);
}