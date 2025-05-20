//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void clear(){
    system("clear");
}

void pause(){
    printf("\nPress Enter to continue...");
    getchar();
}

int main(){

    time_t now = time(NULL);
    char buffer[26], command[50], temp_year[5];
    struct tm * time_info;
    time_info = localtime(&now);   
    strftime(buffer, 26, "%Y", time_info);
    int current_year = atoi(buffer);
    int year, month, day;
    int bad_input = 1;
    char choice;

    clear();
    printf("\nWelcome to the Time Travel Simulator!\n");

    while(1){
        
        printf("\nEnter a year from 1900 to the current year %d: ", current_year);
        scanf("%d", &year);
        if(year < 1900 || year > current_year){
            printf("\nInvalid Input!");
            continue;
        }
        break;
    }

    while(1){

        printf("\nEnter a month from 1 to 12: ");
        scanf("%d", &month);
        if(month < 1 || month > 12){
            printf("\nInvalid Input!");
            continue;
        }
        break;
    }

    while(1){

        printf("\nEnter a day from 1 to 31: ");
        scanf("%d", &day);

        if((month == 2 && day > 28) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) || (day < 1 || day > 31)){
            printf("\nInvalid Input");
            continue;    
        }

        break;
    }

    clear();
    printf("\nTraveling to %d/%d/%d...", day, month, year);

    printf("\nPress r to return to current time, or q to quit: ");
    scanf("%s", &choice);

    while(1){

        if(choice == 'r' || choice == 'R'){
            clear();
            printf("\nReturning to current time...");
            year = current_year;
            time_info = localtime(&now);
            month = time_info -> tm_mon + 1;
            day = time_info -> tm_mday;
            printf("\nCurrent time: %d/%d/%d", day, month, year);
            break;
        }

        else if(choice == 'q' || choice == 'Q'){
            printf("\nThank you for using Time Travel Simulator!");
            exit(0);
        }

        else{
            printf("\nInvalid command!");
            printf("\nPress r to return to current time, or q to quit: ");
            scanf("%s", &choice);
            continue;
        }
    }

    clear();
    printf("\nWhat would you like to do?\n\n");

    while(1){

        printf("1. Travel to the future\n");
        printf("2. Travel to the past\n");
        printf("3. Quit\n");

        scanf("%s", &command);

        if(strcmp(command, "1") == 0){

            while(1){

                printf("\nEnter the number of years in the future you want to travel: ");
                scanf("%d", &year);
                if(year < 1){
                    printf("\nInvalid Input!");
                    continue;
                }
                break;
            }

            clear();
            printf("\nTraveling to %d years in the future...", year);
            pause();

            while(year > 0){
                if(month == 2 && day == 28 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)){
                    day = 29;
                    year += 1;
                }
                else if((month == 4 || month == 6 || month == 9 || month == 11) && day == 30){
                    month += 1;
                    day = 1;
                }
                else if(month == 12 && day == 31){
                    year += 1;
                    month = 1;
                    day = 1;
                }
                else if(month == 2 && day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))){
                    month += 1;
                    day = 1;
                }
                else if(day == 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)){
                    month += 1;
                    day = 1;
                }
                else{
                    day += 1;
                }
                year -= 1;
            }

            printf("\nYou have arrived to %d/%d/%d", day, month, current_year + year);

            break;
        }

        else if(strcmp(command, "2") == 0){

            while(bad_input){

                printf("\nEnter the number of years in the past you want to travel: ");
                scanf("%d", &year);

                if(year < 0 || (current_year - year) < 1900 || (current_year - year) > current_year){
                    printf("\nInvalid Input!");
                    continue;
                }
                bad_input = 0;
            }

            clear();
            printf("\nTraveling to %d years in the past...", year);
            pause();

            while(year > 0){
                if(day == 1 && month == 3 && ((current_year - year) % 4 == 0 && (current_year - year) % 100 != 0 || (current_year - year) % 400 == 0)){
                    day = 29;
                    month -= 1;
                }
                else if(day == 1 && month == 3){
                    day = 28;
                    month -= 1;
                }
                else if(day == 1 && (month == 5 || month == 7 || month == 10 || month == 12)){
                    month -= 1;
                    day = 30;
                }
                else if(day == 1 && month == 1){
                    year -= 1;
                    month = 12;
                    day = 31;
                }
                else if(day == 1 && (month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11)){
                    month -= 1;
                    day = 31;
                }
                else{
                    day -= 1;
                }
                year -= 1;
            }

            printf("\nYou have arrived to %d/%d/%d", day, month, current_year - year);
            break;
        }

        else if(strcmp(command, "3") == 0){
            printf("\nThank you for using Time Travel Simulator!");
            exit(0);
        }

        else{
            printf("\nInvalid command!");
            continue;
        }
    }

    return 0;
}