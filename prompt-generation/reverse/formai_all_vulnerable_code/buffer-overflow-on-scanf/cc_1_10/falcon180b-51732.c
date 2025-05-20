//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

struct entry {
    char date[20];
    char time[20];
    char content[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *file;
    int entry_count = 0;
    struct entry entries[MAX_ENTRIES];
    char filename[50] = "diary.txt";

    if ((file = fopen(filename, "r")) == NULL) {
        printf("File does not exist. Creating new file.\n");
        file = fopen(filename, "w");
    } else {
        fclose(file);
    }

    while (entry_count < MAX_ENTRIES) {
        printf("Enter a new diary entry:\n");
        scanf("%s", entries[entry_count].content);

        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        strftime(entries[entry_count].date, 20, "%Y-%m-%d", t);
        strftime(entries[entry_count].time, 20, "%H:%M:%S", t);

        entry_count++;
        entries[entry_count].content[0] = '\0';
    }

    file = fopen(filename, "a");

    for (int i = 0; i < entry_count; i++) {
        fprintf(file, "%s %s %s\n", entries[i].date, entries[i].time, entries[i].content);
    }

    fclose(file);

    return 0;
}