//Falcon-180B DATASET v1.0 Category: Data mining ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA 1000
#define MAX_ATTRIBUTES 10

typedef struct {
    char *name;
    int value;
} attribute;

typedef struct {
    attribute *attributes;
    int num_attributes;
    int num_data;
    int **data;
} dataset;

dataset *create_dataset(int num_attributes) {
    dataset *d = (dataset *) malloc(sizeof(dataset));
    d->attributes = (attribute *) malloc(num_attributes * sizeof(attribute));
    d->num_attributes = num_attributes;
    d->num_data = 0;
    d->data = (int **) malloc(num_attributes * sizeof(int *));
    for (int i = 0; i < num_attributes; i++) {
        d->data[i] = (int *) malloc(MAX_DATA * sizeof(int));
    }
    return d;
}

void destroy_dataset(dataset *d) {
    for (int i = 0; i < d->num_attributes; i++) {
        free(d->data[i]);
    }
    free(d->data);
    for (int i = 0; i < d->num_attributes; i++) {
        free(d->attributes[i].name);
    }
    free(d->attributes);
    free(d);
}

void add_data(dataset *d, int *data) {
    for (int i = 0; i < d->num_attributes; i++) {
        d->data[i][d->num_data] = data[i];
    }
    d->num_data++;
}

void print_dataset(dataset *d) {
    for (int i = 0; i < d->num_attributes; i++) {
        printf("%s: ", d->attributes[i].name);
        for (int j = 0; j < d->num_data; j++) {
            printf("%d ", d->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    dataset *d = create_dataset(3);
    d->attributes[0].name = "age";
    d->attributes[1].name = "gender";
    d->attributes[2].name = "income";
    int data1[] = {25, 0, 50000};
    int data2[] = {30, 1, 75000};
    int data3[] = {20, 0, 40000};
    add_data(d, data1);
    add_data(d, data2);
    add_data(d, data3);
    print_dataset(d);
    destroy_dataset(d);
    return 0;
}