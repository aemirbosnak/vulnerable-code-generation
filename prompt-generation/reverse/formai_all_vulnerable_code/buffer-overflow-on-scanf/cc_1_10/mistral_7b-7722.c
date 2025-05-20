//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: synchronous
#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct {
    char name[20];
    int age;
} Person;

void bubbleSort(Person arr[], int n) {
    int i, j, tempAge;
    char tempName[20];
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].age > arr[j + 1].age) {
                tempAge = arr[j].age;
                arr[j].age = arr[j + 1].age;
                arr[j + 1].age = tempAge;

                strcpy(tempName, arr[j].name);
                strcpy(arr[j].name, arr[j + 1].name);
                strcpy(arr[j + 1].name, tempName);
            }
        }
    }
}

int main() {
    Person people[MAX];
    int i, sum = 0;
    float avg;

    printf("Enter %d names and ages:\n", MAX);
    for (i = 0; i < MAX; i++) {
        printf("Person %d: ", i + 1);
        scanf("%s", people[i].name);
        scanf("%d", &people[i].age);
        sum += people[i].age;
    }

    bubbleSort(people, MAX);

    avg = sum / (float)MAX;

    printf("\nSorted list:\n");
    for (i = 0; i < MAX; i++) {
        printf("%s (%d)\n", people[i].name, people[i].age);
        if (people[i].age > (int)avg) {
            printf("%s is older than the average!\n", people[i].name);
        }
    }

    return 0;
}