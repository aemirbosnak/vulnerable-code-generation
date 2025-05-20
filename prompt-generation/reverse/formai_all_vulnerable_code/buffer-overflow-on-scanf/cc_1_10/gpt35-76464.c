//FormAI DATASET v1.0 Category: Database Indexing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 100
#define MAX_AGE 120

struct record {
    char name[MAX_NAME_LENGTH];
    int age;
};

int compare_record_names(const void *a, const void *b) {
    return strcmp(((struct record*)a)->name, ((struct record*)b)->name);
}

int compare_record_ages(const void *a, const void *b) {
    return ((struct record*)a)->age - ((struct record*)b)->age;
}

int main() {
    struct record records[MAX_RECORDS];
    int num_records = 0;
    char command;

    while(1) {
        printf("Enter 'a' to add a record, 'n' to sort by name, 'a' to sort by age, or 'q' to quit: ");
        scanf(" %c", &command);

        if(command == 'q') {
            break;
        } else if(command == 'a') {
            if(num_records >= MAX_RECORDS) {
                printf("Too many records!\n");
            } else {
                struct record new_record;
                printf("Enter name (up to %d characters): ", MAX_NAME_LENGTH-1);
                scanf("%s", new_record.name);
                printf("Enter age (0 to %d): ", MAX_AGE);
                scanf("%d", &new_record.age);

                records[num_records++] = new_record;
            }
        } else if(command == 'n') {
            qsort(records, num_records, sizeof(struct record), compare_record_names);
            printf("Record sorted by name:\n");
            for(int i=0; i<num_records; i++) {
                printf("%s: %d\n", records[i].name, records[i].age);
            }
        } else if(command == 'a') {
            qsort(records, num_records, sizeof(struct record), compare_record_ages);
            printf("Record sorted by age:\n");
            for(int i=0; i<num_records; i++) {
                printf("%s: %d\n", records[i].name, records[i].age);
            }
        } else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}