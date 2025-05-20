//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_ENTRIES 100

typedef struct entry {
    char date[20];
    char time[10];
    char mood[20];
    char content[500];
} Entry;

void add_entry(Entry* diary, int num_entries) {
    time_t now = time(0);
    strftime(diary[num_entries].date, 20, "%Y-%m-%d", localtime(&now));
    strftime(diary[num_entries].time, 10, "%H:%M:%S", localtime(&now));
    printf("Enter your mood: ");
    scanf("%s", diary[num_entries].mood);
    printf("Enter your diary entry: ");
    scanf("%[^\n]", diary[num_entries].content);
    diary[num_entries].content[strcspn(diary[num_entries].content, "\n")] = '\0';
    num_entries++;
}

void display_entries(Entry* diary, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s - %s\n%s\n\n", diary[i].date, diary[i].time, diary[i].mood, diary[i].content);
    }
}

int main() {
    Entry diary[MAX_ENTRIES];
    int num_entries = 0;

    add_entry(diary, num_entries);

    while (num_entries < MAX_ENTRIES) {
        system("clear");
        printf("Digital Diary\n");
        printf("1. Add Entry\n2. Display Entries\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(diary, num_entries);
                break;
            case 2:
                display_entries(diary, num_entries);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}