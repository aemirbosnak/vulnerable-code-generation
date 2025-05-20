//FormAI DATASET v1.0 Category: Sorting ; Style: real-life
//This program sorts a list of students based on their grades in a real-life classroom scenario.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char name[50];
    int grade;
} student;

void bubble_sort(student arr[], int size) {
    int i, j;
    student temp;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - 1; j++) {
            if (arr[j].grade < arr[j+1].grade) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of students in the class: ");
    scanf("%d", &n);
    
    student* roster = (student*) malloc(n * sizeof(student));
    
    //Inputting student names and grades
    for (int i = 0; i < n; i++) {
        printf("Enter the name of student %d: ", i+1);
        scanf("%s", roster[i].name);
        printf("Enter the grade of student %d: ", i+1);
        scanf("%d", &roster[i].grade);
    }
    
    printf("\nUnsorted Class Roster:\n");
    for (int i = 0; i < n; i++) {
        printf("%s - Grade: %d\n", roster[i].name, roster[i].grade);
    }
    
    //Sorting the roster in descending order based on grades
    bubble_sort(roster, n);
    
    printf("\nSorted Class Roster:\n");
    for (int i = 0; i < n; i++) {
        printf("%s - Grade: %d\n", roster[i].name, roster[i].grade);
    }
    
    free(roster);
    return 0;
}