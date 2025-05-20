//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

struct entry {
    time_t timestamp;
    char text[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *diary;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[20];
    int choice;

    do {
        printf("Welcome to the Digital Diary\n");
        printf("1. Open Diary\n");
        printf("2. Create New Entry\n");
        printf("3. Save Diary\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the filename of the diary: ");
                scanf("%s", filename);
                diary = fopen(filename, "r");
                if(diary == NULL) {
                    printf("Diary not found.\n");
                } else {
                    printf("Diary opened successfully.\n");
                }
                break;
            case 2:
                printf("Enter the text for the new entry: ");
                fflush(stdin);
                gets(entries[num_entries].text);
                entries[num_entries].timestamp = time(NULL);
                num_entries++;
                printf("New entry created successfully.\n");
                break;
            case 3:
                diary = fopen(filename, "w");
                if(diary == NULL) {
                    printf("Failed to save diary.\n");
                } else {
                    for(int i = 0; i < num_entries; i++) {
                        fprintf(diary, "%s - %s\n", ctime(&entries[i].timestamp), entries[i].text);
                    }
                    fclose(diary);
                    printf("Diary saved successfully.\n");
                }
                break;
            case 4:
                printf("Exiting Digital Diary.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 4);

    return 0;
}