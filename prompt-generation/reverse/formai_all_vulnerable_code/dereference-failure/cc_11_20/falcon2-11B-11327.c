//Falcon2-11B DATASET v1.0 Category: Digital Diary ; Style: futuristic
#include <stdio.h>
#include <string.h>

struct DiaryEntry {
    int date;
    char* title;
    char* content;
};

int main() {
    struct DiaryEntry entries[10];

    int numEntries = 0;
    printf("Welcome to the future! Let's start your digital diary.\n");
    printf("Please enter the date of your first entry in the format YYYY-MM-DD:\n");
    scanf("%d", &entries[numEntries].date);
    printf("Enter the title of your first entry:\n");
    gets(entries[numEntries].title);
    printf("Enter the content of your first entry:\n");
    gets(entries[numEntries].content);
    numEntries++;

    printf("Your entry has been saved!\n");

    while (1) {
        int index;
        printf("To add a new entry, enter 1.\n");
        printf("To view a previous entry, enter 2.\n");
        printf("To delete a previous entry, enter 3.\n");
        printf("To exit, enter 0.\n");
        scanf("%d", &index);

        if (index == 0) {
            printf("Goodbye!\n");
            break;
        } else if (index == 1) {
            printf("Enter the date of your new entry in the format YYYY-MM-DD:\n");
            scanf("%d", &entries[numEntries].date);
            printf("Enter the title of your new entry:\n");
            gets(entries[numEntries].title);
            printf("Enter the content of your new entry:\n");
            gets(entries[numEntries].content);
            numEntries++;
            printf("Your entry has been saved!\n");
        } else if (index == 2) {
            printf("Enter the index of the entry you want to view:\n");
            scanf("%d", &index);
            if (index >= 0 && index < numEntries) {
                printf("Entry %d:\n", index + 1);
                printf("Date: %d\n", entries[index].date);
                printf("Title: %s\n", entries[index].title);
                printf("Content: %s\n", entries[index].content);
            } else {
                printf("Invalid entry index.\n");
            }
        } else if (index == 3) {
            printf("Enter the index of the entry you want to delete:\n");
            scanf("%d", &index);
            if (index >= 0 && index < numEntries) {
                printf("Are you sure you want to delete entry %d? (y/n): ", index + 1);
                char deleteResponse;
                scanf(" %c", &deleteResponse);
                if (deleteResponse == 'y') {
                    for (int i = index; i < numEntries - 1; i++) {
                        entries[i] = entries[i + 1];
                    }
                    numEntries--;
                } else {
                    printf("Entry %d was not deleted.\n", index + 1);
                }
            } else {
                printf("Invalid entry index.\n");
            }
        }
    }

    return 0;
}