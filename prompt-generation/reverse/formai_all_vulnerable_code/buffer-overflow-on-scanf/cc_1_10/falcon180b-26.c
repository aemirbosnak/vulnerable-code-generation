//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_SIZE 1024

typedef struct {
    char date[32];
    char time[32];
    char entry[MAX_ENTRY_SIZE];
} diary_entry;

diary_entry diary[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }

    time_t now = time(NULL);
    struct tm* tm = localtime(&now);

    strftime(diary[num_entries].date, 32, "%Y-%m-%d", tm);
    strftime(diary[num_entries].time, 32, "%H:%M:%S", tm);

    printf("Enter your entry:\n");
    fgets(diary[num_entries].entry, MAX_ENTRY_SIZE, stdin);

    num_entries++;
}

void view_entries() {
    if (num_entries == 0) {
        printf("Diary is empty.\n");
        return;
    }

    for (int i = 0; i < num_entries; i++) {
        printf("%s %s\n%s\n", diary[i].date, diary[i].time, diary[i].entry);
    }
}

void delete_entry() {
    if (num_entries == 0) {
        printf("Diary is empty.\n");
        return;
    }

    int id;
    printf("Enter the ID of the entry you want to delete:\n");
    scanf("%d", &id);

    if (id >= num_entries || id < 0) {
        printf("Invalid ID.\n");
        return;
    }

    for (int i = id; i < num_entries - 1; i++) {
        memcpy(&diary[i], &diary[i+1], sizeof(diary_entry));
    }

    num_entries--;
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("Cyberpunk Digital Diary\n");
        printf("1. Add entry\n2. View entries\n3. Delete entry\n4. Exit\n");
        scanf("%d", &choice);

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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}