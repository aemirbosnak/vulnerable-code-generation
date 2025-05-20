//Falcon-180B DATASET v1.0 Category: Sorting ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define structure for elements to be sorted
typedef struct {
    int id;
    char name[50];
    float score;
} element;

// Function to compare two elements based on their scores
int compare(const void *a, const void *b) {
    const element *elemA = (const element *)a;
    const element *elemB = (const element *)b;
    return (elemA->score - elemB->score);
}

int main() {
    int numElements;
    element *elements = NULL;
    int i;

    // Get number of elements from user
    printf("Enter number of elements: ");
    scanf("%d", &numElements);

    // Allocate memory for elements
    elements = (element *)malloc(numElements * sizeof(element));

    // Get data for each element
    for (i = 0; i < numElements; i++) {
        printf("Enter ID for element %d: ", i+1);
        scanf("%d", &elements[i].id);
        printf("Enter name for element %d: ", i+1);
        scanf("%s", elements[i].name);
        printf("Enter score for element %d: ", i+1);
        scanf("%f", &elements[i].score);
    }

    // Sort elements based on score
    qsort(elements, numElements, sizeof(element), compare);

    // Print sorted elements
    printf("\nSorted elements:\n");
    for (i = 0; i < numElements; i++) {
        printf("ID: %d\nName: %s\nScore: %f\n", elements[i].id, elements[i].name, elements[i].score);
    }

    // Free memory for elements
    free(elements);

    return 0;
}