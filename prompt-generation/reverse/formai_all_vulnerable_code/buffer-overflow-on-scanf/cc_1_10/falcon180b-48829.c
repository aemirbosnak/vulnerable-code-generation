//Falcon-180B DATASET v1.0 Category: Data mining ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 1000

typedef struct data {
    int id;
    char category[50];
    double value;
} Data;

int main() {
    int num_data;
    Data data_set[MAX_DATA_SIZE];
    char input_buffer[100];

    printf("Enter the number of data points: ");
    scanf("%d", &num_data);

    printf("Enter the data points:\n");
    for (int i = 0; i < num_data; i++) {
        printf("Data point %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &data_set[i].id);
        printf("Category: ");
        scanf("%s", data_set[i].category);
        printf("Value: ");
        scanf("%lf", &data_set[i].value);
    }

    printf("Enter the category to search for: ");
    scanf("%s", input_buffer);

    int category_index = -1;
    for (int i = 0; i < num_data; i++) {
        if (strcmp(data_set[i].category, input_buffer) == 0) {
            category_index = i;
            break;
        }
    }

    if (category_index == -1) {
        printf("Category not found.\n");
    } else {
        printf("Category '%s' found in data point %d:\n", input_buffer, category_index+1);
        printf("ID: %d\n", data_set[category_index].id);
        printf("Value: %lf\n", data_set[category_index].value);
    }

    return 0;
}