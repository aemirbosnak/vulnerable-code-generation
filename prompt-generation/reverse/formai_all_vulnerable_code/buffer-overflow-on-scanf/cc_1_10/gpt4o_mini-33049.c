//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20

// Structure for an element
typedef struct {
    int atomic_number;
    char name[MAX_NAME_LENGTH];
    char symbol[3];
    float atomic_weight;
    char category[MAX_NAME_LENGTH];
} Element;

// Function declarations
void initialize_elements(Element elements[]);
void display_elements(Element elements[], int count);
void search_element(Element elements[], int count);
void quiz_user(Element elements[], int count);
int get_user_score(int score);

int main() {
    Element elements[MAX_ELEMENTS];
    int choice;

    initialize_elements(elements);

    do {
        printf("\nPeriodic Table Quiz Program\n");
        printf("1. Display all elements\n");
        printf("2. Search for an element\n");
        printf("3. Take a quiz\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_elements(elements, MAX_ELEMENTS);
                break;
            case 2:
                search_element(elements, MAX_ELEMENTS);
                break;
            case 3:
                quiz_user(elements, MAX_ELEMENTS);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void initialize_elements(Element elements[]) {
    // Initialization of some elements
    elements[0] = (Element){1, "Hydrogen", "H", 1.008, "Nonmetal"};
    elements[1] = (Element){2, "Helium", "He", 4.0026, "Noble Gas"};
    elements[2] = (Element){3, "Lithium", "Li", 6.94, "Alkali Metal"};
    elements[3] = (Element){4, "Beryllium", "Be", 9.0122, "Alkaline Earth Metal"};
    elements[4] = (Element){5, "Boron", "B", 10.81, "Metalloid"};
    // Adding more elements could be done similarly...
}

void display_elements(Element elements[], int count) {
    printf("\n%-5s %-20s %-5s %-15s %-20s\n", "Atomic#", "Name", "Symbol", "Atomic Weight", "Category");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-5s %-15.4f %-20s\n", elements[i].atomic_number,
               elements[i].name, elements[i].symbol,
               elements[i].atomic_weight, elements[i].category);
    }
}

void search_element(Element elements[], int count) {
    char search_name[MAX_NAME_LENGTH];
    int found = 0;

    printf("Enter the name of the element to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < count; i++) {
        if (strcasecmp(elements[i].name, search_name) == 0) {
            printf("Element found: %s (Symbol: %s, Atomic Number: %d, Atomic Weight: %.4f, Category: %s)\n",
                   elements[i].name, elements[i].symbol,
                   elements[i].atomic_number, elements[i].atomic_weight,
                   elements[i].category);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element not found in the periodic table.\n");
    }
}

void quiz_user(Element elements[], int count) {
    int score = 0, total_questions = 3;
    char answer[MAX_NAME_LENGTH];

    printf("\nPeriodic Table Quiz! Answer the following questions:\n");

    // Question 1
    printf("1. What is the symbol for Gold? ");
    scanf("%s", answer);
    if (strcasecmp(answer, "Au") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect! The correct answer is Au.\n");
    }

    // Question 2
    printf("2. Which element has the atomic number 1? ");
    scanf("%s", answer);
    if (strcasecmp(answer, "Hydrogen") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect! The correct answer is Hydrogen.\n");
    }

    // Question 3
    printf("3. What is the atomic weight of Carbon? ");
    float user_weight;
    scanf("%f", &user_weight);
    if (user_weight == 12.011) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect! The correct answer is approximately 12.011.\n");
    }

    // Display final score
    get_user_score(score);
}

int get_user_score(int score) {
    printf("Your score is: %d out of 3\n", score);
    return score;
}