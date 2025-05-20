//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[50];
    int age;
} Person;

void bucketSort(Person arr[], int n) {
    int i, j, count[MAX_SIZE] = {0};
    Person temp[MAX_SIZE];

    for (i = 0; i < n; i++) {
        count[(arr[i].age) / 10]++;
    }

    for (i = 0; i < MAX_SIZE; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        temp[count[(arr[i].age) / 10] - 1] = arr[i];
        count[(arr[i].age) / 10]--;
    }

    for (i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    Person arr[MAX_SIZE];
    int n, i;

    printf("Enter the number of people: ");
    scanf("%d", &n);

    printf("Enter the name and age of each person:\n");

    for (i = 0; i < n; i++) {
        scanf("%s %d", arr[i].name, &arr[i].age);
    }

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        int randIndex = rand() % n;
        Person temp = arr[i];
        arr[i] = arr[randIndex];
        arr[randIndex] = temp;
    }

    bucketSort(arr, n);

    printf("Sorted by age:\n");
    for (i = 0; i < n; i++) {
        printf("%s %d years old\n", arr[i].name, arr[i].age);
    }

    return 0;
}