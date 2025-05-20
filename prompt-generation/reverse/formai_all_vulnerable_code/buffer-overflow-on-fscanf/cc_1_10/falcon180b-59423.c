//Falcon-180B DATASET v1.0 Category: File handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

typedef struct {
    char name[30];
    int age;
    char address[50];
} person;

void read_data(FILE *fp, person *p) {
    fscanf(fp, "%s %d %s", p->name, &p->age, p->address);
}

void write_data(FILE *fp, person p) {
    fprintf(fp, "%s %d %s\n", p.name, p.age, p.address);
}

void sort_data(person *data, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(data[i].name, data[j].name) > 0) {
                person temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

int main() {
    FILE *fp;
    person data[SIZE];
    int n = 0;

    fp = fopen("data.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fscanf(fp, "%s %d %s", data[n].name, &data[n].age, data[n].address)!= EOF) {
        n++;
    }

    fclose(fp);

    sort_data(data, n);

    fp = fopen("data.txt", "w");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        write_data(fp, data[i]);
    }

    fclose(fp);

    return 0;
}