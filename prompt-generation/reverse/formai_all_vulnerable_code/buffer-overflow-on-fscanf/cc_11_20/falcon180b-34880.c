//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int main() {
    char input[MAX_ENTRY_LENGTH];
    int i, j, numEntries = 0;
    Entry diary[MAX_ENTRIES];

    printf("Welcome to your digital diary!\n");

    // Load existing entries
    FILE *file = fopen("diary.txt", "r");
    if (file!= NULL) {
        while (fscanf(file, "%s %s", diary[numEntries].date, diary[numEntries].entry)!= EOF) {
            numEntries++;
        }
        fclose(file);
    }

    // Main loop
    while (1) {
        printf("\n");
        if (numEntries == 0) {
            printf("No entries yet. Press any key to continue.\n");
            getchar();
        } else {
            printf("Select an option:\n");
            printf("1. View entries\n");
            printf("2. Add entry\n");
            printf("3. Search entries\n");
            printf("4. Exit\n");
            scanf("%d", &i);

            switch (i) {
                case 1:
                    for (j = 0; j < numEntries; j++) {
                        printf("%s - %s\n", diary[j].date, diary[j].entry);
                    }
                    break;
                case 2:
                    printf("Enter date (YYYY-MM-DD): ");
                    scanf("%s", diary[numEntries].date);
                    printf("Enter entry:\n");
                    fgets(diary[numEntries].entry, MAX_ENTRY_LENGTH, stdin);
                    numEntries++;
                    break;
                case 3:
                    printf("Enter search term: ");
                    scanf("%s", input);
                    for (j = 0; j < numEntries; j++) {
                        if (strstr(diary[j].entry, input)!= NULL) {
                            printf("%s - %s\n", diary[j].date, diary[j].entry);
                        }
                    }
                    break;
                case 4:
                    printf("Exiting...\n");
                    break;
                default:
                    printf("Invalid option.\n");
            }
        }
    }

    return 0;
}