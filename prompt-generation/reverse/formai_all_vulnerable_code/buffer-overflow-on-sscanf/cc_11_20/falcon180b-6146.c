//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

struct diary_entry {
    char date[10];
    char time[10];
    char content[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *diary_file;
    char filename[20];
    struct diary_entry entries[MAX_ENTRIES];
    int num_entries = 0;
    int choice;

    do {
        printf("\nWelcome to Digital Diary!\n");
        printf("1. Create new diary entry\n");
        printf("2. Read existing diary entries\n");
        printf("3. Save diary to file\n");
        printf("4. Load diary from file\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the date (YYYY-MM-DD): ");
                scanf("%s", entries[num_entries].date);
                printf("Enter the time (HH:MM:SS): ");
                scanf("%s", entries[num_entries].time);
                printf("Enter your diary entry:\n");
                fgets(entries[num_entries].content, MAX_ENTRY_LENGTH, stdin);
                num_entries++;
                break;
            case 2:
                for(int i=0; i<num_entries; i++) {
                    printf("\n%s\n%s\n%s\n\n", entries[i].date, entries[i].time, entries[i].content);
                }
                break;
            case 3:
                printf("Enter the filename to save diary to: ");
                scanf("%s", filename);
                diary_file = fopen(filename, "w");
                if(diary_file == NULL) {
                    printf("Error: could not open file.\n");
                } else {
                    for(int i=0; i<num_entries; i++) {
                        fprintf(diary_file, "%s %s\n%s\n\n", entries[i].date, entries[i].time, entries[i].content);
                    }
                    fclose(diary_file);
                }
                break;
            case 4:
                printf("Enter the filename to load diary from: ");
                scanf("%s", filename);
                diary_file = fopen(filename, "r");
                if(diary_file == NULL) {
                    printf("Error: could not open file.\n");
                } else {
                    char line[MAX_ENTRY_LENGTH];
                    while(fgets(line, MAX_ENTRY_LENGTH, diary_file)!= NULL) {
                        sscanf(line, "%s %s %s", entries[num_entries].date, entries[num_entries].time, entries[num_entries].content);
                        num_entries++;
                    }
                    fclose(diary_file);
                }
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 5);

    return 0;
}