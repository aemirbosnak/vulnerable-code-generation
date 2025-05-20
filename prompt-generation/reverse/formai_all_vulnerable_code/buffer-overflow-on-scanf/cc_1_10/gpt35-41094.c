//FormAI DATASET v1.0 Category: Digital Diary ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_SIZE 100

// User-defined structure to hold diary entries
typedef struct DiaryEntry {
    char title[50];
    char message[1000];
    struct tm *timestamp;
} DiaryEntry;

// Function to get current timestamp
struct tm * getCurrentTime() {
    time_t now;
    time(&now);
    return localtime(&now);
}

// Function to add diary entry
void addEntry(DiaryEntry *diary, int *size) {
    // Check if diary is already full
    if (*size == MAX_SIZE) {
        printf("Sorry, diary is full!\n");
        return;
    }
    
    // Get user input
    char title[50];
    char message[1000];
    printf("Enter title of diary entry: ");
    fgets(title, 50, stdin);
    printf("Enter message of diary entry: ");
    fgets(message, 1000, stdin);
    
    // Add new entry
    DiaryEntry newEntry;
    strcpy(newEntry.title, title);
    strcpy(newEntry.message, message);
    newEntry.timestamp = getCurrentTime();
    diary[*size] = newEntry;
    
    (*size)++;
    printf("Entry added successfully!\n");
}

// Function to print all diary entries
void printEntries(DiaryEntry *diary, int size) {
    // Check if diary is empty
    if (size == 0) {
        printf("Diary is empty!\n");
        return;
    }
    
    // Print each entry
    for (int i=0; i<size; i++) {
        printf("\nEntry %d\n", i+1);
        printf("Title: %s", diary[i].title);
        printf("Message: %s", diary[i].message);
        printf("Timestamp: %s", asctime(diary[i].timestamp));
    }
}

int main() {
    DiaryEntry diary[MAX_SIZE];
    int size = 0;
    int choice;
    
    do {
        // Display menu options
        printf("\nDigital Diary Menu\n");
        printf("1. Add new entry\n");
        printf("2. Print all entries\n");
        printf("3. Quit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        getchar(); // to clear input buffer
        
        // Perform selected action
        switch (choice) {
            case 1:
                addEntry(diary, &size);
                break;
            case 2:
                printEntries(diary, size);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a choice from 1 to 3.\n");
                break;
        }
    } while (choice != 3);
    
    return 0;
}