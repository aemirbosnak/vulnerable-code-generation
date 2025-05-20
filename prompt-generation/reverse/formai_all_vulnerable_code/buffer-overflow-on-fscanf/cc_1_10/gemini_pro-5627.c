//GEMINI-pro DATASET v1.0 Category: File handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    char dob[11];
} Person;

void mergeSort(Person *arr, int l, int r);
void merge(Person *arr, int l, int m, int r);

int main() {
    FILE *fp;
    Person arr[100];
    int n, i;
    char filename[20];

    // Get the file name from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the number of persons from the file
    fscanf(fp, "%d", &n);

    // Read the details of each person from the file
    for (i = 0; i < n; i++) {
        fscanf(fp, "%s %d %s", arr[i].name, &arr[i].age, arr[i].dob);
    }

    // Close the file
    fclose(fp);

    // Sort the array of persons using merge sort
    mergeSort(arr, 0, n - 1);

    // Print the details of each person in the sorted order
    for (i = 0; i < n; i++) {
        printf("%s %d %s\n", arr[i].name, arr[i].age, arr[i].dob);
    }

    return 0;
}

void mergeSort(Person *arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void merge(Person *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    Person L[n1], R[n2];

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
        if (strcmp(L[i].name, R[j].name) < 0) {
            arr[k] = L[i];
            i++;
        }
        else {
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