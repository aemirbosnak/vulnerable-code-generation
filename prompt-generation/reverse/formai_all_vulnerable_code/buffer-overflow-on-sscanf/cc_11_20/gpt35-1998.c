//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

// Function to check if the year is a leap year
int isLeap(int year) {
    return (year%4==0 && year%100!=0 || year%400==0);
}

// Function to display the result of the date conversion
void display(int year, int month, int day) {
    printf("The date in Natural Language is:\n");
    
    // Convert year
    if (year >= 2000) {
        printf("After the fall of civilization in the year %d, ", year);
    } else {
        printf("In the year %d, before the end of the world, ", year);
    }
    
    // Convert month
    switch (month) {
        case 1:
            printf("the first month");
            break;
        case 2:
            printf("the second month");
            break;
        case 3:
            printf("the third month");
            break;
        case 4:
            printf("the fourth month");
            break;
        case 5:
            printf("the fifth month");
            break;
        case 6:
            printf("the sixth month");
            break;
        case 7:
            printf("the seventh month");
            break;
        case 8:
            printf("the eighth month");
            break;
        case 9:
            printf("the ninth month");
            break;
        case 10:
            printf("the tenth month");
            break;
        case 11:
            printf("the eleventh month");
            break;
        case 12:
            printf("the twelfth month");
            break;
        default:
            break;
    }
    
    // Convert day
    if (day == 1 || day == 21 || day == 31) {
        printf(" %dst day.\n", day);
    } else if (day == 2 || day == 22) {
        printf(" %dnd day.\n", day);
    } else if (day == 3 || day == 23) {
        printf(" %drd day.\n", day);
    } else {
        printf(" %dth day.\n", day);
    }
}

int main() {
    int day, month, year;
    char input[11];
    
    // Get input from user
    printf("Enter a date in the format DD/MM/YYYY: ");
    fgets(input, 11, stdin);
    
    // Parse input
    sscanf(input,"%d/%d/%d",&day,&month,&year);
    
    // Check if input is valid
    if (month<1 || month>12 || day<1 || day>31) {
        printf("Invalid date.\n");
        return 0;
    } else if (month==2 && day>29) {
        printf("Invalid date.\n");
        return 0;
    } else if ((month==4 || month==6 || month==9 || month==11) && day>30) {
        printf("Invalid date.\n");
        return 0;
    } else if (day==31 && (month==2 || month==4 || month==6 || month==9 || month==11)) {
        printf("Invalid date.\n");
        return 0;
    }
    
    // Check if leap year
    if (month==2 && day==29 && !isLeap(year)) {
        printf("Invalid date.\n");
        return 0;
    }
    
    // Display result
    display(year, month, day);
    
    return 0;
}