//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_THEORIES 100
#define MAX_LENGTH 256

typedef struct {
    char premise[MAX_LENGTH];
    char conclusion[MAX_LENGTH];
} Theory;

const char *crazy_agenda[] = {
    "aliens",
    "secret societies",
    "global corporations",
    "artificial intelligence",
    "the government",
    "the illuminati",
    "big pharma",
    "the education system"
};

const char *random_event[] = {
    "the moon landing",
    "the COVID-19 pandemic",
    "the stock market crash",
    "the disappearance of Amelia Earhart",
    "the assassination of JFK",
    "the rise of cryptocurrencies",
    "climate change",
    "the invention of the internet"
};

const char *outlandish_claims[] = {
    "is a cover-up for sinister experiments.",
    "was orchestrated to control the masses.",
    "is actually a tool for mind control.",
    "was designed to distract from ongoing surveillance.",
    "is directly related to the emergence of deep fake technology.",
    "is part of a larger agenda to replace humans.",
    "is an elaborate hoax created by world leaders.",
    "is connected to ancient prophecies."
};

Theory theories[MAX_THEORIES];
int theory_count = 0;

void create_random_theory() {
    if (theory_count >= MAX_THEORIES) {
        printf("Max theories reached.\n");
        return;
    }

    snprintf(theories[theory_count].premise, MAX_LENGTH,
             "The event '%s' involving %s", 
             random_event[rand() % (sizeof(random_event) / sizeof(random_event[0]))],
             crazy_agenda[rand() % (sizeof(crazy_agenda) / sizeof(crazy_agenda[0]))]);

    snprintf(theories[theory_count].conclusion, MAX_LENGTH,
             "leads to the conclusion that %s", 
             outlandish_claims[rand() % (sizeof(outlandish_claims) / sizeof(outlandish_claims[0]))]);

    theory_count++;
}

void display_theories() {
    for (int i = 0; i < theory_count; i++) {
        printf("Theory %d: %s %s.\n", i + 1, theories[i].premise, theories[i].conclusion);
    }
}

void save_theories_to_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Failed to open file for writing.\n");
        return;
    }
    for (int i = 0; i < theory_count; i++) {
        fprintf(file, "Theory %d: %s %s.\n", i + 1, theories[i].premise, theories[i].conclusion);
    }
    fclose(file);
    printf("Theories saved to %s.\n", filename);
}

int main() {
    srand(time(0));

    int choice;
    char filename[MAX_LENGTH];

    while (1) {
        printf("\nConspiracy Theory Generator\n");
        printf("1. Generate a random theory\n");
        printf("2. Display all theories\n");
        printf("3. Save theories to file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_random_theory();
                printf("Random theory generated.\n");
                break;
            case 2:
                display_theories();
                break;
            case 3:
                printf("Enter filename to save theories: ");
                scanf("%s", filename);
                save_theories_to_file(filename);
                break;
            case 4:
                printf("Exiting the program. Stay safe!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}