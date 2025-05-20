//FormAI DATASET v1.0 Category: Database simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent a database record
typedef struct {
    int id;
    char name[20];
    int age;
} Record;

// Function to print a record
void print_record(Record r) {
    printf("ID: %d\nName: %s\nAge: %d\n", r.id, r.name, r.age);
}

int main() {
    int choice;
    int num_records = 0;
    Record* records = NULL;

    printf("Welcome to the Retro Database Simulator!\n");

    while(1) {
        printf("\n1. Add record\n2. Delete record\n3. View all records\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Add record
                num_records++;
                records = realloc(records, num_records * sizeof(Record));
                printf("Enter ID, Name, and Age separated by spaces: ");
                scanf("%d %s %d", &records[num_records-1].id, records[num_records-1].name, &records[num_records-1].age);
                printf("Record added!\n");
                break;
            case 2: // Delete record
                if(num_records == 0) {
                    printf("There are no records to delete!\n");
                }
                else {
                    int id_to_delete;
                    printf("Enter the ID of the record to delete: ");
                    scanf("%d", &id_to_delete);
                    int index_to_delete = -1;
                    for(int i = 0; i < num_records; i++) {
                        if(records[i].id == id_to_delete) {
                            index_to_delete = i;
                            break;
                        }
                    }
                    if(index_to_delete == -1) {
                        printf("Record with ID %d not found!\n", id_to_delete);
                    }
                    else {
                        printf("Record deleted:\n");
                        print_record(records[index_to_delete]);
                        for(int i = index_to_delete; i < num_records-1; i++) {
                            records[i] = records[i+1];
                        }
                        num_records--;
                        records = realloc(records, num_records * sizeof(Record));
                    }
                }
                break;
            case 3: // View all records
                if(num_records == 0) {
                    printf("There are no records to view!\n");
                }
                else {
                    for(int i = 0; i < num_records; i++) {
                        printf("\nRecord %d:\n", i+1);
                        print_record(records[i]);
                    }
                }
                break;
            case 4: // Exit
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}