//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKET_SIZE 5

typedef struct {
    int key;
    char name[20];
} Student;

void bucket_sort(Student arr[], int n) {
    int i, bucket, index;
    Student *bucket_arr[BUCKET_SIZE];

    for (i = 0; i < BUCKET_SIZE; i++) {
        bucket_arr[i] = malloc(sizeof(Student) * n);
    }

    for (i = 0; i < n; i++) {
        bucket = arr[i].key % BUCKET_SIZE;
        index = (bucket + n) % n;
        bucket_arr[bucket][index] = arr[i];
    }

    for (i = 0; i < BUCKET_SIZE; i++) {
        for (int j = 0; j < n; j++) {
            arr[j] = bucket_arr[i][j];
        }
    }

    for (int i = 0; i < BUCKET_SIZE; i++) {
        free(bucket_arr[i]);
    }
}

void print_students(Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Roll Number: %d\n", arr[i].name, arr[i].key);
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    Student students[n];

    printf("Enter the details of students:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s %d", students[i].name, &students[i].key);
    }

    bucket_sort(students, n);
    printf("\nSorted Students:\n");
    print_students(students, n);

    return 0;
}