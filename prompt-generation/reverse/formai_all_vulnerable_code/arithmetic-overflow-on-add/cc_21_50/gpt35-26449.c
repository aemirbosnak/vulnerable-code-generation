//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: medieval
#include <stdio.h>

int main() {
    int day, month, year, num_days, total_days;
    char suffix[3];

    printf("Greetings traveller! I am a date converter that can help you understand the date you are looking at in a more medieval way.\n\n");

    printf("Please enter a day (1-31): ");
    scanf("%d", &day);

    printf("Please enter a month (1-12): ");
    scanf("%d", &month);

    printf("Please enter a year: ");
    scanf("%d", &year);

    // Calculate the number of total days since the beginning of the year
    switch(month) {
        case 12:
            num_days = 30;
        case 11:
            num_days = 31 + num_days;
        case 10:
            num_days = 30 + num_days;
        case 9:
            num_days = 31 + num_days;
        case 8:
            num_days = 31 + num_days;
        case 7:
            num_days = 30 + num_days;
        case 6:
            num_days = 31 + num_days;
        case 5:
            num_days = 30 + num_days;
        case 4:
            num_days = 31 + num_days;
        case 3:
            num_days = 28 + num_days;
        case 2:
            num_days = 31 + num_days;
        case 1:
            num_days = day;
    }

    // Check if the year is a leap year
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        if(month > 2) {
            num_days++;
        }
    }

    // Calculate the total number of days since 1st March 1 AD
    total_days = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + num_days + 306;

    // Determine the suffix for the day
    if(day == 1 || day == 21 || day == 31) {
        sprintf(suffix, "st");
    } else if(day == 2 || day == 22) {
        sprintf(suffix, "nd");
    } else if(day == 3 || day == 23) {
        sprintf(suffix, "rd");
    } else {
        sprintf(suffix, "th");
    }

    printf("\n\nThe date you entered is: %d%s of ", day, suffix);

    // Determine the month
    switch(month) {
        case 1:
            printf("January ");
            break;
        case 2:
            printf("February ");
            break;
        case 3:
            printf("March ");
            break;
        case 4:
            printf("April ");
            break;
        case 5:
            printf("May ");
            break;
        case 6:
            printf("June ");
            break;
        case 7:
            printf("July ");
            break;
        case 8:
            printf("August ");
            break;
        case 9:
            printf("September ");
            break;
        case 10:
            printf("October ");
            break;
        case 11:
            printf("November ");
            break;
        case 12:
            printf("December ");
            break;
    }

    printf("%d AD\n\n", total_days);

    printf("I hope you found my service helpful. Fare thee well on thine travels!");

    return 0;
}