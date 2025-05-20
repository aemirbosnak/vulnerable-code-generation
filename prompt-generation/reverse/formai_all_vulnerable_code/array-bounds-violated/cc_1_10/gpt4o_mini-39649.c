//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

void printCrown() {
    printf("   /\\     /\\ \n");
    printf("  /  \\   /  \\ \n");
    printf(" /____\\_/____\\ \n");
    printf("   |  | |  | \n");
    printf("   |  | |  | \n");
    printf("   |__| |__| \n");
}

void declareDate(Date d) {
    char *months[] = { "January", "February", "March", "April", "May", "June", 
                       "July", "August", "September", "October", "November", "December" };

    printf("Hark! On this day of %d %s in the year of our Lord %d!\n", d.day, months[d.month - 1], d.year);
}

int equalsIgnoreCase(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        if (tolower((unsigned char)*str1) != tolower((unsigned char)*str2)) {
            return 0;
        }
        str1++;
        str2++;
    }
    return *str1 == *str2;
}

void parseDate(char *input, Date *d) {
    char *dayStr, *monthStr, *yearStr;
    
    dayStr = strtok(input, " ");
    monthStr = strtok(NULL, " ");
    yearStr = strtok(NULL, " ");
    
    if (dayStr != NULL) d->day = atoi(dayStr);
    if (monthStr != NULL) {
        if (equalsIgnoreCase(monthStr, "January")) d->month = 1;
        else if (equalsIgnoreCase(monthStr, "February")) d->month = 2;
        else if (equalsIgnoreCase(monthStr, "March")) d->month = 3;
        else if (equalsIgnoreCase(monthStr, "April")) d->month = 4;
        else if (equalsIgnoreCase(monthStr, "May")) d->month = 5;
        else if (equalsIgnoreCase(monthStr, "June")) d->month = 6;
        else if (equalsIgnoreCase(monthStr, "July")) d->month = 7;
        else if (equalsIgnoreCase(monthStr, "August")) d->month = 8;
        else if (equalsIgnoreCase(monthStr, "September")) d->month = 9;
        else if (equalsIgnoreCase(monthStr, "October")) d->month = 10;
        else if (equalsIgnoreCase(monthStr, "November")) d->month = 11;
        else if (equalsIgnoreCase(monthStr, "December")) d->month = 12;
    }
    if (yearStr != NULL) d->year = atoi(yearStr);
}

int main() {
    printCrown();
    
    char input[50];
    Date d;

    printf("Enter a date in the 'day Month year' format (e.g., '15 June 1215'):\n");
    fgets(input, 50, stdin);
    input[strcspn(input, "\n")] = 0; // Removing newline character

    parseDate(input, &d);
    
    declareDate(d);
    
    printf("Rejoice! The date has been recorded in the royal chronicles.\n");

    return 0;
}