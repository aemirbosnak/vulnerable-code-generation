//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "example.txt"
#define MAX_LINE_LENGTH 256
#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    int age;
} Person;

void addPerson(FILE *file);
void displayPeople(FILE *file);
void searchPerson(FILE *file);
void deletePerson(FILE *file);
void updatePerson(FILE *file);
void clearBuffer();

int main() {
    int choice;
    FILE *file = fopen(FILENAME, "a+");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    do {
        printf("\n--- Menu ---\n");
        printf("1. Add Person\n");
        printf("2. Display People\n");
        printf("3. Search Person\n");
        printf("4. Update Person\n");
        printf("5. Delete Person\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addPerson(file);
                break;
            case 2:
                displayPeople(file);
                break;
            case 3:
                searchPerson(file);
                break;
            case 4:
                updatePerson(file);
                break;
            case 5:
                deletePerson(file);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    fclose(file);
    return EXIT_SUCCESS;
}

void clearBuffer() {
    while (getchar() != '\n');
}

void addPerson(FILE *file) {
    Person p;
    printf("Enter name: ");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = 0; // Remove trailing newline
    printf("Enter age: ");
    scanf("%d", &p.age);
    clearBuffer();
    
    fprintf(file, "%s, %d\n", p.name, p.age);
    printf("Person added successfully!\n");
}

void displayPeople(FILE *file) {
    rewind(file); // Move to the beginning of the file
    char line[MAX_LINE_LENGTH];
    printf("\n--- People List ---\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
}

void searchPerson(FILE *file) {
    rewind(file);
    char name[50], line[MAX_LINE_LENGTH];
    printf("Enter name to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove trailing newline
    
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, name)) {
            printf("%s", line);
            found = 1;
        }
    }
    if (!found) {
        printf("No person found with the name '%s'.\n", name);
    }
}

void updatePerson(FILE *file) {
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        perror("Error opening temporary file");
        return;
    }
    
    rewind(file);
    char name[50], line[MAX_LINE_LENGTH];
    Person p;
    printf("Enter name of person to update: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove trailing newline
    
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, name)) {
            found = 1;
            printf("Updating details for %s:\n", name);
            printf("Enter new age: ");
            scanf("%d", &p.age);
            clearBuffer();
            sprintf(p.name, "%s", name);
            fprintf(tempFile, "%s, %d\n", p.name, p.age);
            printf("Person updated successfully!\n");
        } else {
            fprintf(tempFile, "%s", line);
        }
    }
    if (!found) {
        printf("No person found with the name '%s'.\n", name);
    }
    
    fclose(file);
    fclose(tempFile);
    
    remove(FILENAME);
    rename("temp.txt", FILENAME);
    file = fopen(FILENAME, "a+");
}

void deletePerson(FILE *file) {
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        perror("Error opening temporary file");
        return;
    }
    
    rewind(file);
    char name[50], line[MAX_LINE_LENGTH];
    printf("Enter name of person to delete: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove trailing newline
    
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, name)) {
            found = 1;
            printf("Deleted: %s", line);
        } else {
            fprintf(tempFile, "%s", line);
        }
    }
    if (!found) {
        printf("No person found with the name '%s'.\n", name);
    }
    
    fclose(file);
    fclose(tempFile);
    
    remove(FILENAME);
    rename("temp.txt", FILENAME);
    file = fopen(FILENAME, "a+");
}