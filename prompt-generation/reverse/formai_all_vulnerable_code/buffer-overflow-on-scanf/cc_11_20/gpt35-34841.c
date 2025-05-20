//FormAI DATASET v1.0 Category: Data validation ; Style: expert-level
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool is_valid_date(int dd, int mm, int yy);

int main() {
    int date, month, year;
    
    printf("Enter a date (DD MM YYYY): ");
    scanf("%d %d %d", &date, &month, &year);
    
    if (is_valid_date(date, month, year)) {
        printf("The date entered is valid.\n");
    } else {
        printf("The date entered is invalid.\n");
    }
    
    return 0;
}

bool is_valid_date(int dd, int mm, int yy) {
    
    // Checking the range of year, month, and date
    if (yy < 1900 || yy > 9999 || mm < 1 || mm > 12)
        return false;
  
    // Handling February with leap year
    if (mm == 2) {
        if ((yy % 4 == 0 && yy % 100 != 0) || (yy % 400 == 0))
            if (dd > 29 || dd < 1)
                return false;
        else 
            if (dd > 28 || dd < 1)
                return false;
    }
    // Checking the days in April, June, September and November
    else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
        if (dd > 30 || dd < 1)
            return false;
    }
    // Checking the days in January, March, May, July, August, October and December
    else {
        if (dd > 31 || dd < 1)
            return false;
    }
  
    // All checks pass - date is valid
    return true;
}