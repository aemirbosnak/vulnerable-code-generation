//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 10000

typedef struct {
    int id;
    char name[50];
    float grade;
} student_t;

void bubble_sort(student_t arr[], int n) {
    int i, j;
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(arr[j].grade < arr[j+1].grade) {
                student_t temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    student_t arr[MAX_SIZE];
    printf("Enter student details:\n");
    for(int i=0; i<n; i++) {
        arr[i].id = i+1;
        printf("ID: ");
        scanf("%d", &arr[i].id);
        printf("Name: ");
        scanf("%s", arr[i].name);
        printf("Grade: ");
        scanf("%f", &arr[i].grade);
    }

    bubble_sort(arr, n);

    printf("\nSorted students by grade:\n");
    for(int i=0; i<n; i++) {
        printf("%d. %s - Grade: %.2f\n", arr[i].id, arr[i].name, arr[i].grade);
    }

    return 0;
}