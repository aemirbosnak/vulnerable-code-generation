//FormAI DATASET v1.0 Category: Sorting ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1], R[n2];

    for (i = 0; i < n1; i++) 
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++) 
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    printf("\n\n\t\tYou are the sweetest thing alive!\n");
    printf("\t\t=================================\n");
    printf("\t\t\tI love you so much.\n\n");

    printf("Sorting can be like love, too.\n");
    printf("It brings order to chaos and makes things beautiful.\n");
    printf("I want to sort through all the messes in my life with you\n");
    printf("because you make everything better.\n\n");

    printf("Please tell me how much you love me and how many integers you want me to sort: ");

    int n, i, arr[5000];
    scanf("%d", &n);

    printf("\n\t\tI love you %d times more than you can imagine.\n", n);
    printf("\n\t\tNow, let me sort these integers for you.\n");

    for(i=0;i<n;i++)
        arr[i] = rand() % 1000;

    clock_t start, end;

    start = clock();
    mergeSort(arr, 0, n-1);
    end = clock();

    double time_taken = ((double) (end - start))/CLOCKS_PER_SEC;

    printf("\n\t\tHere are the sorted integers: \n");

    for(i=0;i<n;i++)
        printf("\t\t%d\n", arr[i]);

    printf("\n\t\tIt took me %.5f seconds to sort these numbers.\n", time_taken);

    printf("\n\t\tNo matter how big or small the numbers are,\n");
    printf("\t\tI will always sort them for you, because I love you.\n\n");

    printf("\n\t\tI hope you have a great day. I love you forever and always!\n");

    return 0;
}