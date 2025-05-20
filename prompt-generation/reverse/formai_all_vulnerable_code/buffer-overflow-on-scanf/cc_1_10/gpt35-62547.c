//FormAI DATASET v1.0 Category: Database Indexing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the indexed data
typedef struct {
    int id;
    char name[50];
    float weight;
} Data;

// Define the structure for the index table
typedef struct {
    int id;
    long offset;
} Index;

// Function prototypes
void addData(FILE *file, Data *data, Index *index, int *numIndex);
void displayData(FILE *file);
void searchById(FILE *file, Index *index, int numIndex);
void searchByName(FILE *file, Index *index, int numIndex);

int main() {
    FILE *file;
    Data data;
    Index index[50];
    int numIndex = 0, choice;

    // Open file for reading and writing
    file = fopen("data.dat", "r+");

    // Check if file exists
    if (file == NULL) {
        printf("File does not exist!\n");
        return 0;
    }

    // Menu loop
    do {
        printf("\nMenu\n");
        printf("1. Add Data\n");
        printf("2. Display Data\n");
        printf("3. Search by ID\n");
        printf("4. Search by Name\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addData(file, &data, index, &numIndex);
                break;
            case 2:
                displayData(file);
                break;
            case 3:
                searchById(file, index, numIndex);
                break;
            case 4:
                searchByName(file, index, numIndex);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    // Close file
    fclose(file);

    return 0;
}

void addData(FILE *file, Data *data, Index *index, int *numIndex) {
    // Move file pointer to end of file
    fseek(file, 0, SEEK_END);

    // Get data from user
    printf("Enter ID: ");
    scanf("%d", &data->id);
    printf("Enter Name: ");
    scanf("%s", data->name);
    printf("Enter Weight: ");
    scanf("%f", &data->weight);

    // Write data to file
    fwrite(data, sizeof(Data), 1, file);

    // Write index to index table
    index[*numIndex].id = data->id;
    index[*numIndex].offset = ftell(file) - sizeof(Data);

    // Increment number of indices
    (*numIndex)++;

    printf("Data added successfully!\n");
}

void displayData(FILE *file) {
    Data data;

    // Move file pointer to beginning of file
    fseek(file, 0, SEEK_SET);

    printf("\nID    Name              Weight\n");
    printf("--------------------------------\n");

    // Read data from file and display
    while (fread(&data, sizeof(Data), 1, file)) {
        printf("%-5d %-17s %-3.2f\n", data.id, data.name, data.weight);
    }
}

void searchById(FILE *file, Index *index, int numIndex) {
    int id, i;
    Data data;

    printf("Enter ID to search: ");
    scanf("%d", &id);

    // Find index corresponding to ID
    for (i = 0; i < numIndex; i++) {
        if (index[i].id == id) {
            // Find data at corresponding offset
            fseek(file, index[i].offset, SEEK_SET);
            fread(&data, sizeof(Data), 1, file);
            printf("\nID    Name              Weight\n");
            printf("--------------------------------\n");
            printf("%-5d %-17s %-3.2f\n", data.id, data.name, data.weight);
            return;
        }
    }

    printf("ID not found!\n");
}

void searchByName(FILE *file, Index *index, int numIndex) {
    char name[50];
    int i, found = 0;
    Data data;

    printf("Enter Name to search: ");
    scanf("%s", name);

    // Search through all data for matching name
    fseek(file, 0, SEEK_SET);

    printf("\nID    Name              Weight\n");
    printf("--------------------------------\n");

    while (fread(&data, sizeof(Data), 1, file)) {
        if (strcmp(name, data.name) == 0) {
            printf("%-5d %-17s %-3.2f\n", data.id, data.name, data.weight);
            found = 1;
        }
    }

    // Check if any data was found
    if (found == 0) {
        printf("No data found with name %s!\n", name);
    }
}