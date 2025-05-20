//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(){
    char name[20];
    int age;

    printf("Welcome to the Grateful Adventure Game!\n");
    printf("--------------------------------------\n\n");
    printf("What is your name?\n");
    scanf("%s", name);

    printf("\nHello, %s! How old are you?\n", name);
    scanf("%d", &age);

    printf("\nGreat! Are you ready to enter the world of gratitude? (y/n)\n");
    char choice;
    scanf(" %c", &choice);

    if(choice == 'y' || choice == 'Y'){
        printf("\nLet's go!\n\n");
        printf("You find yourself in a beautiful forest with a river running through it...\n\n");

        printf("You can choose to either:\n");
        printf("a) Follow the river\n");
        printf("b) Explore the forest\n");

        scanf(" %c", &choice);

        if(choice == 'a' || choice == 'A'){
            printf("\nYou follow the river and come across a group of lost hikers.\n");
            printf("They are thankful for your help and give you a map of the area.\n\n");
            printf("You can choose to either:\n");
            printf("a) Continue following the river\n");
            printf("b) Use the map to find a hidden treasure\n");
            scanf(" %c", &choice);

            if(choice == 'a' || choice == 'A'){
                printf("\nAs you continue following the river, you come across a wounded deer.\n");
                printf("You can choose to either:\n");
                printf("a) Ignore the deer\n");
                printf("b) Help the deer\n");
                scanf(" %c", &choice);

                if(choice == 'a' || choice == 'A'){
                    printf("\nYou decide to ignore the deer and continue on your journey.\n");
                    printf("As you walk further, you begin to feel guilty for not helping the deer...\n\n");
                    printf("You lose the game.\n");
                    return 0;
                }
                else if(choice == 'b' || choice == 'B'){
                    printf("\nYou choose to help the deer and tend to its wounds.\n");
                    printf("As a gesture of gratitude, the deer leads you to a hidden grotto where you find a magical ring.\n");
                    printf("Congratulations! You have won the game!\n");
                    return 0;
                }
            }
            else if(choice == 'b' || choice == 'B'){
                printf("\nUsing the map, you find a hidden treasure chest full of gold and riches!\n");
                printf("Congratulations! You have won the game!\n");
                return 0;
            }
        }
        else if(choice == 'b' || choice == 'B'){
            printf("\nAs you explore the forest, you come across a group of friendly woodland creatures.\n");
            printf("They offer to guide you through the forest and protect you from danger.\n");
            printf("You can choose to either:\n");
            printf("a) Accept their offer\n");
            printf("b) Decline their offer\n");
            scanf(" %c", &choice);

            if(choice == 'a' || choice == 'A'){
                printf("\nYou make new friends with the woodland creatures and they lead you safely through the forest.\n");
                printf("As a gesture of gratitude for their help, you plant a tree to give back to nature.\n");
                printf("Congratulations! You have won the game!\n");
                return 0;
            }
            else if(choice == 'b' || choice == 'B'){
                printf("\nYou decline their offer and continue on your own path through the forest.\n");
                printf("As you walk further, you get lost and are unable to find your way out...\n\n");
                printf("You lose the game.\n");
                return 0;
            }
        }
    }
    else{
        printf("\nMaybe next time. Goodbye!\n");
        return 0;
    }
}