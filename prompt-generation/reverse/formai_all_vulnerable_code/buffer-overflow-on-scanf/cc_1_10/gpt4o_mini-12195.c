//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define FILE_NAME "records.txt"

typedef struct {
    char name[NAME_LENGTH];
    int age;
} Person;

void addRecord(FILE *file) {
    Person p;
    printf("Enter Name: ");
    scanf("%s", p.name);
    printf("Enter Age: ");
    scanf("%d", &p.age);
    
    fseek(file, 0, SEEK_END); // Move to the end of the file
    fwrite(&p, sizeof(Person), 1, file);
    printf("Record added successfully!\n");
}

void displayRecords(FILE *file) {
    Person p;
    fseek(file, 0, SEEK_SET); // Move to the beginning of the file
    
    printf("\nRecords in the file:\n");
    while (fread(&p, sizeof(Person), 1, file)) {
        printf("Name: %s, Age: %d\n", p.name, p.age);
    }
}

void searchRecord(FILE *file) {
    char nameToSearch[NAME_LENGTH];
    Person p;
    
    printf("Enter name to search: ");
    scanf("%s", nameToSearch);
    
    fseek(file, 0, SEEK_SET);
    
    int found = 0;
    while (fread(&p, sizeof(Person), 1, file)) {
        if (strcmp(p.name, nameToSearch) == 0) {
            printf("Record found: Name: %s, Age: %d\n", p.name, p.age);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Record not found.\n");
    }
}

void deleteRecord(FILE *file) {
    FILE *tempFile;
    Person p;
    char nameToDelete[NAME_LENGTH];
    
    printf("Enter name to delete: ");
    scanf("%s", nameToDelete);
    
    tempFile = fopen("temp.txt", "wb");
    fseek(file, 0, SEEK_SET);
    int found = 0;

    while (fread(&p, sizeof(Person), 1, file)) {
        if (strcmp(p.name, nameToDelete) != 0) {
            fwrite(&p, sizeof(Person), 1, tempFile);
        } else {
            found = 1;
        }
    }
    
    fclose(tempFile);
    fclose(file);
    
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);
    
    if (found) {
        printf("Record deleted successfully!\n");
    } else {
        printf("No record found with that name to delete.\n");
    }
}

void modifyRecord(FILE *file) {
    char nameToModify[NAME_LENGTH];
    Person p;
    
    printf("Enter name to modify: ");
    scanf("%s", nameToModify);
    
    fseek(file, 0, SEEK_SET);
    int found = 0;

    while (fread(&p, sizeof(Person), 1, file)) {
        if (strcmp(p.name, nameToModify) == 0) {
            found = 1;
            printf("Current Name: %s, Age: %d\n", p.name, p.age);
            printf("Enter new Age: ");
            scanf("%d", &p.age);
            fseek(file, -sizeof(Person), SEEK_CUR); // Move to the previous position
            fwrite(&p, sizeof(Person), 1, file);
            printf("Record modified successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("No record found with that name to modify.\n");
    }
}

void displayMenu() {
    printf("\nChoose an option:\n");
    printf("1. Add Record\n");
    printf("2. Display Records\n");
    printf("3. Search Record\n");
    printf("4. Delete Record\n");
    printf("5. Modify Record\n");
    printf("6. Exit\n");
}

int main() {
    FILE *file;

    // Open in binary read/write mode
    file = fopen(FILE_NAME, "rb+");
    if (file == NULL) {
        file = fopen(FILE_NAME, "wb+"); // Create file if it doesn't exist
        if (file == NULL) {
            perror("Unable to open file");
            return EXIT_FAILURE;
        }
    }

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addRecord(file);
                break;
            case 2:
                displayRecords(file);
                break;
            case 3:
                searchRecord(file);
                break;
            case 4:
                deleteRecord(file);
                file = fopen(FILE_NAME, "rb+"); // Reopen the file after deleting
                break;
            case 5:
                modifyRecord(file);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    fclose(file);
    return 0;
}