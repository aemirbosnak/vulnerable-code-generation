//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 10

typedef struct {
    time_t timestamp;
    char message[100];
} DiaryEntry;

DiaryEntry diary[DIARY_SIZE];
int diary_index = 0;

void save_entry() {
    diary[diary_index].timestamp = time(NULL);
    printf("Enter your message: ");
    fgets(diary[diary_index].message, sizeof(diary[diary_index].message), stdin);
    diary[diary_index].message[strcspn(diary[diary_index].message, "\n")] = '\0';
    diary_index = (diary_index + 1) % DIARY_SIZE;
}

void load_entry(int index) {
    if (index >= 0 && index < DIARY_SIZE) {
        printf("\nDate and Time: %s %s\n", ctime(&diary[index].timestamp), "\nMessage: ");
        printf("%s", diary[index].message);
    } else {
        printf("Invalid index.\n");
    }
}

void list_entries() {
    int i;
    printf("\nList of entries:\n");
    for (i = 0; i < DIARY_SIZE; i++) {
        if (diary[i].timestamp != 0) {
            printf("%d. ", i + 1);
            load_entry(i);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nDigital Diary\n1. Save Entry\n2. Load Entry\n3. List Entries\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                save_entry();
                break;
            case 2:
                printf("Enter the index of the entry you want to load: ");
                int index;
                scanf("%d", &index);
                load_entry(index);
                break;
            case 3:
                list_entries();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}