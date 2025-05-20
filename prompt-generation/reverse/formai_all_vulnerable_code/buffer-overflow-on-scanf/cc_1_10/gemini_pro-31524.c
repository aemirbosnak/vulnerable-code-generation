//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
  char *text;
  time_t timestamp;
} diary_entry;

diary_entry diary[MAX_ENTRIES];
int num_entries = 0;

void write_entry(char *text) {
  if (num_entries < MAX_ENTRIES) {
    diary[num_entries].text = strdup(text);
    diary[num_entries].timestamp = time(NULL);
    num_entries++;
  } else {
    printf("Error: Diary is full.\n");
  }
}

void read_entry(int index) {
  if (index >= 0 && index < num_entries) {
    printf("Entry %d:\n", index + 1);
    printf("---------------------\n");
    printf("%s\n", diary[index].text);
    printf("Date: %s\n", ctime(&diary[index].timestamp));
  } else {
    printf("Error: Invalid entry index.\n");
  }
}

void list_entries() {
  for (int i = 0; i < num_entries; i++) {
    printf("Entry %d: %s\n", i + 1, diary[i].text);
  }
}

void main() {
  int choice;

  while (1) {
    printf("\nMedieval Digital Diary\n");
    printf("---------------------\n");
    printf("1. Write an entry\n");
    printf("2. Read an entry\n");
    printf("3. List entries\n");
    printf("4. Quit\n");
    printf("> ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter your entry: ");
        char text[1000];
        scanf(" %[^\n]%*c", text);
        write_entry(text);
        break;
      case 2:
        printf("Enter the entry number: ");
        int index;
        scanf("%d", &index);
        read_entry(index - 1);
        break;
      case 3:
        list_entries();
        break;
      case 4:
        printf("Farewell, good scribe.\n");
        exit(0);
      default:
        printf("Error: Invalid choice.\n");
    }
  }
}