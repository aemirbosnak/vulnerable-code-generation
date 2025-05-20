//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: cheerful
#include<stdio.h>
#include<string.h>

int main(){
    char name[20];
    printf("Welcome to the Adventure Game!!!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("\nHello %s!!!\n", name);
    printf("In this game, you are starting in a town and your job is to find\n");
    printf("the treasure hidden in a dungeon. Let's begin!!!\n");
    printf("You find yourself in front of a signpost that says there are\n");
    printf("three paths to take. Enter '1' for the left path, '2' for the\n");
    printf("middle path, and '3' for the right path: ");
    int choice;
    scanf("%d", &choice);
    if(choice == 1){
        printf("\nYou come across a river. Enter '1' to swim across\n");
        printf("or '2' to try and find a bridge: ");
        int cross;
        scanf("%d", &cross);
        if(cross == 1){
            printf("\nYou made it across the river safely but now you're\n");
            printf("completely soaked. You're shivering and now vulnerable.\n");
            printf("Suddenly a friendly hermit appears and gives you a warm\n");
            printf("peppermint tea to help you warm up. Thank the hermit and\n");
            printf("continue your journey!!!\n");
        }
        else if(cross == 2){
            printf("\nYou come across the bridge and notice a troll guarding it.\n");
            printf("Talk to the troll ('1') or try to sneak past ('2')?");
            int troll;
            scanf("%d", &troll);
            if(troll == 1){
                printf("\nThe troll greets you and tells you a joke, giving\n");
                printf("you a good laugh. The troll doesn't want to mess with\n");
                printf("a happy-go-lucky adventurer like you!!!\n");
            }
            else if(troll == 2){
                printf("\nYou try to sneak past the troll but your attempt fails.\n");
                printf("The troll notices you and demands you solve a math problem.\n");
                printf("If you don't solve it in time, you'll have to fight the troll. \n");
                printf("25 + 33 = ? ");
                int ans;
                scanf("%d", &ans);
                if(ans == 58){
                    printf("\nThe troll is impressed and lets you pass.\n");
                }
                else{
                    printf("\nThe troll is upset you couldn't solve such an easy problem.\n");
                    printf("You now have to fight the troll.\nGood luck!!!\n");
                }
            }
        }
    }
    else if(choice == 2){
        printf("\nYou see a horse carriage with a strange merchant offering\n");
        printf("goods. Buy from him ('1') or ignore him and continue ('2')?\n");
        int merchant;
        scanf("%d", &merchant);
        if(merchant == 1){
            printf("\nThe merchant offers you a magical healing potion for 50 gold\n");
            printf("pieces. Buy it ('1') or ignore him and continue ('2')?\n");
            int potion;
            scanf("%d", &potion);
            if(potion == 1){
                printf("\nYou made a great decision! The potion comes in handy\n");
                printf("later in the game.\n");
            }
            else{
                printf("\nYou ignore the merchant and continue but you later\n");
                printf("regret not buying the potion.\n");
            }
        }
        else{
            printf("\nYou ignore the merchant and continue on your journey.\n");
        }
    }
    else if(choice == 3){
        printf("\nYou come across a forked road and need to choose which way to continue. \n");
        printf("Enter '1' to take the left path and enter '2' to take the right path: ");
        int fork;
        scanf("%d", &fork);
        if(fork == 1){
            printf("\nYou find a group of puppies. Play with them ('1') or leave them be ('2')?\n");
            int puppy;
            scanf("%d", &puppy);
            if(puppy == 1){
                printf("\nYou spend time playing with the puppies. They're so cute!\n");
                printf("They show you a secret path deeper into the forest.\n");
            }
            else{
                printf("\nYou leave the puppies and continue through the forest.\n");
            }
        }
        else{
            printf("\nYou come across a farmer and his wife planting crops.\n");
            printf("They notice you and offer you some fresh vegetables and water.\n");
            printf("Take a break and accept their offer ('1') or continue your journey ('2')?");
            int offer;
            scanf("%d", &offer);
            if(offer == 1){
                printf("\nYou accept the farmer and his wife's offer. They're very hospitable\n");
                printf("and offer you a room to rest and refresh.\n");
            }
            else{
                printf("\nYou decline the offer and continue your journey.\n");
            }
        }
    }
    printf("\nYou have found a dungeon! You must enter to find the treasure! Good luck!!!\n");
    printf("Thank you for playing %s!!!\n", name);
    return 0;
}