//Falcon-180B DATASET v1.0 Category: File handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REC_SIZE 80

typedef struct {
    char name[MAX_REC_SIZE];
    int age;
    float salary;
} employee;

int compare_age(const void *a, const void *b) {
    const employee *e1 = a;
    const employee *e2 = b;
    return (e1->age - e2->age);
}

int compare_salary(const void *a, const void *b) {
    const employee *e1 = a;
    const employee *e2 = b;
    return (e1->salary - e2->salary);
}

void read_data(employee *emp, FILE *fp) {
    fscanf(fp, "%s %d %f", emp->name, &emp->age, &emp->salary);
}

void write_data(const employee *emp, FILE *fp) {
    fprintf(fp, "%s %d %f\n", emp->name, emp->age, emp->salary);
}

int main() {
    FILE *fp;
    employee emp[100];
    int num_recs, i;
    char filename[MAX_REC_SIZE];

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    num_recs = 0;
    while (fscanf(fp, "%s %d %f", emp[num_recs].name, &emp[num_recs].age, &emp[num_recs].salary)!= EOF) {
        num_recs++;
    }

    for (i = 0; i < num_recs; i++) {
        read_data(&emp[i], fp);
    }

    fclose(fp);

    // Sort by age
    qsort(emp, num_recs, sizeof(employee), compare_age);

    // Sort by salary
    qsort(emp, num_recs, sizeof(employee), compare_salary);

    printf("\nSorted by age:\n");
    for (i = 0; i < num_recs; i++) {
        write_data(&emp[i], stdout);
    }

    printf("\n\nSorted by salary:\n");
    for (i = 0; i < num_recs; i++) {
        write_data(&emp[i], stdout);
    }

    return 0;
}