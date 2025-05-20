//FormAI DATASET v1.0 Category: Digital Diary ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100 // maximum number of diary entries

// representing a single diary entry
struct DiaryEntry {
    char date[11]; // format: "dd/mm/yyyy"
    char time[6]; // format: "hh:mm"
    char text[500];
};

// diary data structure
struct Diary {
    int count; // number of entries
    struct DiaryEntry entries[MAX_ENTRIES]; // array of entries
};

// function prototypes
void printMainMenu();
int chooseMenuOption();
void printEntries(struct Diary* diary);
void addEntry(struct Diary* diary);
void editEntry(struct Diary* diary);
void deleteEntry(struct Diary* diary);
void searchEntries(struct Diary* diary);
void saveEntries(struct Diary* diary);
void loadEntries(struct Diary* diary);

int main() {
    struct Diary diary = {.count = 0}; // initialize empty diary

    while (1) {
        printMainMenu();
        int option = chooseMenuOption();

        switch (option) {
            case 1:
                printEntries(&diary);
                break;
            case 2:
                addEntry(&diary);
                break;
            case 3:
                editEntry(&diary);
                break;
            case 4:
                deleteEntry(&diary);
                break;
            case 5:
                searchEntries(&diary);
                break;
            case 6:
                saveEntries(&diary);
                break;
            case 7:
                loadEntries(&diary);
                break;
            case 8:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
}

// prints the main menu options
void printMainMenu() {
    printf("\n------------------------------\n");
    printf("       DIGITAL DIARY\n");
    printf("------------------------------\n");
    printf("1. View Entries\n");
    printf("2. Add Entry\n");
    printf("3. Edit Entry\n");
    printf("4. Delete Entry\n");
    printf("5. Search Entries\n");
    printf("6. Save Entries\n");
    printf("7. Load Entries\n");
    printf("8. Exit Program\n");
    printf("------------------------------\n");
}

// prompts the user to choose a menu option and returns the selected option
int chooseMenuOption() {
    printf("Please choose an option (1-8): ");
    int option;
    scanf("%d", &option);
    return option;
}

// prints all diary entries in chronological order
void printEntries(struct Diary* diary) {
    if (diary->count == 0) {
        printf("No entries found!\n");
        return;
    }

    printf("\n------------------------------\n");
    printf("         DIARY ENTRIES\n");
    printf("------------------------------\n");

    // sort entries by date and time (bubble sort)
    for (int i = 0; i < diary->count; i++) {
        for (int j = 0; j < diary->count - 1; j++) {
            struct DiaryEntry* entry1 = &diary->entries[j];
            struct DiaryEntry* entry2 = &diary->entries[j+1];

            // if entry2 is earlier than entry1, swap them
            if (strcmp(entry1->date, entry2->date) > 0
                || (strcmp(entry1->date, entry2->date) == 0 
                    && strcmp(entry1->time, entry2->time) > 0)) {
                struct DiaryEntry temp = *entry1;
                *entry1 = *entry2;
                *entry2 = temp;
            }
        }
    }

    // print entries
    for (int i = 0; i < diary->count; i++) {
        struct DiaryEntry* entry = &diary->entries[i];
        printf("%s %s\n%s\n\n", entry->date, entry->time, entry->text);
    }
}

// prompts the user to add a new diary entry
void addEntry(struct Diary* diary) {
    if (diary->count == MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    printf("\n------------------------------\n");
    printf("        ADD A NEW ENTRY\n");
    printf("------------------------------\n");

    // get current date and time
    time_t t = time(NULL);
    struct tm* now = localtime(&t);
    char date[11];
    char time[6];
    sprintf(date, "%02d/%02d/%d", now->tm_mday, now->tm_mon+1, now->tm_year+1900);
    sprintf(time, "%02d:%02d", now->tm_hour, now->tm_min);

    // prompt user for entry text
    printf("Enter your diary entry text (max 500 characters):\n");
    char text[500];
    fflush(stdin);
    fgets(text, sizeof(text), stdin);
    strtok(text, "\n"); // remove newline character if present

    // add new entry to diary
    struct DiaryEntry newEntry = {.date = "", .time = "", .text = ""};
    strcpy(newEntry.date, date);
    strcpy(newEntry.time, time);
    strcpy(newEntry.text, text);
    diary->entries[diary->count++] = newEntry;
    printf("Entry added successfully!\n");
}

// prompts the user to edit an existing diary entry
void editEntry(struct Diary* diary) {
    if (diary->count == 0) {
        printf("No entries found! Cannot edit.\n");
        return;
    }

    printf("\n------------------------------\n");
    printf("         EDIT AN ENTRY\n");
    printf("------------------------------\n");

    // prompt user to select an entry to edit
    printf("Please enter the number of the entry you want to edit:\n");
    for (int i = 0; i < diary->count; i++) {
        printf("%d. %s %s\n", i+1, diary->entries[i].date, diary->entries[i].time);
    }
    int selection;
    scanf("%d", &selection);

    // prompt user for new text
    printf("Enter the new text for this entry (max 500 characters):\n");
    char text[500];
    fflush(stdin);
    fgets(text, sizeof(text), stdin);
    strtok(text, "\n"); // remove newline character if present

    // update entry and display success message
    struct DiaryEntry* entry = &diary->entries[selection-1];
    strcpy(entry->text, text);
    printf("Entry edited successfully!\n");
}

// prompts the user to delete an existing diary entry
void deleteEntry(struct Diary* diary) {
    if (diary->count == 0) {
        printf("No entries found! Cannot delete.\n");
        return;
    }

    printf("\n------------------------------\n");
    printf("        DELETE AN ENTRY\n");
    printf("------------------------------\n");

    // prompt user to select an entry to delete
    printf("Please enter the number of the entry you want to delete:\n");
    for (int i = 0; i < diary->count; i++) {
        printf("%d. %s %s\n", i+1, diary->entries[i].date, diary->entries[i].time);
    }
    int selection;
    scanf("%d", &selection);

    // move all entries after the deleted entry up by one index
    for (int i = selection-1; i < diary->count-1; i++) {
        diary->entries[i] = diary->entries[i+1];
    }
    diary->count--;
    printf("Entry deleted successfully!\n");
}

// prompts the user to search for diary entries that contain a certain string
void searchEntries(struct Diary* diary) {
    if (diary->count == 0) {
        printf("No entries found! Cannot search.\n");
        return;
    }

    printf("\n------------------------------\n");
    printf("         SEARCH ENTRIES\n");
    printf("------------------------------\n");

    // prompt user for search string
    printf("Enter the search string:\n");
    char searchString[100];
    fflush(stdin);
    fgets(searchString, sizeof(searchString), stdin);
    strtok(searchString, "\n"); // remove newline character if present

    // search for entries containing the search string and print them
    int foundCount = 0;
    for (int i = 0; i < diary->count; i++) {
        struct DiaryEntry* entry = &diary->entries[i];
        if (strstr(entry->text, searchString) != NULL) {
            printf("%s %s\n%s\n\n", entry->date, entry->time, entry->text);
            foundCount++;
        }
    }
    if (foundCount == 0) {
        printf("No entries found containing the search string '%s'\n", searchString);
    } else {
        printf("%d entries found containing the search string '%s'\n", foundCount, searchString);
    }
}

// saves all diary entries to a file
void saveEntries(struct Diary* diary) {
    if (diary->count == 0) {
        printf("No entries found! Cannot save.\n");
        return;
    }

    printf("\n------------------------------\n");
    printf("          SAVE ENTRIES\n");
    printf("------------------------------\n");

    // prompt user for filename
    printf("Enter the filename to save the entries to:\n");
    char filename[100];
    fflush(stdin);
    fgets(filename, sizeof(filename), stdin);
    strtok(filename, "\n"); // remove newline character if present

    // open file for writing and write the entries
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Unable to open file for writing!\n");
        return;
    }
    fprintf(file, "%d\n", diary->count);
    for (int i = 0; i < diary->count; i++) {
        struct DiaryEntry* entry = &diary->entries[i];
        fprintf(file, "%s %s\n%s\n", entry->date, entry->time, entry->text);
    }
    fclose(file);
    printf("Entries saved successfully to '%s'!\n", filename);
}

// loads diary entries from a file
void loadEntries(struct Diary* diary) {
    printf("\n------------------------------\n");
    printf("          LOAD ENTRIES\n");
    printf("------------------------------\n");

    // prompt user for filename
    printf("Enter the filename to load the entries from:\n");
    char filename[100];
    fflush(stdin);
    fgets(filename, sizeof(filename), stdin);
    strtok(filename, "\n"); // remove newline character if present

    // open file for reading and read the entries
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file for reading!\n");
        return;
    }
    int count;
    fscanf(file, "%d", &count);
    diary->count = 0;
    for (int i = 0; i < count; i++) {
        char date[11];
        char time[6];
        char text[500];
        fscanf(file, "%s %s\n%[^\n]s", date, time, text);
        struct DiaryEntry newEntry = {.date = "", .time = "", .text = ""};
        strcpy(newEntry.date, date);
        strcpy(newEntry.time, time);
        strcpy(newEntry.text, text);
        diary->entries[diary->count++] = newEntry;
    }
    fclose(file);
    printf("Entries loaded successfully from '%s'!\n", filename);
}