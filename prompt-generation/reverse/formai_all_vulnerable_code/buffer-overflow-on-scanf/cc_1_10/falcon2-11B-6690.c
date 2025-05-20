//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: real-life
#include <stdio.h>

int main() {
    int elements[100];
    int num_elements = 0;
    int element_id;
    int element_name;
    int element_symbol;
    int element_group;
    int element_period;
    int element_atomic_mass;
    int element_density;
    int element_melting_point;
    int element_boiling_point;
    int element_crystal_structure;
    int element_electronegativity;
    int element_ionic_radius;
    int element_electron_affinity;
    int element_first_ionization_energy;
    int element_electronegativity_difference;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Please enter the number of elements to quiz:\n");
    scanf("%d", &num_elements);

    for (int i = 0; i < num_elements; i++) {
        printf("Enter the ID of element %d:\n", i + 1);
        scanf("%d", &element_id);

        printf("Enter the name of element %d:\n", i + 1);
        scanf("%d", &element_name);

        printf("Enter the symbol of element %d:\n", i + 1);
        scanf("%d", &element_symbol);

        printf("Enter the group of element %d:\n", i + 1);
        scanf("%d", &element_group);

        printf("Enter the period of element %d:\n", i + 1);
        scanf("%d", &element_period);

        printf("Enter the atomic mass of element %d:\n", i + 1);
        scanf("%d", &element_atomic_mass);

        printf("Enter the density of element %d:\n", i + 1);
        scanf("%d", &element_density);

        printf("Enter the melting point of element %d:\n", i + 1);
        scanf("%d", &element_melting_point);

        printf("Enter the boiling point of element %d:\n", i + 1);
        scanf("%d", &element_boiling_point);

        printf("Enter the crystal structure of element %d:\n", i + 1);
        scanf("%d", &element_crystal_structure);

        printf("Enter the electronegativity of element %d:\n", i + 1);
        scanf("%d", &element_electronegativity);

        printf("Enter the ionic radius of element %d:\n", i + 1);
        scanf("%d", &element_ionic_radius);

        printf("Enter the electron affinity of element %d:\n", i + 1);
        scanf("%d", &element_electron_affinity);

        printf("Enter the first ionization energy of element %d:\n", i + 1);
        scanf("%d", &element_first_ionization_energy);

        printf("Enter the electronegativity difference of element %d:\n", i + 1);
        scanf("%d", &element_electronegativity_difference);

        elements[i] = element_id;
        elements[i + 1] = element_name;
        elements[i + 2] = element_symbol;
        elements[i + 3] = element_group;
        elements[i + 4] = element_period;
        elements[i + 5] = element_atomic_mass;
        elements[i + 6] = element_density;
        elements[i + 7] = element_melting_point;
        elements[i + 8] = element_boiling_point;
        elements[i + 9] = element_crystal_structure;
        elements[i + 10] = element_electronegativity;
        elements[i + 11] = element_ionic_radius;
        elements[i + 12] = element_electron_affinity;
        elements[i + 13] = element_first_ionization_energy;
        elements[i + 14] = element_electronegativity_difference;
    }

    printf("Periodic Table Quiz Results:\n");
    printf("-------------------------------\n");
    printf("Element ID\tElement Name\tSymbol\tGroup\tPeriod\tAtomic Mass\tDensity\tMelting Point\tBoiling Point\tCrystalline Structure\tElectronegativity\tIonic Radius\tElectron Affinity\tFirst Ionization Energy\tElectronegativity Difference\n");

    for (int i = 0; i < num_elements; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", elements[i], elements[i + 1], elements[i + 2], elements[i + 3], elements[i + 4], elements[i + 5], elements[i + 6], elements[i + 7], elements[i + 8], elements[i + 9], elements[i + 10], elements[i + 11], elements[i + 12], elements[i + 13], elements[i + 14]);
    }

    printf("-------------------------------\n");
    printf("Thank you for participating in the Periodic Table Quiz!\n");

    return 0;
}