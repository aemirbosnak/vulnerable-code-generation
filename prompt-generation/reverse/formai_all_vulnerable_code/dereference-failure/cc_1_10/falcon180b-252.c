//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[11];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    strncpy(entries[num_entries].date, date, 11);
    strncpy(entries[num_entries].entry, entry, MAX_ENTRY_LENGTH);
    num_entries++;
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    srand(time(NULL));
    char* entries_file = "entries.txt";
    FILE* fp = fopen(entries_file, "r");
    if (fp!= NULL) {
        char line[MAX_ENTRY_LENGTH];
        while (fgets(line, MAX_ENTRY_LENGTH, fp)!= NULL) {
            char* date = strtok(line, " -");
            char* entry = strtok(NULL, "\n");
            add_entry(date, entry);
        }
        fclose(fp);
    } else {
        fp = fopen(entries_file, "w");
        if (fp!= NULL) {
            fprintf(fp, "Welcome to your digital diary!\n\n");
            fprintf(fp, "To add an entry, simply type:\n\n");
            fprintf(fp, "entry [date] [entry]\n\n");
            fprintf(fp, "Example:\n\n");
            fprintf(fp, "entry 2021-10-01 My first entry\n\n");
            fclose(fp);
        }
    }

    while (1) {
        char input[MAX_ENTRY_LENGTH];
        printf("> ");
        fgets(input, MAX_ENTRY_LENGTH, stdin);
        char* command = strtok(input, " ");
        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "entry") == 0) {
            char* date = strtok(NULL, " ");
            char* entry = strtok(NULL, "\n");
            if (date!= NULL && entry!= NULL) {
                add_entry(date, entry);
                printf("Entry added!\n");
            } else {
                printf("Invalid input format.\n");
            }
        } else if (strcmp(command, "print") == 0) {
            print_entries();
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}