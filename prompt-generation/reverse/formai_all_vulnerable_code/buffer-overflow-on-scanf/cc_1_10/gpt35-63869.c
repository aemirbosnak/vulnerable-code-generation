//FormAI DATASET v1.0 Category: Digital Diary ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    int year;
    int month;
    int day;
    char message[200];
} Entry;

Entry diary[MAX_ENTRIES];
int cur_entries = 0;

void displayEntries() {
    printf("\n------------------------------------------------------------------------------\n");
    printf("| Date       | Message                                                         |\n");
    printf("------------------------------------------------------------------------------\n");
    for(int i = 0; i < cur_entries; i++) {
        printf("| %02d/%02d/%04d | %-65s |\n", diary[i].day, diary[i].month, diary[i].year, diary[i].message);
    }
    printf("------------------------------------------------------------------------------\n");
}

void addEntry() {
    Entry e;
    printf("\nEnter the date (dd mm yyyy): ");
    scanf("%d %d %d", &e.day, &e.month, &e.year);
    printf("Enter your message (max 200 characters):\n");
    scanf("\n");
    fgets(e.message, 200, stdin);
    diary[cur_entries++] = e;
    printf("\nEntry added successfully!\n");
}

void menu() {
    int option = 0;
    do {
        printf("\n1 - View entries\n2 - Add entry\n3 - Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                displayEntries();
                break;
            case 2:
                addEntry();
                break;
            case 3:
                printf("\nThank you for using the Grateful Digital Diary!\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
        }
    } while(option != 3);
}

int main() {
    printf("Welcome to the Grateful Digital Diary!\n");
    menu();
    return 0;
}