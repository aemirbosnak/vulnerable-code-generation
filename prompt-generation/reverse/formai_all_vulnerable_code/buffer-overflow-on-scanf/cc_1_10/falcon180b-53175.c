//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000

struct entry {
    char title[256];
    time_t timestamp;
    char content[4096];
};

FILE *diary_file = NULL;
int num_entries = 0;

void init() {
    diary_file = fopen("diary.txt", "r+");
    if (diary_file == NULL) {
        printf("Error: Could not open diary file.\n");
        exit(1);
    }
    num_entries = 0;
}

void read_entries() {
    struct entry entry;
    rewind(diary_file);
    while (fread(&entry, sizeof(struct entry), 1, diary_file) == 1) {
        printf("%s\n", entry.title);
        printf("%s\n", ctime(&entry.timestamp));
        printf("%s\n\n", entry.content);
    }
}

void write_entry(char *title, char *content) {
    struct entry entry;
    strncpy(entry.title, title, 256);
    strncpy(entry.content, content, 4096);
    entry.timestamp = time(NULL);
    fseek(diary_file, 0, SEEK_END);
    fwrite(&entry, sizeof(struct entry), 1, diary_file);
    fclose(diary_file);
    diary_file = fopen("diary.txt", "r+");
    num_entries++;
    printf("Entry saved.\n");
}

void delete_entry(int index) {
    if (index < 0 || index >= num_entries) {
        printf("Invalid entry index.\n");
        return;
    }
    fseek(diary_file, (index - 1) * sizeof(struct entry), SEEK_SET);
    ftruncate(fileno(diary_file), num_entries * sizeof(struct entry));
    num_entries--;
    printf("Entry deleted.\n");
}

int main() {
    int choice;
    char title[256];
    char content[4096];

    init();

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Read Entries\n");
        printf("2. Write Entry\n");
        printf("3. Delete Entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            read_entries();
            break;
        case 2:
            printf("Enter entry title: ");
            scanf("%s", title);
            printf("Enter entry content: ");
            fgets(content, 4096, stdin);
            write_entry(title, content);
            break;
        case 3:
            printf("Enter entry index to delete: ");
            scanf("%d", &choice);
            delete_entry(choice);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}