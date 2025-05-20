//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CASES 100
#define MAX_DESC_LENGTH 256

typedef struct {
    int id;
    char description[MAX_DESC_LENGTH];
    char detective[MAX_DESC_LENGTH];
    int solved; // 1 for solved, 0 for unsolved
} Case;

Case cases[MAX_CASES];
int case_count = 0;

// Function prototypes
void add_case();
void list_cases();
void search_case(int id);

int main() {
    int choice, id;

    while (1) {
        printf("\n=== Sherlock Holmes Case Database ===\n");
        printf("1. Add a new case\n");
        printf("2. List all cases\n");
        printf("3. Search case by ID\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_case();
                break;
            case 2:
                list_cases();
                break;
            case 3:
                printf("Enter case ID to search: ");
                scanf("%d", &id);
                search_case(id);
                break;
            case 4:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}

void add_case() {
    if (case_count >= MAX_CASES) {
        printf("Case database is full. Cannot add more cases.\n");
        return;
    }

    Case new_case;
    new_case.id = case_count + 1;

    printf("Enter case description: ");
    getchar(); // Clear newline character
    fgets(new_case.description, MAX_DESC_LENGTH, stdin);
    new_case.description[strcspn(new_case.description, "\n")] = 0; // Remove newline

    printf("Enter detective's name: ");
    fgets(new_case.detective, MAX_DESC_LENGTH, stdin);
    new_case.detective[strcspn(new_case.detective, "\n")] = 0; // Remove newline

    printf("Is the case solved? (1 for yes, 0 for no): ");
    scanf("%d", &new_case.solved);

    cases[case_count] = new_case;
    case_count++;

    printf("New case added successfully!\n");
}

void list_cases() {
    if (case_count == 0) {
        printf("No cases in the database.\n");
        return;
    }

    printf("\nList of cases:\n");
    printf("ID\tDescription\t\t\tDetective\tSolved\n");
    for (int i = 0; i < case_count; i++) {
        printf("%d\t%s\t%s\t%d\n", cases[i].id, cases[i].description, cases[i].detective, cases[i].solved);
    }
}

void search_case(int id) {
    if (id < 1 || id > case_count) {
        printf("No case found with ID: %d\n", id);
        return;
    }

    Case found_case = cases[id - 1];
    printf("Case found:\n");
    printf("ID: %d\n", found_case.id);
    printf("Description: %s\n", found_case.description);
    printf("Detective: %s\n", found_case.detective);
    printf("Solved: %s\n", found_case.solved ? "Yes" : "No");
}