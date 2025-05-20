//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayWelcome() {
    printf("===================================\n");
    printf(" WELCOME TO THE MEDIEVAL FORTUNE TELLER \n");
    printf("===================================\n");
    printf(" Gaze into the mystical crystal ball...\n");
    printf(" Choose your fate wisely!\n\n");
}

void displayChoices() {
    printf("Select the factor of your fortune:\n");
    printf("1. Your noble profession\n");
    printf("2. A fateful journey\n");
    printf("3. A secret love\n");
    printf("4. A bothersome enemy\n");
    printf("5. Consult the crystal ball (Exit)\n");
}

const char* getFortune(int choice) {
    switch (choice) {
        case 1: // Noble Profession
            switch (rand() % 5) {
                case 0: return "You shall have a prosperous harvest, noble farmer!";
                case 1: return "The sword shall sing for you, brave knight!";
                case 2: return "Your wisdom shall lead the village, esteemed scholar!";
                case 3: return "The merchant's goods shall be plentiful, cunning trader!";
                case 4: return "Your healing touch shall save many, benevolent healer!";
            }
            break;
        case 2: // Fateful Journey
            switch (rand() % 5) {
                case 0: return "Your travels will lead you to undiscovered lands!";
                case 1: return "Beware of trolls along the winding path!";
                case 2: return "You will forge powerful alliances in distant realms!";
                case 3: return "A companion will betray you, trust not too easily!";
                case 4: return "You shall return home with great wealth!";
            }
            break;
        case 3: // Secret Love
            switch (rand() % 5) {
                case 0: return "A forbidden romance awaits you in the shadows!";
                case 1: return "Love blossoms like roses, but thorns may prick!";
                case 2: return "The moon shall witness your secret rendezvous!";
                case 3: return "Beware, for jealousy lurks amongst your friends!";
                case 4: return "A knight shall steal your heart with valor!";
            }
            break;
        case 4: // Bothersome Enemy
            switch (rand() % 5) {
                case 0: return "Your enemy shall falter and fall into their own trap!";
                case 1: return "Stay vigilant; they weave webs of deceit!";
                case 2: return "Through wisdom, you shall outsmart your foe!";
                case 3: return "A hidden ally will come to your defense!";
                case 4: return "Your greatest strength will be your patience!";
            }
            break;
        default: return "The crystal ball is cloudy, seek another fortune!";
    }
    return "An error occurred while consulting the crystal ball.";
}

int main() {
    srand(time(NULL)); // Seed the random number generator for fortune selection
    int choice = 0;

    displayWelcome();

    do {
        displayChoices();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4) {
            const char* fortune = getFortune(choice);
            printf("Fortune: %s\n", fortune);
        } else if (choice == 5) {
            printf("May the fates be kind to you! Fare thee well!\n");
        } else {
            printf("A strange tremor shakes the crystal ball! Choose wisely!\n");
        }
        
        printf("\n");
    } while (choice != 5);

    return 0;
}