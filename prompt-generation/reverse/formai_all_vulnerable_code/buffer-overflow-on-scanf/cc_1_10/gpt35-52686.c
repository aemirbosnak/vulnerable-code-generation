//FormAI DATASET v1.0 Category: Digital Diary ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition to store diary entry
struct diary_entry {
    char date[20];
    char entry[200];
};

void menu()
{
    printf("\n--------------------\n");
    printf("Digital Diary\n");
    printf("--------------------\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

int main()
{
    int choice, num_entries = 0;
    struct diary_entry entries[50];

    while(1) {
        menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                printf("Enter the date(dd-mm-yyyy): ");
                scanf("%s", entries[num_entries].date);
                printf("Enter the entry: ");
                getchar();
                fgets(entries[num_entries].entry, 200, stdin);
                num_entries++;
                break;
            }
            case 2: {
                if(num_entries == 0) {
                    printf("\nNo entries found!\n");
                    break;
                }
                printf("\nDATE\t\tENTRY\n");
                printf("-------------------------\n");
                for(int i=0;i<num_entries;i++) {
                    printf("%s\t%s", entries[i].date, entries[i].entry);
                }
                printf("-------------------------\n\n");
                break;
            }   
            case 3: {
                printf("Exiting diary...\n");
                exit(0);
            }
            default: {
                printf("\nInvalid choice. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}