//FormAI DATASET v1.0 Category: Database Indexing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define MAX_INDEX 100
#define MAX_NAME 50

struct Record {
    int id;
    char name[MAX_NAME];
    float score;
};

struct Index {
    char name[MAX_NAME];
    int start;
    int end;
};

int num_records = 0;
int num_indexes = 0;
struct Record records[MAX_SIZE];
struct Index indexes[MAX_INDEX];

void add_record() {
    if (num_records == MAX_SIZE) {
        printf("Sorry, the database is full!\n");
        return;
    }
    struct Record rec;
    rec.id = num_records;
    printf("Enter name: ");
    scanf("%s", rec.name);
    printf("Enter score: ");
    scanf("%f", &rec.score);
    records[num_records] = rec;
    for (int i = 0; i < num_indexes; i++) {
        if (strcmp(indexes[i].name, rec.name) == 0) {
            indexes[i].end = num_records;
            return;
        }
    }
    struct Index ind;
    strcpy(ind.name, rec.name);
    ind.start = num_records;
    ind.end = num_records;
    indexes[num_indexes] = ind;
    num_indexes++;
    num_records++;
    printf("Record added successfully!\n");
}

void search_record() {
    printf("Enter name to search: ");
    char name[MAX_NAME];
    scanf("%s", name);
    for (int i = 0; i < num_indexes; i++) {
        if (strcmp(indexes[i].name, name) == 0) {
            printf("Search results:\n");
            for (int j = indexes[i].start; j <= indexes[i].end; j++) {
                printf("%d. %s, %f\n", records[j].id, records[j].name, records[j].score);
            }
            return;
        }
    }
    printf("Record not found!\n");
}

int main() {
    int choice;
    do {
        printf("Menu:\n");
        printf("1. Add record\n");
        printf("2. Search record\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                search_record();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 3);
    return 0;
}