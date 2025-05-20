//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NUM_QUESTIONS 20

struct Question {
    char element[10];
    char symbol[2];
    char atomic_number[10];
    char atomic_mass[10];
    char electron_configuration[100];
    char group[10];
    char period[10];
    char name[20];
    bool is_metal;
    bool is_noble_gas;
    bool is_halogen;
    bool is_alkali_metal;
    bool is_transition_metal;
    char chemical_formula[100];
    char melting_point[20];
    char boiling_point[20];
    char density[20];
    char color[20];
    char appearance[100];
    char uses[100];
    char common_compounds[100];
};

struct Question questions[NUM_QUESTIONS] = {
    {
       .element = "Helium",
       .symbol = "He",
       .atomic_number = "2",
       .atomic_mass = "4.002602",
       .electron_configuration = "1s² 2s² 2p⁶",
       .group = "18",
       .period = "2",
       .name = "Helium",
       .is_metal = false,
       .is_noble_gas = true,
       .is_halogen = false,
       .is_alkali_metal = false,
       .is_transition_metal = false,
       .chemical_formula = "He",
       .melting_point = "4.22 K",
       .boiling_point = "5.12 K",
       .density = "0.1783 g/cm³",
       .color = "White",
       .appearance = "Colorless, odorless, tasteless, inert gas",
       .uses = "As a breathing gas for deep sea divers and for space exploration",
       .common_compounds = "None"
    },
    {
        // More questions here...
    },
    {
        // Last question here
    }
};

int main() {
    srand(time(NULL));
    int question_index = rand() % NUM_QUESTIONS;
    struct Question question = questions[question_index];

    printf("Question %d:\n", question_index + 1);
    printf("Element: %s\n", question.element);
    printf("Symbol: %s\n", question.symbol);
    printf("Atomic Number: %s\n", question.atomic_number);
    printf("Atomic Mass: %s\n", question.atomic_mass);
    printf("Electron Configuration: %s\n", question.electron_configuration);
    printf("Group: %s\n", question.group);
    printf("Period: %s\n", question.period);
    printf("Name: %s\n", question.name);
    printf("Is Metal: %s\n", question.is_metal? "Yes" : "No");
    printf("Is Noble Gas: %s\n", question.is_noble_gas? "Yes" : "No");
    printf("Is Halogen: %s\n", question.is_halogen? "Yes" : "No");
    printf("Is Alkali Metal: %s\n", question.is_alkali_metal? "Yes" : "No");
    printf("Is Transition Metal: %s\n", question.is_transition_metal? "Yes" : "No");
    printf("Chemical Formula: %s\n", question.chemical_formula);
    printf("Melting Point: %s\n", question.melting_point);
    printf("Boiling Point: %s\n", question.boiling_point);
    printf("Density: %s\n", question.density);
    printf("Color: %s\n", question.color);
    printf("Appearance: %s\n", question.appearance);
    printf("Uses: %s\n", question.uses);
    printf("Common Compounds: %s\n", question.common_compounds);

    printf("\n");

    char choice;
    while (true) {
        printf("Enter 'q' to quit or the element's letter: ");
        scanf(" %c", &choice);

        if (choice == 'q') {
            break;
        }

        if (choice >= 'a' && choice <= 'z') {
            int index = 0;
            for (index = 0; index < NUM_QUESTIONS; index++) {
                if (questions[index].symbol[0] == choice) {
                    break;
                }
            }

            if (index < NUM_QUESTIONS) {
                question_index = index;
                struct Question question = questions[question_index];

                printf("Question %d:\n", question_index + 1);
                printf("Element: %s\n", question.element);
                printf("Symbol: %s\n", question.symbol);
                printf("Atomic Number: %s\n", question.atomic_number);
                printf("Atomic Mass: %s\n", question.atomic_mass);
                printf("Electron Configuration: %s\n", question.electron_configuration);
                printf("Group: %s\n", question.group);
                printf("Period: %s\n", question.period);
                printf("Name: %s\n", question.name);
                printf("Is Metal: %s\n", question.is_metal? "Yes" : "No");
                printf("Is Noble Gas: %s\n", question.is_noble_gas? "Yes" : "No");
                printf("Is Halogen: %s\n", question.is_halogen? "Yes" : "No");
                printf("Is Alkali Metal: %s\n", question.is_alkali_metal? "Yes" : "No");
                printf("Is Transition Metal: %s\n", question.is_transition_metal? "Yes" : "No");
                printf("Chemical Formula: %s\n", question.chemical_formula);
                printf("Melting Point: %s\n", question.melting_point);
                printf("Boiling Point: %s\n", question.boiling_point);
                printf("Density: %s\n", question.density);
                printf("Color: %s\n", question.color);
                printf("Appearance: %s\n", question.appearance);
                printf("Uses: %s\n", question.uses);
                printf("Common Compounds: %s\n", question.common_compounds);

                printf("\n");
            }
        }
    }

    return 0;
}