//FormAI DATASET v1.0 Category: Digital Diary ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int choice;
    char date[20], title[50], message[500];
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(date, sizeof(date), "%m/%d/%Y", tm);
    FILE *fptr;

    printf("********** WELCOME TO YOUR DIGITAL DIARY **********\n");
    printf("1. Write an entry\n");
    printf("2. View previous entries\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            getchar();
            printf("\nEnter the title: ");
            fgets(title, sizeof(title), stdin);
            printf("\nEnter your message: ");
            fgets(message, sizeof(message), stdin);

            fptr = fopen("diary.txt", "a");
            fprintf(fptr, "\n%s\n%s\n%s\n", date, title, message);
            fclose(fptr);

            printf("\nEntry recorded successfully!\n");
            break;

        case 2:
            fptr = fopen("diary.txt", "r");
            if(fptr == NULL)
            {
                printf("\nNo previous entries found!\n");
                break;
            }

            printf("\n********** PREVIOUS ENTRIES **********\n");
            while(fgets(message, sizeof(message), fptr))
            {
                printf("\n%s", message);
            }
            fclose(fptr);
            break;

        case 3:
            printf("\nThank you for using the digital diary!\n");
            break;

        default:
            printf("\nInvalid choice! Please try again.\n");
            break;
    }
    return 0;
}