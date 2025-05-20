//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    int age;
    char address[100];
} Entry;

void addEntry(Entry* entries, int numEntries) {
    printf("Enter name: ");
    scanf("%s", entries[numEntries].name);

    printf("Enter age: ");
    scanf("%d", &entries[numEntries].age);

    printf("Enter address: ");
    scanf("%s", entries[numEntries].address);

    numEntries++;
}

void displayEntry(Entry entry) {
    printf("Name: %s\n", entry.name);
    printf("Age: %d\n", entry.age);
    printf("Address: %s\n", entry.address);
}

void sortByName(Entry* entries, int numEntries) {
    for (int i = 0; i < numEntries - 1; i++) {
        for (int j = i + 1; j < numEntries; j++) {
            if (strcmp(entries[i].name, entries[j].name) > 0) {
                Entry temp = entries[i];
                entries[i] = entries[j];
                entries[j] = temp;
            }
        }
    }
}

void sortByAge(Entry* entries, int numEntries) {
    for (int i = 0; i < numEntries - 1; i++) {
        for (int j = i + 1; j < numEntries; j++) {
            if (entries[i].age > entries[j].age) {
                Entry temp = entries[i];
                entries[i] = entries[j];
                entries[j] = temp;
            }
        }
    }
}

int main() {
    Entry entries[MAX_ENTRIES];
    int numEntries = 0;

    while (numEntries < MAX_ENTRIES) {
        addEntry(entries, numEntries);
        numEntries++;
    }

    printf("Unsorted entries:\n");
    for (int i = 0; i < numEntries; i++) {
        displayEntry(entries[i]);
    }

    sortByName(entries, numEntries);
    printf("\nSorted by name:\n");
    for (int i = 0; i < numEntries; i++) {
        displayEntry(entries[i]);
    }

    sortByAge(entries, numEntries);
    printf("\nSorted by age:\n");
    for (int i = 0; i < numEntries; i++) {
        displayEntry(entries[i]);
    }

    return 0;
}