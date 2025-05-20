//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_SIZE 5000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_SIZE];
} Entry;

int main() {
    FILE *file;
    char filename[50];
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    int choice;
    char date[20];
    int i;

    do {
        system("clear");
        printf("Digital Diary\n");
        printf("1. Create new entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the date (YYYY-MM-DD): ");
                scanf("%s", date);
                sprintf(filename, "entries_%s.txt", date);
                file = fopen(filename, "a");
                if(file == NULL) {
                    printf("Error creating file.\n");
                    exit(1);
                }
                printf("Enter your entry: ");
                fgets(entries[num_entries].entry, MAX_ENTRY_SIZE, stdin);
                strcpy(entries[num_entries].date, date);
                num_entries++;
                fclose(file);
                break;
            case 2:
                if(num_entries == 0) {
                    printf("No entries found.\n");
                } else {
                    printf("List of entries:\n");
                    for(i=0; i<num_entries; i++) {
                        printf("%s - %s\n", entries[i].date, entries[i].entry);
                    }
                }
                break;
            case 3:
                printf("Enter the date to search (YYYY-MM-DD): ");
                scanf("%s", date);
                sprintf(filename, "entries_%s.txt", date);
                file = fopen(filename, "r");
                if(file == NULL) {
                    printf("No entries found for the given date.\n");
                    fclose(file);
                    break;
                }
                while(fgets(entries[num_entries].entry, MAX_ENTRY_SIZE, file)!= NULL) {
                    strcpy(entries[num_entries].date, date);
                    num_entries++;
                }
                fclose(file);
                printf("List of entries for %s:\n", date);
                for(i=0; i<num_entries; i++) {
                    printf("%s - %s\n", entries[i].date, entries[i].entry);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(1);

    return 0;
}