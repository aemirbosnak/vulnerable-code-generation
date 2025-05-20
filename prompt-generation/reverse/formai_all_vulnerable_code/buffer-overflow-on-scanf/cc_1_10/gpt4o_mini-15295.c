//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPTIONS 4
#define FORM_COUNT 3

typedef struct {
    char* name;
    char* description;
} Form;

void print_welcome() {
    printf("Welcome to the Shape-Shifting Adventure!\n");
    printf("In this mystical forest, you can transform into different creatures to explore and solve puzzles.\n");
}

void print_forms(Form forms[]) {
    printf("You can choose from the following forms:\n");
    for (int i = 0; i < FORM_COUNT; i++) {
        printf("%d. %s - %s\n", i + 1, forms[i].name, forms[i].description);
    }
}

void choose_form(Form forms[], int* current_form) {
    int choice;
    printf("Enter the number corresponding to the form you want to take: ");
    scanf("%d", &choice);
    if (choice >= 1 && choice <= FORM_COUNT) {
        *current_form = choice - 1;
        printf("You transformed into a %s!\n", forms[*current_form].name);
    } else {
        printf("Invalid choice. You remain in your current form.\n");
    }
}

void explore_forest(Form forms[], int current_form) {
    printf("You wander through the dense forest as a %s.\n", forms[current_form].name);
    printf("You encounter a fork in the path, where do you want to go?\n");
    printf("1. Left towards the river\n");
    printf("2. Right towards the cave\n");
    printf("3. Back to the clearing\n");

    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            if (current_form == 0) { // Human
                printf("As a human, you cannot swim! You need a different form.\n");
            } else {
                printf("You safely swim across the river as a frog!\n");
            }
            break;
        case 2:
            if (current_form == 1) { // Frog
                printf("The cave is too dark for a frog! Transform into another form.\n");
            } else {
                printf("You navigate the dark cave and find treasures!\n");
            }
            break;
        case 3:
            printf("You return to the clearing, feel free to choose another form!\n");
            break;
        default:
            printf("Invalid choice. You stand still in confusion.\n");
            break;
    }
}

int main() {
    Form forms[FORM_COUNT];
    forms[0].name = "Human";
    forms[0].description = "A curious adventurer with no special abilities.";
    forms[1].name = "Frog";
    forms[1].description = "A small creature great for swimming.";
    forms[2].name = "Bat";
    forms[2].description = "A flying creature that can navigate the dark.";

    int current_form = 0;

    print_welcome();
    
    while (1) {
        print_forms(forms);
        choose_form(forms, &current_form);
        explore_forest(forms, current_form);

        printf("\nDo you want to continue exploring? (1 for Yes, 0 for No): ");
        int continue_choice;
        scanf("%d", &continue_choice);
        if (continue_choice == 0) {
            printf("Thank you for playing!\n");
            break;
        }
    }

    return 0;
}