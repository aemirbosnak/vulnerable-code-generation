//FormAI DATASET v1.0 Category: Sorting ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[100];
    int age;
    float gpa;
};

void swap(struct student *a, struct student *b) {
    struct student temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(struct student arr[], int low, int high) {
    
    if (low < high) {       
        int i = low - 1;
        struct student pivot = arr[high]; 
        for (int j = low; j <= high - 1; j++) {
            if (strcmp(arr[j].name, pivot.name) < 0) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct student arr[n];
    
    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i+1);
        scanf(" %[^\n]s", arr[i].name);
        printf("Enter age of student %d: ", i+1);
        scanf("%d", &arr[i].age);
        printf("Enter GPA of student %d: ", i+1);
        scanf("%f", &arr[i].gpa);
        printf("\n");
    }

    quickSort(arr, 0, n - 1);
    
    printf("Students sorted by name in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s | Age: %d | GPA: %.2f\n", arr[i].name, arr[i].age, arr[i].gpa);
    }
    
    return 0;
}