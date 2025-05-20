//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char element[3];
    int atomic_number;
    char group[2];
    char period[2];
    char symbol[3];
} Element;

void printElement(Element element) {
    printf("Element: %s - Atomic Number: %d - Group: %s - Period: %s - Symbol: %s\n",
           element.element, element.atomic_number, element.group, element.period, element.symbol);
}

int main() {
    Element elements[] = {
        {"H", 1, "I", "1", "H"},
        {"He", 2, "II", "2", "He"},
        {"Li", 3, "III", "3", "Li"},
        {"Be", 4, "IV", "4", "Be"},
        {"B", 5, "V", "5", "B"},
        {"C", 6, "VI", "6", "C"},
        {"N", 7, "VII", "7", "N"},
        {"O", 8, "VIII", "8", "O"},
        {"F", 9, "IX", "9", "F"},
        {"Ne", 10, "X", "10", "Ne"},
        {"Na", 11, "XI", "11", "Na"},
        {"Mg", 12, "XII", "12", "Mg"},
        {"Al", 13, "XIII", "13", "Al"},
        {"Si", 14, "XIV", "14", "Si"},
        {"P", 15, "XV", "15", "P"},
        {"S", 16, "XVI", "16", "S"},
        {"Cl", 17, "XVII", "17", "Cl"},
        {"Ar", 18, "XVIII", "18", "Ar"},
        {"K", 19, "XIX", "19", "K"},
        {"Ca", 20, "XX", "20", "Ca"},
        {"Sc", 21, "XXI", "21", "Sc"},
        {"Ti", 22, "XXII", "22", "Ti"},
        {"V", 23, "XXIII", "23", "V"},
        {"Cr", 24, "XXIV", "24", "Cr"},
        {"Mn", 25, "XXV", "25", "Mn"},
        {"Fe", 26, "XXVI", "26", "Fe"},
        {"Co", 27, "XXVII", "27", "Co"},
        {"Ni", 28, "XXVIII", "28", "Ni"},
        {"Cu", 29, "XXIX", "29", "Cu"},
        {"Zn", 30, "XXX", "30", "Zn"},
        {"Ga", 31, "XXXI", "31", "Ga"},
        {"Ge", 32, "XXXII", "32", "Ge"},
        {"As", 33, "XXXIII", "33", "As"},
        {"Se", 34, "XXXIV", "34", "Se"},
        {"Br", 35, "XXXV", "35", "Br"},
        {"Kr", 36, "XXXVI", "36", "Kr"},
        {"Rb", 37, "XXXVII", "37", "Rb"},
        {"Sr", 38, "XXXVIII", "38", "Sr"},
        {"Y", 39, "XXXIX", "39", "Y"},
        {"Zr", 40, "XL", "40", "Zr"},
        {"Nb", 41, "XLI", "41", "Nb"},
        {"Mo", 42, "XLII", "42", "Mo"},
        {"Tc", 43, "XLIII", "43", "Tc"},
        {"Ru", 44, "XLIV", "44", "Ru"},
        {"Rh", 45, "XLV", "45", "Rh"},
        {"Pd", 46, "XLVI", "46", "Pd"},
        {"Ag", 47, "XLVII", "47", "Ag"},
        {"Cd", 48, "XLVIII", "48", "Cd"},
        {"In", 49, "XLIX", "49", "In"},
        {"Sn", 50, "L", "50", "Sn"},
        {"Sb", 51, "LI", "51", "Sb"},
        {"Te", 52, "LII", "52", "Te"},
        {"I", 53, "LIII", "53", "I"},
        {"Xe", 54, "LIV", "54", "Xe"},
        {"Cs", 55, "LV", "55", "Cs"},
        {"Ba", 56, "LVI", "56", "Ba"},
        {"La", 57, "LVII", "57", "La"},
        {"Ce", 58, "LVIII", "58", "Ce"},
        {"Pr", 59, "LIX", "59", "Pr"},
        {"Nd", 60, "LX", "60", "Nd"},
        {"Pm", 61, "LXI", "61", "Pm"},
        {"Sm", 62, "LXII", "62", "Sm"},
        {"Eu", 63, "LXIII", "63", "Eu"},
        {"Gd", 64, "LXIV", "64", "Gd"},
        {"Tb", 65, "LXV", "65", "Tb"},
        {"Dy", 66, "LXVI", "66", "Dy"},
        {"Ho", 67, "LXVII", "67", "Ho"},
        {"Er", 68, "LXVIII", "68", "Er"},
        {"Tm", 69, "LXIX", "69", "Tm"},
        {"Yb", 70, "LXX", "70", "Yb"},
        {"Lu", 71, "LXXI", "71", "Lu"},
        {"Hf", 72, "LXXII", "72", "Hf"},
        {"Ta", 73, "LXXIII", "73", "Ta"},
        {"W", 74, "LXXIV", "74", "W"},
        {"Re", 75, "LXXV", "75", "Re"},
        {"Os", 76, "LXXVI", "76", "Os"},
        {"Ir", 77, "LXXVII", "77", "Ir"},
        {"Pt", 78, "LXXVIII", "78", "Pt"},
        {"Au", 79, "LXXIX", "79", "Au"},
        {"Hg", 80, "LXXX", "80", "Hg"},
        {"Tl", 81, "LXXXI", "81", "Tl"},
        {"Pb", 82, "LXXXII", "82", "Pb"},
        {"Bi", 83, "LXXXIII", "83", "Bi"},
        {"Po", 84, "LXXXIV", "84", "Po"},
        {"At", 85, "LXXXV", "85", "At"},
        {"Rn", 86, "LXXXVI", "86", "Rn"},
        {"Fr", 87, "LXXXVII", "87", "Fr"},
        {"Ra", 88, "LXXXVIII", "88", "Ra"},
        {"Ac", 89, "LXXXIX", "89", "Ac"},
        {"Th", 90, "XC", "90", "Th"},
        {"Pa", 91, "XCI", "91", "Pa"},
        {"U", 92, "XCII", "92", "U"},
        {"Np", 93, "XCIII", "93", "Np"},
        {"Pu", 94, "XCIV", "94", "Pu"},
        {"Am", 95, "XCV", "95", "Am"},
        {"Cm", 96, "XCVI", "96", "Cm"},
        {"Bk", 97, "XCVII", "97", "Bk"},
        {"Cf", 98, "XCVIII", "98", "Cf"},
        {"Es", 99, "XCIX", "99", "Es"},
        {"Fm", 100, "C", "100", "Fm"},
    };

    int questions = sizeof(elements) / sizeof(Element);
    int index;
    int answer;
    int answer_given;

    printf("Welcome to the Periodic Table Quiz!\n");

    for (int i = 0; i < questions; i++) {
        printf("Question %d:\n", i + 1);
        printElement(elements[i]);
        printf("\nAnswer:\n");
        index = scanf("%d", &answer);
        if (index == EOF) {
            printf("Invalid input.\n");
            continue;
        }
        answer_given = answer;
        if (answer == elements[i].atomic_number) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %d.\n", elements[i].atomic_number);
        }
    }

    printf("Congratulations! You completed the quiz.\n");

    return 0;
}