//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of entries
#define MAX_ENTRIES 100

// Define the structure for each entry
typedef struct {
    int day;      // Day of the month (1-31)
    int month;     // Month (1-12)
    int year;      // Year (4-digit)
    char entry[100]; // Entry text (up to 100 characters)
} Entry;

// Define the array to store the entries
Entry entries[MAX_ENTRIES];

// Function to read and store the entries
void readEntries() {
    int i;
    for (i = 0; i < MAX_ENTRIES; i++) {
        printf("Day: ");
        scanf("%d", &entries[i].day);
        printf("Month: ");
        scanf("%d", &entries[i].month);
        printf("Year: ");
        scanf("%d", &entries[i].year);
        printf("Entry: ");
        fgets(entries[i].entry, 100, stdin);
    }
}

// Function to display the entries
void displayEntries() {
    int i;
    for (i = 0; i < MAX_ENTRIES; i++) {
        printf("Day: %d, Month: %d, Year: %d - %s\n",
               entries[i].day, entries[i].month, entries[i].year, entries[i].entry);
    }
}

// Main function
int main() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);

    // Read and store the entries
    readEntries();

    // Display the entries
    displayEntries();

    return 0;
}