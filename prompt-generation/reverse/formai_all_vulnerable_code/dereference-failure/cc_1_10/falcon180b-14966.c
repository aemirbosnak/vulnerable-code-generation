//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s:\n%s\n\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    char buffer[MAX_ENTRY_LENGTH];
    char date[20];
    FILE* fp;

    time_t now = time(NULL);
    strftime(date, 20, "%Y-%m-%d", localtime(&now));

    printf("Digital Diary\n");
    printf("Enter your thoughts for today (%s):\n", date);

    fgets(buffer, MAX_ENTRY_LENGTH, stdin);
    add_entry(date, buffer);

    printf("Entry saved.\n");

    fp = fopen("diary.txt", "a");

    if (fp!= NULL) {
        fprintf(fp, "%s:%s\n", date, buffer);
        fclose(fp);
    } else {
        printf("Error saving to file.\n");
    }

    print_entries();

    return 0;
}