//Falcon-180B DATASET v1.0 Category: Data mining ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 1000
#define MAX_COLUMNS 10
#define MAX_ROWS 1000

typedef struct {
    char name[50];
    int age;
    float salary;
} Data;

void readData(Data data[], int rows) {
    FILE *fp = fopen("data.txt", "r");
    int i = 0;
    while (fscanf(fp, "%s %d %f\n", data[i].name, &data[i].age, &data[i].salary)!= EOF) {
        i++;
    }
    fclose(fp);
}

void printData(Data data[], int rows) {
    for (int i = 0; i < rows; i++) {
        printf("Name: %s\nAge: %d\nSalary: %.2f\n", data[i].name, data[i].age, data[i].salary);
    }
}

void sortData(Data data[], int rows, int column) {
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < rows - i - 1; j++) {
            if (data[j].age > data[j + 1].age) {
                Data temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int main() {
    Data data[MAX_ROWS];
    int rows = 0;
    readData(data, rows);
    printf("Unsorted Data:\n");
    printData(data, rows);
    printf("\n");
    int choice;
    do {
        printf("Enter column to sort by (0-2): ");
        scanf("%d", &choice);
        sortData(data, rows, choice);
        printf("Sorted Data:\n");
        printData(data, rows);
        printf("\n");
    } while (choice!= 0 && choice!= 1 && choice!= 2);
    return 0;
}