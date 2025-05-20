//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000

struct entry {
    char date[11];
    char time[9];
    char text[4096];
};

void add_entry(struct entry *diary, int num_entries, char *date, char *time, char *text) {
    strcpy(diary[num_entries].date, date);
    strcpy(diary[num_entries].time, time);
    strcpy(diary[num_entries].text, text);
}

void display_entries(struct entry *diary, int num_entries) {
    int i;
    for(i=0; i<num_entries; i++) {
        printf("%s %s:\n%s\n\n", diary[i].date, diary[i].time, diary[i].text);
    }
}

int main() {
    struct entry diary[MAX_ENTRIES];
    int num_entries = 0;

    char input[4096];
    char date[11];
    char time[9];
    char author[32];

    while(1) {
        printf("Digital Diary\n");
        printf("--------------------\n");
        printf("1. Add entry\n");
        printf("2. Display entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &num_entries);

        switch(num_entries) {
            case 1:
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Enter time (HH:MM:SS): ");
                scanf("%s", time);
                printf("Enter author name: ");
                scanf("%s", author);
                printf("Enter your entry:\n");
                fgets(input, 4096, stdin);
                input[strcspn(input, "\n")] = '\0';
                add_entry(diary, num_entries-1, date, time, input);
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