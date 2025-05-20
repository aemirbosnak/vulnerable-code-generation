//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LENGTH 50
#define ELEMENT_SIZE (sizeof(struct CyberData) + MAX_LENGTH)

typedef struct CyberData {
    char name[MAX_LENGTH];
    int age;
    int neo_points;
} CyberData;

void print_cyber_data(CyberData data) {
    printf("[%s]\n", data.name);
    printf("Age: %d\n", data.age);
    printf("Neo-Points: %d\n", data.neo_points);
}

int compare_neo_points(const void *a, const void *b) {
    CyberData *cyber_a = (CyberData *) a;
    CyberData *cyber_b = (CyberData *) b;
    return (cyber_b->neo_points - cyber_a->neo_points);
}

int main() {
    int num_elements;
    clock_t start, end;
    CyberData *cyber_data;

    printf("===== [ DEADCODE ENTERPRISES - NEURAL SORTING SYSTEM ] =====\n");
    printf("Enter number of elements to sort: ");
    scanf("%d", &num_elements);

    if (num_elements <= 0) {
        printf("Error: Invalid number of elements.\n");
        return 1;
    }

    cyber_data = (CyberData *) malloc(num_elements * ELEMENT_SIZE);

    if (cyber_data == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    start = clock();

    for (int i = 0; i < num_elements; i++) {
        printf("\nEnter Cyberpunk character data [%d]:\n", i + 1);
        printf("Name: ");
        scanf("%s", cyber_data[i].name);
        cyber_data[i].age = rand() % 100 + 19;
        cyber_data[i].neo_points = rand() % 100;
    }

    qsort(cyber_data, num_elements, ELEMENT_SIZE, compare_neo_points);

    printf("\n===== [ SORTED NEURAL DATA ] =====\n");
    for (int i = 0; i < num_elements; i++) {
        print_cyber_data(cyber_data[i]);
    }

    free(cyber_data);

    end = clock();
    printf("\nTime taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}