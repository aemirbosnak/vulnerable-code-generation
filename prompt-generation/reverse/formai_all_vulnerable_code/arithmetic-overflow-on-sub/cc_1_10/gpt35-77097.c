//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: enthusiastic
#include<stdio.h>
int main()
{
  printf("Let's solve an exciting problem using the Greedy Algorithm!\n");
  int n, i, j, temp;
  printf("Enter the size of the array: ");
  scanf("%d",&n);
  int a[n];
  printf("Enter the elements of the array: ");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  printf("The original array is: ");
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
  printf("\n");
  printf("Now let's sort the array in non-decreasing order using the Selection Sort Algorithm!\n");
  for(i=0;i<n-1;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(a[i]>a[j])
      {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
      }
    }
  }
  printf("The sorted array is: ");
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
  printf("\n");
  printf("Now let's implement the Greedy Algorithm to find the minimum number of coins that add up to a given amount!\n");
  int A;
  printf("Enter the required amount: ");
  scanf("%d",&A);
  int coins[4]={25,10,5,1};
  int count[4]={0,0,0,0};
  for(i=0;i<4;i++)
  {
    while(A>=coins[i])
    {
      A-=coins[i];
      count[i]++;
    }
  }
  printf("The minimum coins needed to get %d is ",A);
  int sum=0;
  for(i=0;i<4;i++)
  {
    printf("%d %d-cent coins ",count[i],coins[i]);
    sum+=count[i];
  }
  printf("\n");
  printf("The total number of coins used is %d.\n",sum);
  printf("Hope you had fun solving this problem using the Greedy Algorithm!\n");
  return 0;
}