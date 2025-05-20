//FormAI DATASET v1.0 Category: Digital Diary ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

// a struct to hold diary entries
typedef struct {
    char date[20];
    char entry[1000];
} DiaryEntry;

// a struct to hold user configuration
typedef struct {
    char name[50];
    char password[50];
    int max_entries;
} UserConfig;

// function prototypes
void login(UserConfig *config);
int menu();
void add_entry(DiaryEntry diary[], int *num_entries, int max_entries);
void view_entries(DiaryEntry diary[], int num_entries);
void save_entries(DiaryEntry diary[], int num_entries, UserConfig config);

int main() {
    srand(time(NULL)); // seed for random dates

    UserConfig config = {"", "", MAX_ENTRIES};
    login(&config); // prompt user for name and password

    DiaryEntry diary[MAX_ENTRIES];
    int num_entries = 0;

    int choice;
    do {
        choice = menu(); // display menu and get user choice

        switch (choice) {
            case 1: // add entry
                add_entry(diary, &num_entries, config.max_entries);
                break;
            case 2: // view entries
                view_entries(diary, num_entries);
                break;
            case 3: // save entries
                save_entries(diary, num_entries, config);
                printf("Entries saved successfully!\n");
                break;
            case 4: // exit
                printf("Goodbye %s!\n", config.name);
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// prompt user for name and password
void login(UserConfig *config) {
    printf("Please enter your name: ");
    fgets(config->name, 50, stdin);
    config->name[strcspn(config->name, "\n")] = 0; // remove newline character

    printf("Please enter your password: ");
    fgets(config->password, 50, stdin);
    config->password[strcspn(config->password, "\n")] = 0; // remove newline character
}

// display menu and get user choice
int menu() {
    printf("\n");
    printf("1. Add entry\n");
    printf("2. View entries\n");
    printf("3. Save entries\n");
    printf("4. Exit\n");
    printf("Please enter your choice: ");

    int choice;
    scanf("%d", &choice);
    getchar(); // consume newline character
    printf("\n");
    return choice;
}

// add entry to diary
void add_entry(DiaryEntry diary[], int *num_entries, int max_entries) {
    if (*num_entries >= max_entries) {
        printf("You have reached the maximum number of entries!\n");
        return;
    }

    DiaryEntry entry;

    // generate random date
    int day = rand() % 31 + 1;
    int month = rand() % 12 + 1;
    int year = rand() % 20 + 2000;
    sprintf(entry.date, "%02d/%02d/%d", day, month, year);

    printf("Please enter your entry: ");
    fgets(entry.entry, 1000, stdin);
    entry.entry[strcspn(entry.entry, "\n")] = 0; // remove newline character

    diary[*num_entries] = entry;
    *num_entries += 1;

    printf("Entry added successfully!\n");
}

// view all entries in diary
void view_entries(DiaryEntry diary[], int num_entries) {
    if (num_entries == 0) {
        printf("No entries found!\n");
        return;
    }
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n", diary[i].date);
        printf("%s\n", diary[i].entry);
        printf("\n");
    }
}

// save all entries to file
void save_entries(DiaryEntry diary[], int num_entries, UserConfig config) {
    char filename[100];
    sprintf(filename, "%s_diary.txt", config.name);

    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(fp, "Name: %s\n", config.name);
    fprintf(fp, "Password: %s\n\n", config.password);

    for (int i = 0; i < num_entries; i++) {
        fprintf(fp, "%s\n", diary[i].date);
        fprintf(fp, "%s\n\n", diary[i].entry);
    }

    fclose(fp);
}