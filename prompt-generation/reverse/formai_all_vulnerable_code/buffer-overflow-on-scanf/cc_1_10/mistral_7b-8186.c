//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 10
#define ENTRY_SIZE 256

typedef struct {
    char title[100];
    char content[ENTRY_SIZE];
    time_t timestamp;
} Entry;

void saveEntry(Entry *diary, int index) {
    diary[index].timestamp = time(NULL);
    fwrite(&diary[index], sizeof(Entry), 1, "diary.bin");
}

int loadEntry(Entry *diary, int index) {
    rewind(fopen("diary.bin", "rb"));
    int i;
    for (i = 0; i < DIARY_SIZE; i++) {
        if (feof(fopen("diary.bin", "rb")) || strcmp(diary[i].title, "")) {
            if (i == index) {
                fread(&diary[i], sizeof(Entry), 1, "diary.bin");
                return 1;
            }
        }
    }
    return 0;
}

void printMenu() {
    printf("\nDigital Diary\n");
    printf("1. Add Entry\n");
    printf("2. View Entry\n");
    printf("3. Delete Entry\n");
    printf("4. List Entries\n");
    printf("5. Exit\n");
}

int main() {
    Entry diary[DIARY_SIZE];
    int choice, index;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Title: ");
                scanf("%s", diary[DIARY_SIZE - 1].title);
                printf("Enter Content: ");
                scanf("%[^\n]", diary[DIARY_SIZE - 1].content);
                saveEntry(diary, DIARY_SIZE - 1);
                printf("Entry saved successfully.\n");
                break;
            case 2:
                printf("Enter Entry Index: ");
                scanf("%d", &index);
                if (loadEntry(diary, index)) {
                    printf("\nTitle: %s\n", diary[index].title);
                    printf("Content: %s\n", diary[index].content);
                    printf("Timestamp: %s", ctime(&diary[index].timestamp));
                } else {
                    printf("Entry not found.\n");
                }
                break;
            case 3:
                printf("Enter Entry Index: ");
                scanf("%d", &index);
                if (loadEntry(diary, index)) {
                    for (int i = index; i < DIARY_SIZE - 1; i++) {
                        diary[i] = diary[i + 1];
                    }
                    saveEntry(diary, DIARY_SIZE - 1);
                    printf("Entry deleted successfully.\n");
                } else {
                    printf("Entry not found.\n");
                }
                break;
            case 4:
                printf("\nList of Entries:\n");
                for (int i = 0; i < DIARY_SIZE; i++) {
                    if (loadEntry(diary, i)) {
                        printf("\nTitle: %s", diary[i].title);
                        printf("\nContent: %s", diary[i].content);
                        printf("\nTimestamp: %s", ctime(&diary[i].timestamp));
                    }
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}