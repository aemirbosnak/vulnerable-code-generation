//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: scientific
#include<stdio.h>
#include<stdlib.h>

//Creating a node for the linked list in each bucket
struct node 
{
  int data;
  struct node* next;
};

//Function to insert the elements into the buckets
void bucket_sort(int arr[], int n) 
{
  int i, j;
  
  //Initializing the number of buckets as 10
  int num_buckets = 10;
  struct node* buckets[num_buckets];

  for(i = 0; i < num_buckets; i++) 
  {
    buckets[i] = NULL;
  }

  //Inserting the elements into the bucket according to the index
  for(i = 0; i < n; i++) 
  {
    int index = arr[i] / 10;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = arr[i];
    temp->next = buckets[index];
    buckets[index] = temp;
  }

  //Sorting the elements in each bucket using insertion sort
  for(i = 0; i < num_buckets; i++) 
  {
    struct node* temp = buckets[i];
    while(temp) 
    {
      struct node* p = temp->next;
      int value = temp->data;
      j = i - 1;
      while(j >= 0 && buckets[j]->data > value) 
      {
        buckets[j + 1] = buckets[j];
        j--;
      }
      struct node* new_node = (struct node*)malloc(sizeof(struct node));
      new_node->data = value;
      new_node->next = buckets[j + 1];
      buckets[j + 1] = new_node;
      temp = p;
    }
  }

  //Copying the elements back to the original array
  int k = 0;
  for(i = 0; i < num_buckets; i++) 
  {
    struct node* temp = buckets[i];
    while(temp) 
    {
      arr[k++] = temp->data;
      temp = temp->next;
    }
  }
}

int main() 
{
  int n, i;
  printf("Enter the size of the array to be sorted: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter the elements of the array:\n");
  for(i = 0; i < n; i++) 
  {
    scanf("%d", &arr[i]);
  }
  
  bucket_sort(arr, n);

  printf("The sorted array is:\n");
  for(i = 0; i < n; i++) 
  {
    printf("%d ", arr[i]);
  }
  return 0;
}