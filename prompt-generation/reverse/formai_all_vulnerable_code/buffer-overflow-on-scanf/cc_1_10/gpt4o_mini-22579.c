//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void welcomeMessage() {
    printf("In fair Verona, where we lay our scene...\n");
    printf("A haunted house awaits, full of love and fear!\n");
    printf("Choose wisely, dear player, for fate is near.\n");
    printf("Enter '1' to embark on the haunting, '0' to flee: ");
}

void romeoEncounter() {
    printf("As you step inside, you see Romeo, a spirit so forlorn.\n");
    printf("He whispers, 'Oh, how my heart mourns!'\n");
    printf("Choose:\n");
    printf("1. Comfort him with words of solace.\n");
    printf("2. Flee in terror from his ghostly form.\n");
}

void julietEncounter() {
    printf("Suddenly, a flicker of light reveals Juliet's silhouette.\n");
    printf("She beckons softly, 'Come near, do not regret.'\n");
    printf("Choose:\n");
    printf("1. Embrace her sorrow with a song.\n");
    printf("2. Turn and run from the heart's heavy song.\n");
}

void graveyardScene() {
    printf("You find yourself in a graveyard, shrouded in gloom.\n");
    printf("A voice echoes, 'This is your doom!'\n");
    printf("Choose:\n");
    printf("1. Seek the truth behind this curse.\n");
    printf("2. Hide behind a tombstone, ready to disperse.\n");
}

void climax() {
    printf("In a moment of tension, love and despair entwine.\n");
    printf("You'll face the haunting choice, love or fear, you've drawn the line!\n");
    printf("Choose:\n");
    printf("1. Unite their spirits to break the curse.\n");
    printf("2. Abandon the lovers, for sorrow is worse.\n");
}

void fate(int choice) {
    switch(choice) {
        case 1:
            printf("With a heart full of courage, you unite their spirits!\n");
            printf("The house trembles, love conquers their limits!\n");
            printf("Joyful whispers fill the haunted halls, love prevails!\n");
            break;
        case 2:
            printf("You choose to abandon their fate, darkness prevails.\n");
            printf("The house collapses, and sorrow wails!\n");
            printf("You've succumbed to the shadows, eternally haunted.\n");
            break;
        default:
            printf("Your silence speaks volumes, yet echoes in vain!\n");
    }
}

int main() {
    int choice;

    welcomeMessage();
    scanf("%d", &choice);
    
    if (choice == 1) {
        romeoEncounter();
        scanf("%d", &choice);
        
        if (choice == 1) {
            julietEncounter();
            scanf("%d", &choice);
            
            if (choice == 1) {
                graveyardScene();
                scanf("%d", &choice);
                
                if (choice == 1) {
                    climax();
                    scanf("%d", &choice);
                    fate(choice);
                } else {
                    printf("Hiding in fear, you remain forever lost...\n");
                }
                
            } else {
                printf("In fear, you run, leaving love in despair.\n");
            }
        } else {
            printf("You fled from Romeo, leaving a heart bare.\n");
        }
    } else {
        printf("You chose to flee, a tale never told.\n");
    }
    
    printf("\nThanks for playing, dear friend, in this tale unfold!\n");
    return 0;
}