//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

struct entry {
    int id;
    char title[100];
    char content[500];
    time_t timestamp;
};

FILE *diary;
int num_entries = 0;

void init_diary() {
    diary = fopen("diary.txt", "w");
    if (diary == NULL) {
        printf("Error: could not open diary file.\n");
        exit(1);
    }
}

void write_entry(struct entry *e) {
    fprintf(diary, "%d\t%s\t%s\t%ld\n", e->id, e->title, e->content, e->timestamp);
}

void read_entries() {
    rewind(diary);
    while (!feof(diary)) {
        struct entry e;
        fscanf(diary, "%d\t%s\t%s\t%ld", &e.id, e.title, e.content, &e.timestamp);
        printf("%d\t%s\t%s\t%s", e.id, e.title, e.content, ctime(&e.timestamp));
    }
}

int main() {
    srand(time(NULL));
    init_diary();

    while (1) {
        int choice;
        printf("1. Write an entry\n2. Read entries\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct entry e;
                e.id = rand() % 1000;
                strcpy(e.title, "Random Title");
                strcpy(e.content, "Random Content");
                e.timestamp = time(NULL);
                write_entry(&e);
                break;
            }
            case 2: {
                read_entries();
                break;
            }
            case 3: {
                fclose(diary);
                return 0;
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}