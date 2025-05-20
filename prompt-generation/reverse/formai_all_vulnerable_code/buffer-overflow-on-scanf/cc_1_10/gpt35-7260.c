//FormAI DATASET v1.0 Category: Digital Diary ; Style: immersive
#include<stdio.h>
#include<stdlib.h>

struct diary_entry {
  int month;
  int day;
  int year;
  char entry_text[1000];
};

// function to display the menu
void display_menu()
{
    printf("******************************\n");
    printf("    DIGITAL DIARY             \n");
    printf("******************************\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Exit\n\n");
    printf("Enter your choice: ");
}

int main()
{
    int choice;
    int num_entries = 0;

    // allocate memory for diary entry
    struct diary_entry *entries = (struct diary_entry*) malloc(sizeof(struct diary_entry));

    do {
        display_menu();

        // get the user's choice
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                // add new diary entry
                printf("Enter the date (mm/dd/yyyy): ");
                scanf("%d/%d/%d", &entries[num_entries].month, &entries[num_entries].day, &entries[num_entries].year);
                getchar();

                printf("Enter your entry: ");
                fgets(entries[num_entries].entry_text, 1000, stdin);
                
                // increase the count of entries
                num_entries++;
                
                // allocate more memory for entries
                entries = (struct diary_entry*) realloc(entries, (num_entries+1)*sizeof(struct diary_entry));
                break;

            case 2:
                // view diary entries
                if (num_entries == 0) {
                    printf("\nNo entries found!\n");
                }
                else {
                    printf("\nDIARY ENTRIES\n");
                    printf("-------------\n");

                    for (int i = 0; i < num_entries; i++) {
                        printf("%d/%d/%d:\n%s", entries[i].month, entries[i].day, entries[i].year, entries[i].entry_text);
                        printf("-------------\n");
                    }
                }
                break;

            case 3:
                printf("\nExiting the program. Bye!\n");
                break;

            default:
                printf("\nInvalid choice. Please select a valid option.\n");
                break;
        }
    } while(choice != 3);

    //free the memory
    free(entries);

    return 0;
}