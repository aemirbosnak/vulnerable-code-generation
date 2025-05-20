//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main()
{
    int choice,i,j,n,sum=0;
    float avg,deviation,variance;
    char str[100];

    printf("Enter the number of elements: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the elements:\n");

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter the operation:\n");
    printf("1.Sum\n");
    printf("2.Average\n");
    printf("3.Variance\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            for(i=0;i<n;i++)
            {
                sum+=arr[i];
            }
            printf("Sum of the elements: %d\n",sum);
            break;

        case 2:
            avg=0.0;

            for(i=0;i<n;i++)
            {
                avg+=arr[i];
            }

            avg=avg/n;

            printf("Average of the elements: %.2f\n",avg);
            break;

        case 3:

            for(i=0;i<n;i++)
            {
                deviation=arr[i]-avg;
                variance+=deviation*deviation;
            }

            variance=variance/n;

            printf("Variance of the elements: %.2f\n",variance);
            break;

        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}