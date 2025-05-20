//Falcon-180B DATASET v1.0 Category: Educational ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    float grade;
} Student;

int compare(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;

    if (studentA->age < studentB->age) {
        return -1;
    } else if (studentA->age > studentB->age) {
        return 1;
    } else {
        return 0;
    }
}

void swap(Student *a, Student *b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Student *array, int low, int high) {
    Student pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (compare(array + j, &pivot) < 0) {
            i++;
            swap(array + i, array + j);
        }
    }

    swap(array + i + 1, array + high);
    return i + 1;
}

void quickSort(Student *array, int low, int high) {
    if (low < high) {
        int partitionIndex = partition(array, low, high);

        quickSort(array, low, partitionIndex - 1);
        quickSort(array, partitionIndex + 1, high);
    }
}

int main() {
    int numStudents;
    scanf("%d", &numStudents);

    Student *students = malloc(numStudents * sizeof(Student));

    for (int i = 0; i < numStudents; i++) {
        students[i].name = malloc(MAX_SIZE * sizeof(char));
        scanf("%s %d %f", students[i].name, &students[i].age, &students[i].grade);
    }

    quickSort(students, 0, numStudents - 1);

    for (int i = 0; i < numStudents; i++) {
        printf("%s %d %f\n", students[i].name, students[i].age, students[i].grade);
    }

    for (int i = 0; i < numStudents; i++) {
        free(students[i].name);
    }
    free(students);

    return 0;
}