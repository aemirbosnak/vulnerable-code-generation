//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

struct entry {
    char *date;
    char *title;
    char *text;
};

void read_entries(struct entry *entries) {
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("Error reading diary file.\n");
        exit(1);
    }

    int count = 0;
    while (count < MAX_ENTRIES && fscanf(file, "%s %s %s\n", entries[count].date, entries[count].title, entries[count].text) == 3) {
        count++;
    }

    fclose(file);
}

void write_entry(struct entry *entries, int index, char *date, char *title, char *text) {
    strcpy(entries[index].date, date);
    strcpy(entries[index].title, title);
    strcpy(entries[index].text, text);
}

void sort_entries(struct entry *entries) {
    for (int i = 0; i < MAX_ENTRIES - 1; i++) {
        for (int j = i + 1; j < MAX_ENTRIES; j++) {
            if (strcmp(entries[i].date, entries[j].date) > 0) {
                struct entry temp = entries[i];
                entries[i] = entries[j];
                entries[j] = temp;
            }
        }
    }
}

int main() {
    struct entry entries[MAX_ENTRIES];

    read_entries(entries);

    char date[20];
    time_t now = time(NULL);
    strftime(date, 20, "%Y-%m-%d", localtime(&now));

    char title[MAX_ENTRY_LENGTH];
    printf("Enter title for new entry: ");
    scanf("%s", title);

    char text[MAX_ENTRY_LENGTH];
    printf("Enter text for new entry: ");
    scanf("%s", text);

    write_entry(entries, 0, date, title, text);

    sort_entries(entries);

    printf("Diary entries:\n");
    for (int i = 0; i < MAX_ENTRIES; i++) {
        printf("%s %s %s\n", entries[i].date, entries[i].title, entries[i].text);
    }

    return 0;
}