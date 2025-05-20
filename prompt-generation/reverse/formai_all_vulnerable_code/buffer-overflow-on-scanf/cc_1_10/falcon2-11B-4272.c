//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM_ELEMENTS 100
#define MAX_NAME_LEN 20
#define MAX_NUM_LEN 4

typedef struct {
    char name[MAX_NAME_LEN];
    char num[MAX_NUM_LEN];
} Element;

Element elements[NUM_ELEMENTS] = {
    {"Hydrogen", "1"},
    {"Helium", "2"},
    {"Lithium", "3"},
    {"Beryllium", "4"},
    {"Boron", "5"},
    {"Carbon", "6"},
    {"Nitrogen", "7"},
    {"Oxygen", "8"},
    {"Fluorine", "9"},
    {"Neon", "10"},
    {"Sodium", "11"},
    {"Magnesium", "12"},
    {"Aluminium", "13"},
    {"Silicon", "14"},
    {"Phosphorus", "15"},
    {"Sulfur", "16"},
    {"Chlorine", "17"},
    {"Argon", "18"},
    {"Potassium", "19"},
    {"Calcium", "20"},
    {"Scandium", "21"},
    {"Titanium", "22"},
    {"Vanadium", "23"},
    {"Chromium", "24"},
    {"Manganese", "25"},
    {"Iron", "26"},
    {"Cobalt", "27"},
    {"Nickel", "28"},
    {"Copper", "29"},
    {"Zinc", "30"},
    {"Gallium", "31"},
    {"Germanium", "32"},
    {"Arsenic", "33"},
    {"Selenium", "34"},
    {"Bromine", "35"},
    {"Krypton", "36"},
    {"Rubidium", "37"},
    {"Strontium", "38"},
    {"Yttrium", "39"},
    {"Zirconium", "40"},
    {"Niobium", "41"},
    {"Molybdenum", "42"},
    {"Technetium", "43"},
    {"Ruthenium", "44"},
    {"Rhodium", "45"},
    {"Palladium", "46"},
    {"Silver", "47"},
    {"Cadmium", "48"},
    {"Indium", "49"},
    {"Tin", "50"},
    {"Antimony", "51"},
    {"Tellurium", "52"},
    {"Iodine", "53"},
    {"Xenon", "54"},
    {"Cesium", "55"},
    {"Barium", "56"},
    {"Lanthanum", "57"},
    {"Cerium", "58"},
    {"Praseodymium", "59"},
    {"Neodymium", "60"},
    {"Promethium", "61"},
    {"Samarium", "62"},
    {"Europium", "63"},
    {"Gadolinium", "64"},
    {"Terbium", "65"},
    {"Dysprosium", "66"},
    {"Holmium", "67"},
    {"Erbium", "68"},
    {"Thulium", "69"},
    {"Ytterbium", "70"},
    {"Lutetium", "71"},
    {"Hafnium", "72"},
    {"Tantalum", "73"},
    {"Tungsten", "74"},
    {"Rhenium", "75"},
    {"Osmium", "76"},
    {"Iridium", "77"},
    {"Platinum", "78"},
    {"Gold", "79"},
    {"Mercury", "80"},
    {"Thallium", "81"},
    {"Lead", "82"},
    {"Bismuth", "83"},
    {"Polonium", "84"},
    {"Astatine", "85"},
    {"Radon", "86"},
    {"Francium", "87"},
    {"Radium", "88"},
    {"Actinium", "89"},
    {"Thorium", "90"},
    {"Protactinium", "91"},
    {"Uranium", "92"},
    {"Neptunium", "93"},
    {"Plutonium", "94"},
    {"Americium", "95"},
    {"Curium", "96"},
    {"Berkelium", "97"},
    {"Californium", "98"},
    {"Einsteinium", "99"},
    {"Fermium", "100"}
};

int main() {
    int num_elements;
    char name[MAX_NAME_LEN];

    printf("Enter the number of elements to quiz (1-100): ");
    scanf("%d", &num_elements);

    if (num_elements < 1 || num_elements > NUM_ELEMENTS) {
        printf("Invalid number of elements. Please enter a number between 1 and 100.\n");
        return 1;
    }

    for (int i = 0; i < num_elements; i++) {
        printf("Element %d:\n", i + 1);
        printf("Name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        for (int j = 0; j < NUM_ELEMENTS; j++) {
            if (strcmp(name, elements[j].name) == 0) {
                printf("Element name: %s\n", name);
                printf("Element number: %s\n", elements[j].num);
                break;
            }
        }
    }

    return 0;
}