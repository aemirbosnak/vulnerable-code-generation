//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: complete
#include <stdio.h>
#include <string.h>

typedef struct Student {
    int id;
    char name[50];
    float gpa;
} Student;

void bubbleSort(Student arr[], int n) {
    int i, j, flag;
    for (i = 0; i < n - 1; i++) {
        flag = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].gpa < arr[j + 1].gpa) {
                Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                strcpy(temp.name, arr[j].name);
                strcpy(arr[j].name, arr[j + 1].name);
                flag = 1;
            }
        }
        // If no two elements were swapped in the inner loop, then the array is already sorted
        if (flag == 0) {
            break;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    Student students[n];

    printf("\nEnter student data:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("GPA: ");
        scanf("%f", &students[i].gpa);
    }

    bubbleSort(students, n);

    printf("\nSorted student data:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("GPA: %.2f\n", students[i].gpa);
    }

    return 0;
}