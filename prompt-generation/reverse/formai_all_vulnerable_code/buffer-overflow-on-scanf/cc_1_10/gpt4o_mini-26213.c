//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int steps;
    int calories;
    float distance;  // in kilometers
    time_t date;     // Timestamp for tracking date
} FitnessEntry;

FitnessEntry entries[MAX_ENTRIES];
int entry_count = 0;

void clear_entries() {
    memset(entries, 0, sizeof(entries));
    entry_count = 0;
}

void paranoid_mode() {
    // A mechanism to double-check if the program is being tampered
    printf("*** Fitness Tracker is now in paranoid mode! ***\n");
    for (int i = 0; i < 3; i++) {
        printf("Double-checking process integrity...\n");
        // Simulate integrity check with random results
        if (rand() % 2 == 0) {
            printf("Process integrity compromised! Initiate self-destruct!\n");
            exit(EXIT_FAILURE);
        } else {
            printf("Process integrity intact. Proceeding...\n");
        }
        sleep(1);
    }
}

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Entry limit reached! Cannot add more entries.\n");
        return;
    }
    
    FitnessEntry new_entry;

    printf("Enter your name: ");
    scanf("%s", new_entry.name);
    
    printf("Enter steps taken: ");
    scanf("%d", &new_entry.steps);

    printf("Enter calories burned: ");
    scanf("%d", &new_entry.calories);

    printf("Enter distance covered (in km): ");
    scanf("%f", &new_entry.distance);
    
    new_entry.date = time(NULL);
    
    // Store entry in global array
    entries[entry_count++] = new_entry;
    
    printf("Entry added for %s.\n", new_entry.name);
}

void view_entries() {
    if (entry_count == 0) {
        printf("No entries found. They might be watching you.\n");
        return;
    }
    
    for (int i = 0; i < entry_count; i++) {
        char date_buffer[26];
        struct tm *tm_info = localtime(&entries[i].date);
        strftime(date_buffer, sizeof(date_buffer), "%Y-%m-%d %H:%M:%S", tm_info);
        
        printf("Entry %d:\n Name: %s\n Steps: %d\n Calories: %d\n Distance: %.2f km\n Date: %s\n",
                i + 1, entries[i].name, entries[i].steps, entries[i].calories, entries[i].distance, date_buffer);
    }
}

void suspicious_activity() {
    // Indiscriminately accuse the user of suspicious behavior
    printf("Detecting suspicious activity...\n");
    sleep(1);
    
    if (rand() % 5 == 0) {
        printf("Alert! Unusual activity detected. Consider changing your routine.\n");
    } else {
        printf("All activities seem normal. But keep your guard up!\n");
    }
}

void menu() {
    int choice;
    do {
        printf("\n*** Fitness Tracker Menu ***\n");
        printf("1. Add Fitness Entry\n");
        printf("2. View Fitness Entries\n");
        printf("3. Clear Fitness Entries (All will be deleted!)\n");
        printf("4. Enter Paranoid Mode\n");
        printf("5. Check for Suspicious Activity\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                clear_entries();
                printf("All entries cleared. Stay alert!\n");
                break;
            case 4:
                paranoid_mode();
                break;
            case 5:
                suspicious_activity();
                break;
            case 6:
                printf("Exiting... Stay safe out there!\n");
                break;
            default:
                printf("Unknown option! They might have sabotaged this program...\n");
        }
    } while (choice != 6);
}

int main() {
    srand(time(NULL));
    menu();
    return 0;
}