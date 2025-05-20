//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRY_LENGTH 1024
#define MAX_ENTRIES 100

struct entry {
    time_t timestamp;
    char text[MAX_ENTRY_LENGTH];
};

FILE *diary_file;

void init_diary() {
    diary_file = fopen("diary.txt", "w+");
    if (diary_file == NULL) {
        printf("Error: could not create diary file.\n");
        exit(1);
    }
}

int read_entries(struct entry *entries) {
    int num_entries = 0;
    rewind(diary_file);
    while (fscanf(diary_file, "%d %s\n", &entries[num_entries].timestamp, entries[num_entries].text) == 2) {
        num_entries++;
        if (num_entries >= MAX_ENTRIES) {
            break;
        }
    }
    return num_entries;
}

void write_entry(const char *text) {
    time_t now = time(NULL);
    fprintf(diary_file, "%d %s\n", now, text);
    fflush(diary_file);
}

void print_entries(const struct entry *entries, int num_entries) {
    printf("Diary entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", ctime(&entries[i].timestamp), entries[i].text);
    }
}

int main() {
    init_diary();
    struct entry entries[MAX_ENTRIES];
    int num_entries = read_entries(entries);

    while (1) {
        printf("Enter your thoughts: ");
        char input[MAX_ENTRY_LENGTH];
        fgets(input, MAX_ENTRY_LENGTH, stdin);
        write_entry(input);

        print_entries(entries, num_entries);
    }

    return 0;
}