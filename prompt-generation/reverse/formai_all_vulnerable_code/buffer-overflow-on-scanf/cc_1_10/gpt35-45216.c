//FormAI DATASET v1.0 Category: Firewall ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char input[1000], option;
    int count = 0;

    printf("\nWelcome to My Firewall Program - blocking traffic from hackers!\n\n");

    printf("Please enter the traffic you want to block: ");
    fgets(input, 1000, stdin);
    input[strcspn(input, "\n")] = 0;

    printf("\nWhat type of traffic do you want to block?\n");
    printf("1. Inbound\n");
    printf("2. Outbound\n");
    printf("Enter your option (1/2): ");
    scanf(" %c", &option);

    printf("\n*******************************************\n");

    if(option == '1') {
        printf("Inbound traffic blocked for: %s\n", input);
    }
    else if(option == '2') {
        printf("Outbound traffic blocked for: %s\n", input);
    }
    else {
        printf("Invalid option selected. Please try again.\n");
        return 0;
    }

    printf("*******************************************\n");

    printf("\nDo you want to add more traffic to the block list? (y/n): ");
    scanf(" %c", &option);

    while(option == 'y' || option == 'Y') {
        printf("Please enter the traffic you want to block: ");
        fflush(stdin);
        fgets(input, 1000, stdin);
        input[strcspn(input, "\n")] = 0;

        if(option == '1') {
            printf("Inbound traffic blocked for: %s\n", input);
        }
        else if(option == '2') {
            printf("Outbound traffic blocked for: %s\n", input);
        }

        printf("\nDo you want to add more traffic to the block list? (y/n): ");
        scanf(" %c", &option);
    }

    printf("\nThank you for using My Firewall Program!\n");

    return 0;
}