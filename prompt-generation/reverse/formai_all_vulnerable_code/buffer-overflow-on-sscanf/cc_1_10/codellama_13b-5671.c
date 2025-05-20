//Code Llama-13B DATASET v1.0 Category: Data mining ; Style: portable
// C Data Mining Example Program in a Portable Style

#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 1000

typedef struct {
    int id;
    int age;
    char gender;
    float height;
    float weight;
} Person;

void read_data(Person data[], int* num_people) {
    FILE* fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    char line[MAX_ARRAY_SIZE];
    int i = 0;
    while (fgets(line, MAX_ARRAY_SIZE, fp) != NULL && i < MAX_ARRAY_SIZE) {
        sscanf(line, "%d,%c,%f,%f", &data[i].id, &data[i].gender, &data[i].height, &data[i].weight);
        i++;
    }
    *num_people = i;
    fclose(fp);
}

void print_data(Person data[], int num_people) {
    for (int i = 0; i < num_people; i++) {
        printf("Person %d: %d, %c, %f, %f\n", i, data[i].id, data[i].gender, data[i].height, data[i].weight);
    }
}

void min_max(Person data[], int num_people, int* min_index, int* max_index) {
    *min_index = 0;
    *max_index = 0;
    for (int i = 1; i < num_people; i++) {
        if (data[i].height > data[*max_index].height) {
            *max_index = i;
        }
        if (data[i].height < data[*min_index].height) {
            *min_index = i;
        }
    }
}

void main() {
    Person data[MAX_ARRAY_SIZE];
    int num_people;
    read_data(data, &num_people);
    print_data(data, num_people);
    int min_index, max_index;
    min_max(data, num_people, &min_index, &max_index);
    printf("Min: %d\n", min_index);
    printf("Max: %d\n", max_index);
}