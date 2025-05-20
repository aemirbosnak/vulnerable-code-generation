//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 50
#define MAX_ENTRY_LENGTH 500

struct diary_entry {
    char date[20];
    char time[20];
    char content[MAX_ENTRY_LENGTH];
};

int main() {
    char choice;
    struct diary_entry entries[MAX_ENTRIES];
    int num_entries = 0;
    FILE *diary_file;

    // Open the diary file for appending
    diary_file = fopen("diary.txt", "a");
    if(diary_file == NULL) {
        printf("Error: Could not open diary file.\n");
        exit(1);
    }

    // Check if the diary file is empty
    rewind(diary_file);
    char c;
    while((c = fgetc(diary_file))!= EOF) {
        if(c!= '\n') {
            fseek(diary_file, 0, SEEK_SET);
            break;
        }
    }
    if(c == EOF) {
        printf("Diary file is empty.\n");
        fclose(diary_file);
        return 0;
    }

    while(1) {
        printf("\nDigital Diary\n");
        printf("-----------------\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1': {
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", entries[num_entries].date);
                printf("Enter time (HH:MM): ");
                scanf("%s", entries[num_entries].time);
                printf("Enter content:\n");
                fgets(entries[num_entries].content, MAX_ENTRY_LENGTH, stdin);
                entries[num_entries].content[strcspn(entries[num_entries].content, "\n")] = '\0';
                printf("Entry added.\n");
                num_entries++;
                break;
            }
            case '2': {
                printf("Diary Entries:\n");
                for(int i = 0; i < num_entries; i++) {
                    printf("%s %s - %s", entries[i].date, entries[i].time, entries[i].content);
                    printf("\n");
                }
                break;
            }
            case '3': {
                printf("Exiting program...\n");
                fclose(diary_file);
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}