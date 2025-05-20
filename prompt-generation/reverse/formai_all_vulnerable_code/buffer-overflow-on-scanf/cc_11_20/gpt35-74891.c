//FormAI DATASET v1.0 Category: Digital Diary ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct DiaryEntry {
    char date[20];
    char entry[300];
};

int main() {
    FILE *fp;
    struct DiaryEntry newEntry;
    int numEntries = 0;
    int menuChoice = 0;

    // Check if Diary file exists
    fp = fopen("diary.dat", "rb");
    if(fp == NULL) {
        printf("Diary file does not exist, creating new file.\n");
        fp = fopen("diary.dat", "ab");
        fclose(fp);
    }
    else {
        fclose(fp);
        fp = fopen("diary.dat", "rb");
        while(fread(&newEntry, sizeof(struct DiaryEntry), 1, fp)) {
            numEntries++;
        }
        printf("Welcome back! You have %d entries in your diary.\n", numEntries);
        fclose(fp);
    }

    while(1) {
        printf("\n1. Add new diary entry\n");
        printf("2. View existing diary entry\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &menuChoice);
        getchar();  // To get rid of \n character left by scanf

        switch(menuChoice) {
            case 1: // Add new diary entry
                fp = fopen("diary.dat", "ab");

                // Get current date and time
                time_t current_time = time(NULL);
                struct tm *tm_ptr = localtime(&current_time);

                sprintf(newEntry.date, "%d/%d/%d %d:%02d:%02d",
                        tm_ptr->tm_mday, tm_ptr->tm_mon+1, tm_ptr->tm_year+1900,
                        tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);

                printf("Your current time is: %s\n", newEntry.date);
                printf("Enter your diary entry (maximum 300 characters):\n");
                fgets(newEntry.entry, 300, stdin);

                fwrite(&newEntry, sizeof(struct DiaryEntry), 1, fp);
                fclose(fp);
                printf("Diary entry saved successfully.\n");
                break;

            case 2: // View existing diary entry
                fp = fopen("diary.dat", "rb");

                if(numEntries == 0) {
                    printf("No diary entries found. Please add new entry.\n");
                }
                else {
                    printf("You have %d entries in your diary. Choose an entry to view:\n", numEntries);
                    for(int i=1; i<=numEntries; i++) {
                        fread(&newEntry, sizeof(struct DiaryEntry), 1, fp);
                        printf("%d. %s\n", i, newEntry.date);
                    }

                    int choice = 0;
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    if(choice < 1 || choice > numEntries) {
                        printf("Invalid choice. Please try again.\n");
                    }
                    else {
                        fseek(fp, (choice-1)*sizeof(struct DiaryEntry), SEEK_SET);
                        fread(&newEntry, sizeof(struct DiaryEntry), 1, fp);
                        printf("%s\n\n", newEntry.date);
                        printf("%s\n", newEntry.entry);
                    }
                }
                fclose(fp);
                break;

            case 3: // Exit
                printf("Thank you for using Digital Diary. Have a nice day!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}