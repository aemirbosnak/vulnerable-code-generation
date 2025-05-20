//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ROWS 1000

typedef struct {
    char* name;
    int age;
    float salary;
} Record;

void read_csv(const char* filename, Record* records, int* num_records) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, ",")) {
            char* tokens[3];
            char* token;
            sscanf(line, "%s,%d,%f", tokens[0], &records->age, &records->salary);
            records->name = (char*)malloc(strlen(tokens[0]) + 1);
            strcpy(records->name, tokens[0]);
        } else {
            // Skip empty lines
            continue;
        }

        (*num_records)++;
    }

    fclose(file);
}

int main() {
    Record records[MAX_ROWS];
    int num_records = 0;

    read_csv("data.csv", records, &num_records);

    printf("Number of records: %d\n", num_records);

    for (int i = 0; i < num_records; i++) {
        printf("%s,%d,%.2f\n", records[i].name, records[i].age, records[i].salary);
    }

    return 0;
}