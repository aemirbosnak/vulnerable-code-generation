//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

struct entry {
    char description[50];
    float amount;
    char date[20];
};

void add_entry(struct entry *entries, int *count, char *description, float amount, char *date) {
    if (*count >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    strcpy(entries[*count].description, description);
    entries[*count].amount = amount;
    strcpy(entries[*count].date, date);

    (*count)++;
}

void display_entries(struct entry *entries, int count) {
    printf("Total entries: %d\n", count);

    for (int i = 0; i < count; i++) {
        printf("%s - $%.2f - %s\n", entries[i].description, entries[i].amount, entries[i].date);
    }
}

void search_entries(struct entry *entries, int count, char *keyword) {
    int matches = 0;

    for (int i = 0; i < count; i++) {
        if (strstr(entries[i].description, keyword)!= NULL) {
            printf("%s - $%.2f - %s\n", entries[i].description, entries[i].amount, entries[i].date);
            matches++;
        }
    }

    if (matches == 0) {
        printf("No matches found.\n");
    }
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int count = 0;

    while (count < MAX_ENTRIES) {
        char description[50];
        float amount;
        char date[20];

        printf("Enter a description (up to 50 characters): ");
        scanf("%s", description);

        printf("Enter the amount (up to $9999.99): ");
        scanf("%f", &amount);

        printf("Enter the date (YYYY-MM-DD): ");
        scanf("%s", date);

        add_entry(entries, &count, description, amount, date);

        printf("Do you want to add another entry? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice!= 'y') {
            break;
        }
    }

    display_entries(entries, count);

    char keyword[50];
    printf("Enter a keyword to search for: ");
    scanf("%s", keyword);

    search_entries(entries, count, keyword);

    return 0;
}