//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_RECORDS 100
#define FILE_NAME "futuristic_records.dat"

typedef struct {
    char name[50];
    int age;
    char cybernetics[100];
    time_t created_at;
} Record;

void initialize_file() {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        perror("Failed to create file");
        exit(EXIT_FAILURE);
    }
    fclose(file);
}

void add_record() {
    Record record;
    printf("Enter Name: ");
    fgets(record.name, 50, stdin);
    record.name[strcspn(record.name, "\n")] = 0; // Remove newline

    printf("Enter Age: ");
    scanf("%d", &record.age);
    getchar(); // Consume the newline after age input

    printf("Enter Cybernetics (e.g., Neural Interface, Cybernetic Arm): ");
    fgets(record.cybernetics, 100, stdin);
    record.cybernetics[strcspn(record.cybernetics, "\n")] = 0; // Remove newline

    record.created_at = time(NULL);

    FILE *file = fopen(FILE_NAME, "ab");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    fwrite(&record, sizeof(Record), 1, file);
    fclose(file);
    printf("Record added successfully!\n");
}

void display_records() {
    Record record;
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    printf("\n--- Futuristic Records ---\n");
    while (fread(&record, sizeof(Record), 1, file)) {
        printf("Name: %s\n", record.name);
        printf("Age: %d\n", record.age);
        printf("Cybernetics: %s\n", record.cybernetics);
        printf("Created At: %s", ctime(&record.created_at));
        printf("-------------------------\n");
    }

    fclose(file);
}

void delete_record() {
    char name[50];
    printf("Enter the name of the record to delete: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    Record record, tempRecords[MAX_RECORDS];
    int found = 0, count = 0;

    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    while (fread(&record, sizeof(Record), 1, file)) {
        if (strcmp(record.name, name) == 0) {
            found = 1;
            printf("Deleting Record: %s\n", record.name);
        } else {
            tempRecords[count++] = record;
        }
    }
    
    fclose(file);

    if (!found) {
        printf("No record found with the name: %s\n", name);
        return;
    }

    file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    fwrite(tempRecords, sizeof(Record), count, file);
    fclose(file);
    printf("Record deleted successfully!\n");
}

void futuristic_menu() {
    while (1) {
        printf("\n--- Futuristic Record System ---\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Delete Record\n");
        printf("4. Exit\n");
        printf("Choose an option: ");

        int choice;
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                display_records();
                break;
            case 3:
                delete_record();
                break;
            case 4:
                printf("Exiting the system. Farewell, cyber traveler!\n");
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    initialize_file();
    futuristic_menu();
    return 0;
}