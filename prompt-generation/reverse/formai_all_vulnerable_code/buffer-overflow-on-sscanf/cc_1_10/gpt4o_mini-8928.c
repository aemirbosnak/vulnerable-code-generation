//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototype declarations
void printWelcomeMessage();
void getNaturalDate(char *dateInput);
void convertToDate(char *dateInput, struct tm *date);
void displayDate(struct tm *date);
void printGoodbyeMessage();

int main() {
    char dateInput[100];
    struct tm date;

    printWelcomeMessage();

    // We'll run until the user inputs "exit"
    while (1) {
        printf("\nPlease enter a date in natural language (or type 'exit' to leave): ");
        fgets(dateInput, sizeof(dateInput), stdin);
        dateInput[strcspn(dateInput, "\n")] = 0;  // Remove newline character
        
        if (strcmp(dateInput, "exit") == 0) {
            printGoodbyeMessage();
            break;
        }

        getNaturalDate(dateInput);
        convertToDate(dateInput, &date);
        displayDate(&date);
    }

    return 0;
}

void printWelcomeMessage() {
    printf("🌟 Welcome to the Cheerful Natural Language Date Converter! 🌟\n");
    printf("You can enter dates like:\n");
    printf(" - \"next Friday\"\n");
    printf(" - \"July 20, 2023\"\n");
    printf(" - \"the first day of next month\"\n");
    printf("Let's make some date magic! ✨\n");
}

void getNaturalDate(char *dateInput) {
    printf("You've entered: \"%s\" 🌼\n", dateInput);
}

void convertToDate(char *dateInput, struct tm *date) {
    time_t t = time(NULL);
    struct tm *currentTime = localtime(&t);
    
    // Initialize date with current time
    *date = *currentTime;

    // Let's start processing input
    if (strstr(dateInput, "next")) {
        // Handle 'next' occurrences
        if (strstr(dateInput, "week")) {
            date->tm_mday += 7; // Add 7 days for next week 
        } else if (strstr(dateInput, "month")) {
            date->tm_mon += 1; // Next month
        }
    } else if (strstr(dateInput, "first day of next month")) {
        date->tm_mday = 1; // Set to first of next month
        date->tm_mon += 1; // Increment month
    } else {
        // Attempt a more straightforward date parsing
        sscanf(dateInput, "%d-%d-%d", &date->tm_year, &date->tm_mon, &date->tm_mday);

        // Adjust year and month for tm structure
        date->tm_year -= 1900; // Year starts from 1900
        date->tm_mon -= 1; // Month is 0-11
    }

    // Normalize the time structure
    mktime(date);
    printf("Transformed into our cheerful date struct! 🎉\n");
}

void displayDate(struct tm *date) {
    char dateString[100];
    strftime(dateString, sizeof(dateString), "%A, %B %d, %Y", date);
    printf("Here comes the date: %s! 🌈\n", dateString);
}

void printGoodbyeMessage() {
    printf("🌻 Thank you for using our Cheery Date Converter! 🌻\n");
    printf("Have a fantastically beautiful day! 😄\n");
}