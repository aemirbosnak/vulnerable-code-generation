//FormAI DATASET v1.0 Category: Digital Diary ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

struct Entry {
    char date[20];
    char time[20];
    char text[200];
};

int main() {
    struct Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;

    printf("Welcome to your digital diary!\n");

    while(1) {
        printf("\nSelect an option:\n");
        printf("1. Add entry\n");
        printf("2. View all entries\n");
        printf("3. Search entries by date\n");
        printf("4. Quit\n");
        scanf(" %c", &choice);

        switch(choice) {
            case '1': // Add Entry
                if(num_entries < MAX_ENTRIES) {
                    struct Entry new_entry;
                    time_t t = time(NULL);
                    struct tm *tm = localtime(&t);

                    strftime(new_entry.date, 20, "%d-%m-%Y", tm);
                    strftime(new_entry.time, 20, "%H:%M:%S", tm);

                    printf("Enter your entry:\n");
                    scanf(" %[^\n]s", new_entry.text);

                    entries[num_entries++] = new_entry;
                    printf("Entry added successfully!\n");
                } else {
                    printf("Maximum number of entries reached!\n");
                }
                break;
            case '2': // View all entries
                if(num_entries == 0) {
                    printf("No entries found!\n");
                } else {
                    printf("All Entries:\n");
                    for(int i=0; i<num_entries; i++) {
                        printf("Date: %s\nTime: %s\n%s\n\n", entries[i].date, entries[i].time, entries[i].text);
                    }
                }
                break;
            case '3': // Search by date
                if(num_entries == 0) {
                    printf("No entries found!\n");
                } else {
                    char date[20];
                    int found = 0;

                    printf("Enter the date to search for (DD-MM-YYYY): ");
                    scanf(" %s", date);

                    printf("Entries on %s:\n", date);
                    for(int i=0; i<num_entries; i++) {
                        if(strcmp(entries[i].date, date) == 0) {
                            found = 1;
                            printf("Time: %s\n%s\n\n", entries[i].time, entries[i].text);
                        }
                    }

                    if(!found) {
                        printf("No entries found on %s!\n", date);
                    }
                }
                break;
            case '4': // Quit
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}