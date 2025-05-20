//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 10
#define MAX_FIELD_LENGTH 100

struct CSVData {
    char fields[MAX_FIELDS][MAX_FIELD_LENGTH];
    int num_fields;
};

struct CSVData parse_csv_line(char* line) {
    struct CSVData data;
    char* field;
    char* rest = line;
    int i = 0;

    while ((field = strtok_r(rest, ",", &rest))) {
        strncpy(data.fields[i], field, MAX_FIELD_LENGTH - 1);
        i++;
    }

    data.num_fields = i;
    return data;
}

int main() {
    char filename[100];
    printf("Enter filename:");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[1000];
    struct CSVData data;

    while (fgets(line, 1000, file)) {
        data = parse_csv_line(line);
        for (int i = 0; i < data.num_fields; i++) {
            printf("%s ", data.fields[i]);
        }
        printf("\n");
    }

    fclose(file);
    return 0;
}