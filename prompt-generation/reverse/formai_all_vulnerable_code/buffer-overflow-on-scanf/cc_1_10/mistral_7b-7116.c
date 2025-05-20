//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float weight;
} Record;

int main() {
    int num_records;
    Record *records;
    Record max_weight_record;
    float sum_age = 0.0, sum_weight = 0.0, avg_age, avg_weight;
    int i;

    printf("Enter number of records: ");
    scanf("%d", &num_records);

    records = (Record *)malloc(num_records * sizeof(Record));

    if (records == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < num_records; i++) {
        printf("\nEnter record %d details:\n", i + 1);
        printf("Name: ");
        scanf("%s", records[i].name);
        printf("Age: ");
        scanf("%d", &records[i].age);
        printf("Weight: ");
        scanf("%f", &records[i].weight);

        sum_age += records[i].age;
        sum_weight += records[i].weight;

        if (i == 0 || records[i].weight > max_weight_record.weight) {
            max_weight_record = records[i];
        }
    }

    avg_age = sum_age / num_records;
    avg_weight = sum_weight / num_records;

    printf("\nAverage age: %.2f", avg_age);
    printf("\nAverage weight: %.2f", avg_weight);
    printf("\nRecord with maximum weight:\nName: %s\nAge: %d\nWeight: %.2f", max_weight_record.name, max_weight_record.age, max_weight_record.weight);

    free(records);

    return 0;
}