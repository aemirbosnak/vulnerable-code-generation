//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[50];
    int affection;
} Character;

void clearScreen() {
    // Clear the terminal screen
    printf("\033[H\033[J");
}

void printHeart(int affection) {
    if (affection < 4) {
        printf("Affection: ❤️\n\n");
    } else if (affection < 8) {
        printf("Affection: ❤️❤️❤️\n\n");
    } else {
        printf("Affection: ❤️❤️❤️❤️❤️❤️❤️❤️\n\n");
    }
}

void showCharacter(Character *lover) {
    printf("You are trying to win the heart of %s.\n", lover->name);
    printHeart(lover->affection);
}

void randomEvent(Character *lover) {
    int event = rand() % 3;
    if (event == 0) {
        printf("%s smiles at you, your heart skips a beat!\n", lover->name);
        lover->affection += 2;
    } else if (event == 1) {
        printf("%s gave you a lovely flower!\n", lover->name);
        lover->affection += 3;
    } else {
        printf("You overheard %s talking about someone else...\n", lover->name);
        lover->affection -= 1;
    }
}

void askQuestion(Character *lover) {
    printf("Do you want to confess your feelings to %s? (yes/no)\n", lover->name);
    char response[4];
    scanf("%s", response);
    if (strcmp(response, "yes") == 0) {
        if (lover->affection >= 8) {
            printf("Congratulations! %s reciprocates your feelings and you both live happily ever after!\n", lover->name);
            exit(0);
        } else {
            printf("%s hesitated and did not feel the same way...\n", lover->name);
            lover->affection -= 2;
        }
    } else {
        printf("You decided to stay friends. However, you can’t help but feel a little sad...\n");
        lover->affection++;
    }
}

void romanticScenario(Character *lover) {
    showCharacter(lover);
    int choice = 0;

    while (1) {
        printf("Choose your action:\n");
        printf("1. Take %s for a walk\n", lover->name);
        printf("2. Write a poem for %s\n", lover->name);
        printf("3. Tell %s a joke\n", lover->name);
        printf("4. Ask a question about their feelings\n", lover->name);
        printf("5. Exit the game\n");
        
        scanf("%d", &choice);
        clearScreen();

        switch (choice) {
            case 1:
                printf("You took %s for a walk and enjoyed the beauty of nature together.\n", lover->name);
                lover->affection += 2;
                randomEvent(lover);
                break;
            case 2:
                printf("You wrote a heartfelt poem, and %s was deeply touched!\n", lover->name);
                lover->affection += 3;
                randomEvent(lover);
                break;
            case 3:
                printf("You told %s a funny joke, and their laughter brightened your day!\n", lover->name);
                lover->affection += 1;
                randomEvent(lover);
                break;
            case 4:
                askQuestion(lover);
                break;
            case 5:
                printf("Thank you for playing! Until next time...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
        showCharacter(lover);
        if (lover->affection <= 0) {
            printf("Your affection has dwindled to nothing. Perhaps it's time to let go...\n");
            exit(0);
        }
    }
}

int main() {
    srand(time(NULL));
    Character lover;
    strcpy(lover.name, "Juliet");
    lover.affection = 5; // Start with a neutral affection level

    clearScreen();
    printf("Welcome to 'Love Quest'! Your heart awaits you...\n");
    romanticScenario(&lover);

    return 0;
}