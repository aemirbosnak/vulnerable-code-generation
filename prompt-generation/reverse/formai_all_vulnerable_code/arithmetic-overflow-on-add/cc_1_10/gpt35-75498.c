//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global variable for counting correct answers
int correctAnswers = 0;

// Function to generate random integer between min and max (inclusive)
int generateRandomInt(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to capitalize first letter of a string
void capitalizeFirstLetter(char* str) {
    if(str == NULL || strlen(str) == 0) {
        return;
    }
    str[0] = toupper(str[0]);
}

// Main function
int main() {

    // Seed random number generator
    srand(time(NULL));

    // Welcome message
    printf("Welcome to the Periodic Table Quiz!\n\n");

    // Instructions
    printf("INSTRUCTIONS:\n");
    printf("You will be asked 5 questions about the elements in the periodic table.\n");
    printf("For each question, enter the symbol of the element (e.g. H for Hydrogen).\n");
    printf("You will have 10 seconds to answer each question. If you run out of time, the quiz will end.\n");
    printf("Good luck!\n\n");

    // Pause for user to read instructions
    printf("Press Enter to start...");
    getchar();
    printf("\n");

    // Main loop for questions
    for(int i = 1; i <= 5; i++) {

        // Generate random atomic number between 1 and 118 (inclusive)
        int atomicNumber = generateRandomInt(1, 118);

        // Open file for reading element information
        FILE* fp = fopen("elements.txt", "r");

        // Loop until file is at end or desired atomic number is found
        char line[100];
        while(fgets(line, sizeof(line), fp) != NULL) {

            // Read atomic number and symbol from line
            int num;
            char symbol[3];
            sscanf(line, "%d %s", &num, symbol);

            // Check if desired atomic number is found
            if(num == atomicNumber) {

                // Close file
                fclose(fp);

                // Prompt user to guess element symbol
                printf("QUESTION %d:\n", i);
                printf("What is the symbol for element %s?\n", symbol);

                // Get user input within 10 seconds
                time_t endTime = time(NULL) + 10;
                char input[3];
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0'; // Remove newline character
                capitalizeFirstLetter(input);

                // Check if answer is correct
                if(strcmp(input, symbol) == 0) {
                    printf("Correct!\n\n");
                    correctAnswers++;
                }
                else {
                    printf("Incorrect. The correct answer is %s.\n\n", symbol);
                }

                // Pause for 2 seconds before moving to next question
                sleep(2);
                break;
            }
        }

        // If desired atomic number was not found, close file and display error message
        if(!feof(fp)) {
            fclose(fp);
            printf("Error: element information not found for atomic number %d.\n", atomicNumber);
            return 1;
        }

        // If file is at end and desired atomic number was not found, close file and display error message
        if(feof(fp)) {
            fclose(fp);
            printf("Error: atomic number %d is not valid.\n", atomicNumber);
            return 1;
        }
    }

    // Display final score
    printf("QUIZ RESULTS:\n");
    printf("You answered %d out of 5 questions correctly.\n", correctAnswers);

    return 0;
}