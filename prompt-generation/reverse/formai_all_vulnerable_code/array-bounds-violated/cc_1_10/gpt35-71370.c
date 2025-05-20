//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* correct_answers[] = {
    "Oxygen",
    "Helium",
    "Carbon",
    "Neon",
    "Sodium",
    "Iron",
    "Fluorine",
    "Chlorine",
    "Potassium",
    "Silver"
};

char* elements[] = {
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
    "Aluminum",
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
    "Cesium",
    "Barium",
};

int main() {
    int i;
    int num_correct = 0;
    char answer[16];
    
    printf("Welcome to the Periodic Table Quiz!\n");
    
    for (i = 0; i < 10; i++) {
        int rand_num = rand() % 50;
        char* element = elements[rand_num];
        printf("What is the chemical symbol for %s? ", element);
        scanf("%s", answer);
        tolower(answer);
        
        if (strcmp(answer, correct_answers[rand_num]) == 0) {
            printf("Correct!\n");
            num_correct++;
        } else {
            printf("Incorrect. The correct answer was %s.\n", correct_answers[rand_num]);
        }
    }
    
    printf("You got %d out of 10 correct.\n", num_correct);
    
    return 0;
}