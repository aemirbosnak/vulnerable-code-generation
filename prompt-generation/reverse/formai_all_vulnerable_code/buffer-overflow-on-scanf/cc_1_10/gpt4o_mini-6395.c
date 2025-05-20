//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 100

typedef struct {
    char name[NAME_LENGTH];
    int steps;
    float distance; // in kilometers
    int calories; // burned calories
    time_t date; // timestamp
} Entry;

Entry entries[MAX_ENTRIES];
int entry_count = 0;

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("No more entries can be added!\n");
        return;
    }
    Entry new_entry;
    
    printf("Enter your name: ");
    fgets(new_entry.name, NAME_LENGTH, stdin);
    new_entry.name[strcspn(new_entry.name, "\n")] = 0; // Remove newline character

    printf("Enter steps taken: ");
    scanf("%d", &new_entry.steps);

    printf("Enter distance traveled (in km): ");
    scanf("%f", &new_entry.distance);

    printf("Enter calories burned: ");
    scanf("%d", &new_entry.calories);
    
    new_entry.date = time(NULL);
    
    entries[entry_count++] = new_entry;

    printf("\nEntry added successfully!\n");
}

void view_entries() {
    if (entry_count == 0) {
        printf("No entries to display.\n");
        return;
    }

    printf("\nFitness Tracker Entries:\n");
    printf("=================================================================\n");
    printf("| %-20s | %-7s | %-11s | %-8s | %-20s |\n", "Name", "Steps", "Distance", "Calories", "Date");
    printf("=================================================================\n");

    for (int i = 0; i < entry_count; i++) {
        char date_str[20];
        struct tm *tm_info = localtime(&entries[i].date);
        strftime(date_str, sizeof(date_str), "%Y-%m-%d %H:%M:%S", tm_info);
        printf("| %-20s | %-7d | %-11.2f | %-8d | %-20s |\n",
               entries[i].name, entries[i].steps, entries[i].distance, entries[i].calories, date_str);
    }

    printf("=================================================================\n");
}

void delete_entry() {
    if (entry_count == 0) {
        printf("No entries to delete.\n");
        return;
    }

    int index;
    printf("Enter the index of the entry to delete (0 to %d): ", entry_count - 1);
    scanf("%d", &index);

    if (index < 0 || index >= entry_count) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index; i < entry_count - 1; i++) {
        entries[i] = entries[i + 1];
    }
    entry_count--;

    printf("Entry deleted successfully!\n");
}

void menu() {
    int choice;

    while (1) {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice! Please try again.\n");
            while(getchar() != '\n'); // clear input buffer
            continue;
        }
        
        getchar(); // Consume newline left by scanf
        
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                printf("Exiting Fitness Tracker...\n");
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}