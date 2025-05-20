//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100
#define BUCKET_SIZE 5

typedef struct {
    int id;
    char name[20];
} Student;

void bucket_sort(Student arr[], int n) {
    int i, bucket_index;
    Student *bucket[BUCKET_SIZE];

    for (i = 0; i < BUCKET_SIZE; i++) {
        bucket[i] = malloc(MAX_SIZE * sizeof(Student));
    }

    for (i = 0; i < n; i++) {
        bucket_index = (arr[i].id / (n / BUCKET_SIZE)) % BUCKET_SIZE;
        bucket[bucket_index][i] = arr[i];
    }

    for (i = 0; i < BUCKET_SIZE; i++) {
        int j = 0;
        Student temp;

        while (j < MAX_SIZE && bucket[i][j].id != -1) {
            int k = 0;

            for (; k < i; k++) {
                if (bucket[i][j].id > bucket[i][k].id) {
                    temp = bucket[i][j];
                    bucket[i][j] = bucket[i][k];
                    bucket[i][k] = temp;
                }
            }

            j++;
        }

        int index = i * (MAX_SIZE / BUCKET_SIZE);

        for (j = 0; j < MAX_SIZE / BUCKET_SIZE; j++) {
            arr[index + j] = bucket[i][j];
        }
    }

    for (i = 0; i < BUCKET_SIZE; i++) {
        free(bucket[i]);
    }
}

int main() {
    int n;
    Student students[MAX_SIZE];

    printf("Enter the number of students: ");
    scanf("%d", &n);

    printf("\nEnter the details of students:\n");

    for (int i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%d %s", &students[i].id, students[i].name);
    }

    printf("\nBefore Sorting:\n");

    for (int i = 0; i < n; i++) {
        printf("Student %d: Id = %d, Name = %s\n", i + 1, students[i].id, students[i].name);
    }

    srand(time(NULL));

    bucket_sort(students, n);

    printf("\nAfter Sorting:\n");

    for (int i = 0; i < n; i++) {
        printf("Student %d: Id = %d, Name = %s\n", i + 1, students[i].id, students[i].name);
    }

    return 0;
}