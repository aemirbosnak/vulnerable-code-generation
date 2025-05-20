//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char description[100];
    float amount;
    int date[3]; // Year, month, day
} Entry;

int num_entries = 0;
Entry entries[MAX_ENTRIES];

void add_entry(void) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Cannot add more than %d entries.\n", MAX_ENTRIES);
        return;
    }

    printf("Enter description:\n");
    scanf("%s", entries[num_entries].description);

    printf("Enter amount:\n");
    scanf("%f", &entries[num_entries].amount);

    printf("Enter date (YYYY-MM-DD):\n");
    scanf("%d-%d-%d", &entries[num_entries].date[0], &entries[num_entries].date[1], &entries[num_entries].date[2]);

    num_entries++;
}

void list_entries(void) {
    printf("ID\tDate\tDescription\tAmount\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%d\t", i+1);
        printf("%d-%d-%d\t", entries[i].date[0], entries[i].date[1], entries[i].date[2]);
        printf("%s\t", entries[i].description);
        printf("%f\n", entries[i].amount);
    }
}

void search_entries(void) {
    char search_str[100];

    printf("Enter search string:\n");
    scanf("%s", search_str);

    int matches = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].description, search_str)) {
            printf("%d\t", i+1);
            printf("%s\n", entries[i].description);
            matches++;
        }
    }

    if (matches == 0) {
        printf("No matches found.\n");
    }
}

int main(void) {
    add_entry();
    add_entry();
    list_entries();
    search_entries();

    return 0;
}