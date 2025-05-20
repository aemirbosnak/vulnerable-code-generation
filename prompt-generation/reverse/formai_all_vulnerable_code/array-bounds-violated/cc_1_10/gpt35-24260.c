//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define BUFFER_SIZE 100
 
// Function to check if a given year is leap year or not
int isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
 
// Function to validate if a given date is valid or not
int isValidDate(int dd, int mm, int yyyy) 
{
    if (mm < 1 || mm > 12)
        return 0;
    if (dd < 1 || dd > 31)
        return 0;
    if (mm == 2) {
        if (isLeapYear(yyyy))
            return (dd <= 29);
        else
            return (dd <= 28);
    }
    if (mm == 4 || mm == 6 || mm == 9 || mm == 11)
        return (dd <= 30);
    return 1;
}
 
// Function to convert given date (dd/mm/yyyy) to words
void dateToWords(char* dateStr) {
    char* months[] = { "", "January", "February", "March","April", "May", "June", "July","August", "September", "October", "November", "December" };
    char* days[] = { "", "First", "Second", "Third", "Fourth", "Fifth", "Sixth", "Seventh", "Eighth", "Ninth", "Tenth", "Eleventh", "Twelfth", "Thirteenth", "Fourteenth", "Fifteenth", "Sixteenth", "Seventeenth", "Eighteenth", "Nineteenth", "Twentieth", "Twenty-First", "Twenty-Second", "Twenty-Third", "Twenty-Fourth", "Twenty-Fifth", "Twenty-Sixth", "Twenty-Seventh", "Twenty-Eighth", "Twenty-Ninth", "Thirtieth", "Thirty-First" };
     
    int dd, mm, yyyy;
    sscanf(dateStr, "%d/%d/%d", &dd, &mm, &yyyy);
     
    if (isValidDate(dd, mm, yyyy)) {
        // Print date in words
        printf("%s %s, %d\n", days[dd], months[mm], yyyy);
    } else {
        printf("Invalid date!\n");
    }
}
 
int main() {
    char dateStr[BUFFER_SIZE];
    printf("Enter date (dd/mm/yyyy): ");
    fgets(dateStr, BUFFER_SIZE, stdin);
 
    // remove trailing newline character from date string
    dateStr[strlen(dateStr) - 1] = '\0';
     
    dateToWords(dateStr);
    return 0;
}