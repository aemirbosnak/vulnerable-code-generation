//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: light-weight
#include <stdio.h>
#include <string.h>

// Function to generate a quiz question about a random element
void generateQuestion(char *element) {
    char *question = "What is the atomic number of ";
    strcat(question, element);
    strcat(question, "? (hint: it's an element in the periodic table)");
    printf("%s\n", question);
}

// Function to check the user's answer
int checkAnswer(char *element, int atomicNumber) {
    if (strcmp(element, " ") == 0) {
        printf("Invalid input\n");
        return 0;
    }
    if (strcmp(element, "He") == 0) {
        printf("Correct!\n");
        return 1;
    }
    if (strcmp(element, "H") == 0) {
        printf("Incorrect\n");
        return 0;
    }
    printf("Unknown element\n");
    return 0;
}

// Main program
int main() {
    char element[10];
    int atomicNumber;
    srand(time(0));

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Please enter the atomic number of an element in the periodic table:\n");
    scanf("%d", &atomicNumber);

    while (1) {
        generateQuestion(element);
        printf("Enter the element corresponding to the atomic number %d: ", atomicNumber);
        fgets(element, sizeof(element), stdin);

        if (checkAnswer(element, atomicNumber) == 1) {
            printf("Correct!\n");
        } else {
            printf("Incorrect\n");
            printf("The correct element is %s\n", element);
        }

        printf("Do you want to continue? (y/n): ");
        char response;
        fgets(&response, sizeof(response), stdin);
        if (strcmp(response, "y")!= 0 && strcmp(response, "Y")!= 0) {
            break;
        }
    }

    printf("Thanks for playing!\n");
    return 0;
}