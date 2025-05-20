//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: romantic
#include <stdio.h>

int main()
{
    char name[20];
    int age;
    printf("Welcome to The Romantic Adventure Game!\n");
    printf("What is your name?\n");
    scanf("%s", name);
    printf("Hello %s! How old are you?\n", name);
    scanf("%d", &age);
    printf("Great, let's begin!\n\n");

    printf("You find yourself in a beautiful garden, surrounded by flowers and trees.\n");
    printf("As you walk along the path, you come across a fountain with a note beside it.\n");
    printf("Do you read the note? (1 = Yes, 2 = No)\n");
    int choice1;
    scanf("%d", &choice1);

    if(choice1 == 1){
        printf("\nThe note reads: 'Meet me under the oak tree at midnight, my love.'\n");
        printf("Do you go to the oak tree at midnight? (1 = Yes, 2 = No)\n");
        int choice2;
        scanf("%d", &choice2);
        if(choice2 == 1){
            printf("\nAs you wait under the oak tree, a figure approaches you from the shadows.\n");
            printf("It's the love of your life, and they have a special surprise for you.\n");
            printf("They get down on one knee and ask: 'Will you marry me?' (1 = Yes, 2 = No)\n");
            int choice3;
            scanf("%d", &choice3);
            if(choice3 == 1){
                printf("\nYou joyfully say yes, and your love stands up and embraces you tightly.\n");
                printf("Together, you walk off into the night, hand in hand, filled with love and happiness.\n");
            } else if(choice3 == 2){
                printf("\nYour love looks disappointed, but they understand.\n");
                printf("They give you a warm kiss goodbye and leave, hoping that someday you'll change your mind.\n");
            } else {
                printf("\nInvalid input. Program will now exit.\n");
            }

        } else if(choice2 == 2){
            printf("\nYou decide not to go to the oak tree, and instead continue on your own journey.\n");
            printf("May you someday find the love that you seek. Until then, enjoy the adventure!\n");
        } else {
            printf("\nInvalid input. Program will now exit.\n");
        }

    } else if(choice1 == 2){
        printf("\nYou ignore the note and continue on your journey.\n");
        printf("May you someday find the love that you seek. Until then, enjoy the adventure!\n");
    } else {
        printf("\nInvalid input. Program will now exit.\n");
    }

    printf("\nThank you for playing The Romantic Adventure Game, %s. Goodbye!\n", name);

    return 0;
}