//FormAI DATASET v1.0 Category: Firewall ; Style: cheerful
#include <stdio.h>

// A cheerful Firewall program to protect the network!
// This program filters incoming traffic based on rules set by the user.

int main() {
    
    // Let's start by greeting the user!
    printf("Hello, happy user! You are now running the cheerful Firewall program!\n");

    // Let's create an array to store the rules
    char rules[100][100];

    // Let's ask the user to set the rules
    printf("Please enter the rules you'd like the Firewall to enforce:\n");

    int i = 0; // Counter variable

    // Let's use a loop to add the rules to the array
    while (1) {
        printf("%d. ", i+1); // Display the rule number
        scanf("%s", rules[i]); // Get the rule from the user

        i++; // Increment the counter

        // Let's ask if the user wants to add more rules
        printf("Do you want to add more rules? (Y/N)\n");
        char answer;
        scanf(" %c", &answer);

        // If the user says no, break out of the loop
        if (answer == 'N' || answer == 'n') {
            break;
        }
    }

    // Let's display the rules to the user
    printf("\n\nThe rules you've set are:\n");
    for (int j = 0; j < i; j++) {
        printf("%d. %s\n", j+1, rules[j]);
    }

    // Let's simulate incoming traffic
    printf("\n\nIncoming traffic...\n");

    // Let's use another loop to check if the incoming traffic follows the rules
    while (1) {
        char incoming[100];
        printf("Please enter incoming traffic (or enter 'quit' to exit):\n");
        scanf("%s", incoming);

        if (strcmp(incoming, "quit") == 0) { // If the user wants to quit, break out of the loop
            break;
        }

        // Let's check if the incoming traffic follows the rules
        int matched = 0;
        for (int j = 0; j < i; j++) {
            if (strstr(incoming, rules[j]) != NULL) { // If the rule is found in the incoming traffic, set matched to 1 and break out of the loop
                matched = 1;
                break;
            }
        }

        if (matched) { // If the traffic matched a rule, allow it
            printf("Traffic allowed!\n");
        } else { // If the traffic didn't match any rules, block it
            printf("Traffic blocked!\n");
        }
    }

    // Let's say goodbye to the user!
    printf("\n\nThank you for using the cheerful Firewall program! Have a nice day!\n");

    return 0;
}