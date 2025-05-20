//Falcon2-11B DATASET v1.0 Category: Digital Diary ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char diary[100][80];
    int diaryIndex = 0;
    int pageCount = 0;

    printf("Welcome to the Digital Diary of the Middle Ages!\n");
    printf("Enter the number of pages you wish to write in your diary:\n");
    scanf("%d", &pageCount);

    printf("Enter the title of your diary:\n");
    scanf("%s", diary[diaryIndex]);
    diaryIndex++;

    for (int i = 0; i < pageCount; i++) {
        printf("Enter the date of your entry:\n");
        scanf("%s", diary[diaryIndex]);
        diaryIndex++;

        printf("Enter the content of your entry:\n");
        scanf("%s", diary[diaryIndex]);
        diaryIndex++;

        printf("Do you want to add another entry? (Y/N): ");
        char addEntry = getchar();

        if (addEntry == 'Y' || addEntry == 'y') {
            printf("Enter the date of your next entry:\n");
            scanf("%s", diary[diaryIndex]);
            diaryIndex++;

            printf("Enter the content of your next entry:\n");
            scanf("%s", diary[diaryIndex]);
            diaryIndex++;
        } else {
            break;
        }
    }

    printf("Your diary has been created with %d pages.\n", pageCount);

    for (int i = 0; i < pageCount; i++) {
        printf("Page %d:\n", i + 1);
        printf("Title: %s\n", diary[i]);
        printf("Date: %s\n", diary[i + 1]);
        printf("Content: %s\n", diary[i + 2]);
    }

    printf("Thank you for using the Digital Diary of the Middle Ages!\n");
    return 0;
}