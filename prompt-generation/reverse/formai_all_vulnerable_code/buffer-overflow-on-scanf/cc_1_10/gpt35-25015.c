//FormAI DATASET v1.0 Category: Digital Diary ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 10

struct DiaryEntry {
  time_t timestamp;
  char entry[1000];
};

int main() {
  struct DiaryEntry diary[MAX_ENTRIES];
  int num_entries = 0;

  while (1) {
    printf("Welcome to your digital diary\n");
    printf("Enter '1' to add an entry\n");
    printf("Enter '2' to view all entries\n");
    printf("Enter '3' to exit\n");
    int choice;
    scanf("%d", &choice);

    switch(choice) {
      case 1: {
        if (num_entries >= MAX_ENTRIES) {
          printf("Sorry, your diary is full.\n");
          break;
        }

        struct DiaryEntry new_entry;

        printf("Enter your diary entry (1000 character limit):\n");
        fflush(stdin);
        fgets(new_entry.entry, 1000, stdin);
        new_entry.timestamp = time(NULL);

        diary[num_entries] = new_entry;
        num_entries++;

        printf("Entry added to diary!\n");
        break;
      }

      case 2: {
        if (num_entries == 0) {
          printf("Your diary is empty.\n");
          break;
        }

        printf("All diary entries:\n");
        for (int i = 0; i < num_entries; i++) {
          printf("Entry %d:\n", i+1);
          printf("Timestamp: %s", ctime(&diary[i].timestamp));
          printf("Entry: %s\n", diary[i].entry);
        }

        break;
      }

      case 3: {
        printf("Goodbye!\n");
        exit(0);
      }

      default: {
        printf("Invalid input.\n");
        break;
      }
    }
  }
  
  return 0;
}