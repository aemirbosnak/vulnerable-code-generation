//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a struct to store diary entries
struct diary_entry {
    char date[20]; // Date in the format "dd-mm-yyyy"
    char entry[100]; // Entry text
};

// Function to read and write diary entries
void read_diary() {
    // Open the diary file in read-write mode
    FILE *diary = fopen("diary.txt", "r+");

    // Check if the diary file exists
    if (!diary) {
        printf("Error: Diary file not found!\n");
        return;
    }

    // Read the diary entries
    struct diary_entry entry;
    while (fscanf(diary, "%s %s", entry.date, entry.entry) == 2) {
        // Print the diary entry
        printf("[%s] %s\n", entry.date, entry.entry);
    }

    // Close the diary file
    fclose(diary);
}

// Function to write a new diary entry
void write_diary() {
    // Open the diary file in write-only mode
    FILE *diary = fopen("diary.txt", "w");

    // Check if the diary file exists
    if (!diary) {
        printf("Error: Diary file not found!\n");
        return;
    }

    // Get the current date and time
    struct tm current_time;
    time_t now = time(0);
    localtime_r(&now, &current_time);

    // Format the date and entry text
    char date[20];
    strftime(date, sizeof(date), "%d-%m-%Y", &current_time);
    char entry[100];
    printf("What's your entry for %s? ", date);
    fgets(entry, sizeof(entry), stdin);

    // Write the diary entry
    fprintf(diary, "%s %s\n", date, entry);

    // Close the diary file
    fclose(diary);
}

int main() {
    // Call the read_diary function to read the diary entries
    read_diary();

    // Ask the user if they want to write a new diary entry
    printf("Do you want to write a new diary entry? (y/n): ");
    char response;
    scanf("%c", &response);

    // If the user responds with "y", call the write_diary function
    if (response == 'y') {
        write_diary();
    }

    return 0;
}