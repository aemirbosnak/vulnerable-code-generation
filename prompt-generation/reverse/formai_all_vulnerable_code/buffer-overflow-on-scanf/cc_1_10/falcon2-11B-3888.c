//Falcon2-11B DATASET v1.0 Category: Sorting ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int value;
    char* name;
} element_t;

int compare(const void* a, const void* b) {
    const element_t* e1 = (const element_t*)a;
    const element_t* e2 = (const element_t*)b;
    if (strcmp(e1->name, e2->name) < 0)
        return -1;
    else if (strcmp(e1->name, e2->name) > 0)
        return 1;
    else
        return 0;
}

void print_elements(element_t* elements, int num_elements) {
    for (int i = 0; i < num_elements; i++) {
        printf("%d - %s\n", elements[i].value, elements[i].name);
    }
}

int main() {
    int num_elements = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &num_elements);

    element_t* elements = malloc(num_elements * sizeof(element_t));
    if (elements == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the names and values of the elements:\n");
    for (int i = 0; i < num_elements; i++) {
        char name[100];
        int value;
        printf("Element %d: ", i + 1);
        scanf("%s %d", name, &value);
        elements[i].value = value;
        elements[i].name = strdup(name);
    }

    qsort(elements, num_elements, sizeof(element_t), compare);

    printf("Sorted elements:\n");
    print_elements(elements, num_elements);

    free(elements);

    return 0;
}