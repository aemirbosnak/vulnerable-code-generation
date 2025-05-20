//FormAI DATASET v1.0 Category: Email Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Function to check whether the email id entered is valid or not
int isValidEmail(char email[]) {
    int atSymbol = 0, dotSymbol = 0, i = 0;

    // Loop through the email and check for '@' and '.' symbols
    while(email[i] != '\0') {
        if(email[i] == '@') {
            atSymbol = 1;
        }
        if(email[i] == '.') {
            dotSymbol = 1;
        }
        i++;
    }

    // If both symbols are found, return true, else return false
    if(atSymbol == 1 && dotSymbol == 1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char email[50], subject[100], body[500];

    // Prompt the user to enter their email id
    printf("Enter your Email Address: ");
    scanf("%s", email);

    // Check if the email id entered is valid or not
    if(isValidEmail(email)) {

        // Prompt the user to enter the subject of the email
        printf("Enter Subject: ");
        scanf(" %[^\n]s", subject);

        // Prompt the user to enter the body of the email
        printf("Enter Body: ");
        scanf(" %[^\n]s", body);

        // Construct the email message
        printf("\n\n========== Email Message ==========\n\n");
        printf("To: %s\n", email);
        printf("Subject: %s\n", subject);
        printf("Body: %s\n", body);
        printf("\n\n===================================\n\n");

    } else {
        printf("\nInvalid Email Address.\n");
    }

    return 0;
}