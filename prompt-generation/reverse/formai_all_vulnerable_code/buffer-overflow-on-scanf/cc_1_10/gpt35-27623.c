//FormAI DATASET v1.0 Category: System event logger ; Style: funny
#include <stdio.h> 

int main() {
    printf("Welcome to the Event Logger!\n");
    printf("I am your trusty assistant, Mr. Logger!\n");
    printf("Let's log some events today, shall we?\n");
    printf("Please enter the event code below:\n");
    
    int event_code;
    scanf("%d", &event_code);

    // Oops, they forgot to enter an event code
    if (event_code == 0) {
        printf("ERROR: You forgot to enter an event code!\n");
        printf("Mr. Logger cannot log an event without a code!\n");
        printf("Please try again later.\n");

        return 1; // return an error code
    }

    printf("Wonderful! Now, what is the name of this event?\n");

    char event_name[50];
    scanf("%s", event_name);

    // Check if event name has any special characters
    for (int i = 0; i < strlen(event_name); i++) {
        if (!isalpha(event_name[i]) && !isspace(event_name[i])) {
            printf("WARNING: Event name cannot contain special characters (%c)!\n", event_name[i]);
            printf("Mr. Logger will still log this event, but it may cause issues later.\n");
        }
    }

    printf("Excellent! Now, on what date did this event occur?\n");
    
    char event_date[10];
    scanf("%s", event_date);

    // Check if date is in the right format
    if (strlen(event_date) != 10 || event_date[4] != '-' || event_date[7] != '-') {
        printf("ERROR: Date format should be YYYY-MM-DD!\n");
        printf("Mr. Logger cannot log this event without a valid date!\n");
        printf("Please try again later.\n");

        return 1; // return an error code
    }

    printf("Wow, you're on a roll! Now, give me a brief description of the event:\n");
    
    char event_description[200];
    scanf(" %[^\n]", event_description);

    printf("Thank you for the information! I will now log this event with the following details:\n");
    printf("Event Code: %d\n", event_code);
    printf("Event Name: %s\n", event_name);
    printf("Event Date: %s\n", event_date);
    printf("Event Description: %s\n", event_description);
    printf("Congratulations, you have successfully logged an event with Mr. Logger!\n");

    return 0; // return success code
}