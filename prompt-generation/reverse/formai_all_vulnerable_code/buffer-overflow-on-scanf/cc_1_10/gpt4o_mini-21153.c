//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_THEORIES 10
#define MAX_FACTORS 5
#define MAX_CHAR 256

typedef struct {
    char *description;
    char *factors[MAX_FACTORS];
} ConspiracyTheory;

void initialize_theories(ConspiracyTheory theories[]);
void randomize_factors(ConspiracyTheory *theory);
void generate_conspiracy_report(ConspiracyTheory *theory);
void pick_random_factors(ConspiracyTheory *theory);
void print_theory(ConspiracyTheory *theory);

int main() {
    srand(time(NULL));
    
    ConspiracyTheory theories[MAX_THEORIES];
    initialize_theories(theories);

    int choice;
    
    do {
        printf("\033[0;32m");
        printf("Welcome to the C Random Conspiracy Theory Generator!\n");
        printf("1. Generate a new conspiracy theory\n");
        printf("0. Exit\n");
        printf("\033[0m");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int random_index = rand() % MAX_THEORIES;
            generate_conspiracy_report(&theories[random_index]);
        } else if (choice != 0) {
            printf("\033[0;31mInvalid choice! Please try again.\033[0m\n");
        }
    } while (choice != 0);

    printf("\033[0;34mThank you for using the Conspiracy Theory Generator!\n\033[0m");
    return 0;
}

void initialize_theories(ConspiracyTheory theories[]) {
    theories[0].description = "Aliens are controlling social media to distract humanity.";
    theories[0].factors[0] = "The rise of influencer culture.";
    theories[0].factors[1] = "Unexplained signals from the cosmos.";
    theories[0].factors[2] = "Government silence on UFO sightings.";
    theories[0].factors[3] = "Patterns in viral trends.";
    theories[0].factors[4] = "Whistleblower testimony.";

    theories[1].description = "The education system is designed to keep people ignorant.";
    theories[1].factors[0] = "Standardized testing.";
    theories[1].factors[1] = "Limited critical thinking in curriculums.";
    theories[1].factors[2] = "Funding cuts to the arts and humanities.";
    theories[1].factors[3] = "Corporate influence in textbooks.";
    theories[1].factors[4] = "Access to information disparity.";

    theories[2].description = "Time travelers are influencing historical events.";
    theories[2].factors[0] = "Recorded instances of déjà vu.";
    theories[2].factors[1] = "Inconsistencies in historical documents.";
    theories[2].factors[2] = "Unexplained technological advancements.";
    theories[2].factors[3] = "Witness accounts of strange individuals.";
    theories[2].factors[4] = "Government time travel programs.";

    theories[3].description = "Famous figures are actually clones created by a secret society.";
    theories[3].factors[0] = "Similarities in their behavior.";
    theories[3].factors[1] = "Conspiracy websites claiming to find clones.";
    theories[3].factors[2] = "Media coverage of celebrity mishaps.";
    theories[3].factors[3] = "Decreased life spans of public figures.";
    theories[3].factors[4] = "Unexplained disappearances.";

    theories[4].description = "The moon landing was staged by a consortium of scientists.";
    theories[4].factors[0] = "Photographic anomalies in lunar images.";
    theories[4].factors[1] = "Conflicting statements from astronauts.";
    theories[4].factors[2] = "Documentaries exposing inconsistencies.";
    theories[4].factors[3] = "Advancements in CGI technology.";
    theories[4].factors[4] = "Secret government contracts.";

    theories[5].description = "Bigfoot is a government experiment gone wrong.";
    theories[5].factors[0] = "Unexplained disappearances in the forest.";
    theories[5].factors[1] = "Mysterious and unrecorded sightings.";
    theories[5].factors[2] = "Government denial of biological testing.";
    theories[5].factors[3] = "Hiker confusion and reports.";
    theories[5].factors[4] = "Patterns in movement observed via drones.";

    theories[6].description = "Birds are actually surveillance drones.";
    theories[6].factors[0] = "Inconsistent migration patterns.";
    theories[6].factors[1] = "Reports of birds behaving strangely.";
    theories[6].factors[2] = "Lack of organic material found.";
    theories[6].factors[3] = "Government-funded drone technology.";
    theories[6].factors[4] = "Perpetual surveillance projects.";

    theories[7].description = "Vaccines are a way to control the population.";
    theories[7].factors[0] = "Reports of vaccine side-effects.";
    theories[7].factors[1] = "Questions regarding pharmaceutical funding.";
    theories[7].factors[2] = "Public mistrust in medical establishments.";
    theories[7].factors[3] = "Aggressive marketing of vaccines.";
    theories[7].factors[4] = "Altered health statistics.";

    theories[8].description = "The Earth is actually flat and climate change is a hoax.";
    theories[8].factors[0] = "Non-mainstream research promoting flat Earth theories.";
    theories[8].factors[1] = "Discrepancies in navigation technology.";
    theories[8].factors[2] = "Skepticism towards scientists.";
    theories[8].factors[3] = "History of censorship in science.";
    theories[8].factors[4] = "Community of flat Earth believers.";

    theories[9].description = "The internet is altering reality as we know it.";
    theories[9].factors[0] = "Increased cases of digital addiction.";
    theories[9].factors[1] = "Governments controlling internet access.";
    theories[9].factors[2] = "Social media shaping perceptions.";
    theories[9].factors[3] = "Virtual reality blurring lines of truth.";
    theories[9].factors[4] = "Manipulation of information streams.";
}

void generate_conspiracy_report(ConspiracyTheory *theory) {
    printf("\n\033[0;35m=== Conspiracy Theory ===\033[0m\n");
    printf("\033[1;33m%s\033[0m\n", theory->description);
    printf("\033[0;36mSupporting Factors:\033[0m\n");
    pick_random_factors(theory);
    print_theory(theory);
}

void pick_random_factors(ConspiracyTheory *theory) {
    int chosen_indices[MAX_FACTORS];
    int count = 0;

    while (count < MAX_FACTORS) {
        int idx = rand() % MAX_FACTORS;
        int already_chosen = 0;

        for (int j = 0; j < count; j++) {
            if (chosen_indices[j] == idx) {
                already_chosen = 1;
                break;
            }
        }

        if (!already_chosen) {
            chosen_indices[count++] = idx;
            printf("- %s\n", theory->factors[idx]);
        }
    }
}

void print_theory(ConspiracyTheory *theory) {
    printf("\n\033[0;34mShare this theory widely!\n\033[0m");
}