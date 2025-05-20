//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_SIZE 1000

typedef struct {
  char date[11];
  char time[9];
  char entry[MAX_ENTRY_SIZE];
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int numEntries = 0;

void addEntry(char *date, char *time, char *entry) {
  if (numEntries == MAX_ENTRIES) {
    printf("Error: Diary is full.\n");
    return;
  }

  strcpy(entries[numEntries].date, date);
  strcpy(entries[numEntries].time, time);
  strcpy(entries[numEntries].entry, entry);

  numEntries++;
}

void printEntry(int index) {
  if (index < 0 || index >= numEntries) {
    printf("Error: Invalid entry index.\n");
    return;
  }

  printf("%s %s\n", entries[index].date, entries[index].time);
  printf("%s\n", entries[index].entry);
}

void printAllEntries() {
  for (int i = 0; i < numEntries; i++) {
    printEntry(i);
    printf("\n");
  }
}

int main() {
  char input[1000];
  char command[100];
  char date[11];
  char time[9];
  char entry[MAX_ENTRY_SIZE];

  while (1) {
    printf("> ");
    fgets(input, sizeof(input), stdin);

    sscanf(input, "%s", command);

    if (strcmp(command, "add") == 0) {
      sscanf(input, "%s %s \"%s\"", command, date, time, entry);
      addEntry(date, time, entry);
    } else if (strcmp(command, "print") == 0) {
      sscanf(input, "%s %d", command, &index);
      printEntry(index);
    } else if (strcmp(command, "printall") == 0) {
      printAllEntries();
    } else if (strcmp(command, "quit") == 0) {
      break;
    } else {
      printf("Error: Unknown command '%s'.\n", command);
    }
  }

  return 0;
}