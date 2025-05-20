//FormAI DATASET v1.0 Category: Digital Diary ; Style: statistical
#include<stdio.h>

// Define a structure to store diary entry
struct Diary {
    char date[20];
    char title[50];
    char entry[500];
} diary[365];

int main() {
    int choice, count = 0;
    FILE *fp;

    // Read diary entries from file, if it exists
    fp = fopen("diary.txt", "rb");
    if(fp) {
        fread(&diary, sizeof(diary), 1, fp);
        fclose(fp);
    }

    // Loop until user exits
    while(1) {
        printf("\n\n---- Digital Diary ----\n");
        printf("1. Add Entry\n2. View Entry\n3. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Adding an entry
                printf("\nEnter the date (in dd/mm/yyyy format): ");
                scanf("%s", &diary[count].date);
                printf("Enter the title: ");
                scanf("%s", &diary[count].title);
                printf("Write your entry (max 500 characters):\n");
                scanf(" %[^\n]s", &diary[count].entry);

                printf("\nEntry added successfully!\n");
                count++;
                break;

            case 2: // Viewing an entry
                if(count == 0) {
                    printf("\nNo entries found!\n");
                    break;
                }

                printf("\nEnter the date (in dd/mm/yyyy format): ");
                char view_date[20];
                scanf("%s", view_date);

                int found = 0;
                for(int i=0; i<count; i++) {
                    if(strcmp(diary[i].date, view_date) == 0) {
                        printf("\nTitle: %s\n", diary[i].title);
                        printf("Entry: %s\n", diary[i].entry);
                        found = 1;
                        break;
                    }
                }

                if(!found)
                    printf("\nEntry not found for this date!\n");
                break;

            case 3: // Exiting the program
                printf("\nSaving diary entries to file...\n");
                fp = fopen("diary.txt", "wb");
                fwrite(&diary, sizeof(diary), 1, fp);
                fclose(fp);
                printf("Goodbye!\n");
                return 0;

            default: // Invalid input
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}