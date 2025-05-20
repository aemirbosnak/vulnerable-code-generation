//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define AGE_LENGTH 3
#define FILE_NAME "people.txt"

typedef struct {
    char name[NAME_LENGTH];
    char age[AGE_LENGTH];
} Person;

void add_person();
void display_people();
void search_person();
void delete_person();
void clear_stdin();

int main() {
    int choice;

    while (1) {
        printf("\n--- Person Management System ---\n");
        printf("1. Add Person\n");
        printf("2. Display People\n");
        printf("3. Search Person\n");
        printf("4. Delete Person\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_stdin();

        switch (choice) {
            case 1:
                add_person();
                break;
            case 2:
                display_people();
                break;
            case 3:
                search_person();
                break;
            case 4:
                delete_person();
                break;
            case 5:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void add_person() {
    Person p;
    FILE *fp = fopen(FILE_NAME, "a");

    if (fp == NULL) {
        perror("Error opening file");
        return;
    }
    
    printf("Enter name: ");
    fgets(p.name, NAME_LENGTH, stdin);
    p.name[strcspn(p.name, "\n")] = 0; // Remove newline character

    printf("Enter age: ");
    fgets(p.age, AGE_LENGTH, stdin);
    p.age[strcspn(p.age, "\n")] = 0; // Remove newline character

    fprintf(fp, "%s %s\n", p.name, p.age);
    fclose(fp);

    printf("Person added successfully!\n");
}

void display_people() {
    Person p;
    FILE *fp = fopen(FILE_NAME, "r");
    
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    printf("\n--- List of People ---\n");
    while (fscanf(fp, "%s %s", p.name, p.age) != EOF) {
        printf("Name: %s, Age: %s\n", p.name, p.age);
    }

    fclose(fp);
}

void search_person() {
    char search_name[NAME_LENGTH];
    Person p;
    int found = 0;
    FILE *fp = fopen(FILE_NAME, "r");

    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    printf("Enter name to search: ");
    fgets(search_name, NAME_LENGTH, stdin);
    search_name[strcspn(search_name, "\n")] = 0; // Remove newline character

    while (fscanf(fp, "%s %s", p.name, p.age) != EOF) {
        if (strcmp(p.name, search_name) == 0) {
            printf("Found - Name: %s, Age: %s\n", p.name, p.age);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No entry found for %s.\n", search_name);
    }

    fclose(fp);
}

void delete_person() {
    char delete_name[NAME_LENGTH];
    Person p;
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp_fp = fopen("temp.txt", "w");
    int found = 0;

    if (fp == NULL || temp_fp == NULL) {
        perror("Error opening file");
        return;
    }

    printf("Enter name to delete: ");
    fgets(delete_name, NAME_LENGTH, stdin);
    delete_name[strcspn(delete_name, "\n")] = 0; // Remove newline character

    while (fscanf(fp, "%s %s", p.name, p.age) != EOF) {
        if (strcmp(p.name, delete_name) != 0) {
            fprintf(temp_fp, "%s %s\n", p.name, p.age);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp_fp);
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) {
        printf("Entry for %s has been deleted.\n", delete_name);
    } else {
        printf("No entry found for %s.\n", delete_name);
    }
}

void clear_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}