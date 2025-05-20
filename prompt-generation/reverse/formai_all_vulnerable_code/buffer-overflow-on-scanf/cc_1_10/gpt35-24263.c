//FormAI DATASET v1.0 Category: Digital Diary ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

/* structure to store the data for each diary entry */
struct DiaryEntry 
{
    int day;
    int month;
    int year;
    char entry[1000];
};

/* function prototype */
void addEntry(struct DiaryEntry* diary, int length);

int main()
{
    int length = 0;
    int choice = 0;
    struct DiaryEntry* diary;
    diary = (struct DiaryEntry*)malloc(sizeof(struct DiaryEntry));
    printf("Welcome to your digital diary!\n");
    do 
    {
        printf("What would you like to do?\n");
        printf("1. Add an entry\n");
        printf("2. View all entries\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                addEntry(diary, length);
                length++;
                diary = (struct DiaryEntry*)realloc(diary, sizeof(struct DiaryEntry) * (length + 1));
                break;
            case 2:
                printf("\n");
                for (int i = 0; i < length; i++) 
                {
                    printf("%d-%d-%d: %s\n", diary[i].day, diary[i].month, diary[i].year, diary[i].entry);
                }
                printf("\n");
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid input, please enter a number from 1-3.\n");
        }
    } while (choice != 3);
    free(diary);
    return 0;
}

void addEntry(struct DiaryEntry* diary, int length) 
{
    printf("Enter the date of the entry (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &diary[length].day, &diary[length].month, &diary[length].year);
    printf("Enter your diary entry (maximum 1000 characters):\n");
    scanf("%s", diary[length].entry);
    printf("Entry added!\n");
}