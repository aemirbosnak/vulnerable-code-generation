//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void intro();
void livingRoom();
void kitchen();
void basement();
void library();
void spookyEnding();
void escapeEnding();

int main() {
    intro();
    return 0;
}

void intro() {
    printf("=====================================\n");
    printf("   Welcome to the Haunted House!   \n");
    printf("=====================================\n\n");
    printf("You awaken in a dimly lit room.\n");
    printf("What happened? You can't remember...\n");
    printf("Suddenly, you hear a loud crash!\n");
    printf("Your heart races...\n\n");
    printf("Do you want to:\n");
    printf("1. Explore the Living Room\n");
    printf("2. Check the Kitchen\n");
    printf("3. Go down to the Basement\n");
    printf("4. Search the Library\n");
  
    int choice;
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
  
    switch (choice) {
        case 1: livingRoom(); break;
        case 2: kitchen(); break;
        case 3: basement(); break;
        case 4: library(); break;
        default:
            printf("Invalid choice! The darkness swallows you...\n");
            exit(0);
    }
}

void livingRoom() {
    printf("\nYou step into the Living Room...\n");
    printf("The room feels colder, as if the walls are closing in on you.\n");
    printf("You notice a shadowy figure in the corner.\n");
    printf("Do you:\n");
    printf("1. Approach the figure\n");
    printf("2. Run back to where you came from\n");
    
    int choice;
    printf("Enter your choice (1-2): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("\nAs you approach, the figure turns and reveals a grotesque face...\n");
        spookyEnding();
    } else {
        printf("\nYou run back to the safety of the darkness...\n");
        intro();
    }
}

void kitchen() {
    printf("\nYou enter the Kitchen...\n");
    printf("Eerie sounds of clattering dishes echo around you.\n");
    printf("There's a flickering light coming from the pantry.\n");
    printf("Do you:\n");
    printf("1. Check the pantry\n");
    printf("2. Leave the kitchen and return to the main room\n");
    
    int choice;
    printf("Enter your choice (1-2): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("\nYou open the pantry and find a ghostly figure cooking...\n");
        printf("\"Help me! I'm trapped!\" it screams!\n");
        escapeEnding();
    } else {
        printf("\nYou decide to leave the kitchen, feeling uneasy...\n");
        intro();
    }
}

void basement() {
    printf("\nYou cautiously descend into the Basement...\n");
    printf("It's darker than you imagined...\n");
    printf("Suddenly, the door slams shut behind you!\n");
    printf("Do you:\n");
    printf("1. Search for an exit\n");
    printf("2. Sit down and wait for help\n");
    
    int choice;
    printf("Enter your choice (1-2): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("\nYou frantically search the darkness...\n");
        printf("But it's too late!\n");
        spookyEnding();
    } else {
        printf("\nYou sit in silence...\n");
        printf("The shadows curl around you until there's nothing left...\n");
        exit(0);
    }
}

void library() {
    printf("\nYou tread carefully into the Library...\n");
    printf("Books fly off the shelves, whispering your name...\n");
    printf("A book titled 'The Secrets of the Haunted' catches your eye.\n");
    printf("Do you:\n");
    printf("1. Read the book\n");
    printf("2. Ignore it and leave the library\n");
    
    int choice;
    printf("Enter your choice (1-2): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("\nAs you read, the words spring to life!\n");
        printf("A vortex opens, pulling you into another realm...\n");
        escapeEnding();
    } else {
        printf("\nYou choose to ignore the whispers...\n");
        printf("But the whispers grow louder until you can’t think!\n");
        spookyEnding();
    }
}

void spookyEnding() {
    printf("\n=================================\n");
    printf("         You Have Perished!     \n");
    printf("=================================\n");
    printf("As shadows engulf you, you scream in horror...\n");
    printf("But no one hears you...\n\n");
    exit(0);
}

void escapeEnding() {
    printf("\n=================================\n");
    printf("         You Have Escaped!      \n");
    printf("=================================\n");
    printf("With the last of your strength, you break free!\n");
    printf("Breathing heavily, you vow never to return...\n\n");
    exit(0);
}