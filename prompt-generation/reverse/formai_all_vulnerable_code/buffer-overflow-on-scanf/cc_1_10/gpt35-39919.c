//FormAI DATASET v1.0 Category: String manipulation ; Style: romantic
#include <stdio.h>
#include <string.h>

/* Declare and initialize the strings */
char myName[] = "Amore";
char yourName[] = "Bella";
char greeting[] = "Hello";
char love[] = "I love you, ";

int main() {
    int choice, length;
    char temp[50], temp2[50];

    /* Greet the user */
    printf("%s, my beloved. Welcome to our romantic String Manipulation program.\n", greeting);

    /* Prompt for user input */
    printf("Would you like to:\n");
    printf("1. Write a love letter\n");
    printf("2. Combine our names\n");
    printf("3. Tell me something sweet\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            /* Love letter */
            printf("My dearest %s,\n", yourName);
            printf("I just wanted to tell you how much I love you.\n");
            printf("You are the sunshine that brightens up my days.\n");
            printf("When I am with you, I feel complete.\n");
            printf("I love you more than words can express.\n");
            printf("Forever yours,\n%s\n", myName);
            break;
        
        case 2:
            /* Combine our names */
            printf("Please enter a string of no more than 50 characters:\n");
            scanf("%s", temp);
            length = strlen(temp);
            temp[length] = ' ';
            strncat(temp, yourName, 49-length);
            printf("Our combined names are: %s%s\n", myName, temp);
            break;

        case 3:
            /* Tell me something sweet */
            printf("Please enter something sweet to say to me:\n");
            scanf("%s", temp2);
            strcat(love, temp2);
            printf("%s", love);
            break;
        
        default:
            /* Invalid input */
            printf("Invalid choice. Please try again.\n");
            break;
    }

    /* Farewell message */
    printf("Thank you for using our romantic String Manipulation program. Goodbye, my love!");
    return 0;
}