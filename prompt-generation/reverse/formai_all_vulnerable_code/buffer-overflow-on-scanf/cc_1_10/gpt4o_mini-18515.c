//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CASES 100
#define NAME_LENGTH 50
#define DETAIL_LENGTH 256

// Struct representing a case
typedef struct {
    int id;
    char name[NAME_LENGTH];
    char details[DETAIL_LENGTH];
    int solved; // 0 for unsolved, 1 for solved
} Case;

// Array to store cases and the count of cases
Case caseDatabase[MAX_CASES];
int caseCount = 0;

// Function prototypes
void addCase(char *name, char *details);
void solveCase(int id);
void showCases();
void showCaseDetails(int id);
void displayMenu();

int main() {
    int choice, id;
    char name[NAME_LENGTH], details[DETAIL_LENGTH];

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter the name of the case: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // remove trailing newline

                printf("Enter the details of the case: ");
                fgets(details, DETAIL_LENGTH, stdin);
                details[strcspn(details, "\n")] = '\0'; // remove trailing newline

                addCase(name, details);
                printf("Case added successfully!\n");
                break;

            case 2:
                printf("Enter the ID of the case to solve: ");
                scanf("%d", &id);
                solveCase(id);
                break;

            case 3:
                showCases();
                break;

            case 4:
                printf("Enter the ID of the case to view details: ");
                scanf("%d", &id);
                showCaseDetails(id);
                break;

            case 5:
                printf("Exiting the program. Farewell!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

// Function to add a case
void addCase(char *name, char *details) {
    if (caseCount < MAX_CASES) {
        caseDatabase[caseCount].id = caseCount + 1; // Assign unique ID
        strcpy(caseDatabase[caseCount].name, name);
        strcpy(caseDatabase[caseCount].details, details);
        caseDatabase[caseCount].solved = 0;
        caseCount++;
    } else {
        printf("Case database is full, cannot add more cases.\n");
    }
}

// Function to solve a case
void solveCase(int id) {
    if (id > 0 && id <= caseCount) {
        caseDatabase[id - 1].solved = 1;
        printf("Case ID %d has been marked as solved!\n", id);
    } else {
        printf("Case ID %d does not exist.\n", id);
    }
}

// Function to show all cases
void showCases() {
    printf("\nList of Cases:\n");
    for (int i = 0; i < caseCount; i++) {
        printf("ID: %d | Name: %s | Status: %s\n",
               caseDatabase[i].id,
               caseDatabase[i].name,
               caseDatabase[i].solved ? "Solved" : "Unsolved");
    }
    printf("\n");
}

// Function to show case details
void showCaseDetails(int id) {
    if (id > 0 && id <= caseCount) {
        printf("\nDetails of Case ID %d:\n", id);
        printf("Name: %s\n", caseDatabase[id - 1].name);
        printf("Details: %s\n", caseDatabase[id - 1].details);
        printf("Status: %s\n\n", caseDatabase[id - 1].solved ? "Solved" : "Unsolved");
    } else {
        printf("Case ID %d does not exist.\n", id);
    }
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Sherlock Holmes Case Database ---\n");
    printf("1. Add a Case\n");
    printf("2. Solve a Case\n");
    printf("3. Show All Cases\n");
    printf("4. Show Case Details\n");
    printf("5. Exit\n");
}