//FormAI DATASET v1.0 Category: Digital Diary ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Diary {
    char date[20];
    char title[100];
    char entry[500];
}; //Defining the structure for Diary Entries

int main() {
    int choice, count = 0, i = 0, j = 0;
    char date[20], search_date[20];
    struct Diary diaries[100]; //Array of 100 Diary Entries
    FILE *fp;
    fp = fopen("diary.txt", "a+"); //Opening or Creating the file 'diary.txt'

    //Reading Diary Entries from file and storing in array
    while (!feof(fp)) {
        fscanf(fp, "%[^,], %[^,], %[^\n]", diaries[i].date, diaries[i].title, diaries[i].entry);
        i++;
        count++;
    }
    fclose(fp);

    printf("\nWelcome to your Digital Diary!\n");

    while (1) {
        printf("\nEnter the number corresponding to your desired action:\n");
        printf("1. Add Diary Entry\n2. Search Diary Entry by Date\n3. Display all Diary Entries\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {

        case 1: //Adding a new Diary Entry
            printf("\nEnter Date (mm/dd/yyyy): ");
            scanf("%s", diaries[count].date);
            printf("Enter Title: ");
            getchar(); //clearing input buffer
            fgets(diaries[count].title, 100, stdin);
            printf("Enter Entry: ");
            fgets(diaries[count].entry, 500, stdin);
            fp = fopen("diary.txt", "a+");
            fprintf(fp, "%s, %s, %s\n", diaries[count].date, diaries[count].title, diaries[count].entry);
            fclose(fp);
            count++;
            break;

        case 2: //Searching for a Diary Entry by Date
            printf("\nEnter Date to Search (mm/dd/yyyy): ");
            scanf("%s", search_date);
            for (j = 0; j < count; j++) {
                if (strcmp(search_date, diaries[j].date) == 0) {
                    printf("%s\n%s\n%s\n", diaries[j].date, diaries[j].title, diaries[j].entry);
                    break;
                }
            }
            if (j == count) //If no match found
                printf("\nNo Diary Entry Found for %s\n", search_date);
            break;

        case 3: //Displaying all Diary Entries
            printf("\nDisplaying All Diary Entries:\n");
            for (j = 0; j < count; j++) {
                printf("%s\n%s\n%s\n", diaries[j].date, diaries[j].title, diaries[j].entry);
            }
            break;

        case 4: //Exiting the Program
            printf("\nThank you for using your Digital Diary!\n");
            exit(0);

        default: //Invalid Input
            printf("\nPlease Enter a Valid Input!\n");
        }
    }

    return 0;
}