//FormAI DATASET v1.0 Category: Log analysis ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main() {
    // The Adventure of the Mysterious Log File
    printf("The Adventure of the Mysterious Log File\n\n");

    // Define variables
    char logFileName[100]; // To store user input (log file name)
    char line[1000]; // To store each line of the log file
    char searchKeyword[100]; // To store user input (search keyword)
    int keywordCount = 0; // To count the number of times the search keyword appears in the log file
    int lineCounter = 0; // To count the total number of lines in the log file

    // Ask user to enter log file name
    printf("Please enter the name of the log file: ");
    scanf("%s", logFileName);

    // Open log file
    FILE *logFile = fopen(logFileName, "r");

    // Check if log file exists
    if (logFile == NULL) {
        printf("Sorry, I could not find the log file.\n");
    } else {
        // Ask user to enter search keyword
        printf("Please enter the search keyword: ");
        scanf("%s", searchKeyword);

        // Read each line of the log file
        while (fgets(line, sizeof(line), logFile)) {
            // Count total number of lines
            lineCounter++;

            // Check if line contains search keyword
            if (strstr(line, searchKeyword) != NULL) {
                // If keyword is found, increment keyword count
                keywordCount++;

                // Print the line number and the line text
                printf("Line %d: %s", lineCounter, line);
            }
        }

        // Close log file
        fclose(logFile);

        // Print the number of times the search keyword appears in the log file
        printf("\nThe search keyword appears %d times in the log file.\n", keywordCount);
    }

    return 0;
}