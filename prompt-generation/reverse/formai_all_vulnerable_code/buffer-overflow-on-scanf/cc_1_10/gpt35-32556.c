//FormAI DATASET v1.0 Category: Database querying ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 20
#define MAX_ID_LEN 10
#define MAX_RECORDS 100

typedef struct {
    char id[MAX_ID_LEN];
    char name[MAX_NAME_LEN];
    int age;
    char gender;
} Person;

Person records[MAX_RECORDS];

void searchById() {
    char id[MAX_ID_LEN];
    printf("Enter person's ID: ");
    scanf("%s", id);
    // Validate ID
    int validID = 0;
    for (int i = 0; i < strlen(id); i++) {
        if (isdigit(id[i]) == 0) {
            printf("Invalid ID\n");
            return;
        }
        validID = 1;
    }
    if (validID == 0) {
        printf("Invalid ID\n");
        return;
    }
    // Search for person by ID
    int found = 0;
    for (int i = 0; i < MAX_RECORDS; i++) {
        if (strcmp(records[i].id, id) == 0) {
            // Found person by ID
            printf("ID: %s\nName: %s\nAge: %d\nGender: %c\n", records[i].id, records[i].name, records[i].age, records[i].gender);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("Person not found\n");
    }
}

void searchByName() {
    char name[MAX_NAME_LEN];
    printf("Enter person's name: ");
    scanf("%s", name);
    // Search for person by name
    int found = 0;
    for (int i = 0; i < MAX_RECORDS; i++) {
        if (strcmp(records[i].name, name) == 0) {
            // Found person by name
            printf("ID: %s\nName: %s\nAge: %d\nGender: %c\n", records[i].id, records[i].name, records[i].age, records[i].gender);
            found = 1;
        }
    }
    if (found == 0) {
        printf("Person not found\n");
    }
}

int main() {
    // Populate records with sample data
    strcpy(records[0].id, "123456");
    strcpy(records[0].name, "John");
    records[0].age = 30;
    records[0].gender = 'M';
    strcpy(records[1].id, "654321");
    strcpy(records[1].name, "Sarah");
    records[1].age = 25;
    records[1].gender = 'F';
    // Display menu to user
    int choice = 0;
    while (choice != 3) {
        printf("1. Search by ID\n2. Search by name\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: searchById(); break;
            case 2: searchByName(); break;
            case 3: break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}