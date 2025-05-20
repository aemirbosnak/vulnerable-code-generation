//FormAI DATASET v1.0 Category: Digital Diary ; Style: detailed
#include<stdio.h> //header file for input/output operations
#include<string.h> //header file for string operations

#define MAX_ENTRIES 100 //maximum number of entries

struct diaryEntry { //structure to store a diary entry
    char date[20]; //date of the entry
    char title[50]; //title of the entry
    char text[1000]; //text of the entry
};

struct diaryEntry diary[MAX_ENTRIES]; //array of diary entries

int numEntries = 0; //number of entries in the diary

int main() {
    int choice; //variable to store user's input choice
    char date[20], title[50], text[1000]; //variables to store entry information

    printf("***Digital Diary***\n");
    printf("\n");

    do {
        printf("1. Add a new entry\n");
        printf("2. View all entries\n");
        printf("3. Search for an entry\n");
        printf("4. Delete an entry\n");
        printf("5. Exit\n");
        printf("\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice) {
            case 1:
                printf("Enter the date of the entry (DD/MM/YYYY): ");
                scanf("%s", date);
                printf("Enter the title of the entry: ");
                scanf("%s", title);
                printf("Enter the text of the entry: ");
                scanf("%s", text);

                strcpy(diary[numEntries].date, date);
                strcpy(diary[numEntries].title, title);
                strcpy(diary[numEntries].text, text);

                numEntries++;
                printf("Entry added successfully!\n");
                printf("\n");
                break;

            case 2:
                if(numEntries == 0) {
                    printf("No entries found!\n");
                    printf("\n");
                } else {
                    printf("Date\t\t\tTitle\t\tText\n");

                    for(int i = 0; i < numEntries; i++) {
                        printf("%s\t%s\t%s\n", diary[i].date, diary[i].title, diary[i].text);
                    }

                    printf("\n");
                }

                break;

            case 3:
                if(numEntries == 0) {
                    printf("No entries found!\n");
                    printf("\n");
                } else {
                    printf("Enter the date of the entry to be searched (DD/MM/YYYY): ");
                    scanf("%s", date);

                    int found = 0;

                    for(int i = 0; i < numEntries; i++) {
                        if(strcmp(date, diary[i].date) == 0) {
                            printf("Date\t\t\tTitle\t\tText\n");
                            printf("%s\t%s\t%s\n", diary[i].date, diary[i].title, diary[i].text);
                            found = 1;
                            break;
                        }
                    }

                    if(found == 0) {
                        printf("Entry not found!\n");
                    }

                    printf("\n");
                }

                break;

            case 4:
                if(numEntries == 0) {
                    printf("No entries found!\n");
                    printf("\n");
                } else {
                    printf("Enter the date of the entry to be deleted (DD/MM/YYYY): ");
                    scanf("%s", date);

                    int found = 0;

                    for(int i = 0; i < numEntries; i++) {
                        if(strcmp(date, diary[i].date) == 0) {
                            for(int j = i; j < numEntries; j++) {
                                diary[j] = diary[j + 1];
                            }

                            numEntries--;
                            found = 1;
                            printf("Entry deleted successfully!\n");
                            break;
                        }
                    }

                    if(found == 0) {
                        printf("Entry not found!\n");
                    }

                    printf("\n");
                }

                break;

            case 5:
                printf("Exiting the program...\n");
                printf("\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                printf("\n");
                break;
        }
    } while(choice != 5);

    return 0;
}