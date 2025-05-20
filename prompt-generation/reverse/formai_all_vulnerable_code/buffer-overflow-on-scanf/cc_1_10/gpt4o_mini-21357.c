//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10

typedef struct {
    int case_number;
    char description[256];
    int suspects;  // Bitmask for suspects:
                   // Bit 0 - John
                   // Bit 1 - Mary
                   // Bit 2 - Watson
                   // Bit 3 - Moriarty
                   // Bit 4 - Others
} CaseRecord;

void add_case(CaseRecord *records, int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Case records are full. Cannot add more cases.\n");
        return;
    }
    
    printf("Enter case number: ");
    scanf("%d", &records[*count].case_number);
    printf("Enter case description: ");
    scanf(" %[^\n]", records[*count].description);
    records[*count].suspects = 0; // Reset suspects

    int more_suspects;
    do {
        printf("Enter suspect (0: John, 1: Mary, 2: Watson, 3: Moriarty, 4: Others) or -1 to finish: ");
        scanf("%d", &more_suspects);
        if (more_suspects >= 0 && more_suspects <= 4) {
            records[*count].suspects |= (1 << more_suspects); // Set the suspect bit
        }
    } while (more_suspects != -1);

    (*count)++;
    printf("Case added successfully!\n");
}

void display_cases(CaseRecord *records, int count) {
    printf("\nList of Cases:\n");
    if (count == 0) {
        printf("No cases recorded.\n");
    } else {
        for (int i = 0; i < count; i++) {
            printf("\nCase Number: %d\n", records[i].case_number);
            printf("Description: %s\n", records[i].description);
            printf("Suspects: ");
            if (records[i].suspects == 0) {
                printf("None\n");
            } else {
                if (records[i].suspects & (1 << 0)) printf("John ");
                if (records[i].suspects & (1 << 1)) printf("Mary ");
                if (records[i].suspects & (1 << 2)) printf("Watson ");
                if (records[i].suspects & (1 << 3)) printf("Moriarty ");
                if (records[i].suspects & (1 << 4)) printf("Others ");
                printf("\n");
            }
        }
    }
}

void search_case(CaseRecord *records, int count) {
    int case_num;
    printf("Enter the case number to search: ");
    scanf("%d", &case_num);
    
    for (int i = 0; i < count; i++) {
        if (records[i].case_number == case_num) {
            printf("Case Found:\n");
            printf("Description: %s\n", records[i].description);
            printf("Suspects: ");
            if (records[i].suspects == 0) {
                printf("None\n");
            } else {
                if (records[i].suspects & (1 << 0)) printf("John ");
                if (records[i].suspects & (1 << 1)) printf("Mary ");
                if (records[i].suspects & (1 << 2)) printf("Watson ");
                if (records[i].suspects & (1 << 3)) printf("Moriarty ");
                if (records[i].suspects & (1 << 4)) printf("Others ");
                printf("\n");
            }
            return;
        }
    }
    printf("Case number %d not found.\n", case_num);
}

void delete_case(CaseRecord *records, int *count) {
    int case_num;
    printf("Enter the case number to delete: ");
    scanf("%d", &case_num);
    
    for (int i = 0; i < *count; i++) {
        if (records[i].case_number == case_num) {
            records[i] = records[*count - 1]; // Replace with the last case
            (*count)--;
            printf("Case number %d deleted successfully.\n", case_num);
            return;
        }
    }
    printf("Case number %d not found.\n", case_num);
}

int main() {
    CaseRecord records[MAX_RECORDS];
    int count = 0;
    int choice;

    do {
        printf("\nSherlock’s Case Manager\n");
        printf("1. Add Case\n");
        printf("2. Display Cases\n");
        printf("3. Search Case\n");
        printf("4. Delete Case\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_case(records, &count);
                break;
            case 2:
                display_cases(records, count);
                break;
            case 3:
                search_case(records, count);
                break;
            case 4:
                delete_case(records, &count);
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 5);

    return 0;
}