//FormAI DATASET v1.0 Category: Digital Diary ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {

    // Let's introduce ourselves, shall we?
    printf("Hello there! I am your digital diary. What shall we name this masterpiece of a diary?\n");

    // Let the user take the lead in naming the diary
    char diary[20];
    scanf("%s", diary);

    // Let's have some fun and throw in a pun!
    printf("Great choice, %s! This diary is going to be 'write' up your alley!\n", diary);

    // Let's begin by getting some entry information from the user
    char date[11], entry[1000];
    printf("\nSo, what day is it today? (Please enter in 'dd/mm/yyyy' format):\n");
    scanf("%s", date);
    printf("\nFantastic. Now, go ahead and pour your heart out! (Limit: 1000 characters):\n");
    getchar();
    fgets(entry, 1000, stdin);

    // Let's give the user a summary of their entry
    printf("\n\n----- %s's %s Entry -----\nDate: %s\n\n%s\n\n-----\n", diary, date, date, entry);

    // Let the user decide if they want to add more to their entry
    char addMore[4];
    printf("\nWould you like to add more to this entry? (y/n):\n");
    scanf("%s", addMore);
    int counter = 1;

    // Let the user continue adding to their entry as long as they desire (limit = 10 entries)
    while (strcmp(addMore, "y") == 0 && counter <= 10) {

        // Get entry information from the user
        printf("\n----- Entry #%d -----\nDate:\n", counter + 1);
        scanf("%s", date);
        printf("\nGo ahead and keep writing! (Limit: 1000 characters):\n");
        getchar();            
        fgets(entry, 1000, stdin);

        // Give the user a summary of their entry
        printf("\n\n----- %s's %s Entry -----\nDate: %s\n\n%s\n\n-----\n", diary, date, date, entry);

        // Check if the user wants to add more to their entry
        printf("\nWould you like to add more to this entry? (y/n):\n");
        scanf("%s", addMore);
        counter++;
    }

    // Let the user know they've reached their diary limit
    if (counter == 10) {
        printf("\nSorry, %s! You've reached your diary limit for today. Goodnight!\n", diary);
    } else {
        // Let the user know they've finished for the day
        printf("\nLooks like you're done for the day, %s! Sweet dreams!\n", diary);
    }

    return 0;
}