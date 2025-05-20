//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define RANGE 100

int arr[RANGE];
int bucket[RANGE];

void generateArray(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        arr[i] = rand()%RANGE;
    }
}

void printArray(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

void createBuckets()
{
    int i;
    for(i=0;i<RANGE;i++)
    {
        bucket[i] = 0;
    }
}

void addToBucket(int element)
{
    int index = element%RANGE;
    bucket[index]++;
}

void distributeElements()
{
    int i,j;
    for(i=0;i<RANGE;i++)
    {
        for(j=0;j<bucket[i];j++)
        {
            arr[j+i*RANGE] = i;
        }
    }
}

void sort()
{
    int i,j;
    for(i=0;i<RANGE;i++)
    {
        for(j=0;j<bucket[i];j++)
        {
            addToBucket(arr[i+j*RANGE]);
        }
    }
    distributeElements();
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    generateArray(n);
    printf("Original Array:\n");
    printArray(n);
    createBuckets();
    sort();
    printf("\nSorted Array:\n");
    printArray(n);
    return 0;
}