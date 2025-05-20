//FormAI DATASET v1.0 Category: String manipulation ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main() {

    // Initialize a string 
    char myString[50] = "Hello World!";

    // Ask the user for input
    printf("What do you want to do with this string?");

    // Create a character variable to store user's choice
    char userChoice;

    // Get the user's choice
    scanf("%c", &userChoice);

    // Check the user's choice and perform corresponding action
    switch(userChoice) {

        // If the user wants to reverse the string
        case '1': 
            {
                int len = strlen(myString); // get the length of the string

                // loop through half of the string
                for(int i=0; i<len/2 ;i++){
                    // swap the characters from the beginning and end of the string
                    char temp = myString[i];
                    myString[i] = myString[len-i-1];
                    myString[len-i-1] = temp;
                }

                // print the new string
                printf("The reversed string is: %s", myString);
                break;
            }

        // If the user wants to convert the string to uppercase
        case '2': 
            {
                int len = strlen(myString); // get the length of the string

                // loop through the string
                for(int i=0; i<len ;i++){
                    // if the character is lowercase, convert it to uppercase
                    if(myString[i] >= 'a' && myString[i] <= 'z') {
                        myString[i] -= 32;
                    }
                }

                // print the new string
                printf("The uppercase string is: %s", myString);
                break;
            }

        // If the user wants to check if the string is a palindrome
        case '3': 
            {
                int len = strlen(myString); // get the length of the string
                int flag = 0;

                // loop through half of the string
                for(int i=0; i<len/2 ;i++){
                    // compare the characters from the beginning and end of the string
                    if(myString[i] != myString[len-i-1]) {
                        flag = 1; // set a flag if characters don't match
                        break;
                    }
                }

                // check if flag is set
                if(flag == 1) {
                    printf("The string is not a palindrome.");
                } else {
                    printf("The string is a palindrome!");
                }

                break;
            }

        // If the user enters an invalid choice
        default: 
            {
                printf("Invalid choice.");
            }
    }

    return 0;
}