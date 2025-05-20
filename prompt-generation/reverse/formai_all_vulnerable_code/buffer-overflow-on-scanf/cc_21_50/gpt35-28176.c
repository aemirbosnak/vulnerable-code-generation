//FormAI DATASET v1.0 Category: Text processing ; Style: immersive
#include <stdio.h>
#include <string.h>

int main() {
    char text[100]; // the text that we want to process
    int choice; // the task that we want to perform
    int length; // the length of the text
    char reverse[100]; // the reverse of the text
    int i, j; // loop variables
    char ch; // temporary variable to hold a character

    // welcome the user to the program
    printf("Welcome to the Text Processing Program!\n\n");

    // prompt the user to enter some text
    printf("Please enter some text (maximum 100 characters):\n");
    scanf("%[^\n]", text);

    // prompt the user to choose a task to perform
    printf("\nPlease choose a task to perform:\n");
    printf("1. Calculate the length of the text\n");
    printf("2. Reverse the text\n");
    printf("3. Count the number of vowels in the text\n");
    printf("4. Replace all lowercase vowels with uppercase vowels\n");
    printf("5. Exit\n");
    scanf("%d", &choice);
    getchar(); // to remove the newline character from the input buffer

    // perform the chosen task
    switch (choice) {
        case 1:
            // calculate the length of the text
            length = strlen(text);
            printf("\nThe length of the text is %d\n", length);
            break;
        case 2:
            // reverse the text
            length = strlen(text);
            j = length - 1;
            for (i = 0; i < length; i++) {
                reverse[i] = text[j];
                j--;
            }
            reverse[length] = '\0';
            printf("\nThe reverse of the text is:\n%s\n", reverse);
            break;
        case 3:
            // count the number of vowels in the text
            length = strlen(text);
            int count = 0;
            for (i = 0; i < length; i++) {
                ch = text[i];
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                    ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                    count++;
                }
            }
            printf("\nThe number of vowels in the text is %d\n", count);
            break;
        case 4:
            // replace all lowercase vowels with uppercase vowels
            length = strlen(text);
            for (i = 0; i < length; i++) {
                ch = text[i];
                if (ch >= 'a' && ch <= 'z' &&
                    (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
                    ch -= 32;
                }
                printf("%c", ch);
            }
            printf("\n");
            break;
        case 5:
            // exit the program
            printf("\nThank you for using the Text Processing Program!\n");
            return 0;
        default:
            // handle invalid input
            printf("\nInvalid input. Please choose a number between 1 and 5.\n");
            break;
    }

    // prompt the user to choose another task
    printf("\nWould you like to perform another task? (y/n)\n");
    char choice2;
    scanf("%c", &choice2);
    if (choice2 == 'y' || choice2 == 'Y') {
        main(); // recursive call to main
    } else {
        printf("\nThank you for using the Text Processing Program!\n");
    }
    return 0;
}