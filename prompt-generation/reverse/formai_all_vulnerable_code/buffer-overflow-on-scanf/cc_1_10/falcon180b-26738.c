//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    int id;
    char name[50];
    double score;
} Student;

void bubbleSort(Student arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].score < arr[j + 1].score) {
                Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printStudents(Student arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d %s %.2f\n", arr[i].id, arr[i].name, arr[i].score);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Student arr[MAX_SIZE];
    int count = 0;

    while (count < n) {
        printf("Enter student ID, name, and score (or type -1 to finish):\n");
        scanf("%d %s %lf", &arr[count].id, arr[count].name, &arr[count].score);
        if (arr[count].id == -1) {
            break;
        }
        count++;
    }

    bubbleSort(arr, count);
    printf("Sorted students by score:\n");
    printStudents(arr, count);

    return 0;
}