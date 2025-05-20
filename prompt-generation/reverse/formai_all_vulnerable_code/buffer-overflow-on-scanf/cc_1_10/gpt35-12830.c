//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: real-life
#include <stdio.h>

int main() {
    
    // Game Introduction
    printf("Welcome to the real-life adventure game!\n");
    printf("You are a young professional who is tired of the routine. You decide to quit your job and embark on a journey.\n");
    printf("You have two options:\n");
    printf("1. Travel to a new city\n");
    printf("2. Go backpacking in the mountains\n");
    
    // Option 1: Travel to a new city
    int choice;
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("Congratulations on choosing to travel to a new city!\n");
        printf("As you are walking through the city's famous street, you notice a wallet lying on the ground.\n");
        printf("What would you like to do?\n");
        printf("1. Pick up the wallet and take it to the nearest police station\n");
        printf("2. Leave the wallet there and continue walking\n");
        
        int wallet;
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &wallet);
        
        if (wallet == 1) {
            printf("You pick up the wallet and head towards the police station.\n");
            printf("As you hand the wallet to the police officer, he thanks you and rewards you with $100.\n");
        }
        else {
            printf("You decide to leave the wallet there and continue walking.\n");
            printf("As you walk further, you notice a homeless person who looks like he could use some help.\n");
            printf("What would you like to do?\n");
            printf("1. Offer the person some money\n");
            printf("2. Ignore the person and continue walking\n");
            
            int homeless;
            printf("Enter your choice (1 or 2): ");
            scanf("%d", &homeless);
            
            if (homeless == 1) {
                printf("You offer the person some money.\n");
                printf("As you walk away, you feel good about the good deed you just did.\n");
            }
            else {
                printf("You decide to ignore the person and continue walking.\n");
                printf("As you walk further, you see a sign advertising a concert of your favorite band.\n");
                printf("What would you like to do?\n");
                printf("1. Buy a ticket to the concert\n");
                printf("2. Keep walking\n");
                
                int concert;
                printf("Enter your choice (1 or 2): ");
                scanf("%d", &concert);
                
                if (concert == 1) {
                    printf("You buy a ticket to the concert and have an amazing time.\n");
                    printf("As you head back to your hotel for the night, you reflect on the fun adventures of the day.\n");
                }
                else {
                    printf("You decide to keep walking and explore more of the city.\n");
                    printf("As you walk further, you get lost and have to ask for directions to your hotel.\n");
                    printf("After finding your way back, you decide to rest for the night.\n");
                }
            }
        }
        
    }
    
    // Option 2: Go backpacking in the mountains
    else {
        printf("Congratulations on choosing to go backpacking in the mountains!\n");
        printf("As you are hiking, you come across a fork in the trail.\n");
        printf("Which path would you like to take?\n");
        printf("1. The path that leads upwards to a summit\n");
        printf("2. The path that leads downwards to a valley\n");
        
        int fork;
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &fork);
        
        if (fork == 1) {
            printf("You take the path that leads upwards to a summit.\n");
            printf("As you reach the top, you notice a bird trapped in a trap.\n");
            printf("What would you like to do?\n");
            printf("1. Free the bird\n");
            printf("2. Leave the bird there and continue walking\n");
            
            int bird;
            printf("Enter your choice (1 or 2): ");
            scanf("%d", &bird);
            
            if (bird == 1) {
                printf("You free the bird and it flies away.\n");
                printf("As you continue walking, you witness a majestic flock of migrating birds.\n");
                printf("The sight takes your breath away and you feel a sense of wonder and awe.\n");
            }
            else {
                printf("You decide to leave the bird there and continue walking.\n");
                printf("As you walk further, you come across a bear trap.\n");
                printf("What would you like to do?\n");
                printf("1. Disassemble the trap\n");
                printf("2. Leave the trap there and continue walking\n");
                
                int bear;
                printf("Enter your choice (1 or 2): ");
                scanf("%d", &bear);
                
                if (bear == 1) {
                    printf("You disassemble the trap and continue walking.\n");
                    printf("As you reach the end of the trail, you feel a sense of accomplishment.\n");
                }
                else {
                    printf("You decide to leave the trap there and continue walking.\n");
                    printf("As you walk further, you come across a beautiful stream.\n");
                    printf("You sit down to take a break and enjoy the beauty of nature around you.\n");
                }
            }
        }
        
        else {
            printf("You take the path that leads downwards to a valley.\n");
            printf("As you reach the bottom, you notice a lost hiker who seems disoriented.\n");
            printf("What would you like to do?\n");
            printf("1. Offer the hiker some water and help\n");
            printf("2. Ignore the hiker and continue walking\n");
            
            int hiker;
            printf("Enter your choice (1 or 2): ");
            scanf("%d", &hiker);
            
            if (hiker == 1) {
                printf("You offer the hiker some water and help them find their way back.\n");
                printf("As you walk back up the trail with the hiker, you notice a beautiful waterfall.\n");
                printf("You take a break to enjoy the view and take in the beauty of nature around you.\n");
            }
            else {
                printf("You decide to ignore the hiker and continue walking.\n");
                printf("As you walk further, you get lost and have a hard time finding your way back.\n");
                printf("After walking for hours, you come across a ranger station and ask for directions back.\n");
            }
        }
    }
    
    // Conclusion
    printf("Congratulations on completing the real-life adventure game!\n");
    printf("Whether you chose to travel to a new city or go backpacking in the mountains, you were able to experience new adventures and appreciate the beauty of the world around you.\n");
    
    return 0;
}