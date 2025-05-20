//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: romantic
#include <stdio.h>
#include <string.h>

int main(){
    char name[20], choice[10], location[20], gift[20];
    
    printf("Welcome to the romantic adventure game!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("\n");
    
    printf("Hello %s, are you ready to go on a romantic adventure? (yes/no)", name);
    scanf("%s", choice);
    printf("\n");

    if(strcmp(choice, "yes") == 0){
        printf("Great %s! Where would you like to go on this adventure? (beach/mountain)", name);
        scanf("%s", location);
        printf("\n");
        
        if(strcmp(location, "beach") == 0){
            printf("The beach is a wonderful choice %s! Let's go on a romantic date and watch the sunset together.\n", name);
            printf("What gift will you bring for me? (flowers/chocolates)");
            scanf("%s", gift);
            printf("\n");
            
            if(strcmp(gift, "flowers") == 0){
                printf("Oh %s, you brought me my favorite flowers! You're so sweet, let's enjoy the sunset together.\n", name);
            }
            else if(strcmp(gift, "chocolates") == 0){
                printf("Mmm %s, chocolates are my favorite! This is why I love spending time with you. Let's enjoy the sunset together.\n", name);
            }
            else{
                printf("I'm sorry %s, I don't understand what you mean. Let's try again.\n", name);
            }
        }
        else if(strcmp(location, "mountain") == 0){
            printf("The mountains are a beautiful choice %s! Let's take a romantic hike together and enjoy the view.\n", name);
            printf("What gift will you bring for me? (jacket/hat)");
            scanf("%s", gift);
            printf("\n");
            
            if(strcmp(gift, "jacket") == 0){
                printf("Thank you %s, it's getting cold up here and your jacket keeps me warm. You're such a gentleman. Let's enjoy the view together.\n", name);
            }
            else if(strcmp(gift, "hat") == 0){
                printf("Aww %s, this hat looks great on me! You always know how to make me feel special. Let's enjoy the view together.\n", name);
            }
            else{
                printf("I'm sorry %s, I don't understand what you mean. Let's try again.\n", name);
            }
        }
        else{
            printf("I'm sorry %s, I don't understand where you want to go. Let's try again.\n", name);
        }   
    }
    else{
        printf("Oh %s, I'm sorry to hear that. Maybe next time. Goodbye!\n", name);
    }
    
    return 0;
}