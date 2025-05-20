//FormAI DATASET v1.0 Category: Hotel Management System ; Style: lively
#include<stdio.h>
#include<string.h>
int main() {
    int rooms[10] = {1,2,3,4,5,6,7,8,9,10};
    int availability[10] = {1,1,1,1,1,1,1,1,1,1};
    char names[10][20];
    int checkin_dates[10][3];
    int checkout_dates[10][3];

    printf("\n\tWelcome to our Hotel Management System!\n");
    printf("\nAvailable rooms:\n");
    for(int i=0; i<10; i++){
        if(availability[i])
            printf("%d ", rooms[i]);
    }
    printf("\n");

    //checkin
    int checkin_room;
    char checkin_name[20];
    int checkin_month, checkin_day, checkin_year;
    printf("\nDo you wish to checkin?(y/n): ");
    char choice;
    scanf(" %c", &choice);
    if(choice == 'y') {
        printf("\nEnter the room number you wish to checkin: ");
        scanf("%d", &checkin_room);
        if(availability[checkin_room-1]){
            printf("\nEnter your name: ");
            scanf("%s", checkin_name);
            printf("Enter the date you wish to checkin (mm/dd/yyyy): ");
            scanf("%d/%d/%d", &checkin_month, &checkin_day, &checkin_year);
            availability[checkin_room-1] = 0;
            strcpy(names[checkin_room-1], checkin_name);
            checkin_dates[checkin_room-1][0] = checkin_month;
            checkin_dates[checkin_room-1][1] = checkin_day;
            checkin_dates[checkin_room-1][2] = checkin_year;
            printf("\nThank you for checking in! Your room number is %d", checkin_room);
        }
        else{
            printf("\nSorry, the room is already occupied.");
        }
    }

    //checkout
    int checkout_room;
    printf("\n\nDo you wish to checkout?(y/n): ");
    scanf(" %c", &choice);
    if(choice == 'y') {
        printf("\nEnter the room number you wish to checkout: ");
        scanf("%d", &checkout_room);
        if(!availability[checkout_room-1]){
            int total_days = 0;
            int checkout_month, checkout_day, checkout_year;
            printf("\nEnter the date you wish to checkout (mm/dd/yyyy): ");
            scanf("%d/%d/%d", &checkout_month, &checkout_day, &checkout_year);
            printf("\nCalculating total bill...");
            int daysmonth[] = {0,31,59,90,120,151,181,212,243,273,304,334};
            int days1, days2;
            days1 = daysmonth[checkin_dates[checkout_room-1][0]-1] + checkin_dates[checkout_room-1][1] + (checkin_dates[checkout_room-1][2]-1) * 365;
            days1 += ((checkin_dates[checkout_room-1][2]-1)/4) - ((checkin_dates[checkout_room-1][2]-1)/100) + ((checkin_dates[checkout_room-1][2]-1)/400);
            days2 = daysmonth[checkout_month-1] + checkout_day + (checkout_year-1) * 365;
            days2 += ((checkout_year-1)/4) - ((checkout_year-1)/100) + ((checkout_year-1)/400);
            total_days = days2 - days1;
            printf("\nThe total number of days stayed is %d", total_days);
            printf("\nThank you for staying with us! Your total bill is $%d", total_days * 100);
            availability[checkout_room-1] = 1;
            names[checkout_room-1][0] = '\0';
            checkin_dates[checkout_room-1][0] = 0;
            checkin_dates[checkout_room-1][1] = 0;
            checkin_dates[checkout_room-1][2] = 0;
            checkout_dates[checkout_room-1][0] = checkout_month;
            checkout_dates[checkout_room-1][1] = checkout_day;
            checkout_dates[checkout_room-1][2] = checkout_year;
        }
        else{
            printf("\nSorry, the room is already empty.");
        }
    }
    return 0;
}