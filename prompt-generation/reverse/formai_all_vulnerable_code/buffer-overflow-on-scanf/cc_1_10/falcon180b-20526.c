//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[20];
    char entry[200];
} diary_entry;

void add_entry(diary_entry diary[], int num_entries) {
    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", diary[num_entries].date);
    printf("Enter your diary entry:\n");
    fgets(diary[num_entries].entry, 200, stdin);
    diary[num_entries].entry[strcspn(diary[num_entries].entry, "\n")] = '\0'; // Remove newline character
    num_entries++;
}

void view_entries(diary_entry diary[], int num_entries) {
    printf("Your Diary:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", diary[i].date, diary[i].entry);
    }
}

void search_entries(diary_entry diary[], int num_entries) {
    char search_date[20];
    printf("Enter the date to search (YYYY-MM-DD): ");
    scanf("%s", search_date);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(diary[i].date, search_date) == 0) {
            printf("%s: %s\n", diary[i].date, diary[i].entry);
        }
    }
}

void delete_entry(diary_entry diary[], int num_entries) {
    char delete_date[20];
    printf("Enter the date to delete (YYYY-MM-DD): ");
    scanf("%s", delete_date);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(diary[i].date, delete_date) == 0) {
            for (int j = i; j < num_entries - 1; j++) {
                diary[j] = diary[j + 1];
            }
            num_entries--;
            break;
        }
    }
}

int main() {
    diary_entry diary[MAX_ENTRIES];
    int num_entries = 0;

    srand(time(NULL));
    diary[num_entries].date[0] = '\0';

    while (num_entries < MAX_ENTRIES) {
        int choice = rand() % 4;
        switch (choice) {
            case 0:
                add_entry(diary, num_entries);
                break;
            case 1:
                view_entries(diary, num_entries);
                break;
            case 2:
                search_entries(diary, num_entries);
                break;
            case 3:
                delete_entry(diary, num_entries);
                break;
        }
    }

    return 0;
}