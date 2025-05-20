//Falcon-180B DATASET v1.0 Category: Data mining ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct {
    int id;
    char name[50];
    float salary;
} employee;

void read_data(employee *arr, int n) {
    FILE *fp;
    fp = fopen("data.txt", "r");
    if(fp == NULL) {
        printf("Error opening file");
        exit(0);
    }
    for(int i=0; i<n; i++) {
        fscanf(fp, "%d %s %f", &arr[i].id, arr[i].name, &arr[i].salary);
    }
    fclose(fp);
}

void swap(employee *a, employee *b) {
    employee temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(employee *arr, int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j].salary < arr[j+1].salary) {
                swap(arr+j, arr+j+1);
            }
        }
    }
}

void write_data(employee *arr, int n) {
    FILE *fp;
    fp = fopen("sorted_data.txt", "w");
    for(int i=0; i<n; i++) {
        fprintf(fp, "%d %s %f\n", arr[i].id, arr[i].name, arr[i].salary);
    }
    fclose(fp);
}

int main() {
    employee arr[100];
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    read_data(arr, n);
    bubble_sort(arr, n);
    printf("Sorted data:\n");
    for(int i=0; i<n; i++) {
        printf("%d %s %f\n", arr[i].id, arr[i].name, arr[i].salary);
    }
    write_data(arr, n);
    return 0;
}