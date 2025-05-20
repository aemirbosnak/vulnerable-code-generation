//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum number of entries
#define MAX_ENTRIES 100

// Define the structure for a diary entry
typedef struct {
    int day; // Day of the month (1-31)
    int month; // Month (1-12)
    int year; // Year (4-digit)
    float temperature; // Temperature in Celsius
    float humidity; // Humidity as a percentage
    char note[50]; // User-entered note
} diary_entry;

// Function to read a diary entry from the user
void read_entry(diary_entry *entry) {
    // Prompt the user to enter the date
    printf("Enter the date (dd/mm/yy): ");
    // Read the day, month, and year separately
    scanf("%d/%d/%d", &entry->day, &entry->month, &entry->year);
    // Convert the temperature and humidity to floats
    scanf("%.1f %%C", &entry->temperature);
    scanf("%.1f %%", &entry->humidity);
    // Read the user-entered note
    fgets(entry->note, 50, stdin);
}

// Function to write a diary entry to the file
void write_entry(diary_entry *entry) {
    // Open the file in write mode
    FILE *file = fopen("diary.txt", "w");
    // Write the date and temperature to the file
    fprintf(file, "%d/%d/%d %.1f %%C\n", entry->day, entry->month, entry->year, entry->temperature);
    // Write the humidity and note to the file
    fprintf(file, "%.1f %%\n%s\n", entry->humidity, entry->note);
    // Close the file
    fclose(file);
}

// Function to display the diary entries
void display_entries() {
    // Open the file in read mode
    FILE *file = fopen("diary.txt", "r");
    // Read the contents of the file
    char line[100];
    while (fgets(line, 100, file)) {
        // Parse the line to extract the date and temperature
        int day, month, year;
        float temperature;
        sscanf(line, "%d/%d/%d %.1f %%C", &day, &month, &year, &temperature);
        // Print the date and temperature
        printf("%d/%d/%d %.1f %%C\n", day, month, year, temperature);
    }
    // Close the file
    fclose(file);
}

int main() {
    // Create an array to store the diary entries
    diary_entry entries[MAX_ENTRIES];
    // Initialize the array with zeros
    memset(entries, 0, sizeof(diary_entry) * MAX_ENTRIES);
    // Read the diary entries from the user
    for (int i = 0; i < MAX_ENTRIES; i++) {
        read_entry(&entries[i]);
    }
    // Write the diary entries to the file
    for (int i = 0; i < MAX_ENTRIES; i++) {
        write_entry(&entries[i]);
    }
    // Display the diary entries
    display_entries();
    return 0;
}