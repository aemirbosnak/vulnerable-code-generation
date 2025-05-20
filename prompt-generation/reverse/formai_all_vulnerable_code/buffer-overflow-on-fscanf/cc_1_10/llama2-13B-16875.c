//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a structure to represent a diary entry
struct diary_entry {
    int day;  // day of the month (1-31)
    int month; // month of the year (1-12)
    int year;  // year (4-digit)
    double temperature; // in Celsius
    double precipitation; // in millimeters
};

// Define a function to calculate the average temperature and precipitation
// for a given month and year
void calculate_averages(struct diary_entry *entries, int num_entries, int month, int year) {
    int i;
    double total_temperature = 0;
    double total_precipitation = 0;
    for (i = 0; i < num_entries; i++) {
        if (entries[i].month == month && entries[i].year == year) {
            total_temperature += entries[i].temperature;
            total_precipitation += entries[i].precipitation;
        }
    }
    if (num_entries > 0) {
        entries[0].temperature = total_temperature / num_entries;
        entries[0].precipitation = total_precipitation / num_entries;
    }
}

// Define a function to read and write diary entries from a file
void read_write_diary(struct diary_entry *entries, int num_entries, char *filename) {
    int i;
    FILE *file;
    if ((file = fopen(filename, "r")) == NULL) {
        perror("Failed to open file");
        return;
    }
    for (i = 0; i < num_entries; i++) {
        fscanf(file, "%d %d %d %lf %lf", &entries[i].day, &entries[i].month, &entries[i].year, &entries[i].temperature, &entries[i].precipitation);
    }
    fclose(file);
}

// Define the main function
int main() {
    int num_entries = 12;  // number of diary entries to read and write
    struct diary_entry entries[num_entries];
    char filename[] = "diary.dat";  // file name to read and write

    // Read diary entries from file
    read_write_diary(entries, num_entries, filename);

    // Calculate average temperatures and precipitation for each month
    for (int month = 1; month <= 12; month++) {
        calculate_averages(entries, num_entries, month, entries[0].year);
    }

    // Print the averages for each month
    for (int month = 1; month <= 12; month++) {
        printf("Average temperature for %d: %0.2f\n", month, entries[month].temperature);
        printf("Average precipitation for %d: %0.2f\n", month, entries[month].precipitation);
    }

    return 0;
}