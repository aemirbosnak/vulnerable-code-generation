//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[50];
    float salary;
} Employee;

int compareEmployees(const void *a, const void *b) {
    const Employee *e1 = (const Employee *)a;
    const Employee *e2 = (const Employee *)b;

    int nameComparisonResult = strcmp(e1->name, e2->name);
    if (nameComparisonResult != 0) {
        return nameComparisonResult;
    }

    return (*(float *)&e1->salary) < (*(float *)&e2->salary) ? -1 : 1;
}

void merge(Employee arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    Employee L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (*(float *)&L[i].salary <= *(float *)&R[j].salary) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Employee arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    Employee employees[n];

    for (int i = 0; i < n; i++) {
        printf("Enter employee %d name: ", i + 1);
        scanf("%s", employees[i].name);
        fflush(stdin);

        printf("Enter employee %d salary: ", i + 1);
        scanf("%f", &employees[i].salary);
    }

    printf("\nUnsorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("Employee %d: %s, Salary: %.2f\n", i + 1, employees[i].name, employees[i].salary);
    }

    mergeSort(employees, 0, n - 1);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("Employee %d: %s, Salary: %.2f\n", i + 1, employees[i].name, employees[i].salary);
    }

    FILE *file;
    file = fopen("sorted_employees.txt", "w");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "Employee %d: %s, Salary: %.2f\n", i + 1, employees[i].name, employees[i].salary);
    }

    fclose(file);
    printf("\nSorted array saved to file.\n");

    return 0;
}