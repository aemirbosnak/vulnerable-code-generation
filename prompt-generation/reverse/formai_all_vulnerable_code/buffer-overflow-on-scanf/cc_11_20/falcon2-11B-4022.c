//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_ATOMS 50
#define MAX_NAME_LEN 20
#define MAX_GROUP_LEN 5
#define MAX_PERIOD_LEN 5
#define MAX_ATOM_NAME_LEN (MAX_GROUP_LEN + MAX_PERIOD_LEN + 1)

struct atom {
    char name[MAX_ATOM_NAME_LEN];
    int group;
    int period;
};

int main() {
    struct atom atoms[MAX_NUM_ATOMS];
    int num_atoms = 0;

    printf("Welcome to the periodic table quiz!\n");
    printf("Enter the number of atoms to test: ");
    scanf("%d", &num_atoms);

    for (int i = 0; i < num_atoms; i++) {
        char name[MAX_ATOM_NAME_LEN];
        int group, period;

        printf("Enter the name of atom %d: ", i + 1);
        fgets(name, MAX_ATOM_NAME_LEN, stdin);
        name[strcspn(name, "\n")] = '\0';
        strcpy(atoms[i].name, name);

        printf("Enter the group of atom %d: ", i + 1);
        scanf("%d", &group);
        atoms[i].group = group;

        printf("Enter the period of atom %d: ", i + 1);
        scanf("%d", &period);
        atoms[i].period = period;
    }

    printf("\nTesting...\n");
    for (int i = 0; i < num_atoms; i++) {
        char group_name[MAX_GROUP_LEN], period_name[MAX_PERIOD_LEN];
        int group, period;

        group = atoms[i].group;
        period = atoms[i].period;

        strcpy(group_name, "Group");
        strcpy(period_name, "Period");
        if (group > 0 && group < 4) {
            strcat(group_name, "I");
        } else if (group > 4 && group < 9) {
            strcat(group_name, "II");
        } else if (group > 9 && group < 18) {
            strcat(group_name, "III");
        } else if (group > 18 && group < 30) {
            strcat(group_name, "IV");
        }

        strcpy(period_name, "1");
        if (period > 1) {
            strcat(period_name, "st");
        } else if (period > 2) {
            strcat(period_name, "nd");
        } else if (period > 3) {
            strcat(period_name, "rd");
        } else {
            strcat(period_name, "th");
        }

        printf("%d %s %s: %c%d\n", i + 1, group_name, period_name,
               atoms[i].name[group], atoms[i].name[period]);
    }

    printf("All atoms tested successfully!\n");
    return 0;
}