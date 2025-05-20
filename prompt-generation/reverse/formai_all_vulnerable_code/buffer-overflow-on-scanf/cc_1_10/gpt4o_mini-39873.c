//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node structure for the linked list to keep track of fitness data
typedef struct Node {
    float distance;
    int steps;
    char date[11];  // format: YYYY-MM-DD
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(float distance, int steps, const char* date);
void addEntry(Node** head, float distance, int steps, const char* date);
void displayRecords(Node* head);
void calculateStats(Node* head);
void freeList(Node* head);
int menu();

int main() {
    Node* head = NULL; // Initialize the head of the linked list
    int choice;
    
    printf("Welcome to the C Fitness Tracker!\n");
    
    do {
        choice = menu(); // Display the menu and get user choice
        
        if (choice == 1) {
            float distance;
            int steps;
            char date[11];
            
            printf("Enter distance (in km): ");
            scanf("%f", &distance);
            printf("Enter steps: ");
            scanf("%d", &steps);
            printf("Enter date (YYYY-MM-DD): ");
            scanf("%s", date);
            
            addEntry(&head, distance, steps, date);
            printf("Entry Added!\n\n");
        } 
        else if (choice == 2) {
            printf("Fitness Records:\n");
            displayRecords(head); // Display all entries
            printf("\n");
        } 
        else if (choice == 3) {
            calculateStats(head); // Calculate and display stats
            printf("\n");
        }
        else if (choice != 4) {
            printf("Invalid choice! Please retry.\n\n");
        }

    } while (choice != 4);
    
    freeList(head); // Free the memory used by the linked list
    printf("Exiting Fitness Tracker. Stay Healthy!\n");
    return 0;
}

// Function to create a new node
Node* createNode(float distance, int steps, const char* date) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->distance = distance;
    newNode->steps = steps;
    strcpy(newNode->date, date);
    newNode->next = NULL;
    return newNode;
}

// Function to add a new entry to the linked list
void addEntry(Node** head, float distance, int steps, const char* date) {
    Node* newNode = createNode(distance, steps, date);
    newNode->next = *head; // Add new node at the beginning
    *head = newNode;
}

// Function to display all fitness records
void displayRecords(Node* head) {
    if (head == NULL) {
        printf("No records found.\n");
        return;
    }
    
    Node* current = head;
    while (current != NULL) {
        printf("Date: %s | Distance: %.2f km | Steps: %d\n", current->date, current->distance, current->steps);
        current = current->next;
    }
}

// Function to calculate and display the statistics of the entries
void calculateStats(Node* head) {
    if (head == NULL) {
        printf("No records to calculate stats.\n");
        return;
    }
    
    int totalSteps = 0;
    float totalDistance = 0.0;
    int count = 0;
    
    Node* current = head;
    while (current != NULL) {
        totalSteps += current->steps;
        totalDistance += current->distance;
        count++;
        current = current->next;
    }
    
    printf("Total Entries: %d\n", count);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Steps: %d\n", totalSteps);
    printf("Average Distance: %.2f km\n", (count != 0) ? totalDistance / count : 0);
    printf("Average Steps: %.2f\n", (count != 0) ? (float)totalSteps / count : 0);
}

// Function to free the linked list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to display the menu and return user choice
int menu() {
    int choice;
    printf("Menu:\n");
    printf("1. Add Entry\n");
    printf("2. Display Records\n");
    printf("3. Calculate Statistics\n");
    printf("4. Exit\n");
    printf("Choose an option (1-4): ");
    scanf("%d", &choice);
    return choice;
}