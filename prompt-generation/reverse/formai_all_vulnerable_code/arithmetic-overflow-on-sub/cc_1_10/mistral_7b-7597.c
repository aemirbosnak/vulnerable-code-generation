//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    char name[20];
} Element;

void swap(Element* a, Element* b) {
    Element temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print_elements(Element arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%s: %d\n", arr[i].name, arr[i].value);
    }
}

void sort(Element arr[], int size) {
    int i, j, flag;
    for (i = 0; i < size - 1; i++) {
        flag = 0;
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j].value > arr[j + 1].value) {
                swap(&arr[j], &arr[j + 1]);
                flag = 1;
            }
        }
        if (!flag) break;
    }
}

int main() {
    int n, i;
    Element numbers[100];

    printf("Noble Capulets, come gather round,\nTo hear the tale of sorting numbers profound,\n\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the names and values of elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%s%d", numbers[i].name, &numbers[i].value);
    }

    printf("\nBefore sorting:\n");
    print_elements(numbers, n);

    sort(numbers, n);

    printf("\nAfter sorting:\n");
    print_elements(numbers, n);

    printf("\nMontagues and Capulets, this strife\nEnds here, as numbers now take their place,\nIn order, equal, and fair,\n\n");

    return 0;
}