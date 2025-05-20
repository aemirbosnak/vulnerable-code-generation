//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
    int age;
} Person;

void swap(Person *p1, Person *p2) {
    Person temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void bubbleSort(Person arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    Person students[MAX];
    int n, i;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    printf("\nEnter the details of students:\n");
    for (i = 0; i < n; i++) {
        printf("\nName %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Age %d: ", i + 1);
        scanf("%d", &students[i].age);
    }

    bubbleSort(students, n);

    printf("\nSorted Student List: \n");
    for (i = 0; i < n; i++) {
        printf("\nName: %s", students[i].name);
        printf("\nAge: %d", students[i].age);
    }

    return 0;
}