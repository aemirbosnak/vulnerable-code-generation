//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void intro();
void startGame();
void exploreRoom(int room);
void investigateItem(int item, int room);
void endGame();

int main(){
    intro();
    startGame();
    endGame();
    return 0;
}

void intro(){
    printf("Greetings Detective, I have received a report of a haunted house located on the outskirts of town. It seems that several people have entered the house and never returned. ");
    printf("Your mission, should you choose to accept it, is to investigate the haunted house and find out what is happening inside.\n");
    printf("Press Enter to continue\n");
    getchar();
    system("cls");
}

void startGame(){
    printf("You arrive at the haunted house, the front door is slightly ajar and the interior seems dark. You walk inside.\n");
    printf("As you explore each room, you will be given options to investigate items. Depending on your investigation, you will uncover clues that will help you solve the mystery of this haunted house.\n");
    printf("Press Enter to continue\n");
    getchar();
    system("cls");
    exploreRoom(1);
}

void exploreRoom(int room){
    printf("You enter room %d\n", room);
    printf("You see several items in the room. What would you like to investigate? Enter the corresponding number.\n");
    printf("1. An old portrait on the wall.\n2. A dusty book on the shelf.\n3. A set of drawers.\n4. A peculiar rug on the floor.\n");
    int choice = 0;
    scanf("%d", &choice);
    system("cls");
    investigateItem(choice, room);
}

void investigateItem(int item, int room){
    switch(item){
        case 1:
            printf("You investigate the portrait. It's old and shows a family from the early 1900s. You notice that the patriarch has a particular looking ring.\n");
            printf("Press Enter to continue\n");
            getchar();
            getchar();
            system("cls");
            exploreRoom(room);
            break;
        case 2:
            printf("You investigate the dusty book. It's a journal belonging to one of the house's previous owners. You notice a passage that mentions a hidden room behind a set of bookshelves.\n");
            printf("Press Enter to continue\n");
            getchar();
            getchar();
            system("cls");
            exploreRoom(room);
            break;
        case 3:
            printf("You investigate the set of drawers. You find nothing of interest.\n");
            printf("Press Enter to continue\n");
            getchar();
            getchar();
            system("cls");
            exploreRoom(room);
            break;
        case 4:
            printf("You investigate the peculiar rug. It feels squishy underfoot. You lift the corner and jump back as a swarm of rats scurries out.\n");
            printf("Press Enter to continue\n");
            getchar();
            getchar();
            system("cls");
            exploreRoom(room);
            break;
        default:
            printf("Invalid choice. Please choose a number between 1 and 4.\n");
            getchar();
            system("cls");
            exploreRoom(room);
            break;
    }
}

void endGame(){
    printf("Congratulations detective, you have uncovered enough clues to solve the mystery of the haunted house. You investigate the hidden room and find the remains of several people who had been trapped within.\n");
    printf("As you leave the house, you feel a sense of relief knowing that you have put an end to the haunted house's reign of terror.\n");
    printf("Press enter to finish\n");
    getchar();
}