//Falcon-180B DATASET v1.0 Category: Recursive ; Style: Romeo and Juliet
#include <stdio.h>

// Function to print the Romeo and Juliet story
void romeoAndJuliet(int lineNumber) {
    static int firstTime = 1;
    static char *story[] = {
        "In fair Verona, where we lay our scene,",
        "Two households, both alike in dignity,",
        "From ancient grudge break to new mutiny,",
        "Where civil blood makes civil hands unclean.",
        "",
        "From forth the fatal loins of these two foes,",
        "A pair of star-cross'd lovers take their life;",
        "Whose misadventured piteous overthrows",
        "Doth with their death bury their parents' strife.",
        "",
        "The fearful passage of their death-mark'd love,",
        "And the continuance of their parents' rage,",
        "Which, but their children's end, nought could remove,",
        "Is now the two hours' traffic of our stage;",
        "",
        "The which if you with patient ears attend,",
        "What here shall miss, our toil shall strive to mend.",
    };

    if (firstTime) {
        printf("Romeo and Juliet by William Shakespeare\n\n");
        firstTime = 0;
    }

    printf("%s\n", story[lineNumber]);
}

int main() {
    int choice;

    // Print the Romeo and Juliet story
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Read the story\n");
        printf("2. Quit\n");
        printf("> ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            romeoAndJuliet(0);
            break;

        case 2:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 2);

    return 0;
}