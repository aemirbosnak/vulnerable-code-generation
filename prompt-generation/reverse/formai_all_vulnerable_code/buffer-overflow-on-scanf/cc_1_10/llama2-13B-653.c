//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a struct to represent a diary entry
struct diary_entry {
    int date; // date of the entry (YYYY-MM-DD)
    double temperature; // temperature in Celsius
    int humidity; // humidity as a percentage
    char description[100]; // brief description of the day
};

// Define a function to read a diary entry from the user
void read_entry(struct diary_entry *entry) {
    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%d", &entry->date);
    printf("Enter the temperature (C): ");
    scanf("%.1f", &entry->temperature);
    printf("Enter the humidity (%): ");
    scanf("%d", &entry->humidity);
    printf("Enter a brief description of the day: ");
    fgets(entry->description, 100, stdin);
}

// Define a function to write a diary entry to a file
void write_entry(struct diary_entry *entry, FILE *file) {
    fprintf(file, "%d-%d-%d", entry->date, entry->temperature, entry->humidity);
    fprintf(file, "%s\n", entry->description);
}

// Define the main function
int main() {
    // Create a diary file
    FILE *diary = fopen("diary.txt", "w");
    if (diary == NULL) {
        perror("Error opening diary file");
        return 1;
    }

    // Create a struct to represent the current diary entry
    struct diary_entry current_entry;

    // Read the current entry from the user
    read_entry(&current_entry);

    // Write the current entry to the diary file
    write_entry(&current_entry, diary);

    // Close the diary file
    fclose(diary);

    // Print a message to the user
    printf("Diary entry recorded.\n");

    // Ask the user if they want to add another entry
    printf("Do you want to add another entry? (y/n): ");
    char response;
    scanf(" %c", &response);

    // If the user wants to add another entry, read another entry and write it to the file
    if (response == 'y') {
        // Read the next entry from the user
        read_entry(&current_entry);

        // Write the current entry to the diary file
        write_entry(&current_entry, diary);
    }

    return 0;
}