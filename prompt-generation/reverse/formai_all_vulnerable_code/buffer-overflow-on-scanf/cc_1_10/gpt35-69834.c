//FormAI DATASET v1.0 Category: Database simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[50];
    char major[50];
    float gpa;
};

void insertRecord(FILE *fp) {
    struct student newStudent;
    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);
    printf("Enter student name: ");
    scanf("%s", newStudent.name);
    printf("Enter student major: ");
    scanf("%s", newStudent.major);
    printf("Enter student GPA: ");
    scanf("%f", &newStudent.gpa);
    
    fwrite(&newStudent, sizeof(struct student), 1, fp);
    
    printf("Record inserted successfully!\n");
}

void viewRecords(FILE *fp) {
    struct student currStudent;
    printf("ID\tName\tMajor\tGPA\n");
    while (fread(&currStudent, sizeof(struct student), 1, fp)) {
        printf("%d\t%s\t%s\t%.2f\n", currStudent.id, currStudent.name, currStudent.major, currStudent.gpa);
    }
}

void searchRecord(FILE *fp) {
    int id;
    struct student currStudent;
    printf("Enter student ID to search: ");
    scanf("%d", &id);
    while (fread(&currStudent, sizeof(struct student), 1, fp)) {
        if (currStudent.id == id) {
            printf("ID\tName\tMajor\tGPA\n");
            printf("%d\t%s\t%s\t%.2f\n", currStudent.id, currStudent.name, currStudent.major, currStudent.gpa);
            return;
        }
    }
    printf("No record found with ID: %d\n", id);
}

void updateRecord(FILE *fp) {
    int id;
    struct student currStudent;
    printf("Enter student ID to update: ");
    scanf("%d", &id);
    while (fread(&currStudent, sizeof(struct student), 1, fp)) {
        if (currStudent.id == id) {
            printf("Enter new student name: ");
            scanf("%s", currStudent.name);
            printf("Enter new student major: ");
            scanf("%s", currStudent.major);
            printf("Enter new student GPA: ");
            scanf("%f", &currStudent.gpa);
            
            fseek(fp, -sizeof(struct student), SEEK_CUR);
            fwrite(&currStudent, sizeof(struct student), 1, fp);
            
            printf("Record updated successfully!\n");
            return;
        }
    }
    printf("No record found with ID: %d\n", id);
}

void deleteRecord(FILE *fp) {
    int id;
    struct student currStudent, prevStudent;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);
    rewind(fp);
    while (fread(&currStudent, sizeof(struct student), 1, fp)) {
        if (currStudent.id == id) {
            if (currStudent.id == 1) {
                fseek(fp, sizeof(struct student), SEEK_CUR);
            }
            else {
                fseek(fp, -2 * sizeof(struct student), SEEK_CUR);
            }
            while (fread(&prevStudent, sizeof(struct student), 1, fp)) {
                fseek(fp, -2 * sizeof(struct student), SEEK_CUR);
                fwrite(&prevStudent, sizeof(struct student), 1, fp);
                fseek(fp, sizeof(struct student), SEEK_CUR);
            }
            int returnVal = ftruncate(fileno(fp), ftell(fp));
            if (returnVal == 0) {
                printf("Record deleted successfully!\n");
            }
            else {
                printf("Error deleting record!\n");
            }
            return;
        }
        prevStudent = currStudent;
    }
    printf("No record found with ID: %d\n", id);
}

int main() {
    FILE *fp;
    fp = fopen("students.dat", "r+");
    if (fp == NULL) {
        fp = fopen("students.dat", "w+");
        if (fp == NULL) {
            printf("Error creating file!\n");
            exit(1);
        }
    }
    printf("*** WELCOME TO THE STUDENTS DATABASE ***\n");
    int choice;
    do {
        printf("\nPlease choose an option:\n");
        printf("1. Insert a new record\n");
        printf("2. View all records\n");
        printf("3. Search for a record\n");
        printf("4. Update a record\n");
        printf("5. Delete a record\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertRecord(fp);
                break;
            case 2:
                viewRecords(fp);
                break;
            case 3:
                searchRecord(fp);
                break;
            case 4:
                updateRecord(fp);
                break;
            case 5:
                deleteRecord(fp);
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);
    fclose(fp);
    return 0;
}