//Falcon-180B DATASET v1.0 Category: Recursive ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX];

void merge(int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];

    for(int i=0; i<n1; i++)
        L[i] = arr[l + i];
    for(int j=0; j<n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int l, int r)
{
    if(l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(l, m);
        mergeSort(m + 1, r);

        merge(l, m, r);
    }
}

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    mergeSort(0, n-1);

    printf("\nSorted array: ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);

    return 0;
}