//FormAI DATASET v1.0 Category: Digital Diary ; Style: multiplayer
#include<stdio.h>
#include<time.h>
#include<string.h>

struct entry {
    char timestamp[50];
    char entry[1000];
};

int main() {
    struct entry entries[100];
    int num_entries = 0;
  
    while (1) {
        printf("\n1. Add Entry");
        printf("\n2. View Entries");
        printf("\n3. Exit");
        printf("\nEnter option: ");
        int choice;
        scanf("%d", &choice);
      
        switch (choice) {
            case 1: {
                printf("\nEnter your entry: ");
                scanf("%s", entries[num_entries].entry);
                time_t now = time(NULL);
                struct tm *t = localtime(&now);
                strftime(entries[num_entries].timestamp, sizeof(entries[num_entries].timestamp), "%c", t);
                num_entries++;
                printf("\nEntry added!");
                break;
            }
          
            case 2: {
                if (num_entries == 0) {
                    printf("\nNo entries yet!\n");
                } 
              
                else {
                    for (int i = 0; i < num_entries; i++) {
                        printf("\nEntry %d", i+1);
                        printf("\nTimestamp: %s", entries[i].timestamp);
                        printf("\n%s\n", entries[i].entry);
                    }
                }
                break;
            }
          
            case 3: {
                return 0;
            }
          
            default: {
                printf("\nInvalid option!\n");
            }
        }
    }
  
    return 0;
}