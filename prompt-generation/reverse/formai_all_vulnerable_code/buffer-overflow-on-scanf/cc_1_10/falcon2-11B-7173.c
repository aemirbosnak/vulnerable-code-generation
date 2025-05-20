//Falcon2-11B DATASET v1.0 Category: Educational ; Style: Cyberpunk
#include <stdio.h>

int main() {
    printf("Welcome to the Cyberpunk World!\n");
    printf("Your journey begins here:\n");
    printf("---------------------------\n");

    int strength = 100;
    int intelligence = 120;
    int agility = 90;

    int decision = 0;
    int choice;

    printf("Do you want to enhance your physical abilities (1) or your mental abilities (2)?\n");
    scanf("%d", &choice);

    if (choice == 1) {
        strength += 10;
        printf("Your strength has increased to %d.\n", strength);
        printf("---------------------------\n");

        decision = 0;
        choice = 0;

        printf("Do you want to enhance your physical abilities (1) or your mental abilities (2)?\n");
        scanf("%d", &choice);

        if (choice == 1) {
            strength += 10;
            printf("Your strength has increased to %d.\n", strength);
            printf("---------------------------\n");

            decision = 0;
            choice = 0;

            printf("Do you want to enhance your physical abilities (1) or your mental abilities (2)?\n");
            scanf("%d", &choice);
        }
    }

    if (choice == 2) {
        intelligence += 10;
        printf("Your intelligence has increased to %d.\n", intelligence);
        printf("---------------------------\n");

        decision = 0;
        choice = 0;

        printf("Do you want to enhance your physical abilities (1) or your mental abilities (2)?\n");
        scanf("%d", &choice);

        if (choice == 1) {
            strength += 10;
            printf("Your strength has increased to %d.\n", strength);
            printf("---------------------------\n");

            decision = 0;
            choice = 0;

            printf("Do you want to enhance your physical abilities (1) or your mental abilities (2)?\n");
            scanf("%d", &choice);
        }
    }

    if (decision == 0) {
        printf("You have chosen to enhance your physical abilities.\n");
        printf("Your strength is now %d.\n", strength);
        printf("---------------------------\n");

        printf("Do you want to enhance your physical abilities (1) or your mental abilities (2)?\n");
        scanf("%d", &choice);

        if (choice == 1) {
            strength += 10;
            printf("Your strength has increased to %d.\n", strength);
            printf("---------------------------\n");

            decision = 0;
            choice = 0;

            printf("Do you want to enhance your physical abilities (1) or your mental abilities (2)?\n");
            scanf("%d", &choice);
        }
    }

    if (decision == 0) {
        printf("You have chosen to enhance your mental abilities.\n");
        printf("Your intelligence is now %d.\n", intelligence);
        printf("---------------------------\n");

        printf("Do you want to enhance your physical abilities (1) or your mental abilities (2)?\n");
        scanf("%d", &choice);

        if (choice == 1) {
            strength += 10;
            printf("Your strength has increased to %d.\n", strength);
            printf("---------------------------\n");

            decision = 0;
            choice = 0;

            printf("Do you want to enhance your physical abilities (1) or your mental abilities (2)?\n");
            scanf("%d", &choice);
        }
    }

    printf("Congratulations! You have successfully enhanced your abilities!\n");
    printf("Your final stats are:\n");
    printf("Strength: %d\n", strength);
    printf("Intelligence: %d\n", intelligence);
    printf("Agility: %d\n", agility);
    printf("---------------------------\n");

    return 0;
}