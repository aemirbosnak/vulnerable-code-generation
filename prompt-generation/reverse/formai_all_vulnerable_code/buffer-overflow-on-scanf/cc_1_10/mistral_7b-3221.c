//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 1000

typedef struct {
    int num;
    char name[20];
} Person;

void ephemeralSort(Person arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int r = rand() % n;
        Person temp = arr[i];
        arr[i] = arr[r];
        arr[r] = temp;
        int swapFlag = 1;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].num > arr[j + 1].num) {
                Person temp2 = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp2;
                swapFlag = 0;
            }
        }
        if (swapFlag)
            break;
    }
}

int main() {
    Person arr[MAX];
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the details of each element:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s%d", arr[i].name, &arr[i].num);
    }

    printf("\nUnsorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\n", arr[i].name, arr[i].num);
    }

    ephemeralSort(arr, n);

    printf("\nSorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\n", arr[i].name, arr[i].num);
    }

    return 0;
}