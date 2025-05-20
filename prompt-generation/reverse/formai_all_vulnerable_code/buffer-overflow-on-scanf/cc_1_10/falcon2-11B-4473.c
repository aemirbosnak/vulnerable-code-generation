//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct {
 int key;
 int value;
} elem;

void bucket_sort(elem *arr, int n)
{
 int i, j, k;
 int bucket_size = ceil(sqrt(n));
 int *bucket_arr = (int *)malloc(bucket_size * sizeof(int));

 for(i = 0; i < n; i++)
 {
 int index = floor(arr[i].key / bucket_size);
 bucket_arr[index]++;
 }

 for(i = 0; i < bucket_size; i++)
 {
 int count = bucket_arr[i];
 if(count == 0) continue;

 for(j = 0; j < count; j++)
 {
 int index = i * bucket_size + j;
 int max_index = floor(arr[index].key / bucket_size);
 int min_index = max_index + 1;

 for(k = max_index; k <= min_index; k++)
 {
 if(bucket_arr[k] == 0) continue;

 int temp = arr[index].value;
 arr[index].value = arr[k].value;
 arr[k].value = temp;
 }

 bucket_arr[i]--;
 }
 }

 for(i = 0; i < n; i++)
 printf("%d %d\n", arr[i].key, arr[i].value);
}

int main()
{
 int n;
 printf("Enter the number of elements: ");
 scanf("%d", &n);
 elem *arr = (elem *)malloc(n * sizeof(elem));

 printf("Enter the elements:\n");
 for(int i = 0; i < n; i++)
 {
 scanf("%d %d", &arr[i].key, &arr[i].value);
 }

 bucket_sort(arr, n);

 return 0;
}