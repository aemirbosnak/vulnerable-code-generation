//FormAI DATASET v1.0 Category: Database Indexing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the database entry
struct database_entry {
    int id;
    char name[50];
    float value;
};

// Define the structure for the index table
struct index_table {
    int id;
    int offset;
};

// Define the function to add an entry to the database
void add_entry(struct database_entry entry, FILE *fp_data, FILE *fp_index) {
    // Append the entry to the end of the data file
    fseek(fp_data, 0, SEEK_END);
    fwrite(&entry, sizeof(struct database_entry), 1, fp_data);

    // Add the entry to the index table
    struct index_table index;
    index.id = entry.id;
    index.offset = ftell(fp_data) - sizeof(struct database_entry);
    fwrite(&index, sizeof(struct index_table), 1, fp_index);
}

// Define the function to search for an entry in the database
void search_entry(int id, FILE *fp_data, FILE *fp_index) {
    // Look up the offset for the given ID in the index table
    struct index_table index;
    fseek(fp_index, 0, SEEK_SET);
    while (fread(&index, sizeof(struct index_table), 1, fp_index)) {
        if (index.id == id) {
            // Read the corresponding entry from the data file
            struct database_entry entry;
            fseek(fp_data, index.offset, SEEK_SET);
            fread(&entry, sizeof(struct database_entry), 1, fp_data);

            // Print the entry details
            printf("Entry found:\n");
            printf("ID: %d\nName: %s\nValue: %.2f\n", entry.id, entry.name, entry.value);
            return;
        }
    }

    // If the ID was not found, print an error message
    printf("Error: Entry with ID %d not found.\n", id);
}

int main() {
    // Open the data and index files
    FILE *fp_data = fopen("data.txt", "ab+");
    FILE *fp_index = fopen("index.txt", "ab+");

    // Display the menu options
    int choice, id;
    struct database_entry entry;
    do {
        printf("\nDatabase Indexing System\n");
        printf("------------------------\n");
        printf("1. Add Entry\n");
        printf("2. Search for Entry\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Get the entry details from the user
                printf("Enter the ID: ");
                scanf("%d", &entry.id);
                printf("Enter the name: ");
                scanf("%s", entry.name);
                printf("Enter the value: ");
                scanf("%f", &entry.value);

                // Add the entry to the database
                add_entry(entry, fp_data, fp_index);
                printf("Entry added successfully.\n");
                break;

            case 2:
                // Get the ID to search from the user
                printf("Enter the ID to search: ");
                scanf("%d", &id);

                // Search for the entry in the database
                search_entry(id, fp_data, fp_index);
                break;

            case 3:
                // Exit the program
                break;

            default:
                // Invalid choice entered
                printf("Error: Invalid choice.\n");
                break;
        }
    } while (choice != 3);

    // Close the data and index files
    fclose(fp_data);
    fclose(fp_index);
    
    return 0;
}