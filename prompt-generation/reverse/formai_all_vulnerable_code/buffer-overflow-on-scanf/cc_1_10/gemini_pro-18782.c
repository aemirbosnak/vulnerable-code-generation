//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

int main() {
    // Welcome the user
    printf("Greetings, Watson! I am Sherlock Holmes, and I am here to assist you with your date conversion needs.\n");

    // Get the original date from the user
    Date originalDate;
    printf("Please enter the original date in the format dd/mm/yyyy: ");
    scanf("%d/%d/%d", &originalDate.day, &originalDate.month, &originalDate.year);

    // Convert the original date to the desired format
    char desiredFormat[5];
    printf("Please enter the desired date format (e.g., dd-mm-yyyy, mm/dd/yyyy, etc.): ");
    scanf("%s", desiredFormat);

    char convertedDate[20];
    switch (desiredFormat[0]) {
        case 'd':
            sprintf(convertedDate, "%02d", originalDate.day);
            break;
        case 'm':
            sprintf(convertedDate, "%02d", originalDate.month);
            break;
        case 'y':
            sprintf(convertedDate, "%04d", originalDate.year);
            break;
    }

    switch (desiredFormat[1]) {
        case '-':
            strcat(convertedDate, "-");
            break;
        case '/':
            strcat(convertedDate, "/");
            break;
        default:
            break;
    }

    switch (desiredFormat[2]) {
        case 'd':
            sprintf(convertedDate, "%s%02d", convertedDate, originalDate.day);
            break;
        case 'm':
            sprintf(convertedDate, "%s%02d", convertedDate, originalDate.month);
            break;
        case 'y':
            sprintf(convertedDate, "%s%04d", convertedDate, originalDate.year);
            break;
    }

    // Print the converted date
    printf("The converted date is: %s\n", convertedDate);

    // Bid farewell to the user
    printf("Farewell, Watson! I hope this conversion has been enlightening.\n");

    return 0;
}