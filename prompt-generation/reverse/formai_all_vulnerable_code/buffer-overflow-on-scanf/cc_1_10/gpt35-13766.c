//FormAI DATASET v1.0 Category: Digital Diary ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct diary {
    int day;
    int month;
    int year;
    char entry[200];
};

void add_entry(struct diary *d) {
    printf("Enter the date of the entry in the format dd/mm/yyyy: ");
    scanf("%d/%d/%d", &d->day, &d->month, &d->year);
    
    printf("Enter your entry (maximum 200 characters):\n");
    getchar(); // clear input buffer
    fgets(d->entry, sizeof(d->entry), stdin);
}

void view_entries(struct diary *entries, int num_entries) {
    if (num_entries == 0) {
        printf("No entries to display.\n");
        return;
    }
    
    printf("---------------------------------------------------\n");
    printf("| Date       | Entry                             |\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < num_entries; i++) {
        printf("| %02d/%02d/%4d | %-33.33s|\n", entries[i].day, entries[i].month, 
                entries[i].year, entries[i].entry);
    }
    printf("---------------------------------------------------\n");
}

int main() {
    int option, num_entries = 0, total_entries = 10;
    struct diary *entries = malloc(total_entries * sizeof(struct diary));
    
    do {
        printf("\nDigital Diary\n");
        printf("1. Add new entry\n");
        printf("2. View previous entries\n");
        printf("3. Exit\n");
        printf("Please choose an option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                if (num_entries == total_entries) {
                    total_entries *= 2;
                    entries = realloc(entries, total_entries * sizeof(struct diary));
                }
                
                add_entry(&entries[num_entries]);
                num_entries++;
                printf("Entry added successfully.\n");
                break;
            case 2:
                view_entries(entries, num_entries);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option, please choose again.\n");
        }
    } while (option != 3);
    
    free(entries);
    return 0;
}