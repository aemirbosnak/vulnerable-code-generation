//FormAI DATASET v1.0 Category: Digital Diary ; Style: thoughtful
#include<stdio.h> //header file for standard I/O
#include<stdlib.h> //header file for exit() function
#include<string.h> //header file for string operations

int main()
{
    FILE *fp; //file pointer for file operations
    char date[10], event[100], ch; //variables for date, event and character inputs
    int option;

    printf("\t\t\tDigital Diary Program\n");
    printf("\t\t\t=======================\n\n");

    printf("Enter today's date (dd/mm/yyyy): ");
    scanf("%s", date);

    fp = fopen(date, "a"); //open file in "append" mode

    if(fp == NULL) //file error handling
    {
        printf("Error opening file.");
        exit(1);
    }

    printf("\n1. Add an event\n");
    printf("2. View all events\n");
    printf("3. Exit\n\n");

    while(1)
    {
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("\nEnter the event details: ");
                getchar(); //flushes out newline character from input stream
                fgets(event, 100, stdin); //read event details with whitespace
                fprintf(fp, "%s\n", event); //write event details to file
                printf("\nEvent added successfully\n");
                break;

            case 2:
                fseek(fp, 0, SEEK_SET); //set file pointer at beginning of file
                printf("\nAll events on %s:\n", date);

                while((ch = fgetc(fp)) != EOF) //print all events in file
                {
                    printf("%c", ch);
                }

                fseek(fp, 0, SEEK_END); //set file pointer at end of file
                if(ftell(fp) == 0) //if file is empty
                {
                    printf("\nNo events found.");
                }
                break;

            case 3:
                fclose(fp); //close file
                printf("\nGoodbye!");
                exit(0);

            default:
                printf("\nInvalid option.\n");
        }
    }

    return 0;
}