//Falcon-180B DATASET v1.0 Category: Sorting ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

struct student {
    char name[50];
    int age;
    float GPA;
};

void swap(struct student *a, struct student *b) {
    struct student temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void *a, const void *b) {
    struct student *s1 = (struct student *)a;
    struct student *s2 = (struct student *)b;
    if (s1->age > s2->age) {
        return 1;
    } else if (s1->age < s2->age) {
        return -1;
    } else {
        return 0;
    }
}

void sort(struct student arr[], int n) {
    qsort(arr, n, sizeof(struct student), compare);
}

int main() {
    int n;
    struct student arr[MAX_SIZE];
    srand(time(NULL));
    printf("Enter the number of students: ");
    scanf("%d", &n);
    printf("Enter the name, age and GPA of each student:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s %d %f", arr[i].name, &arr[i].age, &arr[i].GPA);
    }
    sort(arr, n);
    printf("Sorted list of students:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d %.2f\n", arr[i].name, arr[i].age, arr[i].GPA);
    }
    return 0;
}