//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

/**
 * Function to calculate checksum for a given string
 * @param message : string for which checksum is to be calculated
 * @return : calculated checksum value
 */
int calculateChecksum(char *message) {
    int sum = 0;
    int i = 0;

    while(message[i] != '\0') {
        sum += (int) message[i];
        i++;
    }

    return sum;
}

/**
 * Function to validate if the message has been tampered with
 * @param message : original message sent
 * @param checksum : checksum value calculated and sent along with message
 * @return : 1 if message has not been tampered with, 0 otherwise
 */
int validateChecksum(char *message, int checksum) {
    if(checksum == calculateChecksum(message)) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    char message[100];
    int checksum;
    int choice;

    do {
        printf("\n1. Calculate checksum for a message");
        printf("\n2. Validate checksum for a message");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the message for which checksum is to be calculated: ");
                scanf(" %[^\n]s", message);
                checksum = calculateChecksum(message);
                printf("\nChecksum for the message '%s' is: %d", message, checksum);
                break;
            case 2:
                printf("Enter the message: ");
                scanf(" %[^\n]s", message);
                printf("Enter the checksum value for the message: ");
                scanf("%d", &checksum);

                if(validateChecksum(message, checksum)) {
                    printf("\nThe message '%s' has not been tampered with.", message);
                }
                else {
                    printf("\nThe message '%s' has been tampered with.", message);
                }
                break;
            case 3:
                printf("Exiting the program...");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.");
        }
    } while(1);

    return 0;
}