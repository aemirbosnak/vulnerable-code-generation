//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

// Structure for Periodic Table Element
typedef struct {
    char name[20];
    char symbol[3];
    int atomic_number;
} Element;

// Function declarations
void quiz(Element elements[], int size);
void romance_dialogue(char *message);

int main() {
    // Elements of the Periodic Table
    Element elements[] = {
        {"Hydrogen", "H", 1},
        {"Helium", "He", 2},
        {"Lithium", "Li", 3},
        {"Beryllium", "Be", 4},
        {"Boron", "B", 5},
        {"Carbon", "C", 6},
        {"Nitrogen", "N", 7},
        {"Oxygen", "O", 8},
        {"Fluorine", "F", 9},
        {"Neon", "Ne", 10}
    };

    int size = sizeof(elements) / sizeof(elements[0]);

    // A declaration of love for chemistry
    romance_dialogue("O fair Chemistry, thy sonnets dost breathe life into thine elements!");

    // Start the quiz
    quiz(elements, size);

    return 0;
}

// Function to conduct the quiz
void quiz(Element elements[], int size) {
    char answer[3];
    int score = 0;

    printf("\nA Quiz to test thine knowledge of the periodic table, fair user!\n");
    for (int i = 0; i < size; i++) {
        printf("\nWhat is the symbol for %s? ", elements[i].name);
        scanf("%s", answer);

        // Check if answer is correct
        if (strcmp(answer, elements[i].symbol) == 0) {
            printf("Thou art correct, noble scholar! The symbol of %s is indeed %s.\n", 
                    elements[i].name, elements[i].symbol);
            score++;
        } else {
            printf("Alas! Thou art mistaken. The symbol of %s is %s.\n", 
                    elements[i].name, elements[i].symbol);
        }
    }

    // End of quiz and displaying final score
    printf("\nThou hast completed the quiz! Thy final score is: %d out of %d.\n", score, size);
}

// Function for romantic dialogue
void romance_dialogue(char *message) {
    printf("\n%s\n", message);
    printf("With thine heart aflame, embrace the wonders of elements stardust hath wrought!\n");
}