//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: complex
#include<stdio.h>
#include<string.h>

void showIntro() {
    printf("Welcome to the Text-based Adventure Game! \n");
    printf("In this game, you are stranded on a deserted island and your goal is to find a way to escape. \n");
    printf("You will encounter challenges and obstacles along the way, and you will need to think strategically to overcome them. \n\n");
}

void showMenu() {
    printf("What would you like to do? \n");
    printf("Enter 1 to search for food and water \n");
    printf("Enter 2 to explore the island \n");
    printf("Enter 3 to build a shelter \n");
}

void search() {
    printf("You decide to search for food and water. \n");
    printf("After a few hours of wandering around, you find a stream and some fruit trees. \n");
    printf("You drink some water and eat some fruit, and feel re-energized. \n\n");
}

void explore() {
    printf("You decide to explore the island. \n");
    printf("As you navigate through the dense forest, you hear strange noises and rustling in the bushes. \n");
    printf("Suddenly, a wild animal jumps out in front of you! \n");
    printf("What do you do? (Enter 1 to fight, 2 to run away) \n");

    int choice;
    scanf("%d", &choice);

    if(choice == 1) {
        printf("You decide to fight the animal. \n");
        printf("After an intense struggle, you manage to defeat it. \n\n");
    }
    else if(choice == 2) {
        printf("You decide to run away from the animal. \n");
        printf("You manage to escape, but you are exhausted and frightened. \n\n");
    }
    else {
        printf("Invalid choice, please try again. \n\n");
        explore();
    }
}

void buildShelter() {
    printf("You decide to build a shelter. \n");
    printf("After gathering some materials and finding a good spot, you start constructing a basic structure. \n");
    printf("It's hard work, but you manage to finish before nightfall. \n");
    printf("Now you have a place to sleep and protect yourself from the elements. \n\n");
}

int main() {
    showIntro();
    int playerChoice;
    do {
        showMenu();
        scanf("%d", &playerChoice);

        switch(playerChoice) {
            case 1:
                search();
                break;
            case 2:
                explore();
                break;
            case 3:
                buildShelter();
                break;
            default:
                printf("Invalid choice, please try again. \n\n");
                break;
        }
    } while(playerChoice != 4);

    printf("Congratulations, you have successfully escaped the island! \n");
    return 0;
}