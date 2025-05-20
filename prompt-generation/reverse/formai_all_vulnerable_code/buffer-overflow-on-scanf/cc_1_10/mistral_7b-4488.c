//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

typedef struct {
    int id;
    char name[20];
} Student;

void unique_sort(Student arr[], int n) {
    int i, j, flag;
    Student temp;

    for (i = 0; i < n - 1; i++) {
        flag = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
            if (arr[j].id == arr[j + 1].id && strcmp(arr[j].name, arr[j + 1].name) == 0) {
                for (int k = j; k < n - 1; k++) {
                    if (arr[k].id != arr[k + 1].id || strcmp(arr[k].name, arr[k + 1].name) != 0) {
                        temp = arr[k];
                        arr[k] = arr[k + 1];
                        arr[k + 1] = temp;
                        flag = 1;
                        break;
                    }
                }
            }
        }

        if (flag == 0) {
            break;
        }
    }
}

int main() {
    Student students[MAX];
    int n, i;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    printf("\nEnter the details of each student:\n");
    for (i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%d %s", &students[i].id, students[i].name);
    }

    printf("\nBefore sorting:\n");
    for (i = 0; i < n; i++) {
        printf("\nID: %d, Name: %s", students[i].id, students[i].name);
    }

    unique_sort(students, n);

    printf("\nAfter sorting:\n");
    for (i = 0; i < n; i++) {
        printf("\nID: %d, Name: %s", students[i].id, students[i].name);
    }

    return 0;
}