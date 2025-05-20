//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    // Periodic table elements
    char* elements[118] = {
        "Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon",
        "Nitrogen", "Oxygen", "Fluorine", "Neon", "Sodium", "Magnesium",
        "Aluminum", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon",
        "Potassium", "Calcium", "Scandium", "Titanium", "Vanadium", "Chromium",
        "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc",
        "Gallium", "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton",
        "Rubidium", "Strontium", "Yttrium", "Zirconium", "Niobium", "Molybdenum",
        "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium",
        "Indium", "Tin", "Antimony", "Tellurium", "Iodine", "Xenon",
        "Cesium", "Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium",
        "Promethium", "Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium",
        "Holmium", "Erbium", "Thulium", "Ytterbium", "Lutetium", "Hafnium",
        "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum",
        "Gold", "Mercury", "Thallium", "Lead", "Bismuth", "Polonium",
        "Astatine", "Radon", "Francium", "Radium", "Actinium", "Thorium",
        "Protactinium", "Uranium", "Neptunium", "Plutonium", "Americium", "Curium",
        "Berkelium", "Californium", "Einsteinium", "Fermium", "Mendelevium", "Nobelium",
        "Lawrencium", "Rutherfordium", "Dubnium", "Seaborgium", "Bohrium", "Hassium",
        "Meitnerium", "Darmstadtium", "Roentgenium", "Copernicium", "Nihonium", "Flerovium",
        "Moscovium", "Livermorium", "Tennessine", "Oganesson"
    };

    // Randomize seed
    srand(time(0));

    printf("** C PERIODIC TABLE QUIZ **\n");
    printf("Enter the number of questions you want to answer (maximum 118): ");

    int num_questions;
    scanf("%d", &num_questions);

    int score = 0;

    for(int i = 0; i < num_questions; i++) {
        // Generate random index from 0 to 117
        int rand_index = rand() % 118;
        printf("\nQuestion %d: What is the symbol for %s?\n", i+1, elements[rand_index]);

        // Get user input
        char user_input[3];
        scanf("%s", user_input);

        // Check if user input matches symbol
        if(elements[rand_index][0] == user_input[0] && elements[rand_index][1] == user_input[1]) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct symbol is %c%c.\n", elements[rand_index][0], elements[rand_index][1]);
        }
    }

    printf("\n** QUIZ COMPLETE **\n");
    printf("You scored %d out of %d.\n", score, num_questions);
    printf("Thank you for playing!\n");

    return 0;
}