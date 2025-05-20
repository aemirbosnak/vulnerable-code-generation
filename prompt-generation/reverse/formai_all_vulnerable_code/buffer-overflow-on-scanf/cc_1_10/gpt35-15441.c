//FormAI DATASET v1.0 Category: Digital Diary ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int choice, date, month, year;
    char task[1000];

    srand(time(0));

    printf("Welcome to the Retro Digital Diary!\n");
    printf("What would you like to do today?\n");

    do{
        printf("\n[1] Add a new entry\n");
        printf("[2] View past entries\n");
        printf("[3] Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("\nEnter the date (DD/MM/YYYY): ");
                scanf("%d/%d/%d", &date, &month, &year);
                printf("Enter the task: ");
                scanf("\n%[^\n]", task);

                FILE *fptr; 
                char filename[20];
                sprintf(filename, "diary_%d%d%d.txt", date, month, year);

                fptr = fopen(filename, "a");

                if(fptr == NULL){
                    printf("\nError in opening file!");
                    exit(1);
                }

                fprintf(fptr, "%d/%d/%d\n%s\n", date, month, year, task);
                fclose(fptr);

                printf("\nEntry added successfully!\n");

                break;

            case 2:
                printf("\nEnter the date of the entry to view (DD/MM/YYYY): ");
                scanf("%d/%d/%d", &date, &month, &year);

                FILE *fp;
                char file[20];

                sprintf(file, "diary_%d%d%d.txt", date, month, year);

                fp = fopen(file, "r");

                if(fp == NULL){
                    printf("\nNo entries found for the entered date!");
                    break;
                }

                printf("\n");
                char ch = fgetc(fp);
                while(ch != EOF){
                    printf("%c", ch);
                    ch = fgetc(fp);
                }
                printf("\n");
                fclose(fp);
                break;

            case 3:
                printf("\nThank you for using Retro Digital Diary!\n");
                break;

            default:
                printf("\nInvalid choice. Please choose again.\n");
                break;

        }
    }while(choice != 3);

    return 0;
}