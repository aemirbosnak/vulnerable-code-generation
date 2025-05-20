//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100
#define SWAP(type, x, y) do { type temp = x; x = y; y = temp; } while (0)

typedef struct {
    int id;
    char name[20];
    float gpa;
} Student;

void print_students(Student students[], int size);
void bubble_sort(Student students[], int size, int (*compare)(const void *, const void *));
int compare_id(const void *a, const void *b);
int compare_gpa(const void *a, const void *b);

int main() {
    Student students[MAX_SIZE];
    int size = 0;
    int choice;

    srand(time(NULL));

    while (1) {
        printf("\n--------------------------\n");
        printf(" Student Management System\n");
        printf("--------------------------\n");
        printf("\n1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Sort Students by ID\n");
        printf("4. Sort Students by GPA\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (size >= MAX_SIZE) {
                    printf("Maximum capacity reached!\n");
                    break;
                }

                students[size].id = rand() % 100 + 1;
                strcpy(students[size].name, "Student");
                students[size].gpa = (float) rand() / RAND_MAX;

                size++;
                break;

            case 2:
                print_students(students, size);
                break;

            case 3:
                bubble_sort(students, size, compare_id);
                print_students(students, size);
                break;

            case 4:
                bubble_sort(students, size, compare_gpa);
                print_students(students, size);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void print_students(Student students[], int size) {
    int i;

    printf("\nID\tName\tGPA\n");

    for (i = 0; i < size; i++) {
        printf("%d\t%s\t%.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
}

void bubble_sort(Student students[], int size, int (*compare)(const void *, const void *)) {
    int i, j;
    Student temp;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (compare(&students[j], &students[j + 1]) < 0) {
                SWAP(Student, students[j], students[j + 1]);
            }
        }
    }
}

int compare_id(const void *a, const void *b) {
    return (*(Student *)a).id - (*(Student *)b).id;
}

int compare_gpa(const void *a, const void *b) {
    return (*(Student *)b).gpa > (*(Student *)a).gpa ? -1 : 1;
}