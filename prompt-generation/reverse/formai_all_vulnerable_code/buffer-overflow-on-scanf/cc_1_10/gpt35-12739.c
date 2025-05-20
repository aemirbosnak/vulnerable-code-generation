//FormAI DATASET v1.0 Category: Digital Diary ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void show_menu();
void add_entry();
void view_entries();
void search_entry();
void delete_entry();

// Global variable declaration
int entry_counter = 0;

// Structure definition
struct Entry {
    int day;
    int month;
    int year;
    char content[1000];
} diary[1000];

int main() {
    int choice;

    printf("Welcome to your Digital Diary\n");
    printf("Please enter today's date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &diary[entry_counter].day, &diary[entry_counter].month, &diary[entry_counter].year);
    printf("\n");

    do {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                delete_entry();
                break;
            case 5:
                printf("Thank you for using the Digital Diary. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 5);

    return 0;
}

// Function definitions

// Shows the main menu
void show_menu() {
    printf("---------- Main Menu ----------\n");
    printf("1. Add entry\n");
    printf("2. View entries\n");
    printf("3. Search entry\n");
    printf("4. Delete entry\n");
    printf("5. Quit\n");
    printf("------------------------------\n");
}

// Adds a new entry to the diary
void add_entry() {
    printf("Enter your diary entry (max 1000 characters):\n");
    fflush(stdin);
    fgets(diary[entry_counter].content, 1000, stdin);

    printf("\nEntry added successfully.\n");
    entry_counter++;
}

// Displays all the entries in the diary
void view_entries() {
    if (entry_counter == 0) {
        printf("There are no entries in the diary.\n");
        return;
    }

    printf("---------- Diary Entries ----------\n");
    for (int i = 0; i < entry_counter; i++) {
        printf("%d/%d/%d:\n%s\n", diary[i].day, diary[i].month, diary[i].year, diary[i].content);
        printf("----------------------------------\n");
    }
}

// Searches for an entry in the diary
void search_entry() {
    if (entry_counter == 0) {
        printf("There are no entries in the diary.\n");
        return;
    }

    int count = 0, search_day, search_month, search_year;
    printf("Enter the date you want to search for (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &search_day, &search_month, &search_year);

    for (int i = 0; i < entry_counter; i++) {
        if (diary[i].day == search_day && diary[i].month == search_month && diary[i].year == search_year) {
            printf("%d/%d/%d:\n%s\n", diary[i].day, diary[i].month, diary[i].year, diary[i].content);
            count++;
        }
    }

    if (count == 0) {
        printf("No entries found for the given date.\n");
    }
}

// Deletes an entry from the diary
void delete_entry() {
    if (entry_counter == 0) {
        printf("There are no entries in the diary.\n");
        return;
    }

    int delete_day, delete_month, delete_year;
    printf("Enter the date of the entry you want to delete (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &delete_day, &delete_month, &delete_year);

    int found = -1;
    for (int i = 0; i < entry_counter; i++) {
        if (diary[i].day == delete_day && diary[i].month == delete_month && diary[i].year == delete_year) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("No entries found for the given date.\n");
    } else {
        for (int i = found; i < entry_counter - 1; i++) {
            diary[i] = diary[i + 1];
        }

        entry_counter--;
        printf("Entry deleted successfully.\n");
    }
}