//FormAI DATASET v1.0 Category: Database simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 120
#define MAX_EMAIL_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_RECORDS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Record;

Record database[MAX_RECORDS];
int num_records = 0;

void add_record() {
    if (num_records >= MAX_RECORDS) {
        printf("Error: Maximum number of records reached.\n");
        return;
    }
    
    Record new_record;
    
    printf("Enter name (up to %d characters): ", MAX_NAME_LENGTH);
    fgets(new_record.name, MAX_NAME_LENGTH, stdin);
    new_record.name[strcspn(new_record.name, "\n")] = '\0';
    
    printf("Enter age (0 to %d): ", MAX_AGE);
    scanf("%d", &new_record.age);
    
    printf("Enter email (up to %d characters): ", MAX_EMAIL_LENGTH);
    scanf("%s", new_record.email);
    
    printf("Enter phone number (up to %d characters): ", MAX_PHONE_LENGTH);
    scanf("%s", new_record.phone);
    
    database[num_records++] = new_record;
    
    printf("Record added successfully.\n");
}

void view_records() {
    if (num_records == 0) {
        printf("No records to display.\n");
        return;
    }
    
    printf("\nName\t\tAge\tEmail\t\t\tPhone\n");
    printf("-------------------------------------------------------------\n");
    
    for (int i = 0; i < num_records; i++) {
        printf("%s\t", database[i].name);
        printf("%d\t", database[i].age);
        printf("%s\t", database[i].email);
        printf("%s\n", database[i].phone);
    }
    
    printf("\n");
}

void search_records() {
    if (num_records == 0) {
        printf("No records to search.\n");
        return;
    }
    
    char search_name[MAX_NAME_LENGTH];
    
    printf("Enter name to search: ");
    fgets(search_name, MAX_NAME_LENGTH, stdin);
    search_name[strcspn(search_name, "\n")] = '\0';
    
    int found = 0;
    
    for (int i = 0; i < num_records; i++) {
        if (strcmp(database[i].name, search_name) == 0) {
            printf("\nName\t\tAge\tEmail\t\t\tPhone\n");
            printf("-------------------------------------------------------------\n");
            printf("%s\t", database[i].name);
            printf("%d\t", database[i].age);
            printf("%s\t", database[i].email);
            printf("%s\n", database[i].phone);
            printf("\n");
            found++;
        }
    }
    
    if (found == 0) {
        printf("No records found.\n");
    } else {
        printf("%d record(s) found.\n", found);
    }
}

int main() {
    int choice;
    
    while (1) {
        printf("Please choose an option:\n");
        printf("1. Add record\n");
        printf("2. View records\n");
        printf("3. Search records\n");
        printf("4. Exit\n");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                view_records();
                break;
            case 3:
                search_records();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}