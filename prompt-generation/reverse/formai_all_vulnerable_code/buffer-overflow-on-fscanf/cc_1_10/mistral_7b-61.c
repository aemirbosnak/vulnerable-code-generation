//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10
#define RECORD_SIZE 50

typedef struct {
    int id;
    char name[30];
    float value;
    char shape;
} Record;

void shift_records(Record records[], int index);

int main() {
    Record records[MAX_RECORDS];
    int current_index = 0;

    while (current_index < MAX_RECORDS && (fscanf(stdin, "%d%s%f%c", &records[current_index].id, records[current_index].name, &records[current_index].value, &records[current_index].shape) == 4)) {
        current_index++;
    }

    shift_records(records, current_index);

    for (int i = 0; i < current_index; i++) {
        printf("Record %d: ID = %d, Name = %s, Value = %.2f, Shape = %c\n", i+1, records[i].id, records[i].name, records[i].value, records[i].shape);
    }

    return 0;
}

void shift_records(Record records[], int index) {
    if (index < 2) {
        printf("Not enough records to shift.\n");
        return;
    }

    for (int i = 0; i < index/2; i++) {
        Record temp = records[i];
        records[i] = records[index-i-1];
        records[index-i-1] = temp;
    }

    for (int i = 0; i < index; i++) {
        if (records[i].shape != records[i+1].shape) {
            printf("\nShape shift detected!\n");
            char temp_shape = records[i].shape;
            records[i].shape = records[i+1].shape;
            records[i+1].shape = temp_shape;
            shift_records(records, index);
            return;
        }
    }

    printf("No shape shift detected.\n");
}