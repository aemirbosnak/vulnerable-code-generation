//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *months[] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun", 
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

typedef struct {
    int day;
    int month;
    int year;
} Date;

Date parseDate(const char *input) {
    Date date = {0, 0, 0};
    char monthStr[4];
    int scannedItems = sscanf(input, "%d %3s %d", &date.day, monthStr, &date.year);
    
    if (scannedItems != 3) {
        printf("Whoops! That's not a date, my friend. Give me something like '21 Sep 2023'!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 12; i++) {
        if (strcmp(monthStr, months[i]) == 0) {
            date.month = i + 1; // 1-12
            break;
        }
    }

    if (date.month == 0) {
        printf("Hmm, I don't recognize that month. Please use short month names like 'Jan', 'Feb'...\n");
        exit(EXIT_FAILURE);
    }

    return date;
}

void printDateInDifferentFormats(Date date) {
    printf("Date: %02d/%02d/%04d\n", date.day, date.month, date.year);
    printf("Date: %04d-%02d-%02d\n", date.year, date.month, date.day);
    printf("Date: %s %02d, %04d\n", months[date.month - 1], date.day, date.year);
}

void giveAdviceBasedOnDate(Date date) {
    if (date.month == 12 && date.day == 25) {
        printf("Ho ho ho! Merry Christmas! Time for cookies and milk!\n");
    } else if (date.month == 1 && date.day == 1) {
        printf("Happy New Year! May your resolutions last longer than your leftovers!\n");
    } else if (date.month == 2 && date.day == 14) {
        printf("It's Valentine's Day! Don't forget to woo the one you love, or risk the lonely heart pizza!\n");
    } else {
        printf("No special advice for this day. Just keep being awesome!\n");
    }
}

int main() {
    char input[100];

    printf("Welcome to the Wacky Date Converter!\n");
    printf("Please enter a date in the format 'DD Mon YYYY': ");
    fgets(input, sizeof(input), stdin);
    
    // Strip newline character
    input[strcspn(input, "\n")] = 0;

    Date date = parseDate(input);
    printDateInDifferentFormats(date);
    giveAdviceBasedOnDate(date);

    printf("Now that you’re armed with date knowledge, go forth and confuse your friends!\n");
    return 0;
}