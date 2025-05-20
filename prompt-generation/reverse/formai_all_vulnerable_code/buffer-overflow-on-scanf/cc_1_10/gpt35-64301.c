//FormAI DATASET v1.0 Category: Database simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_ID 999
#define MAX_NAME_LEN 20

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    float score;
} student;

int getNextId(student records[MAX_SIZE], int currentIndex);
void addStudent(student records[MAX_SIZE], int currentIndex);
void displayAllRecords(student records[MAX_SIZE], int currentIndex, int start);
void searchRecords(student records[MAX_SIZE], int searchId, int currentIndex, int start);
void deleteRecords(student records[MAX_SIZE], int deleteId, int currentIndex);

int main() {
    student records[MAX_SIZE];
    int currentIndex = 0;
    int start = 0;
    int option;
    int searchId;
    int deleteId;
    
    do {
        printf("Please select an option:\n");
        printf("1. Add new student record\n");
        printf("2. Display all student records\n");
        printf("3. Search for a student record\n");
        printf("4. Delete a student record\n");
        printf("5. Exit\n");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                addStudent(records, currentIndex);
                currentIndex++;
                break;
            case 2:
                displayAllRecords(records, currentIndex, start);
                break;
            case 3:
                printf("Enter student ID to search: ");
                scanf("%d", &searchId);
                searchRecords(records, searchId, currentIndex, start);
                break;
            case 4:
                printf("Enter student ID to delete: ");
                scanf("%d", &deleteId);
                deleteRecords(records, deleteId, currentIndex);
                currentIndex--;
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option selected!\n");
        }
    } while(option != 5);
    
    return 0;
}

int getNextId(student records[MAX_SIZE], int currentIndex) {
    int nextId = 0;
    
    if(currentIndex == 0) {
        nextId = 1;
    } else {
        int i;
        for(i = 0; i < currentIndex; i++) {
            if(records[i].id > nextId) {
                nextId = records[i].id;
            }
        }
        nextId++;
    }
    
    return nextId;
}

void addStudent(student records[MAX_SIZE], int currentIndex) {
    int id = getNextId(records, currentIndex);
    char name[MAX_NAME_LEN];
    float score;
    
    printf("Enter student name: ");
    scanf("%s", name);
    
    printf("Enter student score: ");
    scanf("%f", &score);
    
    records[currentIndex].id = id;
    strcpy(records[currentIndex].name, name);
    records[currentIndex].score = score;
    
    printf("Student record added successfully.\n");
}

void displayAllRecords(student records[MAX_SIZE], int currentIndex, int start) {
    if(currentIndex == start) {
        printf("No records found.\n");
        return;
    }
    
    printf("All student records:\n");
    int i;
    for(i = start; i < currentIndex; i++) {
        printf("%d\t%s\t%.2f\n", records[i].id, records[i].name, records[i].score);
    }
}

void searchRecords(student records[MAX_SIZE], int searchId, int currentIndex, int start) {
    if(currentIndex == start) {
        printf("No records found.\n");
        return;
    }
    
    int i;
    for(i = start; i < currentIndex; i++) {
        if(records[i].id == searchId) {
            printf("Student record found:\n");
            printf("%d\t%s\t%.2f\n", records[i].id, records[i].name, records[i].score);
            return;
        }
    }
    
    printf("Student record not found.\n");
}

void deleteRecords(student records[MAX_SIZE], int deleteId, int currentIndex) {
    int i;
    for(i = 0; i < currentIndex; i++) {
        if(records[i].id == deleteId) {
            int j;
            for(j = i; j < currentIndex - 1; j++) {
                records[j] = records[j+1];
            }
            printf("Student record deleted successfully.\n");
            return;
        }
    }
    
    printf("Student record not found.\n");
}