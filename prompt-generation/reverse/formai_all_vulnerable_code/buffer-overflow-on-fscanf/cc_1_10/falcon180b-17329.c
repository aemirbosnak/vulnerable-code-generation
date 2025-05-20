//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Student;

int compare(const void *a, const void *b) {
    Student *student1 = (Student *)a;
    Student *student2 = (Student *)b;

    if (student1->age > student2->age) {
        return 1;
    } else if (student1->age < student2->age) {
        return -1;
    } else {
        return 0;
    }
}

int binary_search(Student *students, int size, int target_age) {
    qsort(students, size, sizeof(Student), compare);

    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (students[mid].age == target_age) {
            return mid;
        } else if (students[mid].age < target_age) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    Student students[MAX_SIZE];
    int size = 0;

    FILE *file = fopen("students.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(file, "%s %d\n", students[size].name, &students[size].age)!= EOF) {
        size++;
    }

    fclose(file);

    int target_age = 22;
    int index = binary_search(students, size, target_age);

    if (index!= -1) {
        printf("Found student with age %d: %s\n", target_age, students[index].name);
    } else {
        printf("Student not found.\n");
    }

    return 0;
}