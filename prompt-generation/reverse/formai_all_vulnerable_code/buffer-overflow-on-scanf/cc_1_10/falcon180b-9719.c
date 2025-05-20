//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000

struct entry {
    time_t timestamp;
    char message[1024];
};

void add_entry(struct entry* diary, int count, char* message) {
    if (count >= MAX_ENTRIES) {
        printf("Diary is full. Cannot add more entries.\n");
        return;
    }

    time(&diary[count].timestamp);
    strncpy(diary[count].message, message, 1024);
    printf("Entry added:\n%s\n", diary[count].message);
}

void view_entry(struct entry* diary, int count) {
    if (count < 0 || count >= MAX_ENTRIES) {
        printf("Invalid entry number.\n");
        return;
    }

    printf("Timestamp: %s\nMessage:\n%s\n", ctime(&diary[count].timestamp), diary[count].message);
}

void view_all_entries(struct entry* diary) {
    int i;

    for (i = 0; i < MAX_ENTRIES; i++) {
        if (diary[i].message[0]!= '\0') {
            printf("Entry %d:\n", i+1);
            view_entry(diary, i);
            printf("\n");
        }
    }
}

int main() {
    struct entry diary[MAX_ENTRIES];
    int choice, count = 0;

    srand(time(NULL));

    while (1) {
        printf("Digital Diary\n");
        printf("1. Add Entry\n2. View Entries\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your message:\n");
                scanf("%[^\n]s", diary[count].message);
                add_entry(diary, count++, diary[count-1].message);
                break;
            case 2:
                view_all_entries(diary);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}