//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10

typedef struct Entry {
  char name[20];
  int year;
  int month;
  int day;
  char message[200];
} Entry;

Entry entries[MAX_ENTRIES];

void addEntry() {
  Entry newEntry;

  printf("Enter name: ");
  scanf("%s", newEntry.name);

  printf("Enter year: ");
  scanf("%d", &newEntry.year);

  printf("Enter month: ");
  scanf("%d", &newEntry.month);

  printf("Enter day: ");
  scanf("%d", &newEntry.day);

  printf("Enter message: ");
  scanf("%s", newEntry.message);

  entries[0] = newEntry;
}

void printEntries() {
  int i = 0;
  for (i = 0; entries[i].name[0] != '\0'; i++) {
    printf("Name: %s\n", entries[i].name);
    printf("Year: %d\n", entries[i].year);
    printf("Month: %d\n", entries[i].month);
    printf("Day: %d\n", entries[i].day);
    printf("Message: %s\n", entries[i].message);
    printf("\n");
  }
}

int main() {
  addEntry();
  addEntry();
  printEntries();

  return 0;
}