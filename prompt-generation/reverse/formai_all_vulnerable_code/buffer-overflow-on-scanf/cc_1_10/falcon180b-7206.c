//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define ENTRY_LENGTH 1024

struct entry {
    time_t timestamp;
    char content[ENTRY_LENGTH];
};

FILE *diary_file;
char diary_filename[50] = "diary.txt";
int entry_count = 0;

void init_diary() {
    diary_file = fopen(diary_filename, "a+");
    if (diary_file == NULL) {
        printf("Error: Could not open diary file.\n");
        exit(1);
    }
}

void write_entry(const char *content) {
    struct entry entry;
    time_t now = time(NULL);
    strftime(entry.content, ENTRY_LENGTH, "%Y-%m-%d %H:%M:%S", localtime(&now));
    strcat(entry.content, " ");
    strcat(entry.content, content);
    fwrite(&entry, sizeof(struct entry), 1, diary_file);
    fflush(diary_file);
    entry_count++;
}

void read_entries() {
    rewind(diary_file);
    while (entry_count > 0) {
        struct entry entry;
        fread(&entry, sizeof(struct entry), 1, diary_file);
        printf("%s\n", entry.content);
        entry_count--;
    }
}

void destroy_diary() {
    fclose(diary_file);
}

int main() {
    init_diary();

    char command[50];
    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "write") == 0) {
            char content[ENTRY_LENGTH];
            printf("Enter your diary entry:\n");
            scanf("%s", content);
            write_entry(content);
        } else if (strcmp(command, "read") == 0) {
            read_entries();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    destroy_diary();
    return 0;
}