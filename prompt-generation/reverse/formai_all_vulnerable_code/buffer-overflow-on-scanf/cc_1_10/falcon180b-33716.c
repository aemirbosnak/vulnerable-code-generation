//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: medieval
#include <stdio.h>

#define MAX_VIRUSES 10

struct Virus {
    char name[50];
    char type[50];
    int danger_level;
};

int main() {
    struct Virus viruses[MAX_VIRUSES] = {
        {"Black Death", "Plague", 10},
        {"Smallpox", "Disease", 8},
        {"Influenza", "Flu", 6},
        {"Measles", "Disease", 7},
        {"Typhoid Fever", "Disease", 9},
        {"Yellow Fever", "Disease", 7},
        {"Malaria", "Disease", 6},
        {"Cholera", "Disease", 8},
        {"Tuberculosis", "Disease", 7},
        {"Pneumonia", "Disease", 5}
    };

    int choice;
    char input[50];

    printf("Welcome to the Medieval Antivirus Scanner!\n");
    printf("Please choose an option:\n");
    printf("1. Scan for viruses\n");
    printf("2. View virus list\n");
    printf("3. Exit\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Scanning for viruses...\n");
            for(int i=0; i<MAX_VIRUSES; i++) {
                if(viruses[i].danger_level > 0) {
                    printf("Virus found: %s (%s) - Danger level: %d\n", viruses[i].name, viruses[i].type, viruses[i].danger_level);
                }
            }
            break;

        case 2:
            printf("List of known viruses:\n");
            for(int i=0; i<MAX_VIRUSES; i++) {
                if(viruses[i].danger_level > 0) {
                    printf("%s (%s) - Danger level: %d\n", viruses[i].name, viruses[i].type, viruses[i].danger_level);
                }
            }
            break;

        case 3:
            printf("Goodbye!");
            break;

        default:
            printf("Invalid option!");
            break;
    }

    return 0;
}