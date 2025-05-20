//FormAI DATASET v1.0 Category: Ebook reader ; Style: cheerful
#include <stdio.h>

int main() {

    // Start by welcoming the user
    printf("Welcome to the C Ebook reader program!\n");

    // Ask the user for the name of the Ebook file they want to read
    printf("Please enter the name of your Ebook file (without the .pdf extension): ");

    // Declare a string variable to store the Ebook file name
    char filename[100];

    // Use scanf to get the Ebook file name from the user
    scanf("%s", filename);

    // Open the Ebook file using fopen
    FILE *fp;
    fp = fopen(filename, "r");

    // If fopen was unsuccessful (i.e. fp is NULL), let the user know and exit the program
    if (fp == NULL) {
        printf("Oops! Unable to open the Ebook file. Please check the file name and try again.\n");
        return 1;
    }

    // If fopen was successful, inform the user and start reading the Ebook
    printf("Great! Your Ebook has been loaded successfully. Let's start reading!\n");

    // Declare a character variable to hold each character as we read the Ebook
    char c;

    // Use a while loop to keep reading the Ebook until we reach the end of the file
    while((c = getc(fp)) != EOF) {

        // Print each character to the console
        putchar(c);
    }

    // Close the Ebook file using fclose
    fclose(fp);

    // Inform the user that we've reached the end of the Ebook
    printf("\n\nCongratulations! You've reached the end of your Ebook. Happy reading!\n");

    // End the program with a cheerful message
    printf("Thank you for choosing our C Ebook reader program. We hope you enjoyed it!\n");

    return 0;
}