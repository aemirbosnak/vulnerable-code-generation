//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void parseInput(char *input);
void printDate(struct tm *date);

// Main function
int main() {
    char input[100];

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("You can enter a date in the format of:\n");
    printf("1. 'Next Monday'\n");
    printf("2. '3 days from now'\n");
    printf("3. 'January 1st, 2022'\n");
    printf("4. 'Tomorrow'\n");
    printf("5. 'In 2 weeks'\n");
    printf("Type 'exit' to quit the program.\n\n");

    while (1) {
        printf("Please enter a date: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character
        
        if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        parseInput(input);
    }

    return 0;
}

// Function to parse the user input
void parseInput(char *input) {
    time_t t = time(NULL);
    struct tm *currentTime = localtime(&t);
    struct tm date = *currentTime;

    if (strstr(input, "next") && strstr(input, "Monday")) {
        date.tm_wday = (1 - currentTime->tm_wday + 7) % 7 + 7; // Next Monday
    } else if (strstr(input, "tomorrow")) {
        date.tm_mday += 1;
    } else if (strstr(input, "days from now")) {
        int days;
        sscanf(input, "%d days from now", &days);
        date.tm_mday += days;
    } else if (strstr(input, "In") && strstr(input, "weeks")) {
        int weeks;
        sscanf(input, "In %d weeks", &weeks);
        date.tm_mday += weeks * 7;
    } else {
        sscanf(input, "%d/%d/%d", &date.tm_mday, &date.tm_mon, &date.tm_year);
        date.tm_year -= 1900; // Adjust for struct tm
        date.tm_mon -= 1; // Adjust for struct tm
    }

    // Normalize date values
    mktime(&date);
    printDate(&date);
}

// Function to print formatted date
void printDate(struct tm *date) {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", date);
    printf("Converted date: %s\n\n", buffer);
}