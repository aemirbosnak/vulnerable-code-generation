//FormAI DATASET v1.0 Category: Database simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
} Record;

typedef struct {
    int count;
    Record* records[100];
} Database;

int main() {
    Database db;
    db.count = 0;

    printf("Welcome to the Wacky Database Simulator!\n");
    while (1) {
        printf("What would you like to do?\n");
        printf("1. Add a record\n");
        printf("2. View all records\n");
        printf("3. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Record* new_record = malloc(sizeof(Record));
                new_record->id = db.count + 1;
                printf("What is the record's name? ");
                scanf("%s", new_record->name);
                db.records[db.count++] = new_record;
                printf("Record added successfully!\n");
            } break;

            case 2: {
                printf("ID\tName\n");
                for (int i = 0; i < db.count; i++) {
                    printf("%d\t%s\n", db.records[i]->id, db.records[i]->name);
                }
            } break;

            case 3: {
                printf("Goodbye!\n");
                for (int i = 0; i < db.count; i++) {
                    free(db.records[i]);
                }
                exit(0);
            } break;

            default: {
                printf("Invalid choice, please try again.\n");
            } break;
        }
    }
}