//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 5
#define DATE_STRING_SIZE 100

void convert_date(const char *date_input, char *output) {
    struct tm tm = {0};
    
    // Use strptime to parse the input date string
    if (strptime(date_input, "%B %d, %Y", &tm) == NULL) {
        strcpy(output, "Invalid Date Format. Please use 'Month Day, Year'.");
    } else {
        // Format the output into standard format
        strftime(output, DATE_STRING_SIZE, "%Y-%m-%d", &tm);
    }
}

void handle_player(int player_id) {
    char date_input[DATE_STRING_SIZE];
    char output[DATE_STRING_SIZE];

    printf("Player %d, enter a date (e.g., 'March 10, 2023'): ", player_id);
    fgets(date_input, DATE_STRING_SIZE, stdin);
    date_input[strcspn(date_input, "\n")] = 0;  // Remove newline character

    convert_date(date_input, output);
    
    printf("Player %d entered: '%s' -> Converted Date: '%s'\n\n", player_id, date_input, output);
}

int main() {
    int player_count = 0;

    printf("Welcome to the Multiplayer Natural Language Date Converter!\n");
    
    printf("How many players will be converting dates? (Max %d): ", MAX_PLAYERS);
    scanf("%d", &player_count);
    getchar(); // clean the newline after scanf

    if (player_count < 1 || player_count > MAX_PLAYERS) {
        printf("Invalid number of players. Please restart the program.\n");
        return 1;
    }

    for (int i = 1; i <= player_count; i++) {
        handle_player(i);
    }

    printf("Thank you for playing! Date conversions complete.\n");
    return 0;
}