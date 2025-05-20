//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for storing record
typedef struct Record {
    int id;
    char name[50];
} Record;

// Define a node for the linked list to create an index
typedef struct Node {
    int id;
    struct Node* next;
} Node;

// Function to create a new record
Record create_record(int id, const char* name) {
    Record r;
    r.id = id;
    strncpy(r.name, name, sizeof(r.name) - 1);
    r.name[sizeof(r.name) - 1] = '\0'; // Ensure null termination
    return r;
}

// Function to add a node to the index
Node* add_index(Node* head, int id) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->id = id;
    new_node->next = head;
    return new_node;
}

// Function to cleanup index
void free_index(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to display records
void display_records(Record* records, int count) {
    printf("Displaying records:\n");
    printf("%-5s %-30s\n", "ID", "Name");
    printf("-------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-30s\n", records[i].id, records[i].name);
    }
}

// Function to search a record by ID in the index
Record* search_record(Record* records, int count, Node* index, int id) {
    Node* current = index;
    while (current != NULL) {
        if (current->id == id) {
            return &records[id];
        }
        current = current->next;
    }
    return NULL; // Not found
}

// Function to save records to a file
void save_records_to_file(Record* records, int count) {
    FILE* file = fopen("records.dat", "wb");
    if (file) {
        fwrite(records, sizeof(Record), count, file);
        fclose(file);
        printf("Records saved to 'records.dat'\n");
    } else {
        fprintf(stderr, "Could not open file for writing\n");
    }
}

// Function to load records from a file
int load_records_from_file(Record** records_ptr) {
    FILE* file = fopen("records.dat", "rb");
    if (!file) {
        fprintf(stderr, "Could not open file for reading\n");
        return 0;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    
    int count = size / sizeof(Record);
    *records_ptr = (Record*)malloc(size);
    fread(*records_ptr, sizeof(Record), count, file);
    fclose(file);
    
    return count;
}

int main() {
    Record* records = NULL;
    Node* index = NULL;
    int count = 0;

    // Load existing records
    count = load_records_from_file(&records);
    for (int i = 0; i < count; i++) {
        index = add_index(index, records[i].id);
    }

    // Interactive section to create new records
    int choice;
    do {
        printf("\n1. Add Record\n2. Search Record\n3. Display All\n4. Save and Exit\nChoose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int id;
            char name[50];
            printf("Enter ID: ");
            scanf("%d", &id);
            printf("Enter Name: ");
            scanf("%s", name);
            records = (Record*)realloc(records, (count + 1) * sizeof(Record));
            records[count] = create_record(id, name);
            index = add_index(index, id);
            count++;
            printf("Record added!\n");
        } else if (choice == 2) {
            int search_id;
            printf("Enter ID to search: ");
            scanf("%d", &search_id);
            Record* found_record = search_record(records, count, index, search_id);
            if (found_record) {
                printf("Found Record: ID: %d, Name: %s\n", found_record->id, found_record->name);
            } else {
                printf("Record not found!\n");
            }
        } else if (choice == 3) {
            display_records(records, count);
        } else if (choice == 4) {
            save_records_to_file(records, count);
            printf("Exiting. Goodbye!\n");
        } else {
            printf("Invalid option, please try again.\n");
        }
    } while (choice != 4);

    // Clean up
    free(records);
    free_index(index);
    return 0;
}