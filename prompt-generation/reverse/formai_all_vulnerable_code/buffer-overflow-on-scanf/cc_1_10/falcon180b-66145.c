//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: decentralized
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX 1000

int arr[MAX];
int n;
int count=0;

void *sum(void *param)
{
    int i;
    int sum=0;
    for(i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    printf("Sum of array elements = %d\n",sum);
    pthread_exit(0);
}

void *product(void *param)
{
    int i;
    int prod=1;
    for(i=0;i<n;i++)
    {
        prod*=arr[i];
    }
    printf("Product of array elements = %d\n",prod);
    pthread_exit(0);
}

int main()
{
    int i,j;
    int choice;
    pthread_t thread_id[2];
    void *status;

    printf("Enter the size of array: ");
    scanf("%d",&n);

    printf("Enter the elements of array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter your choice:\n1.Sum of array elements\n2.Product of array elements\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            pthread_create(&thread_id[0],NULL,sum,NULL);
            pthread_create(&thread_id[1],NULL,product,NULL);
            break;

        case 2:
            pthread_create(&thread_id[0],NULL,product,NULL);
            pthread_create(&thread_id[1],NULL,sum,NULL);
            break;

        default:
            printf("Invalid choice\n");
            exit(0);
    }

    for(i=0;i<2;i++)
    {
        pthread_join(thread_id[i],&status);
    }

    return 0;
}