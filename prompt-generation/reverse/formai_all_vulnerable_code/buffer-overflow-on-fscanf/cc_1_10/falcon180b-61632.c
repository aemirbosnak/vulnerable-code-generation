//Falcon-180B DATASET v1.0 Category: File handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[MAX];
    int age;
    char gender;
} Person;

void read_file(FILE *fp, Person arr[]) {
    int i = 0;
    while (fscanf(fp, "%s %d %c", arr[i].name, &arr[i].age, &arr[i].gender)!= EOF) {
        i++;
    }
}

void write_file(FILE *fp, Person arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        fprintf(fp, "%s %d %c\n", arr[i].name, arr[i].age, arr[i].gender);
    }
}

void sort_by_age(Person arr[], int n) {
    int i, j;
    Person temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i].age > arr[j].age) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    FILE *fp;
    Person arr[MAX];
    int n, i;

    fp = fopen("data.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(0);
    }

    n = 0;
    while (fscanf(fp, "%s %d %c", arr[n].name, &arr[n].age, &arr[n].gender)!= EOF) {
        n++;
    }

    fclose(fp);

    sort_by_age(arr, n);

    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(0);
    }

    write_file(fp, arr, n);
    fclose(fp);

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(0);
    }

    read_file(fp, arr);

    for (i = 0; i < n; i++) {
        printf("%s %d %c\n", arr[i].name, arr[i].age, arr[i].gender);
    }

    fclose(fp);

    return 0;
}