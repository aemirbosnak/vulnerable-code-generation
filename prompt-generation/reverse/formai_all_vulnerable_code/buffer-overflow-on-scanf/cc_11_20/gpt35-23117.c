//FormAI DATASET v1.0 Category: Data mining ; Style: irregular
// A unique C Data Mining example program that uses irregular styles
#include<stdio.h>
main()
{
  int arr[10],i,j,n;
  printf("Enter the number of elements you want to enter: ");
  scanf("%d",&n);
  printf("Enter the elements: ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  printf("The given array is: \n");
  for(i=0;i<n;i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
  printf("The even numbers are: ");
  for(i=0;i<n;i++)
  {
    if(arr[i]%2==0)
    {
      printf("%d ",arr[i]);
    }
  }
  printf("\n");
  printf("The odd numbers are: ");
  for(i=0;i<n;i++)
  {
    if(arr[i]%2!=0)
    {
      printf("%d ",arr[i]);
    }
  }
  printf("\n");
  int max=arr[0],min=arr[0];
  for(i=1;i<n;i++)
  {
    if(arr[i]>max)
    {
      max=arr[i];
    }
    if(arr[i]<min)
    {
      min=arr[i];
    }
  }
  printf("The maximum number in the array is: %d\n",max);
  printf("The minimum number in the array is: %d\n",min);
  int sum=0,avg;
  for(i=0;i<n;i++)
  {
    sum=sum+arr[i];
  }
  avg=sum/n;
  printf("The sum of all the elements is: %d\n",sum);
  printf("The average of all the elements is: %d\n",avg);
  printf("The prime numbers in the array are: ");
  for(i=0;i<n;i++)
  {
    int flag=0;
    for(j=2;j<=arr[i]/2;j++)
    {
      if(arr[i]%j==0)
      {
        flag=1;
        break;
      }
    }
    if(flag==0)
    {
      printf("%d ",arr[i]);
    }
  }
  printf("\n");
  printf("The given array in reverse order is: ");
  for(i=n-1;i>=0;i--)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
  return 0;
}