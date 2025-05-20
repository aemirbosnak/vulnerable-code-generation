//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct entry {
    char date[20];
    char time[20];
    char content[500];
};

void write_entry(struct entry* entry, char* date, char* time, char* content) {
    strcpy(entry->date, date);
    strcpy(entry->time, time);
    strcpy(entry->content, content);
}

void read_entry(struct entry* entry) {
    printf("Date: %s\n", entry->date);
    printf("Time: %s\n", entry->time);
    printf("Content:\n%s\n\n", entry->content);
}

void main() {
    FILE* file;
    char filename[50];
    struct entry entry;
    char choice;
    time_t now = time(NULL);
    strftime(filename, 50, "diary_%Y%m%d.txt", localtime(&now));

    file = fopen(filename, "a");

    if (file == NULL) {
        printf("File not found. Creating new file.\n");
        file = fopen(filename, "w");
        write_entry(&entry, "N/A", "N/A", "First entry. Welcome to your digital diary!");
        fclose(file);
        file = fopen(filename, "a");
    }

    while (1) {
        printf("Enter your entry:\n");
        scanf("%[^\n]", entry.content);
        entry.content[strcspn(entry.content, "\n")] = '\0';
        write_entry(&entry, ctime(&now), ctime(&now), entry.content);
        printf("Entry saved.\n");

        printf("Press 'r' to read your entries.\n");
        scanf(" %c", &choice);

        if (choice == 'r') {
            rewind(file);
            while (fgets(filename, 50, file)!= NULL) {
                if (sscanf(filename, "%s %s %s", entry.date, entry.time, entry.content) == 3) {
                    read_entry(&entry);
                }
            }
            printf("End of entries.\n");
        }
    }

    fclose(file);
}