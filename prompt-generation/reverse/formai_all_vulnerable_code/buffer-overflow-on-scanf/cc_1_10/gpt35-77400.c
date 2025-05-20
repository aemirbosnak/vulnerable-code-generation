//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char name[30];
    int choice1, choice2, choice3;
    int score = 0;
    
    printf("Enter your name: ");
    scanf("%s", name);
    printf("\nWelcome, %s. Shall we begin?\n\n", name);
    
    printf("You are Romeo, a young Montague, deeply in love with the beautiful Juliet Capulet.\n");
    printf("However, your families have been sworn enemies for generations and your love is forbidden.\n");
    printf("Will you risk everything to be with her?\n\n");
    
    printf("1. Yes, I will do anything for Juliet.\n");
    printf("2. No, our families' feud has gone on long enough.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice1);
    
    if(choice1 == 1) {
        printf("\nYou sneak into the Capulet's garden to see your beloved Juliet. She is standing on her balcony,\n");
        printf("bathed in moonlight. But suddenly, you hear the sound of guards approaching.\n");
        printf("What will you do?\n\n");
        
        printf("1. Confront the guards and fight for your love.\n");
        printf("2. Flee the garden and meet Juliet another day.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice2);
        
        if(choice2 == 1) {
            printf("\nYou draw your sword and engage the guards in battle. It is a fierce fight, but you emerge victorious.\n");
            printf("However, the commotion has caught the attention of the rest of the household. You must escape before you are caught.\n\n");
            
            printf("1. Make a run for it, risking everything.\n");
            printf("2. Hide and wait for another opportunity.\n");
            printf("Enter your choice: ");
            scanf("%d", &choice3);
            
            if(choice3 == 1) {
                printf("\nYou make a daring escape through the Capulet's orchard, running as fast as you can.\n");
                printf("Finally, you reach safety, but you know that you cannot keep avoiding the feud forever.\n\n");
                
                printf("1. Seek out a peaceful resolution to the feud.\n");
                printf("2. Continue seeing Juliet in secret, risking everything for love.\n");
                printf("Enter your choice: ");
                scanf("%d", &choice3);
                
                if(choice3 == 1) {
                    printf("\nYou work tirelessly to bring your families together and put an end to the feud.\n");
                    printf("It is a difficult process, but eventually, you are successful. Your families come together in peace,\n");
                    printf("and you and Juliet are finally free to be together without fear or shame.\n");
                    score += 100;
                }
                else {
                    printf("\nDespite the risks, your love for Juliet is too strong to ignore.\n");
                    printf("You continue to see her in secret, living life on the edge of danger every day.\n");
                    printf("But ultimately, the risks prove too great, and tragedy strikes. You and Juliet both lose your lives.\n");
                    score -= 50;
                }
            }
            else {
                printf("\nYou hide in the shadows and wait for your chance to strike.\n");
                printf("Hours pass, and finally, the coast is clear. You sneak out of the garden and make your way back to safety.\n");
                printf("But as you return home, you know that you cannot keep risking everything for love forever.\n\n");
                
                printf("1. Seek out a peaceful resolution to the feud.\n");
                printf("2. Continue seeing Juliet in secret, risking everything for love.\n");
                printf("Enter your choice: ");
                scanf("%d", &choice3);
                
                if(choice3 == 1) {
                    printf("\nYou work tirelessly to bring your families together and put an end to the feud.\n");
                    printf("It is a difficult process, but eventually, you are successful. Your families come together in peace,\n");
                    printf("and you and Juliet are finally free to be together without fear or shame.\n");
                    score += 100;
                }
                else {
                    printf("\nDespite the risks, your love for Juliet is too strong to ignore.\n");
                    printf("You continue to see her in secret, living life on the edge of danger every day.\n");
                    printf("But ultimately, the risks prove too great, and tragedy strikes. You and Juliet both lose your lives.\n");
                    score -= 50;
                }
            }
        }
        else {
            printf("\nYou realize that it is too risky to confront the guards head-on. You make a hasty retreat,\n");
            printf("returning to the safety of your own home. But you know that you cannot keep avoiding the feud forever.\n\n");
            
            printf("1. Seek out a peaceful resolution to the feud.\n");
            printf("2. Continue seeing Juliet in secret, risking everything for love.\n");
            printf("Enter your choice: ");
            scanf("%d", &choice3);
            
            if(choice3 == 1) {
                printf("\nYou work tirelessly to bring your families together and put an end to the feud.\n");
                printf("It is a difficult process, but eventually, you are successful. Your families come together in peace,\n");
                printf("and you and Juliet are finally free to be together without fear or shame.\n");
                score += 100;
            }
            else {
                printf("\nDespite the risks, your love for Juliet is too strong to ignore.\n");
                printf("You continue to see her in secret, living life on the edge of danger every day.\n");
                printf("But ultimately, the risks prove too great, and tragedy strikes. You and Juliet both lose your lives.\n");
                score -= 50;
            }
        }
    }
    else {
        printf("\nYou know that your love for Juliet is strong, but the feud between your families is too great to overcome.\n");
        printf("You try to move on, but your heart is always with her. Eventually, you both realize that your love is worth the risk.\n\n");
        
        printf("1. Continue seeing each other in secret.\n");
        printf("2. Confront your families and fight for your love.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice2);
        
        if(choice2 == 1) {
            printf("\nYou and Juliet continue to see each other in secret, living life on the edge of danger every day.\n");
            printf("But ultimately, the risks prove too great, and tragedy strikes. You and Juliet both lose your lives.\n");
            score -= 50;
        }
        else {
            printf("\nYou and Juliet confront your families and plead for them to end the feud.\n");
            printf("At first, it seems like it will never work. But as you speak, your words begin to have an effect.\n");
            printf("Finally, your families agree to put an end to the feud and you and Juliet are free to be together without fear or shame.\n");
            score += 100;
        }
    }
    
    printf("\n\nThank you for playing, %s. Your final score is %d.\n", name, score);
    
    return 0;
}