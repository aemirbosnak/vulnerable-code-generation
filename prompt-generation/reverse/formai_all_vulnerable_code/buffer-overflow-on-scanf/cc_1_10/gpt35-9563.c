//FormAI DATASET v1.0 Category: Database Indexing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a student record
struct student {
    int rollNo;
    char name[20];
};

// Setup a global variable to keep track of the number of records
int numOfRecords = 0;

// Declare the array to store the student records
struct student records[100];

// Declare the binary search function
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        
        if (arr[mid] == x) {
            return mid;
        }
        
        if (arr[mid] > x) {
            return binarySearch(arr, l, mid - 1, x);
        }
        
        return binarySearch(arr, mid + 1, r, x);
    }
    
    return -1;
}

// Declare the function to insert a student record
void insert() {
    struct student s;

    printf("\nEnter the roll number: ");
    scanf("%d", &s.rollNo);
    printf("Enter the name: ");
    scanf("%s", &s.name);

    // Insert the record in the array
    records[numOfRecords++] = s;
}

// Declare the function to display all student records
void display() {
    printf("\nRoll No.\tName\n");
    for (int i = 0; i < numOfRecords; i++) {
        printf("%d\t\t%s\n", records[i].rollNo, records[i].name);
    }
}

// Declare the function to search for a student record by roll number using binary search
void search() {
    int rollNo;
    printf("\nEnter the roll number to search for: ");
    scanf("%d", &rollNo);

    int index = binarySearch(records, 0, numOfRecords - 1, rollNo);

    if (index == -1) {
        printf("\nRecord not found!\n");
    } else {
        printf("\nRoll No.\tName\n");
        printf("%d\t\t%s\n", records[index].rollNo, records[index].name);
    }
}

int main() {
    int choice;

    do {
        printf("\nMenu\n");
        printf("1. Insert a student record\n");
        printf("2. Display all student records\n");
        printf("3. Search for a student record by roll number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                printf("\nExiting program...Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    } while (1);

    return 0;
}