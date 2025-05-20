//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main() {
    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Welcome %s to the world of Romeo and Juliet!\n\n", name);

    // Introduction
    printf("You are a young noble from the city of Verona, and you have fallen in love with a young woman from the rival city of Mantua.\n");
    printf("Her name is Juliet, and she is the daughter of Lord Capulet, the enemy of your own family, the Montagues.\n\n");
    
    // Opening Scene
    printf("It is a warm summer night, and you have decided to sneak into the Capulet's garden to see Juliet.\n");
    printf("As you approach the balcony, you see her there, looking as beautiful as ever.\n");
    printf("You call out to her softly, and she turns to greet you.\n\n");
    
    // Dialogue
    printf("Romeo: Juliet, my love, how I long to be with you!\n");
    printf("Juliet: Romeo, I feel the same way, but our families will never allow us to be together.\n");
    printf("Romeo: I know, but I am willing to risk everything for your love.\n\n");

    // Game Choices
    int choice;
    printf("What do you want to do?\n");
    printf("1. Declare your love for Juliet openly and leave with her\n");
    printf("2. Keep your love a secret and meet Juliet in secret\n");
    printf("3. Conspire with friends to fake your own death and elope with Juliet later\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("\nYou declare your love openly, but Lord Capulet catches you and orders his guards to arrest you.\n");
            printf("Sadly, your love story ends abruptly.\n");
            break;
        case 2:
            printf("\nYou keep your love a secret and continue to meet with Juliet in secret.\n");
            printf("However, one day, Lord Capulet discovers your secret and forbids Juliet from seeing you again.\n");
            printf("Your heart is broken, and you vow to find a way to be with Juliet no matter what it takes.\n");
            break;
        case 3:
            printf("\nYou conspire with your friends to fake your own death and elope with Juliet later.\n");
            printf("With your friends' help, you successfully stage your own death, and Juliet thinks you are dead.\n");
            printf("However, when she finds out the truth, she is heartbroken and decides to take her own life.\n");
            printf("You arrive in time to find her lifeless body, and your heart is shattered into a million pieces.\n");
            break;
        default:
            printf("\nInvalid choice!\n");
            break;
    }
    
    // Conclusion
    printf("\nSadly, your love story ends in tragedy, but your love for Juliet will always burn bright in your heart.\n");
    printf("Thank you for playing Romeo and Juliet style text-based adventure game!\n");
    
    return 0;
}