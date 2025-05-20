//FormAI DATASET v1.0 Category: Mailing list manager ; Style: grateful
#include <stdio.h>
#include <string.h>

#define MAX_EMAILS 100

// Function to validate email address format
int isValidEmail(char email[]) {
    int len = strlen(email);
    int at = 0, dot = 0;
    for(int i = 0; i < len; i++) {
        if(email[i] == '@') at++;
        else if(email[i] == '.') dot++;
    }
    if(at == 1 && dot >= 1) return 1;
    else return 0;
}

int main() {
    char emails[MAX_EMAILS][50]; // Array to store email addresses
    int count = 0; // Variable to keep track of number of email addresses

    printf("\nWelcome to Mailing List Manager\n");
    while(1) {
        printf("\nEnter 1 to add email address\n");
        printf("Enter 2 to remove email address\n");
        printf("Enter 3 to view email addresses\n");
        printf("Enter 0 to exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                printf("\nEnter email address: ");
                char email[50];
                scanf("%s", email);

                if(!isValidEmail(email)) {
                    printf("Invalid email format!\n");
                    break;
                }

                int duplicate = 0;
                for(int i = 0; i < count; i++) {
                    if(strcmp(email, emails[i]) == 0) {
                        duplicate = 1;
                        break;
                    }
                }

                if(duplicate) {
                    printf("Email address already exists in mailing list!\n");
                    break;
                }

                strcpy(emails[count], email);
                count++;
                printf("Email address added to mailing list!\n");
                break;
            }

            case 2: {
                printf("\nEnter email address to remove: ");
                char email[50];
                scanf("%s", email);

                if(!isValidEmail(email)) {
                    printf("Invalid email format!\n");
                    break;
                }

                int found = -1;
                for(int i = 0; i < count; i++) {
                    if(strcmp(email, emails[i]) == 0) {
                        found = i;
                        break;
                    }
                }

                if(found == -1) {
                    printf("Email address not found in mailing list!\n");
                    break;
                }

                for(int i = found; i < count - 1; i++) {
                    strcpy(emails[i], emails[i+1]);
                }

                count--;
                printf("Email address removed from mailing list!\n");
                break;
            }

            case 3: {
                printf("\nMailing List:\n");
                for(int i = 0; i < count; i++) {
                    printf("%d. %s\n", i+1, emails[i]);
                }
                break;
            }

            case 0:
                printf("\nThank you for using Mailing List Manager!\n");
                return 0;

            default:
                printf("\nInvalid choice, please try again!\n");
        }
    }

    return 0;
}