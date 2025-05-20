//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    // Seed the random number generator
    srand(time(NULL));

    // Define the periodic table
    const char* table[] = {
        "Hydrogen",
        "Helium",
        "Lithium",
        "Beryllium",
        "Boron",
        "Carbon",
        "Nitrogen",
        "Oxygen",
        "Fluorine",
        "Neon",
        "Sodium",
        "Magnesium",
        "Aluminium",
        "Silicon",
        "Phosphorus",
        "Sulfur",
        "Chlorine",
        "Argon",
        "Potassium",
        "Calcium",
        "Scandium",
        "Titanium",
        "Vanadium",
        "Chromium",
        "Manganese",
        "Iron",
        "Cobalt",
        "Nickel",
        "Copper",
        "Zinc",
        "Gallium",
        "Germanium",
        "Arsenic",
        "Selenium",
        "Bromine",
        "Krypton",
        "Rubidium",
        "Strontium",
        "Yttrium",
        "Zirconium",
        "Niobium",
        "Molybdenum",
        "Technetium",
        "Ruthenium",
        "Rhodium",
        "Palladium",
        "Silver",
        "Cadmium",
        "Indium",
        "Tin",
        "Antimony",
        "Tellurium",
        "Iodine",
        "Xenon",
        "Caesium",
        "Barium",
        "Lanthanum",
        "Cerium",
        "Praseodymium",
        "Neodymium",
        "Promethium",
        "Samarium",
        "Europium",
        "Gadolinium",
        "Terbium",
        "Dysprosium",
        "Holmium",
        "Erbium",
        "Thulium",
        "Ytterbium",
        "Lutetium",
        "Hafnium",
        "Tantalum",
        "Tungsten",
        "Rhenium",
        "Osmium",
        "Iridium",
        "Platinum",
        "Gold",
        "Mercury",
        "Thallium",
        "Lead",
        "Bismuth",
        "Polonium",
        "Astatine",
        "Radon",
        "Francium",
        "Radium",
        "Actinium",
        "Thorium",
        "Protactinium",
        "Uranium",
        "Neptunium",
        "Plutonium",
        "Americium",
        "Curium",
        "Berkelium",
        "Californium",
        "Einsteinium",
        "Fermium",
        "Mendelevium",
        "Nobelium",
        "Lawrencium",
        "Rutherfordium",
        "Dubnium",
        "Seaborgium",
        "Bohrium",
        "Hassium",
        "Meitnerium",
        "Darmstadtium",
        "Roentgenium",
        "Copernicium",
        "Nihonium",
        "Flerovium",
        "Moscovium",
        "Livermorium",
        "Ununtrium",
        "Ununpentium",
        "Ununhexium",
        "Ununseptium",
        "Ununeptium",
        "Ununennium",
        "Ununeptennium",
        "Ununhexium",
        "Ununseptium",
        "Ununhexium",
        "Unununium",
        "Ununununium",
        "Unununununium",
        "Ununununununium"
    };

    // Quiz the user
    int num_questions = 10;
    int num_correct = 0;
    int num_incorrect = 0;
    int total = num_questions * 100;
    int percentage = 0;

    for (int i = 0; i < num_questions; i++) {
        int question = rand() % (num_questions + 1);
        const char* element = table[question];

        // Ask the user the question
        printf("Question %d: What is the name of element %d? (1) ", i + 1, question);
        int choice;
        scanf("%d", &choice);
        if (choice == question + 1) {
            num_correct++;
            printf("\nCorrect!\n");
        } else {
            num_incorrect++;
            printf("\nIncorrect. The correct answer is %s.\n", element);
        }

        // Calculate the percentage
        percentage = (num_correct / total) * 100;
        printf("\nYour score so far is %.2f%% (%d/%d)\n", percentage, num_correct, total);
    }

    printf("\nFinal score: %.2f%% (%d/%d)\n", percentage, num_correct, total);

    return 0;
}