//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX 1000
#define SIZE 32

typedef struct {
    int value;
    char name[SIZE];
} Element;

void sorcererHatSort(Element arr[], int n);
void printElements(Element arr[], int n);

int main() {
    Element elements[MAX];
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("\nEnter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("\nElement %d: ", i + 1);
        scanf("%s %d", elements[i].name, &elements[i].value);
        elements[i].name[strcspn(elements[i].name, "\n")] = '\0';
    }

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        int j = rand() % n;
        Element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }

    printf("\nUnsorted array:\n");
    printElements(elements, n);

    sorcererHatSort(elements, n);

    printf("\nSorted array:\n");
    printElements(elements, n);

    return 0;
}

void sorcererHatSort(Element arr[], int n) {
    int i, j, start, end;

    for (i = 0; i < n - 1; i++) {
        if (arr[i].value > arr[i + 1].value) {
            start = i;
            for (j = i + 1; j < n; j++) {
                if (arr[j].value < arr[i].value) {
                    end = j;
                    break;
                }
            }

            if (end > start) {
                Element temp = arr[start];
                for (i = start; i < end; i++) {
                    arr[i] = arr[i + 1];
                }
                arr[end] = temp;

                int k = start;
                for (j = i + 1; j < n && arr[j].value > arr[k].value; j++) {
                    k = j;
                }

                if (k > start + 1) {
                    for (i = start; i < k; i++) {
                        Element temp2 = arr[i];
                        arr[i] = arr[i + 1];
                        arr[i + 1] = temp2;
                    }
                }
            }
        }
    }
}

void printElements(Element arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\n%s: %d", arr[i].name, arr[i].value);
    }
}