//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_STR_LEN 50

typedef struct {
    int id;
    char name[MAX_STR_LEN];
    float value;
} Record;

void print_record(Record *r) {
    printf("ID: %d, Name: %s, Value: %.2f\n", r->id, r->name, r->value);
}

void load_data(const char *filename, Record records[], int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%d %s %f", &records[*count].id, records[*count].name, &records[*count].value) != EOF) {
        (*count)++;
    }

    fclose(file);
}

void find_max_value(Record records[], int count) {
    float max_value = records[0].value;
    char max_name[MAX_STR_LEN];
    strcpy(max_name, records[0].name);

    for (int i = 1; i < count; i++) {
        if (records[i].value > max_value) {
            max_value = records[i].value;
            strcpy(max_name, records[i].name);
        }
    }

    printf("Record with max value: %s with value %.2f\n", max_name, max_value);
}

void sort_records(Record records[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (records[j].value > records[j + 1].value) {
                Record temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }
}

void display_records(Record records[], int count) {
    printf("\nSorted Records:\n");
    for (int i = 0; i < count; i++) {
        print_record(&records[i]);
    }
}

void save_to_file(const char *filename, Record records[], int count) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Could not open file for writing");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %.2f\n", records[i].id, records[i].name, records[i].value);
    }

    fclose(file);
}

int main() {
    Record records[MAX_RECORDS];
    int count = 0;

    const char *input_file = "data.txt";
    const char *output_file = "sorted_data.txt";

    load_data(input_file, records, &count);
    find_max_value(records, count);
    sort_records(records, count);
    display_records(records, count);
    save_to_file(output_file, records, count);

    return 0;
}