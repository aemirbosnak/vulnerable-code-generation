//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEART "♥"
#define ROSE "🌹"

void love_letter(char* name) {
    printf("My Dearest %s,\n", name);
    printf("As I sit here under the twinkling stars, I cannot help but think of you.\n");
    printf("Your beauty is like the vastness of space, infinite and breathtaking.\n");
    printf("I am but a mere astronaut, exploring the depths of my love for you.\n");
    printf("Will you join me on this journey, my love?\n");
    printf("Together, we can conquer galaxies and create our own universe.\n");
    printf("Forever and always, yours truly.\n");
}

int main() {
    srand(time(NULL));
    int choice;
    char name[20];

    printf("Welcome to the Space Adventure of Love!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    while(1) {
        printf("\n");
        printf("1. Send a love letter\n");
        printf("2. Confess your love\n");
        printf("3. Propose marriage\n");
        printf("4. Exit\n");
        printf("\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                love_letter(name);
                break;
            case 2:
                printf("I must confess, my love for you is as vast as the universe itself.\n");
                printf("%s %s %s\n", HEART, name, HEART);
                break;
            case 3:
                printf("Will you marry me, my love?\n");
                printf("Together, we can create our own galaxy of happiness.\n");
                break;
            case 4:
                printf("Farewell, my love. Until we meet again in the stars.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}