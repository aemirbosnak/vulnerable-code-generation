//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 10000
#define MAX_ATTRIBUTES 5

// Structure to represent a record
typedef struct {
    int age;
    char gender[5];
    double income;
    char education[10];
} record_t;

// Function to read records from a file
record_t *read_records(const char *file_name) {
    record_t *records = calloc(MAX_RECORDS, sizeof(record_t));
    int i = 0;
    FILE *file = fopen(file_name, "r");
    char line[100];
    while (fgets(line, 100, file)) {
        sscanf(line, "%d %5s %lf %10s", &records[i].age, records[i].gender, &records[i].income, records[i].education);
        i++;
    }
    fclose(file);
    return records;
}

// Function to mine data
void mine_data(record_t *records, int num_records) {
    int i, j, k;
    for (i = 0; i < num_records; i++) {
        for (j = i + 1; j < num_records; j++) {
            if (strcmp(records[i].gender, records[j].gender) == 0) {
                // Same gender, find the similarity
                double similarity = 0;
                for (k = 0; k < 3; k++) {
                    if (records[i].education[k] == records[j].education[k]) {
                        similarity++;
                    }
                }
                if (similarity > 2) {
                    // Similar records found!
                    printf("Records %d and %j are similar because of their education\n", i, j);
                }
            }
        }
    }
}

int main() {
    record_t *records = read_records("records.txt");
    int num_records = sizeof(records) / sizeof(record_t);
    mine_data(records, num_records);
    free(records);
    return 0;
}