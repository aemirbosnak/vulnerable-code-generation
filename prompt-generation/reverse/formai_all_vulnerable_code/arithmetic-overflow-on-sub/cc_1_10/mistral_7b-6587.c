//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define TABLE_SIZE 10

typedef struct {
    char name[MAX_SIZE];
    int age;
} Person;

void swap(Person *p1, Person *p2) {
    Person temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void bubbleSort(Person table[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(table[j].name, table[j + 1].name) > 0) {
                swap(&table[j], &table[j + 1]);
            }
        }
    }
}

int main() {
    Person table[TABLE_SIZE];
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    printf("\nEnter the name and age of each student:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%s %d", table[i].name, &table[i].age);
    }

    bubbleSort(table, n);

    printf("\nSorted students list:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Age: %d\n", table[i].name, table[i].age);
    }

    return 0;
}