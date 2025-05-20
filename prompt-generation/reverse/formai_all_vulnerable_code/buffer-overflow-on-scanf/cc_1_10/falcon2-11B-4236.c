//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: innovative
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a given element is in the periodic table
bool isPeriodicElement(char* element) {
    bool result = false;
    char* elements[7] = {"H", "He", "Li", "Be", "B", "C", "N"};
    for (int i = 0; i < 7; i++) {
        if (strcmp(elements[i], element) == 0) {
            result = true;
            break;
        }
    }
    return result;
}

// Function to check if a given element is in a given group
bool isInGroup(char* element, char* group) {
    bool result = false;
    char* groups[8] = {"Ia", "Ib", "Ic", "IIa", "IIb", "IIc", "IIIa", "Iva"};
    for (int i = 0; i < 8; i++) {
        if (strcmp(groups[i], group) == 0) {
            result = isPeriodicElement(element);
            break;
        }
    }
    return result;
}

// Function to check if a given element is in a given block
bool isInBlock(char* element, char* block) {
    bool result = false;
    char* blocks[4] = {"S", "P", "D", "F"};
    for (int i = 0; i < 4; i++) {
        if (strcmp(blocks[i], block) == 0) {
            result = isPeriodicElement(element);
            break;
        }
    }
    return result;
}

// Function to check if a given element is in a given family
bool isInFamily(char* element, char* family) {
    bool result = false;
    char* families[6] = {"Alkali Metals", "Alkaline Earth Metals", "Halogens", "Noble Gases", "Lanthanides", "Actinides"};
    for (int i = 0; i < 6; i++) {
        if (strcmp(families[i], family) == 0) {
            result = isPeriodicElement(element);
            break;
        }
    }
    return result;
}

// Function to check if a given element is in a given row
bool isInRow(char* element, char* row) {
    bool result = false;
    char* rows[7] = {"1", "2", "3", "4", "5", "6", "7"};
    for (int i = 0; i < 7; i++) {
        if (strcmp(rows[i], row) == 0) {
            result = isPeriodicElement(element);
            break;
        }
    }
    return result;
}

// Main function
int main() {
    char element[20];
    char group[20];
    char block[20];
    char family[20];
    char row[20];

    printf("Enter an element: ");
    scanf("%s", element);

    printf("Enter a group: ");
    scanf("%s", group);

    printf("Enter a block: ");
    scanf("%s", block);

    printf("Enter a family: ");
    scanf("%s", family);

    printf("Enter a row: ");
    scanf("%s", row);

    if (isPeriodicElement(element)) {
        if (isInGroup(element, group)) {
            if (isInBlock(element, block)) {
                if (isInFamily(element, family)) {
                    if (isInRow(element, row)) {
                        printf("The element %s is in group %s, block %s, family %s, and row %s.\n", element, group, block, family, row);
                    } else {
                        printf("The element %s is in group %s, block %s, family %s, but not in row %s.\n", element, group, block, family, row);
                    }
                } else {
                    printf("The element %s is in group %s, block %s, but not in family %s.\n", element, group, block, family);
                }
            } else {
                printf("The element %s is in group %s, but not in block %s.\n", element, group, block);
            }
        } else {
            printf("The element %s is in group %s, but not in block %s.\n", element, group, block);
        }
    } else {
        printf("The element %s is not in the periodic table.\n", element);
    }

    return 0;
}