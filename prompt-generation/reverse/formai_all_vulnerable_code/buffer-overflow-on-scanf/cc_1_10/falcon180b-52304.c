//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NAME_LENGTH 100
#define MAX_PLOT_LENGTH 1000
#define MAX_CONSPIRATORS 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char plot[MAX_PLOT_LENGTH];
} Conspirator;

void generate_conspiracy_theory(int num_conspirators) {
    srand(time(0));

    Conspirator conspirators[MAX_CONSPIRATORS];
    int num_generated_conspirators = 0;

    while (num_generated_conspirators < num_conspirators) {
        Conspirator new_conspirator;
        strcpy(new_conspirator.name, "");
        strcpy(new_conspirator.plot, "");

        int name_length = rand() % MAX_NAME_LENGTH + 1;
        for (int i = 0; i < name_length; i++) {
            char letter = rand() % 26 + 'a';
            new_conspirator.name[i] = letter;
        }

        int plot_length = rand() % MAX_PLOT_LENGTH + 1;
        for (int i = 0; i < plot_length; i++) {
            char letter = rand() % 26 + 'a';
            new_conspirator.plot[i] = letter;
        }

        conspirators[num_generated_conspirators] = new_conspirator;
        num_generated_conspirators++;
    }

    printf("Conspiracy Theory:\n");
    for (int i = 0; i < num_conspirators; i++) {
        printf("Conspirator %d: %s - %s\n", i + 1, conspirators[i].name, conspirators[i].plot);
    }
}

int main() {
    int num_conspirators;

    printf("Enter the number of conspirators: ");
    scanf("%d", &num_conspirators);

    generate_conspiracy_theory(num_conspirators);

    return 0;
}