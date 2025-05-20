//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DATA_SETS 5
#define MAX_DATA_SET_SIZE 1000
#define MAX_NUM_DATA_SETS 100

typedef struct {
    int num_data_sets;
    int data_set_size[MAX_DATA_SET_SIZE];
} DataSet;

void generate_data_set(DataSet* data_set, int num_data_sets, int max_data_set_size) {
    int i;
    for (i = 0; i < num_data_sets; i++) {
        int data_set_size = rand() % max_data_set_size + 1;
        int j;
        for (j = 0; j < data_set_size; j++) {
            data_set->data_set_size[i] = rand() % max_data_set_size + 1;
        }
    }
}

int main() {
    int num_data_sets;
    int max_data_set_size;
    int i;

    printf("Enter the number of data sets: ");
    scanf("%d", &num_data_sets);

    printf("Enter the maximum size of each data set: ");
    scanf("%d", &max_data_set_size);

    if (num_data_sets > MAX_NUM_DATA_SETS || max_data_set_size > MAX_DATA_SET_SIZE) {
        printf("Invalid input. Please try again.\n");
        return 1;
    }

    DataSet data_set;
    generate_data_set(&data_set, num_data_sets, max_data_set_size);

    printf("Data sets generated:\n");
    for (i = 0; i < num_data_sets; i++) {
        printf("Data set %d: ", i + 1);
        int j;
        for (j = 0; j < data_set.data_set_size[i]; j++) {
            printf("%d ", data_set.data_set_size[i]);
        }
        printf("\n");
    }

    return 0;
}