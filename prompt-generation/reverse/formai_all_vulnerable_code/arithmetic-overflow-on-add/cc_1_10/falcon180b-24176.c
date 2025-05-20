//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100

int arr[MAX];
int n;

void generate_array(int min, int max)
{
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        arr[i] = rand()%(max-min+1) + min;
    }
}

void print_array(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    printf("Enter the size of the array: ");
    scanf("%d",&n);

    printf("Enter the minimum value: ");
    int min;
    scanf("%d",&min);

    printf("Enter the maximum value: ");
    int max;
    scanf("%d",&max);

    generate_array(min,max);

    printf("Original array:\n");
    print_array(arr,n);

    int sum = 0;
    int min_index = 0;
    int max_index = 0;

    for(int i=0;i<n;i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
            max_index = i;
        }
        if(arr[i] < min)
        {
            min = arr[i];
            min_index = i;
        }
        sum += arr[i];
    }

    printf("Maximum value: %d\n",max);
    printf("Minimum value: %d\n",min);
    printf("Sum: %d\n",sum);

    return 0;
}