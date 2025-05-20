//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: complete
#include <stdio.h>
#include <string.h>

#define MAX_RECORD_SIZE 10

typedef struct Record {
    char name[20];
    char date[20];
    char entry[200];
} Record;

Record records[MAX_RECORD_SIZE];

void addRecord() {
    Record newRecord;

    printf("Enter your name: ");
    scanf("%s", newRecord.name);

    printf("Enter the date: ");
    scanf("%s", newRecord.date);

    printf("Enter your entry: ");
    scanf("%[^\n]%*c", newRecord.entry);

    records[MAX_RECORD_SIZE - 1] = newRecord;
}

void displayRecords() {
    int i = 0;

    for (i = 0; i < MAX_RECORD_SIZE; i++) {
        if (records[i].name[0] != '\0') {
            printf("Name: %s\n", records[i].name);
            printf("Date: %s\n", records[i].date);
            printf("Entry: %s\n", records[i].entry);
            printf("\n");
        }
    }
}

int main() {
    int choice = 0;

    printf("Welcome to your digital diary!\n");

    while (choice != 3) {
        printf("Please select an option:\n");
        printf("1. Add a new record\n");
        printf("2. Display records\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                printf("Thank you for using your digital diary. Goodbye!\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    }

    return 0;
}