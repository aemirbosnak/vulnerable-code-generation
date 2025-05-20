//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_KEY_SIZE 20
#define MAX_VALUE_SIZE 50

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} record_t;

int main() {
    FILE *fp;
    char ch, search_key[MAX_KEY_SIZE] = {0};
    record_t record;

    // Open input file
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    // Read input file and store data in records
    while (fscanf(fp, "%s %s", record.key, record.value)!= EOF) {
        // Process each record and store in a linked list or any other data structure
    }

    // Close input file
    fclose(fp);

    // Open output file
    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    // Search for a specific record based on user input
    printf("Enter the search key: ");
    scanf("%s", search_key);

    // Search for the record in the input file
    rewind(fp);
    while (fscanf(fp, "%s %s", record.key, record.value)!= EOF) {
        if (strcmp(record.key, search_key) == 0) {
            // Record found, write to output file
            fprintf(fp, "%s %s\n", record.key, record.value);
        }
    }

    // Close output file
    fclose(fp);

    return 0;
}