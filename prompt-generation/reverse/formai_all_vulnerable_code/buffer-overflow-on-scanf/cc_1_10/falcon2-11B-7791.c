//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Element {
    char name[15];
    int atomicNumber;
    int mass;
};

struct Element elements[] = {
    {"Hydrogen", 1, 1},
    {"Helium", 2, 4},
    {"Lithium", 3, 7},
    {"Beryllium", 4, 9},
    {"Boron", 5, 10},
    {"Carbon", 6, 12},
    {"Nitrogen", 7, 14},
    {"Oxygen", 8, 16},
    {"Fluorine", 9, 19},
    {"Neon", 10, 20},
    {"Sodium", 11, 23},
    {"Magnesium", 12, 24},
    {"Aluminum", 13, 27},
    {"Silicon", 14, 28},
    {"Phosphorus", 15, 31},
    {"Sulfur", 16, 32},
    {"Chlorine", 17, 35},
    {"Argon", 18, 40},
    {"Potassium", 19, 39},
    {"Calcium", 20, 40},
    {"Scandium", 21, 44},
    {"Titanium", 22, 47},
    {"Vanadium", 23, 50},
    {"Chromium", 24, 51},
    {"Manganese", 25, 54},
    {"Iron", 26, 55},
    {"Cobalt", 27, 58},
    {"Nickel", 28, 58},
    {"Copper", 29, 63},
    {"Zinc", 30, 65},
    {"Gallium", 31, 69},
    {"Germanium", 32, 72},
    {"Arsenic", 33, 74},
    {"Selenium", 34, 78},
    {"Bromine", 35, 79},
    {"Krypton", 36, 83},
    {"Rubidium", 37, 85},
    {"Strontium", 38, 88},
    {"Yttrium", 39, 88},
    {"Zirconium", 40, 91},
    {"Niobium", 41, 92},
    {"Molybdenum", 42, 95},
    {"Technetium", 43, 97},
    {"Ruthenium", 44, 101},
    {"Rhodium", 45, 102},
    {"Palladium", 46, 106},
    {"Silver", 47, 107},
    {"Cadmium", 48, 112},
    {"Indium", 49, 114},
    {"Tin", 50, 118},
    {"Antimony", 51, 121},
    {"Tellurium", 52, 128},
    {"Iodine", 53, 126},
    {"Xenon", 54, 131},
    {"Cesium", 55, 132},
    {"Barium", 56, 137},
    {"Lanthanum", 57, 138},
    {"Cerium", 58, 140},
    {"Praseodymium", 59, 140},
    {"Neodymium", 60, 144},
    {"Promethium", 61, 145},
    {"Samarium", 62, 150},
    {"Europium", 63, 151},
    {"Gadolinium", 64, 157},
    {"Terbium", 65, 158},
    {"Dysprosium", 66, 162},
    {"Holmium", 67, 164},
    {"Erbium", 68, 167},
    {"Thulium", 69, 169},
    {"Ytterbium", 70, 173},
    {"Lutetium", 71, 174},
    {"Hafnium", 72, 178},
    {"Tantalum", 73, 180},
    {"Tungsten", 74, 183},
    {"Rhenium", 75, 186},
    {"Osmium", 76, 190},
    {"Iridium", 77, 192},
    {"Platinum", 78, 195},
    {"Gold", 79, 197},
    {"Mercury", 80, 200},
    {"Thallium", 81, 204},
    {"Lead", 82, 207},
    {"Bismuth", 83, 208},
    {"Polonium", 84, 209},
    {"Astatine", 85, 210},
    {"Radon", 86, 222},
    {"Francium", 87, 223},
    {"Radium", 88, 226},
    {"Actinium", 89, 227},
    {"Thorium", 90, 232},
    {"Protactinium", 91, 231},
    {"Uranium", 92, 238},
    {"Neptunium", 93, 237},
    {"Plutonium", 94, 244},
    {"Americium", 95, 243},
    {"Curium", 96, 247},
    {"Berkelium", 97, 247},
    {"Californium", 98, 251},
    {"Einsteinium", 99, 252},
    {"Fermium", 100, 257},
    {"Mendelevium", 101, 258},
    {"Nobelium", 102, 259},
    {"Lawrencium", 103, 262},
    {"Rutherfordium", 104, 262},
    {"Dubnium", 105, 268},
    {"Seaborgium", 106, 270},
    {"Bohrium", 107, 268},
    {"Hassium", 108, 270},
    {"Meitnerium", 109, 276},
    {"Darmstadtium", 110, 281},
    {"Roentgenium", 111, 281},
    {"Copernicium", 112, 285},
    {"Nihonium", 113, 286},
    {"Flerovium", 114, 289},
    {"Moscovium", 115, 289},
    {"Livermorium", 116, 294},
    {"Tennessine", 117, 294},
    {"Oganesson", 118, 294},
};

int main() {
    int testCases, i, j;
    char name[15];

    scanf("%d", &testCases);

    for (i = 0; i < testCases; i++) {
        scanf("%s", name);
        int index = 0;

        for (j = 0; j < 118; j++) {
            if (strcmp(elements[j].name, name) == 0) {
                printf("%s\n", elements[j].name);
                printf("Atomic Number: %d\n", elements[j].atomicNumber);
                printf("Mass: %d\n\n", elements[j].mass);
                break;
            }
        }

        if (j == 118) {
            printf("Element not found!\n\n");
        }
    }

    return 0;
}