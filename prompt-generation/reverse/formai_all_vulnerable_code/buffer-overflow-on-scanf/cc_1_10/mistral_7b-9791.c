//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define BUCKET_COUNT 10

typedef struct {
    int key;
    char name[50];
} Student;

int hashFunction(int key) {
    return fabs(fmod(key, BUCKET_COUNT));
}

void bucketSort(Student arr[], int n) {
    int i, bucketIndex;
    Student *bucket[BUCKET_COUNT] = {0};

    for (i = 0; i < BUCKET_COUNT; i++) {
        bucket[i] = malloc(sizeof(Student) * n);
    }

    for (i = 0; i < n; i++) {
        bucketIndex = hashFunction(arr[i].key);
        bucket[bucketIndex][arr[i].key - 1] = arr[i];
    }

    int index = 0;
    for (i = 0; i < BUCKET_COUNT; i++) {
        for (int j = 0; j < n; j++) {
            arr[index++] = bucket[i][j];
        }
        free(bucket[i]);
    }
}

void printStudents(Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %s\n", arr[i].key, arr[i].name);
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    Student students[n];

    printf("\nEnter the student details:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Key: ");
        scanf("%d", &students[i].key);
        printf("Name: ");
        scanf("%s", students[i].name);
    }

    bucketSort(students, n);
    printf("\nSorted students:\n");
    printStudents(students, n);

    return 0;
}