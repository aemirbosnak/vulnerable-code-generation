//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 500
#define MAX_TAGS 10

typedef struct {
    char title[MAX_ENTRY_LENGTH];
    char content[MAX_ENTRY_LENGTH];
    time_t timestamp;
    int tags[MAX_TAGS];
    int tag_count;
} Entry;

void read_entries(Entry entries[], int count) {
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open diary.txt\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s %s %ld %d", entries[i].title, entries[i].content, &entries[i].timestamp, entries[i].tags) == 4) {
        entries[i].tag_count = entries[i].tag_count + count_tags(entries[i].tags);
        i++;
    }

    fclose(file);
}

int count_tags(int tags[]) {
    int count = 0;
    for (int i = 0; i < MAX_TAGS; i++) {
        if (tags[i]!= 0) {
            count++;
        }
    }
    return count;
}

void write_entry(Entry entry) {
    FILE *file = fopen("diary.txt", "a");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open diary.txt\n");
        exit(1);
    }

    fprintf(file, "%s %s %ld %d", entry.title, entry.content, entry.timestamp, entry.tag_count);
    for (int i = 0; i < entry.tag_count; i++) {
        fprintf(file, " %d", entry.tags[i]);
    }
    fprintf(file, "\n");

    fclose(file);
}

void add_tag(Entry *entry, int tag) {
    for (int i = 0; i < entry->tag_count; i++) {
        if (entry->tags[i] == tag) {
            return;
        }
    }

    if (entry->tag_count >= MAX_TAGS) {
        fprintf(stderr, "Error: too many tags\n");
        exit(1);
    }

    entry->tags[entry->tag_count++] = tag;
}

int main() {
    Entry entries[MAX_ENTRIES];
    int count = 0;

    read_entries(entries, count);

    char title[MAX_ENTRY_LENGTH];
    char content[MAX_ENTRY_LENGTH];
    int tags[MAX_TAGS];
    int tag_count = 0;

    while (1) {
        printf("Enter a title: ");
        fgets(title, MAX_ENTRY_LENGTH, stdin);
        title[strcspn(title, "\n")] = '\0';

        printf("Enter content: ");
        fgets(content, MAX_ENTRY_LENGTH, stdin);
        content[strcspn(content, "\n")] = '\0';

        int tag;
        printf("Enter tags (separated by spaces): ");
        while (scanf("%d", &tag) == 1) {
            add_tag(&entries[count], tag);
        }

        write_entry(entries[count++]);

        if (count >= MAX_ENTRIES) {
            fprintf(stderr, "Error: too many entries\n");
            exit(1);
        }
    }

    return 0;
}