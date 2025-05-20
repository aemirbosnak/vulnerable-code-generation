//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[20];
    char entry[200];
} Entry;

Entry diary[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    strcpy(diary[num_entries].date, date);
    strcpy(diary[num_entries].entry, entry);
    num_entries++;
}

void display_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%s\n%s\n", diary[i].date, diary[i].entry);
    }
}

int main() {
    srand(time(0));

    int choice;
    char date[20];
    char entry[200];

    do {
        printf("Digital Diary\n");
        printf("1. Add Entry\n2. Display Entries\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Enter entry:\n");
                fgets(entry, sizeof(entry), stdin);
                add_entry(date, entry);
                break;
            case 2:
                display_entries();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}