//FormAI DATASET v1.0 Category: Digital Diary ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int choice, num, month, day, year;
    char filename[20];
    FILE *fp;

    printf("*************************\n");
    printf("** DIGITAL DIARY 1.0 **\n");
    printf("*************************\n\n");

    while(1)
    {
        printf("1. Write an Entry\n");
        printf("2. View Last Entry\n");
        printf("3. View All Entries\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter today's date (mm/dd/yyyy): ");
                scanf("%d/%d/%d", &month, &day, &year);

                sprintf(filename, "entry_%02d%02d%d.txt", month, day, year);

                fp = fopen(filename, "w");

                printf("\nBegin typing your entry: \n");

                while((num=getchar()) != EOF)
                    fputc(num, fp);
                
                fclose(fp);

                printf("\nEntry saved successfully!\n");
                break;

            case 2:
                printf("\nEnter today's date (mm/dd/yyyy): ");
                scanf("%d/%d/%d", &month, &day, &year);

                sprintf(filename, "entry_%02d%02d%d.txt", month, day, year);

                fp = fopen(filename, "r");

                if(fp == NULL)
                {
                    printf("Entry not found!\n");
                    break;
                }

                printf("\n********* LAST ENTRY *********\n\n");

                while((num = fgetc(fp)) != EOF)
                    printf("%c", num);
                
                fclose(fp);
                break;

            case 3:
                printf("\nEnter today's date (mm/dd/yyyy): ");
                scanf("%d/%d/%d", &month, &day, &year);

                printf("\n********* ALL ENTRIES *********\n\n");

                srand(time(0));

                for(int i=1; i<=7; i++)
                {
                    sprintf(filename, "entry_%02d%02d%d.txt", month, (day-i), year);

                    fp = fopen(filename, "r");

                    if(fp != NULL)
                    {
                        printf("*************** Entry %d ***************\n\n", i);
                        
                        while((num = fgetc(fp)) != EOF)
                            printf("%c", num);
                        
                        printf("\n************************************\n\n");

                        fclose(fp);
                    }
                }

                break;

            case 4:
                printf("Exiting Program...\n");
                exit(0);

            default:
                printf("Invalid Choice!\n\n");
        }
    }

    return 0;
}