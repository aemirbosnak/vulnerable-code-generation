//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
} Record;

void create(Record* record, int size) {
    printf("Enter the number of records: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        printf("Enter the name of record %d: ", i+1);
        scanf("%s", record[i].name);
        printf("Enter the age of record %d: ", i+1);
        scanf("%d", &record[i].age);
    }
}

void display(Record* record, int size) {
    printf("The records are:\n");
    for (int i = 0; i < size; i++) {
        printf("%s is %d years old.\n", record[i].name, record[i].age);
    }
}

void search(Record* record, int size, char* name) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(record[i].name, name) == 0) {
            printf("%s is %d years old.\n", name, record[i].age);
            found = 1;
        }
    }
    if (found == 0) {
        printf("No record found with name %s.\n", name);
    }
}

int main() {
    Record record[MAX_SIZE];
    int size;

    create(record, size);
    display(record, size);

    char name[MAX_SIZE];
    printf("Enter the name to search: ");
    scanf("%s", name);

    search(record, size, name);

    return 0;
}