//FormAI DATASET v1.0 Category: Digital Diary ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Structure to hold diary entries */
struct diary_entry {
    char date[20];
    char entry[1000];
} diary[365];

int main() {
    int option, num_entries = 0;
    FILE *file;
    char file_name[50], date[20], entry[1000];

    /* Get filename from user */
    printf("Enter filename for diary: ");
    scanf("%s", file_name);

    /* Open file for reading */
    file = fopen(file_name, "r");

    /* If file exists, read in entries */
    if (file != NULL) {
        while (!feof(file)) {
            fscanf(file, "%s %s", diary[num_entries].date, diary[num_entries].entry);
            num_entries++;
        }
        fclose(file);
    }

    do {
        /* Print menu options */
        printf("\nDigital Diary\n\n");
        printf("1. Add Entry\n");
        printf("2. View Entry\n");
        printf("3. Exit\n\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                /* Get date and entry from user */
                printf("\nEnter date (DD-MM-YYYY): ");
                scanf("%s", date);
                printf("Enter diary entry: ");
                getchar(); /* Clear input buffer */
                fgets(entry, sizeof(entry), stdin);

                /* Add entry to diary array */
                strcpy(diary[num_entries].date, date);
                strcpy(diary[num_entries].entry, entry);
                num_entries++;

                /* Open file for writing */
                file = fopen(file_name, "w");

                /* Write all entries to file */
                for (int i=0; i<num_entries; i++) {
                    fprintf(file, "%s %s", diary[i].date, diary[i].entry);
                }

                fclose(file);
                printf("Entry added successfully.\n");
                break;

            case 2:
                /* Get date from user */
                printf("\nEnter date (DD-MM-YYYY): ");
                scanf("%s", date);

                /* Search for entry in diary array */
                for (int i=0; i<num_entries; i++) {
                    if (strcmp(diary[i].date, date) == 0) {
                        printf("\n%s\n", diary[i].entry);
                        break;
                    }
                    else if (i == num_entries-1) {
                        printf("\nNo entry found for given date.\n");
                    }
                }
                break;

            case 3:
                printf("\nExiting program.\n");
                break;

            default:
                printf("\nInvalid option. Please try again.\n");
        }
    } while (option != 3);

    return 0;
}