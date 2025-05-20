//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORD_SIZE 255

typedef struct Record {
    char name[MAX_RECORD_SIZE];
    char date[MAX_RECORD_SIZE];
    char content[MAX_RECORD_SIZE];
} Record;

Record records[100];

void write_record() {
    Record new_record;

    printf("Enter your name: ");
    scanf("%s", new_record.name);

    printf("Enter the date: ");
    scanf("%s", new_record.date);

    printf("Enter your content: ");
    scanf("%s", new_record.content);

    records[0] = new_record;
}

void read_records() {
    int i = 0;
    for (i = 0; i < 100; i++) {
        if (records[i].name[0] != '\0') {
            printf("Name: %s\n", records[i].name);
            printf("Date: %s\n", records[i].date);
            printf("Content: %s\n", records[i].content);
            printf("\n");
        }
    }
}

int main() {
    int choice;

    printf("Enter 1 to write a new record, 2 to read records: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            write_record();
            break;
        case 2:
            read_records();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}