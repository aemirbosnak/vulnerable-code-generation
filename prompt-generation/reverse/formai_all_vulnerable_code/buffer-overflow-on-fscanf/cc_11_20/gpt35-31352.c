//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: statistical
/*
  Program: Statistic Component
  Description: This program takes an input file with numbers separated by spaces or new lines and calculates statistical values.
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

int main()
{
    int input[MAX], n, i, j, temp, sum = 0;
    float mean, median, mode;
    FILE *fp;

    fp = fopen("input.txt", "r");   //opening the file in read mode

    if(fp == NULL)
    {
        printf("File not found");
        exit(1);
    }

    n = 0;   // storing the values in an array
    while(fscanf(fp, "%d", &input[n++]) == 1);

    fclose(fp);

    n--;   // adjust the count

    // Sorting the array using Bubble Sort
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(input[j]>input[j+1])
            {
                temp = input[j];
                input[j] = input[j+1];
                input[j+1] = temp;
            }
        }
    }

    //calculate mean
    for(i=0; i<n; i++)
    {
        sum += input[i];
    }
    mean = (float) sum/n;

    //calculate median
    if(n%2==0)
    {
        median = (float)(input[(n-1)/2] + input[n/2])/2.0;
    }
    else
    {
        median = (float)input[n/2];
    }

    //calculate mode
    int count = 1;
    int max_count = 1;
    mode = input[0];
    for(i=1;i<n;i++)
    {
        if(input[i]==input[i-1])
        {
            count++;
        }
        else
        {
            if(count>max_count)
            {
                max_count = count;
                mode = input[i-1];
            }
            count = 1;
        }
    }
    if(count>max_count)
    {
        mode = input[n-1];
    }

    //Printing the results
    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", median);
    printf("Mode: %.2f", mode);

    return 0;
}