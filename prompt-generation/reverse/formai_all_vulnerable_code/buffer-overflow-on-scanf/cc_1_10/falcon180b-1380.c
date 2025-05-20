//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Record;

int main() {
    FILE *fp;
    Record records[MAX_RECORDS];
    int num_records = 0;
    char filename[MAX_NAME_LEN];

    // Prompt the user for the filename
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read the records from the file
    while (fscanf(fp, "%s %s\n", records[num_records].name, records[num_records].value)!= EOF) {
        num_records++;
    }

    // Close the file
    fclose(fp);

    // Sort the records alphabetically by name
    for (int i = 0; i < num_records - 1; i++) {
        for (int j = i + 1; j < num_records; j++) {
            if (strcmp(records[i].name, records[j].name) > 0) {
                Record temp = records[i];
                records[i] = records[j];
                records[j] = temp;
            }
        }
    }

    // Print the sorted records
    printf("Sorted records:\n");
    for (int i = 0; i < num_records; i++) {
        printf("%s: %s\n", records[i].name, records[i].value);
    }

    // Prompt the user for a search query
    char query[MAX_NAME_LEN];
    printf("Enter a search query: ");
    scanf("%s", query);

    // Search for the query in the records
    Record *result = NULL;
    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].name, query) == 0) {
            result = &records[i];
            break;
        }
    }

    // Print the search result
    if (result!= NULL) {
        printf("Search result:\n");
        printf("%s: %s\n", result->name, result->value);
    } else {
        printf("No match found.\n");
    }

    return 0;
}