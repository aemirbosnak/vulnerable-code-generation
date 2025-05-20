//FormAI DATASET v1.0 Category: Data mining ; Style: active
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, i, j, k, flag = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    printf("Enter %d numbers: ", n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value of k: ");
    scanf("%d", &k);
    printf("The %d most frequent elements in the array are: ", k);
    int *freq = (int *)calloc(n, sizeof(int));
    for(i=0; i<n; i++)
    {
        if(freq[i] != -1)
        {
            int count = 1;
            for(j=i+1; j<n; j++)
            {
                if(arr[i] == arr[j])
                {
                    count++;
                    freq[j] = -1;
                }
            }
            freq[i] = count;
        }
    }
    for(i=0; i<k; i++)
    {
        int max = 0, index;
        for(j=0; j<n; j++)
        {
            if(freq[j]>max)
            {
                max = freq[j];
                index = j;
            }
        }
        freq[index] = -1;
        printf("%d ", arr[index]);
        flag = 1;
    }
    if(flag == 0)
    {
        printf("No frequent elements found in the array");
    }
    free(arr);
    free(freq);
    return 0;
}