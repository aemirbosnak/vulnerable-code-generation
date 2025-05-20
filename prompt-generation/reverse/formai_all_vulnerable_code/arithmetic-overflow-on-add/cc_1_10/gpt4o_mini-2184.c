//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function declarations
void getDateInfo(char *input);
void printDate(struct tm *timeinfo);

int main() {
    char input[100];

    printf("🎉 Welcome to the Surprise Natural Language Date Converter! 🎉\n");
    printf("Please enter a date in natural language (e.g., 'next Friday', '3 days from now', 'in 2 weeks'): ");
    
    // Get the input from the user
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove the newline character

    // Process the input and get the date information
    getDateInfo(input);

    return 0;
}

// Function to interpret the date input
void getDateInfo(char *input) {
    time_t now;
    struct tm timeinfo;
    
    // Get the current time
    time(&now);
    localtime_r(&now, &timeinfo);
    
    // Surprise! Let's get a quirky interpretation of the input
    if (strcmp(input, "today") == 0) {
        // Setting the date to today
        printf("You want the date for today! 🎊 Let's check it out...\n");
    } else if (strcmp(input, "tomorrow") == 0) {
        timeinfo.tm_mday += 1; // Add a day for tomorrow
        printf("You want to know what will happen tomorrow? Let's find out! 🌞\n");
    } else if (strncmp(input, "next", 4) == 0) {
        char *day = input + 5; // Get the day specified after 'next'
        if (strcmp(day, "Monday") == 0) {
            timeinfo.tm_mday += (7 - timeinfo.tm_wday) % 7 + 1; // Move to next Monday
        } else if (strcmp(day, "Tuesday") == 0) {
            timeinfo.tm_mday += (7 - timeinfo.tm_wday) % 7 + 2;
        } else if (strcmp(day, "Wednesday") == 0) {
            timeinfo.tm_mday += (7 - timeinfo.tm_wday) % 7 + 3;
        } else if (strcmp(day, "Thursday") == 0) {
            timeinfo.tm_mday += (7 - timeinfo.tm_wday) % 7 + 4;
        } else if (strcmp(day, "Friday") == 0) {
            timeinfo.tm_mday += (7 - timeinfo.tm_wday) % 7 + 5;
        } else if (strcmp(day, "Saturday") == 0) {
            timeinfo.tm_mday += (7 - timeinfo.tm_wday) % 7 + 6;
        } else if (strcmp(day, "Sunday") == 0) {
            timeinfo.tm_mday += (7 - timeinfo.tm_wday) % 7 + 7;
        } else {
            printf("Hmm... I couldn't understand the day: '%s'. 🎭 But I'll try my best!\n", day);
            return;
        }
    } else if (strstr(input, "days from now")) {
        int days;
        sscanf(input, "%d days from now", &days);
        timeinfo.tm_mday += days; // Add specified days
        printf("I'll calculate the date for you, including those %d days! ⏳\n", days);
    } else if (strstr(input, "weeks from now")) {
        int weeks;
        sscanf(input, "%d weeks from now", &weeks);
        timeinfo.tm_mday += weeks * 7; // Weeks to days
        printf("Exciting! Let's jump forward by %d weeks! 🚀\n", weeks);
    } else {
        printf("🙃 Interesting phrase! I might need more training to understand that.\n");
        return;
    }

    // Normalize the date structure
    mktime(&timeinfo); // Normalize the time structure

    // Print the final date
    printDate(&timeinfo);
}

// Function to print formatted date
void printDate(struct tm *timeinfo) {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y", timeinfo);
    printf("🎆 Here is the converted date: %s 🎆\n", buffer);
}