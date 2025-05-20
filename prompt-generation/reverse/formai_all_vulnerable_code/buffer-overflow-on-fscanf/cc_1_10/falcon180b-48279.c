//Falcon-180B DATASET v1.0 Category: File handling ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
} person;

void read_file(person *p, int size, FILE *fp) {
    int i = 0;
    while (fscanf(fp, "%s %d", p[i].name, &p[i].age)!= EOF) {
        i++;
    }
}

void write_file(person *p, int size, FILE *fp) {
    int i = 0;
    while (i < size) {
        fprintf(fp, "%s %d\n", p[i].name, p[i].age);
        i++;
    }
}

void display_data(person *p, int size) {
    int i = 0;
    while (i < size) {
        printf("%s %d\n", p[i].name, p[i].age);
        i++;
    }
}

int main() {
    person data[MAX_SIZE];
    int size = 0;
    FILE *fp;

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    read_file(data, MAX_SIZE, fp);
    fclose(fp);

    size = sizeof(data) / sizeof(data[0]);

    display_data(data, size);

    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    write_file(data, size, fp);
    fclose(fp);

    return 0;
}