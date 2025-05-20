//FormAI DATASET v1.0 Category: Digital Diary ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

    printf("Welcome to your Digital Diary\n\n");

    int choice, year, month, day;
    char entry[1000];
    time_t now;

    while(1) {

        printf("\n\nChoose an option:\n");
        printf("1. Add new entry\n");
        printf("2. View previous entries\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("\nEnter today's date: (dd mm yyyy) ");
                scanf("%d %d %d", &day, &month, &year);
                printf("\nType your entry (max 1000 characters):\n");
                getchar();
                fgets(entry, 1000, stdin);
                now = time(NULL);
                printf("\nEntry added successfully!\n");
                break;

            case 2:
                printf("\nEnter the date of the entry you wish to view: (dd mm yyyy) ");
                scanf("%d %d %d", &day, &month, &year);

                //Generating random number for date
                srand(time(NULL));
                int randNum = rand() % 10;

                //Checking the random number
                if(randNum%2==0) {
                    printf("\nEntry not found for the date %d-%d-%d\n", day, month, year);
                }
                else {
                    printf("\nEntry found for the date %d-%d-%d:\n", day, month, year);
                    printf("%s", entry);
                }
                break;

            case 3:
                printf("\nExiting Digital Diary...");
                exit(0);

            default:
                printf("\nInvalid choice! Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}