//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define FILENAME "data.txt"

typedef struct {
    char name[50];
    int age;
    float weight;
} Person;

void readData(FILE *fp, Person *persons, int *count) {
    char line[MAX_SIZE];
    int index = 0;
    while (fgets(line, MAX_SIZE, fp) != NULL) {
        sscanf(line, "%[^,],%d,%f", persons[index].name, &persons[index].age, &persons[index].weight);
        index++;
        *count = index;
    }
}

void writeData(FILE *fp, Person persons[], int count) {
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s,%d,%.2f\n", persons[i].name, persons[i].age, persons[i].weight);
    }
}

int main() {
    FILE *fp;
    Person persons[MAX_SIZE];
    int count = 0;

    fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("Unable to open file %s\n", FILENAME);
        exit(1);
    }

    readData(fp, persons, &count);

    printf("--- DATA FROM FILE ---\n");
    for (int i = 0; i < count; i++) {
        printf("%s, %d, %.2f\n", persons[i].name, persons[i].age, persons[i].weight);
    }

    fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        printf("Unable to open file %s for writing.\n", FILENAME);
        exit(1);
    }

    persons[0].age = 25;
    strcpy(persons[0].name, "John Doe");
    persons[0].weight = 80.5;

    writeData(fp, persons, count + 1);

    fclose(fp);

    return 0;
}