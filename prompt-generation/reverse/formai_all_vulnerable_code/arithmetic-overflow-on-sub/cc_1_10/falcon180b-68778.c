//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100

int arr[MAX];
int n;

void merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        merge_sort(l, m);
        merge_sort(m + 1, r);

        merge(l, m, r);
    }
}

void generate_array()
{
    int i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void print_array()
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    srand(time(0));
    generate_array();
    merge_sort(0, n - 1);
    printf("Sorted array: ");
    print_array();
    return 0;
}