//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    char choice[20];
    
    printf("Welcome to the Surrealist Adventure!\n");
    printf("What is your name?\n");
    scanf("%s", name);
    
    printf("Your name is %s. You find yourself in a strange land, surrounded by surreal landscapes and bizarre creatures.\n", name);
    printf("As you explore this strange world, you encounter a talking tree.\n");
    printf("The tree asks you, \"What is your deepest desire?\");\n");
    
    while (1) {
        printf("Please choose an option:\n");
        printf("1. Tell the tree your deepest desire\n");
        printf("2. Ignore the tree and keep exploring\n");
        printf("3. Run away from the tree\n");
        printf("4. Ask the tree if it can give you a map\n");
        printf("5. Quit the game\n");
        
        scanf("%s", choice);
        
        if (strcmp(choice, "1") == 0) {
            printf("You tell the tree your deepest desire.\n");
            printf("The tree nods and disappears.\n");
            printf("Suddenly, you find yourself back in your own world, with your deepest desire fulfilled.\n");
            printf("Congratulations, %s! You have completed the Surrealist Adventure!\n", name);
            break;
        } else if (strcmp(choice, "2") == 0) {
            printf("You ignore the tree and keep exploring.\n");
            printf("You stumble upon a strange door, which opens to reveal a hidden room.\n");
            printf("In the room, you find a mysterious object that grants you incredible powers.\n");
            printf("With these powers, you are able to conquer the surrealist world and emerge victorious!\n");
            printf("Congratulations, %s! You have completed the Surrealist Adventure!\n", name);
            break;
        } else if (strcmp(choice, "3") == 0) {
            printf("You run away from the tree.\n");
            printf("As you flee, you hear the tree's laughter echoing in your ears.\n");
            printf("Suddenly, you find yourself back in your own world, but everything seems different.\n");
            printf("You realize that you have lost your memory of the surrealist adventure.\n");
            printf("Congratulations, %s! You have completed the Surrealist Adventure, but lost your memory of it.\n", name);
            break;
        } else if (strcmp(choice, "4") == 0) {
            printf("You ask the tree if it can give you a map.\n");
            printf("The tree nods and hands you a map.\n");
            printf("You follow the map and explore the surrealist world.\n");
            printf("Eventually, you find a way back to your own world.\n");
            printf("Congratulations, %s! You have completed the Surrealist Adventure!\n", name);
            break;
        } else if (strcmp(choice, "5") == 0) {
            printf("You quit the game.\n");
            printf("As you exit the surrealist world, you hear the tree's laughter again.\n");
            printf("You wonder if you will ever return to the strange and surreal adventure.\n");
            printf("Congratulations, %s! You have completed the Surrealist Adventure!\n", name);
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}