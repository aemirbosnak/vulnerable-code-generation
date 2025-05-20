//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: happy
#include <stdio.h>
#include <string.h>

#define MAX_RECORD_SIZE 100
#define MAX_RECORDS 10

typedef struct Record {
    char name[MAX_RECORD_SIZE];
    char content[MAX_RECORD_SIZE];
    int timestamp;
} Record;

Record records[MAX_RECORDS];

void addRecord() {
    Record newRecord;

    printf("Enter name: ");
    scanf("%s", newRecord.name);

    printf("Enter content: ");
    scanf("%s", newRecord.content);

    printf("Enter timestamp: ");
    scanf("%d", &newRecord.timestamp);

    records[MAX_RECORDS - 1] = newRecord;
}

void displayRecords() {
    int i;

    for (i = 0; i < MAX_RECORDS; i++) {
        if (records[i].name[0] != '\0') {
            printf("Name: %s\n", records[i].name);
            printf("Content: %s\n", records[i].content);
            printf("Timestamp: %d\n", records[i].timestamp);
            printf("\n");
        }
    }
}

int main() {
    int choice;

    printf("Welcome to the Digital Diary!\n");

    while (1) {
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}