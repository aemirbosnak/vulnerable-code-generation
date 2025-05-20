//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10

int main()
{
    int arr[SIZE];
    int i,j,k,temp;
    int choice;
    int sum = 0;
    int product = 1;
    int count = 0;
    int even = 0;
    int odd = 0;
    int min = 9999;
    int max = -9999;
    int average;
    char ch;
    srand(time(NULL));
    for(i=0;i<SIZE;i++)
    {
        arr[i] = rand()%100;
    }
    printf("\nThe array elements are:\n");
    for(i=0;i<SIZE;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nEnter your choice:\n1.Sum\n2.Product\n3.Count of even numbers\n4.Count of odd numbers\n5.Minimum element\n6.Maximum element\n7.Average\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            for(i=0;i<SIZE;i++)
            {
                sum += arr[i];
            }
            printf("\nThe sum of array elements is: %d",sum);
            break;
        case 2:
            for(i=0;i<SIZE;i++)
            {
                product *= arr[i];
            }
            printf("\nThe product of array elements is: %d",product);
            break;
        case 3:
            for(i=0;i<SIZE;i++)
            {
                if(arr[i]%2==0)
                {
                    count++;
                }
            }
            printf("\nThe count of even numbers in the array is: %d",count);
            break;
        case 4:
            for(i=0;i<SIZE;i++)
            {
                if(arr[i]%2!=0)
                {
                    count++;
                }
            }
            printf("\nThe count of odd numbers in the array is: %d",count);
            break;
        case 5:
            for(i=0;i<SIZE;i++)
            {
                if(arr[i]<min)
                {
                    min = arr[i];
                }
            }
            printf("\nThe minimum element in the array is: %d",min);
            break;
        case 6:
            for(i=0;i<SIZE;i++)
            {
                if(arr[i]>max)
                {
                    max = arr[i];
                }
            }
            printf("\nThe maximum element in the array is: %d",max);
            break;
        case 7:
            for(i=0;i<SIZE;i++)
            {
                sum += arr[i];
            }
            average = sum/SIZE;
            printf("\nThe average of array elements is: %.2f",average);
            break;
        default:
            printf("\nInvalid choice");
            break;
    }
    return 0;
}