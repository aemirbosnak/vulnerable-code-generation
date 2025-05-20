//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct {
    int rollno;
    char name[20];
    float marks;
} Student;

void BucketSort(Student arr[], int n) {
    int i;
    Student *bucket[TABLE_SIZE];

    for (i = 0; i < TABLE_SIZE; i++) {
        bucket[i] = (Student *)calloc(1, sizeof(Student));
    }

    for (i = 0; i < n; i++) {
        int index = arr[i].rollno % TABLE_SIZE;
        bucket[index] -> rollno = arr[i].rollno;
        strcpy(bucket[index]->name, arr[i].name);
        bucket[index]->marks = arr[i].marks;
    }

    for (i = 0; i < TABLE_SIZE; i++) {
        int j;
        Student temp;

        for (j = 1; j < TABLE_SIZE - i; j++) {
            if (bucket[j]->rollno > bucket[j - 1]->rollno) {
                temp = *bucket[j];
                *bucket[j] = *bucket[j - 1];
                *bucket[j - 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        int index = arr[i].rollno % TABLE_SIZE;
        arr[i].rollno = bucket[index]->rollno;
        strcpy(arr[i].name, bucket[index]->name);
        arr[i].marks = bucket[index]->marks;
        free(bucket[index]);
    }

    for (i = 0; i < TABLE_SIZE; i++) {
        free(bucket[i]);
    }
}

int main() {
    int n;
    Student students[50];

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("\nEnter student details:\n");
    for (int i = 0; i < n; i++) {
        printf("\nRoll No: ");
        scanf("%d", &students[i].rollno);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    BucketSort(students, n);

    printf("\nSorted Student Details:\n");
    for (int i = 0; i < n; i++) {
        printf("\nRoll No: %d", students[i].rollno);
        printf("\nName: %s", students[i].name);
        printf("\nMarks: %.2f", students[i].marks);
    }

    return 0;
}