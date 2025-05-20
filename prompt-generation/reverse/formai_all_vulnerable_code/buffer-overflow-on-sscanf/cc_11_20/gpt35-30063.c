//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: authentic
#include <stdio.h>
#include <string.h>

int main() {
    char date[30];
    int day, month, year;
    printf("Enter a date (Format: dd/mm/yyyy) : ");
    scanf("%s", date);

    sscanf(date, "%d/%d/%d", &day, &month, &year);
    printf("Day: %d\n", day);
    printf("Month: %d\n", month);
    printf("Year: %d\n", year);

    switch(month) { // switch to convert month to string
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
        default:
            printf("Invalid month.");
            return 0;
    }

    printf("%d, %d", day, year);
    return 0;
}