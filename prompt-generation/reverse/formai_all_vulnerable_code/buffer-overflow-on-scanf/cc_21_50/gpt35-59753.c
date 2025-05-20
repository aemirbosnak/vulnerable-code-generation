//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: funny
#include<stdio.h>
#include<stdlib.h>

int main(){
    char date[11]; //declaring an array to store date string
    int day, month, year; //declaring variables for day, month and year
    printf("Welcome to Natural Language Date Converter!\n");
    printf("Please enter the date in natural language: ");
    scanf("%s", date); //taking user input for date in natural language
    
    printf("Converting your input... ");
    //let's add some suspense, shall we?
    printf("Done!\n");
    
    //converting day from string to integer
    sscanf(date, "%d", &day);
    //if the input contains only day and no month or year
    if(day>0 && day<32){
        printf("%d", day);
        //displaying the suffix of the day
        switch(day){
            case 1:
            case 21:
            case 31:
                printf("st");
                break;
            case 2:
            case 22:
                printf("nd");
                break;
            case 3:
            case 23:
                printf("rd");
                break;
            default:
                printf("th");
        }
        printf(" of ");
        //now that we have the day, let's ask for the month
        printf("which month, you ask? ");
        //adding a question to keep things light-hearted
        scanf("%s", date);
        //converting month from string to integer
        sscanf(date, "%d", &month);
        //displaying the month in text form
        switch(month){
            case 1:
                printf("January");
                break;
            case 2:
                printf("February");
                break;
            case 3:
                printf("March");
                break;
            case 4:
                printf("April");
                break;
            case 5:
                printf("May");
                break;
            case 6:
                printf("June");
                break;
            case 7:
                printf("July");
                break;
            case 8:
                printf("August");
                break;
            case 9:
                printf("September");
                break;
            case 10:
                printf("October");
                break;
            case 11:
                printf("November");
                break;
            case 12:
                printf("December");
                break;
            default:
                //if month is not within 1-12, we exit the program
                printf("Sorry, I am not programmed to handle that input. Goodbye!");
                exit(0);
        }
        printf(", in the year? ");
        //ask for the year now
        scanf("%d", &year);
        printf("%d.\n", year);
        //display the final output
        printf("The full date is: %d", day);
        switch(day){
            case 1:
            case 21:
            case 31:
                printf("st");
                break;
            case 2:
            case 22:
                printf("nd");
                break;
            case 3:
            case 23:
                printf("rd");
                break;
            default:
                printf("th");
        }
        printf(" of ");
        switch(month){
            case 1:
                printf("January");
                break;
            case 2:
                printf("February");
                break;
            case 3:
                printf("March");
                break;
            case 4:
                printf("April");
                break;
            case 5:
                printf("May");
                break;
            case 6:
                printf("June");
                break;
            case 7:
                printf("July");
                break;
            case 8:
                printf("August");
                break;
            case 9:
                printf("September");
                break;
            case 10:
                printf("October");
                break;
            case 11:
                printf("November");
                break;
            case 12:
                printf("December");
                break;
        }
        printf(", %d.\n", year);
    }
    else{
        //if input is not in correct format, we exit the program
        printf("Sorry, I am not programmed to handle that input. Goodbye!");
        exit(0);
    }
    return 0;
}