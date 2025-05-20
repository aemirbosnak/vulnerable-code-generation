//FormAI DATASET v1.0 Category: Digital Diary ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//structure to store diary entries
typedef struct {
    char date[20];
    char entry[500];
} DiaryEntry;

//function to display main menu
void displayMainMenu() {
    printf("\n\n---Digital Diary---\n");
    printf("1. Create a new entry\n");
    printf("2. View existing entry\n");
    printf("3. Exit program\n");
    printf("Enter your choice: ");
}

//function to get current date
void getCurrentDate(char *date) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(date, 20, "%d/%m/%Y", t);
}

//function to create new diary entry
void createNewEntry() {
    DiaryEntry entry;
    FILE *fp;

    //get current date
    getCurrentDate(entry.date);

    printf("Enter your diary entry (maximum 500 characters):\n");
    scanf(" %[^\n]s", entry.entry);

    //open file in append mode
    fp = fopen("diary.dat", "ab");

    //write entry to file
    fwrite(&entry, sizeof(DiaryEntry), 1, fp);

    fclose(fp);
    printf("\nEntry successfully created!\n");
}

//function to view existing diary entries
void viewEntries() {
    DiaryEntry entry;
    FILE *fp;

    //open file in read mode
    fp = fopen("diary.dat", "rb");

    //read and display each entry
    while(fread(&entry, sizeof(DiaryEntry), 1, fp) == 1) {
        printf("\nDate: %s\n", entry.date);
        printf("Entry: %s\n", entry.entry);
    }

    fclose(fp);
}

int main() {
    int choice;

    do {
        displayMainMenu();

        scanf("%d", &choice);

        switch(choice) {
            case 1: createNewEntry();
                    break;
            case 2: viewEntries();
                    break;
            case 3: printf("\nProgram terminated.\n");
                    break;
            default: printf("\nInvalid choice. Please try again.");
                     break;
        }
    } while(choice != 3);

    return 0;
}