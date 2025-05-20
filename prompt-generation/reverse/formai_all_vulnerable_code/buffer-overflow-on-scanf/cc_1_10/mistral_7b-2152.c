//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[50];
    char description[100];
    time_t timestamp;
} Entry;

void create_entry(Entry* entry, char* name, char* description);
void print_entry(Entry* entry);
void save_entry(Entry* entry, FILE* file);

int main() {
    FILE* file = fopen("digital_diary.txt", "w+");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    while (1) {
        Entry new_entry;
        printf("\nWhisper to me, dear ephemera:\n");
        scanf("%[^\n]", new_entry.description);
        getchar();
        printf("Who pens this fleeting moment?\n");
        fgets(new_entry.name, sizeof(new_entry.name), stdin);
        new_entry.timestamp = time(NULL);
        create_entry(&new_entry, new_entry.name, new_entry.description);
        save_entry(&new_entry, file);

        printf("\nAnother entry has been added.\n");
        printf("Do you wish to add another? (y/n)\n");
        char choice;
        scanf("%c", &choice);
        if (choice == 'n') {
            break;
        }
    }

    fclose(file);
    printf("\nYour digital diary has been saved.\n");
    return 0;
}

void create_entry(Entry* entry, char* name, char* description) {
    strcpy(entry->name, name);
    strcpy(entry->description, description);
}

void print_entry(Entry* entry) {
    printf("\nName: %s", entry->name);
    printf("\nDescription: %s", entry->description);
    printf("\nTimestamp: %s", ctime(&entry->timestamp));
}

void save_entry(Entry* entry, FILE* file) {
    fprintf(file, "%s%s%s%ld\n", entry->name, entry->description, "\n", entry->timestamp);
}