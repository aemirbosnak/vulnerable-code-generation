//FormAI DATASET v1.0 Category: File handling ; Style: modular
#include<stdio.h>
#include<stdlib.h>

// define maximum length of name and email
#define MAX_LENGTH 50

// function prototypes
void mainMenu();
void addRecord();
void searchRecord();
void modifyRecord();
void deleteRecord();

// structure of a record
struct Record {
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
};

int main() {
    mainMenu();
    return 0;
}

void mainMenu() {
    int choice;
    printf("1. Add Record\n");
    printf("2. Search Record\n");
    printf("3. Modify Record\n");
    printf("4. Delete Record\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            addRecord();
            break;
        case 2:
            searchRecord();
            break;
        case 3:
            modifyRecord();
            break;
        case 4:
            deleteRecord();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice!\n");
            mainMenu();
    }
}

void addRecord() {
    struct Record record;
    FILE *file;
    file = fopen("records.txt", "a");
    printf("Enter name: ");
    scanf("%s", record.name);
    printf("Enter email: ");
    scanf("%s", record.email);
    fprintf(file, "%s %s\n", record.name, record.email);
    fclose(file);
    printf("Record added successfully!\n");
    mainMenu();
}

void searchRecord() {
    struct Record record;
    int found = 0;
    char searchName[MAX_LENGTH];
    FILE *file;
    file = fopen("records.txt", "r");
    printf("Enter name to search: ");
    scanf("%s", searchName);
    while(fscanf(file, "%s %s", record.name, record.email) != EOF) {
        if(strcmp(searchName, record.name) == 0) {
            printf("Name: %s\nEmail: %s\n", record.name, record.email);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Record not found!\n");
    }
    fclose(file);
    mainMenu();
}

void modifyRecord() {
    struct Record record;
    int found = 0;
    char searchName[MAX_LENGTH];
    FILE *file, *temp;
    file = fopen("records.txt", "r");
    temp = fopen("temp.txt", "w");
    printf("Enter name to modify: ");
    scanf("%s", searchName);
    while(fscanf(file, "%s %s", record.name, record.email) != EOF) {
        if(strcmp(searchName, record.name) == 0) {
            printf("Enter new name: ");
            scanf("%s", record.name);
            printf("Enter new email: ");
            scanf("%s", record.email);
            fprintf(temp, "%s %s\n", record.name, record.email);
            found = 1;
        } else {
            fprintf(temp, "%s %s\n", record.name, record.email);
        }
    }
    if(!found) {
        printf("Record not found!\n");
    } else {
        printf("Record modified successfully!\n");
    }
    fclose(file);
    fclose(temp);
    remove("records.txt");
    rename("temp.txt", "records.txt");
    mainMenu();
}

void deleteRecord() {
    struct Record record;
    int found = 0;
    char searchName[MAX_LENGTH];
    FILE *file, *temp;
    file = fopen("records.txt", "r");
    temp = fopen("temp.txt", "w");
    printf("Enter name to delete: ");
    scanf("%s", searchName);
    while(fscanf(file, "%s %s", record.name, record.email) != EOF) {
        if(strcmp(searchName, record.name) == 0) {
            found = 1;
        } else {
            fprintf(temp, "%s %s\n", record.name, record.email);
        }
    }
    if(!found) {
        printf("Record not found!\n");
    } else {
        printf("Record deleted successfully!\n");
    }
    fclose(file);
    fclose(temp);
    remove("records.txt");
    rename("temp.txt", "records.txt");
    mainMenu();
}