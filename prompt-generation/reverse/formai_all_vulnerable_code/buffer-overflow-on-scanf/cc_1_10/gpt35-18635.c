//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    float weight;
} PERSON;

void printPerson(PERSON *p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Weight: %.2f\n", p->weight);
}

void sortPersonsByWeight(PERSON *list, int len) {
    int i, j;
    PERSON tmp;
    for (i = 0; i < len; i++) {
        for (j = i+1; j < len; j++) {
            if (list[i].weight > list[j].weight) {
                memcpy(&tmp, &list[i], sizeof(PERSON));
                memcpy(&list[i], &list[j], sizeof(PERSON));
                memcpy(&list[j], &tmp, sizeof(PERSON));
            }
        }
    }
}

int main() {
    int i, count;
    printf("Number of persons: ");
    scanf("%d", &count);

    PERSON *list = (PERSON*) malloc(count * sizeof(PERSON));
    if (!list) {
        printf("Memory allocation error\n");
        return 1;
    }

    for (i = 0; i < count; i++) {
        printf("Person %d name: ", i+1);
        scanf("%s", list[i].name);
        printf("Person %d age: ", i+1);
        scanf("%d", &list[i].age);
        printf("Person %d weight: ", i+1);
        scanf("%f", &list[i].weight);
    }

    sortPersonsByWeight(list, count);

    printf("\nSorted List:\n");
    for (i = 0; i < count; i++) {
        printf("\nPerson %d:\n", i+1);
        printPerson(&list[i]);
    }

    free(list);
    return 0;
}