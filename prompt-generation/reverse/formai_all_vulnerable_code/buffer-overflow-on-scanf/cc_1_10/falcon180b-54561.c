//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 1000
#define RANGE 10000

int main()
{
    int i,n,range,*arr,max,min;
    float avg;
    struct tm *t;
    time_t now;
    srand(time(NULL));

    printf("Enter the number of elements to be sorted: ");
    scanf("%d",&n);

    arr=(int*)malloc(n*sizeof(int));

    printf("Enter the range of the elements to be sorted: ");
    scanf("%d",&range);

    for(i=0;i<n;i++)
        arr[i]=rand()%range;

    max=arr[0];
    min=arr[0];

    for(i=1;i<n;i++)
    {
        if(arr[i]>max)
            max=arr[i];
        if(arr[i]<min)
            min=arr[i];
    }

    avg=(float)range/(max-min+1);

    printf("\nThe elements to be sorted are: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    printf("\nThe range of the elements is: %d",range);
    printf("\nThe maximum element is: %d",max);
    printf("\nThe minimum element is: %d",min);
    printf("\nThe average range of the elements is: %.2f",avg);

    t=localtime(&now);
    printf("\nThe current date and time is: %d-%d-%d %d:%d:%d",t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min,t->tm_sec);

    return 0;
}