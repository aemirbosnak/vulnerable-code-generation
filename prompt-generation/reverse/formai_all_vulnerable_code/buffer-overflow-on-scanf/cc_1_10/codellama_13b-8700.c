//Code Llama-13B DATASET v1.0 Category: Data mining ; Style: Cyberpunk
// Cyberpunk-style Data Mining Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_STRING_LEN 100

// Struct to represent a data entry
typedef struct {
    char string[MAX_STRING_LEN];
    int number;
} data_entry;

// Function to read a data entry from the user
data_entry read_entry() {
    data_entry entry;
    printf("Enter a string: ");
    scanf("%s", entry.string);
    printf("Enter a number: ");
    scanf("%d", &entry.number);
    return entry;
}

// Function to print a data entry
void print_entry(data_entry entry) {
    printf("String: %s\nNumber: %d\n", entry.string, entry.number);
}

// Function to sort the data entries by number
void sort_by_number(data_entry entries[], int num_entries) {
    for (int i = 0; i < num_entries - 1; i++) {
        for (int j = i + 1; j < num_entries; j++) {
            if (entries[i].number > entries[j].number) {
                data_entry temp = entries[i];
                entries[i] = entries[j];
                entries[j] = temp;
            }
        }
    }
}

// Function to sort the data entries by string
void sort_by_string(data_entry entries[], int num_entries) {
    for (int i = 0; i < num_entries - 1; i++) {
        for (int j = i + 1; j < num_entries; j++) {
            if (strcmp(entries[i].string, entries[j].string) > 0) {
                data_entry temp = entries[i];
                entries[i] = entries[j];
                entries[j] = temp;
            }
        }
    }
}

// Function to find the minimum and maximum values of the data entries
void min_max(data_entry entries[], int num_entries, int* min, int* max) {
    *min = entries[0].number;
    *max = entries[0].number;
    for (int i = 1; i < num_entries; i++) {
        if (entries[i].number < *min) {
            *min = entries[i].number;
        } else if (entries[i].number > *max) {
            *max = entries[i].number;
        }
    }
}

// Function to find the average of the data entries
double average(data_entry entries[], int num_entries) {
    int sum = 0;
    for (int i = 0; i < num_entries; i++) {
        sum += entries[i].number;
    }
    return (double) sum / num_entries;
}

int main() {
    // Initialize the data entries
    data_entry entries[MAX_ENTRIES];
    int num_entries = 0;

    // Read the data entries from the user
    while (num_entries < MAX_ENTRIES) {
        data_entry entry = read_entry();
        entries[num_entries++] = entry;
    }

    // Sort the data entries by number and print them
    sort_by_number(entries, num_entries);
    printf("Sorted by number:\n");
    for (int i = 0; i < num_entries; i++) {
        print_entry(entries[i]);
    }

    // Sort the data entries by string and print them
    sort_by_string(entries, num_entries);
    printf("Sorted by string:\n");
    for (int i = 0; i < num_entries; i++) {
        print_entry(entries[i]);
    }

    // Find the minimum and maximum values of the data entries
    int min, max;
    min_max(entries, num_entries, &min, &max);
    printf("Minimum: %d\nMaximum: %d\n", min, max);

    // Find the average of the data entries
    double avg = average(entries, num_entries);
    printf("Average: %.2f\n", avg);

    return 0;
}