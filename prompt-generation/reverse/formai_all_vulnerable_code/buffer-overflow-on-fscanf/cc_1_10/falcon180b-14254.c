//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 100

// Define our entry structure
typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Entry;

// Function to initialize the database
void init_database() {
    // Open the database file for writing
    FILE *db_file = fopen("database.txt", "w");
    if (db_file == NULL) {
        printf("Error: Could not open database file.\n");
        exit(1);
    }

    // Write some sample data
    Entry sample_data[] = {
        {"John Doe", "123 Main St"},
        {"Jane Doe", "456 Elm St"},
        {"Bob Smith", "789 Oak St"}
    };

    for (int i = 0; i < sizeof(sample_data) / sizeof(Entry); i++) {
        fprintf(db_file, "%s\t%s\n", sample_data[i].name, sample_data[i].value);
    }

    // Close the database file
    fclose(db_file);
}

int main() {
    // Initialize the database
    init_database();

    // Open the database file for reading
    FILE *db_file = fopen("database.txt", "r");
    if (db_file == NULL) {
        printf("Error: Could not open database file.\n");
        exit(1);
    }

    // Read in the data
    Entry data[MAX_ENTRIES];
    int num_entries = 0;

    while (fscanf(db_file, "%s\t%s", data[num_entries].name, data[num_entries].value)!= EOF) {
        num_entries++;
    }

    // Print out the data
    printf("Database contents:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", data[i].name, data[i].value);
    }

    // Close the database file
    fclose(db_file);

    return 0;
}