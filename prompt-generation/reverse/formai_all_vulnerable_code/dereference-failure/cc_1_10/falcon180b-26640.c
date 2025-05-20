//Falcon-180B DATASET v1.0 Category: Error handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    int id;
    char name[MAX_LINE_LENGTH];
} employee;

void read_employees(employee *emp, int num_employees) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int i = 0;

    fp = fopen("employees.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (i >= num_employees) {
            fprintf(stderr, "Error: Too many employees in file.\n");
            exit(1);
        }

        sscanf(line, "%d %s", &emp[i].id, emp[i].name);
        i++;
    }

    fclose(fp);
}

void print_employees(employee *emp, int num_employees) {
    int i;

    for (i = 0; i < num_employees; i++) {
        printf("%d: %s\n", emp[i].id, emp[i].name);
    }
}

int main(int argc, char *argv[]) {
    employee emp[100];
    int num_employees;

    if (argc!= 3) {
        fprintf(stderr, "Error: Usage: %s <number of employees> <employees.txt>\n", argv[0]);
        exit(1);
    }

    num_employees = atoi(argv[1]);

    if (num_employees <= 0) {
        fprintf(stderr, "Error: Invalid number of employees.\n");
        exit(1);
    }

    read_employees(emp, num_employees);
    print_employees(emp, num_employees);

    return 0;
}