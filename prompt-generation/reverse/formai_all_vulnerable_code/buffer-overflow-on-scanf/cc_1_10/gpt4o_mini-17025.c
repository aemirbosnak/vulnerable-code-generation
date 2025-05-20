//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define AGE_LENGTH 3
#define ERROR_MSG "An error has occurred! Please check the input."

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
} Record;

Record database[MAX_RECORDS];
int record_count = 0;

void add_record();
void view_records();
void search_record();
void delete_record();
void paranoid_mode();
void clear_input_buffer();

int main() {
    int choice;

    while(1) {
        printf("\n=== Paranoid Database Simulation ===\n");
        printf("1. Add Record\n");
        printf("2. View Records\n");
        printf("3. Search Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if(scanf("%d", &choice) != 1) {
            clear_input_buffer();
            printf(ERROR_MSG "\n");
            continue;
        }

        switch(choice) {
            case 1:
                add_record();
                break;
            case 2:
                view_records();
                break;
            case 3:
                search_record();
                break;
            case 4:
                delete_record();
                break;
            case 5:
                printf("Exiting... Are you sure? (Y/N): ");
                if(getchar() == 'Y') {
                    exit(0);
                } else {
                    printf("Operation cancelled.\n");
                }
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}

void add_record() {
    if(record_count >= MAX_RECORDS) {
        printf("Database is full! Cannot add more records.\n");
        return;
    }

    Record r;
    printf("Enter ID: ");
    if(scanf("%d", &r.id) != 1) {
        clear_input_buffer();
        printf(ERROR_MSG "\n");
        return;
    }
    printf("Enter Name: ");
    clear_input_buffer(); // Clear buffer before taking string input
    fgets(r.name, NAME_LENGTH, stdin);
    r.name[strcspn(r.name, "\n")] = 0; // Remove newline
    printf("Enter Age: ");
    if(scanf("%d", &r.age) != 1 || r.age < 0 || r.age > 150) {
        clear_input_buffer();
        printf(ERROR_MSG "\n");
        return;
    }

    database[record_count++] = r;
    printf("Record added successfully!\n");
}

void view_records() {
    printf("\n=== Current Records ===\n");
    for(int i = 0; i < record_count; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", database[i].id, database[i].name, database[i].age);
    }
}

void search_record() {
    int id;
    printf("Enter ID to search: ");
    if(scanf("%d", &id) != 1) {
        clear_input_buffer();
        printf(ERROR_MSG "\n");
        return;
    }
    
    for(int i = 0; i < record_count; i++) {
        if(database[i].id == id) {
            printf("Found Record - ID: %d, Name: %s, Age: %d\n", database[i].id, database[i].name, database[i].age);
            return;
        }
    }
    printf("Record with ID %d not found!\n", id);
}

void delete_record() {
    int id;
    printf("Enter ID to delete: ");
    if(scanf("%d", &id) != 1) {
        clear_input_buffer();
        printf(ERROR_MSG "\n");
        return;
    }

    int found = 0;
    for(int i = 0; i < record_count; i++) {
        if(database[i].id == id) {
            found = 1;
            // Shift records left to overwrite the deleted record
            for(int j = i; j < record_count - 1; j++) {
                database[j] = database[j + 1];
            }
            record_count--;
            printf("Record with ID %d deleted successfully!\n", id);
            break;
        }
    }
    if(!found) {
        printf("Record with ID %d not found! Nothing was deleted.\n", id);
    }
}

void clear_input_buffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF); // Clear stdin buffer
}