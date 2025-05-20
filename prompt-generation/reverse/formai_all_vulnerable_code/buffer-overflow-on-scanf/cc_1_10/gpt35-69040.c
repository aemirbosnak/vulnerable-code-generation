//FormAI DATASET v1.0 Category: Database simulation ; Style: content
#include <stdio.h>
#include <stdlib.h>

typedef struct Record {
    int id;
    char name[20];
    int age;
    char gender[10];
} Record;

void menu() {
    printf("\nWelcome to our database simulation program!\n");
    printf("1. Add a record\n");
    printf("2. Search for a record\n");
    printf("3. Delete a record\n");
    printf("4. Print all records\n");
    printf("5. Exit\n");
}

void addRecord(FILE *fp) {
    Record record;
    printf("\nEnter an ID for the record: ");
    scanf("%d", &record.id);
    printf("Enter a name for the record: ");
    scanf("%s", record.name);
    printf("Enter an age for the record: ");
    scanf("%d", &record.age);
    printf("Enter a gender for the record: ");
    scanf("%s", record.gender);
    fwrite(&record, sizeof(Record), 1, fp);
    printf("Record added successfully!\n");
}

void searchRecord(FILE *fp) {
    Record record;
    int id, found = 0;
    printf("\nEnter the ID of the record you'd like to search for: ");
    scanf("%d", &id);
    rewind(fp);
    while (fread(&record, sizeof(Record), 1, fp)) {
        if (record.id == id) {
            found = 1;
            printf("Record found!\n\n");
            printf("ID: %d\n", record.id);
            printf("Name: %s\n", record.name);
            printf("Age: %d\n", record.age);
            printf("Gender: %s\n", record.gender);
            break;
        }
    }
    if (!found) {
        printf("Record not found!\n");
    }
}

void deleteRecord(FILE *fp) {
    Record record;
    FILE *temp;
    int id, found = 0;
    printf("\nEnter the ID of the record you'd like to delete: ");
    scanf("%d", &id);
    temp = fopen("temp.txt", "wb");
    rewind(fp);
    while (fread(&record, sizeof(Record), 1, fp)) {
        if (record.id != id) {
            fwrite(&record, sizeof(Record), 1, temp);
        } else {
            found = 1;
        }
    }
    fclose(fp);
    fclose(temp);
    if (!found) {
        remove("temp.txt");
        printf("Record not found!\n");
    } else {
        remove("records.txt");
        rename("temp.txt", "records.txt");
        printf("Record deleted successfully!\n");
    }
    fp = fopen("records.txt", "ab+");
}

void printRecords(FILE *fp) {
    Record record;
    rewind(fp);
    printf("\nPrinting all records in the database:\n\n");
    while (fread(&record, sizeof(Record), 1, fp)) {
        printf("ID: %d\n", record.id);
        printf("Name: %s\n", record.name);
        printf("Age: %d\n", record.age);
        printf("Gender: %s\n\n", record.gender);
    }
}

int main() {
    FILE *fp;
    int choice;
    fp = fopen("records.txt", "ab+");
    if (!fp) {
        printf("Error opening file! Please check if the file exists and has correct permissions.\n");
        return 1;
    }
    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addRecord(fp);
                break;
            case 2:
                searchRecord(fp);
                break;
            case 3:
                deleteRecord(fp);
                break;
            case 4:
                printRecords(fp);
                break;
            case 5:
                fclose(fp);
                printf("\nGoodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}