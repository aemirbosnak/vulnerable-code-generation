//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

int main() {
    int pushups = 0;
    int situps = 0;
    int squats = 0;

    printf("Welcome to your fitness tracker!\n");

    while(1) {
        int choice;

        printf("\nChoose an option:\n");
        printf("1. Log pushups\n");
        printf("2. Log situps\n");
        printf("3. Log squats\n");
        printf("4. View progress\n");
        printf("5. Quit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter number of pushups: ");
                int new_pushups;
                scanf("%d", &new_pushups);
                pushups += new_pushups;
                break;
            case 2:
                printf("Enter number of situps: ");
                int new_situps;
                scanf("%d", &new_situps);
                situps += new_situps;
                break;
            case 3:
                printf("Enter number of squats: ");
                int new_squats;
                scanf("%d", &new_squats);
                squats += new_squats;
                break;
            case 4:
                printf("Pushups: %d\n", pushups);
                printf("Situps: %d\n", situps);
                printf("Squats: %d\n", squats);
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}