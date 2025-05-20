//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100000

struct Data {
    int id;
    double value;
};

int main() {
    struct Data data[MAX_SIZE];

    int num_records = 0;
    int num_attributes = 0;

    printf("Enter the number of records: ");
    scanf("%d", &num_records);

    printf("Enter the number of attributes: ");
    scanf("%d", &num_attributes);

    for (int i = 0; i < num_records; i++) {
        int id, value;

        printf("Enter record %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &id);
        printf("Value: ");
        scanf("%lf", &value);

        data[i].id = id;
        data[i].value = value;
    }

    struct Data *min_data = NULL;
    struct Data *max_data = NULL;

    for (int i = 0; i < num_records; i++) {
        if (min_data == NULL || data[i].value < min_data->value) {
            min_data = &data[i];
        }

        if (max_data == NULL || data[i].value > max_data->value) {
            max_data = &data[i];
        }
    }

    printf("Min value: %lf\n", min_data->value);
    printf("Max value: %lf\n", max_data->value);

    for (int i = 0; i < num_records; i++) {
        if (data[i].value < min_data->value) {
            data[i].value = min_data->value;
        }

        if (data[i].value > max_data->value) {
            data[i].value = max_data->value;
        }
    }

    for (int i = 0; i < num_records; i++) {
        printf("Record %d:\n", i + 1);
        printf("ID: %d\n", data[i].id);
        printf("Value: %lf\n", data[i].value);
    }

    return 0;
}