//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Data structures
typedef struct {
    int id;
    char *name;
    double age;
    double income;
} Person;

typedef struct {
    int num_persons;
    Person *persons;
} Dataset;

// Functions
Dataset* load_dataset(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    Dataset *dataset = malloc(sizeof(Dataset));
    if (dataset == NULL) {
        perror("Error allocating memory for dataset");
        fclose(fp);
        return NULL;
    }

    fscanf(fp, "%d", &dataset->num_persons);

    dataset->persons = malloc(sizeof(Person) * dataset->num_persons);
    if (dataset->persons == NULL) {
        perror("Error allocating memory for persons");
        fclose(fp);
        free(dataset);
        return NULL;
    }

    for (int i = 0; i < dataset->num_persons; i++) {
        fscanf(fp, "%d %s %lf %lf", &dataset->persons[i].id, dataset->persons[i].name, &dataset->persons[i].age, &dataset->persons[i].income);
    }

    fclose(fp);

    return dataset;
}

void free_dataset(Dataset *dataset) {
    for (int i = 0; i < dataset->num_persons; i++) {
        free(dataset->persons[i].name);
    }

    free(dataset->persons);
    free(dataset);
}

void print_dataset(Dataset *dataset) {
    for (int i = 0; i < dataset->num_persons; i++) {
        printf("%d %s %.2lf %.2lf\n", dataset->persons[i].id, dataset->persons[i].name, dataset->persons[i].age, dataset->persons[i].income);
    }
}

int main() {
    Dataset *dataset = load_dataset("data.csv");
    if (dataset == NULL) {
        return EXIT_FAILURE;
    }

    print_dataset(dataset);

    free_dataset(dataset);

    return EXIT_SUCCESS;
}