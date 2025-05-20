//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUFFER 256
#define MAX_MONTH_NAME 20

// A cheerful greeting message
void cheerfulGreeting() {
    printf("🎉🎊 Hello, lovely user! Welcome to the C Natural Language Date Converter! 🎊🎉\n");
    printf("You can convert your natural language dates into a structured format!\n");
    printf("Let's sprinkle a little magic on your dates! ✨\n\n");
}

// Function to retrieve month number from the month name
int getMonthNumber(const char *month) {
    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    for (int i = 0; i < 12; i++) {
        if (strcasecmp(months[i], month) == 0) {
            return i + 1; // Month numbers start from 1
        }
    }
    return 0; // Return 0 if month is not found
}

// Function to convert natural language date to struct tm
int convertNaturalLanguageDate(char *input, struct tm *date) {
    char month[MAX_MONTH_NAME];
    int day, year;
    char period[10];

    // Parse the input string
    int scannedItems = sscanf(input, "%d %s %d %s", &day, month, &year, period);
    
    // Check if the input matches the expected format
    if (scannedItems < 3) {
        printf("❌ Oops! The date format should be: 'Day Month Year'. Try again! 📅\n");
        return 0;
    }
    
    // Get month number
    int monthNumber = getMonthNumber(month);
    if (monthNumber == 0) {
        printf("❌ Oops! I couldn't recognize the month '%s'. Please use a valid month name! 🌸\n", month);
        return 0;
    }

    // Fill the date struct with values
    date->tm_mday = day;
    date->tm_mon = monthNumber - 1; // tm_mon is 0-11
    date->tm_year = year - 1900; // tm_year is years since 1900

    if (strcasecmp(period, "pm") == 0 || strcasecmp(period, "p.m.") == 0) {
        date->tm_hour = 12; // PM case
    } else if (strcasecmp(period, "am") == 0 || strcasecmp(period, "a.m.") == 0) {
        date->tm_hour = 0; // AM case
    } else {
        date->tm_hour = 0; // Default case
    }

    date->tm_min = 0; // Setting minutes to 0
    date->tm_sec = 0; // Setting seconds to 0
    date->tm_isdst = -1; // Not considering daylight saving time for simplicity

    return 1; // Success!
}

// Function to print the formatted date
void printFormattedDate(struct tm *date) {
    char formattedDate[MAX_BUFFER];
    strftime(formattedDate, sizeof(formattedDate), "%A, %d %B %Y, %I:%M %p", date);
    printf("🎉 Hooray! Here’s your date in a pleasant format: %s 🎉\n", formattedDate);
}

int main() {
    cheerfulGreeting();
    
    char input[MAX_BUFFER];
    struct tm date;

    printf("✨ Please enter the date in the format 'Day Month Year [AM/PM]':\n");
    printf("👉 ");
    fgets(input, MAX_BUFFER, stdin);
    
    // Remove newline character at the end
    input[strcspn(input, "\n")] = 0;

    if (convertNaturalLanguageDate(input, &date)) {
        printFormattedDate(&date);
    } else {
        printf("❌ Let's try that again! You can do it! 👏\n");
    }

    printf("✨ Thank you for using the C Natural Language Date Converter! Have a splendid day! ✨\n");
    return 0;
}