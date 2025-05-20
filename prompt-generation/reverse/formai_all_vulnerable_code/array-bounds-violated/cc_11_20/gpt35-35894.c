//FormAI DATASET v1.0 Category: Sorting ; Style: immersive
#include<stdio.h>

int main()
{

  printf("Welcome to the Sorting Program!\n\n");
  printf("Enter the number of elements you want to sort: ");

  int size;
  scanf("%d", &size);

  int arr[size], i;

  printf("\nEnter the elements to be sorted: ");
  for(i=0; i<size; i++)
  {
      scanf("%d", &arr[i]);
  }

  int choice;
  printf("\nWhich Sorting Algorithm would you like to use? \n1. Bubble Sort \n2. Selection Sort \n3. Insertion Sort \nEnter your choice: ");
  scanf("%d",&choice);

  switch(choice)
  {

    //Bubble Sort Algorithm
    case 1:
    {
        int j, temp;
        for(i=0; i<size-1; i++)
        {
          for(j=0; j<size-i-1; j++)
          {
            if(arr[j]>arr[j+1])
            {
              temp=arr[j];
              arr[j]=arr[j+1];
              arr[j+1]=temp;
            }
          }
        }
        printf("\nThe array after Bubble sort is: ");
        for(i=0; i<size; i++)
        {
          printf("%d ", arr[i]);
        }
        break;
    }

    //Selection Sort Algorithm
    case 2:
    {
        int j, temp, min;
        for(i=0; i<size-1; i++)
        {
          min = i;
          for(j=i+1; j<size; j++)
          {
            if(arr[j]<arr[min])
            {
              min=j;
            }
          }
          temp=arr[i];
          arr[i]=arr[min];
          arr[min]=temp;
        }
        printf("\nThe array after Selection sort is: ");
        for(i=0; i<size; i++)
        {
          printf("%d ", arr[i]);
        }
        break;

    }

    //Insertion Sort Algorithm
    case 3:
    {
        int j, temp;
        for(i=1; i<size; i++)
        {
          temp=arr[i];
          j=i-1;
          while(j>=0 && arr[j]>temp)
          {
            arr[j+1]=arr[j];
            j--;
          }
          arr[j+1]=temp;
        }
        printf("\nThe array after Insertion sort is: ");
        for(i=0; i<size; i++)
        {
          printf("%d ", arr[i]);
        }
        break;
    }

    default:
    {
        printf("\nInvalid choice! Please try again.");
    }

  }

  return 0;
}