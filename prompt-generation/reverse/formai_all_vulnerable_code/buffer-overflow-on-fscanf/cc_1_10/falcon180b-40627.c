//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Record;

int main() {
    FILE *fp;
    char filename[MAX_NAME_LENGTH];
    Record database[MAX_RECORDS];
    int num_records = 0;

    printf("Enter database filename: ");
    fgets(filename, MAX_NAME_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    while (fscanf(fp, "%s %s", database[num_records].name, database[num_records].value) == 2 && num_records < MAX_RECORDS) {
        num_records++;
    }

    fclose(fp);

    printf("Number of records in database: %d\n", num_records);

    while (1) {
        printf("\nEnter query (type 'exit' to quit): ");
        fgets(filename, MAX_NAME_LENGTH, stdin);
        filename[strcspn(filename, "\n")] = '\0';

        if (strcmp(filename, "exit") == 0) {
            break;
        }

        int found = 0;
        for (int i = 0; i < num_records; i++) {
            if (strcmp(database[i].name, filename) == 0) {
                printf("Record found:\nName: %s\nValue: %s\n", database[i].name, database[i].value);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Record not found.\n");
        }
    }

    return 0;
}