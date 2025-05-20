//FormAI DATASET v1.0 Category: Digital Diary ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHARACTERS 500

int main() {
    FILE *file;
    char fileName[50], input[MAX_CHARACTERS], date[30];
    time_t current_time;
    struct tm *time_info;

    // Prompt user for file name and open file for writing
    printf("Enter file name: ");
    scanf("%s", fileName);
    file = fopen(fileName, "w");

    if (file == NULL) {
        printf("Error opening file. Exiting program.");
        return 1;
    }

    // Prompt user to start writing
    printf("Start writing your diary entry:\n");

    // Get current date and time
    current_time = time(NULL);
    time_info = localtime(&current_time);
    strftime(date, 30, "%Y-%m-%d %H:%M:%S", time_info);

    // Write date to file
    fprintf(file, "--- %s ---\n\n", date);

    // Keep prompting user for input until they type "exit"
    while (1) {
        fgets(input, MAX_CHARACTERS, stdin);

        if (strcmp(input, "exit\n") == 0) {
            break;
        } else {
            fprintf(file, "%s", input);
        }
    }

    // Close file and exit program
    fclose(file);
    printf("Diary entry saved to %s.\n", fileName);

    return 0;
}