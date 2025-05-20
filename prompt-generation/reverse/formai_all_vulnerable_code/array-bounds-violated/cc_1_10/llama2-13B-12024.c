//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the structure to store the diary entries
typedef struct {
    int day;    // Day of the month (1-31)
    int month;   // Month of the year (1-12)
    int year;    // Year (4-digit)
    double entry; // Entry for the day
} diary_entry;

// Define an array to store the diary entries
diary_entry diary[31][12][4];

// Function to add a new diary entry
void add_entry(int day, int month, int year, double entry) {
    // Calculate the index of the current entry
    int index = (day - 1) * 12 * 4 + month * 12 * 4 + year * 12 * 4;

    // Check if the index is within the bounds of the array
    if (index >= 0 && index < 31 * 12 * 4) {
        diary[day][month][year].entry = entry;
    } else {
        printf("Error: Index out of bounds\n");
    }
}

// Function to display all diary entries for a given day
void display_day(int day) {
    // Calculate the index of the current day
    int index = day * 12 * 4;

    // Check if the index is within the bounds of the array
    if (index >= 0 && index < 31 * 12 * 4) {
        printf("Day %d:\n", day);
        for (int month = 1; month <= 12; month++) {
            for (int year = 4; year <= 99; year++) {
                printf("%.2f: %f\n", (month * 12 * 4) + (year * 12 * 4) + index, diary[day][month][year].entry);
            }
        }
    } else {
        printf("Error: Index out of bounds\n");
    }
}

int main() {
    // Add some diary entries
    add_entry(1, 5, 2022, 3.14);
    add_entry(3, 7, 2022, 2.71);
    add_entry(15, 10, 2022, 1.23);

    // Display all diary entries for March 15, 2022
    display_day(15);

    return 0;
}