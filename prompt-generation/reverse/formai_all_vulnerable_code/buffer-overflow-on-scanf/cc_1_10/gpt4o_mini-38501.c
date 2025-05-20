//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_ELEMENTS 10

typedef struct {
    char symbol[3];
    char name[30];
    int atomicNumber;
    const char* description;
} Element;

Element elements[NUM_ELEMENTS] = {
    {"H", "Hydrogen", 1, "The lightest and most abundant element in the universe."},
    {"He", "Helium", 2, "The second lightest element, derived from stars."},
    {"Li", "Lithium", 3, "A soft, silvery-white metal, used in batteries."},
    {"Be", "Beryllium", 4, "A hard, brittle metal, used in aerospace applications."},
    {"B", "Boron", 5, "Used in glass and detergents."},
    {"C", "Carbon", 6, "The basis for all known life."},
    {"N", "Nitrogen", 7, "Makes up 78% of the Earth's atmosphere."},
    {"O", "Oxygen", 8, "Essential for respiration."},
    {"Ne", "Neon", 10, "Known for its bright lights in futuristic cities."},
    {"F", "Fluorine", 9, "A highly reactive gas."}
};

void displayIntro() {
    printf("~~~~~ WELCOME TO THE CYBERPUNK PERIODIC TABLE QUIZ ~~~~~\n");
    printf("As neon lights flicker, test your knowledge of elements!\n");
}

int getRandomElementIndex() {
    return rand() % NUM_ELEMENTS;
}

void askQuestion() {
    int index = getRandomElementIndex();
    printf("\nIdentify the element with symbol \"%s\":\n", elements[index].symbol);
    
    char answer[30];
    printf("Your answer: ");
    scanf("%s", answer);

    if (strcasecmp(answer, elements[index].name) == 0) {
        printf("Correct! %s - %s\n", elements[index].name, elements[index].description);
    } else {
        printf("Incorrect! The correct answer is: %s\n", elements[index].name);
    }
}

void displayScore(int score, int total) {
    printf("\nYour score: %d/%d\n", score, total);
}

int main() {
    srand(time(NULL));
    int totalQuestions = 5;
    int score = 0;

    displayIntro();

    for (int i = 0; i < totalQuestions; ++i) {
        askQuestion();
        char option[3];
        printf("Would you like to continue to the next question? (yes/no): ");
        scanf("%s", option);
        if (strcasecmp(option, "no") == 0) {
            break;
        }
    }

    displayScore(score, totalQuestions);
    printf("\nThe neon lights fade out. Until next time.\n");
    
    return 0;
}