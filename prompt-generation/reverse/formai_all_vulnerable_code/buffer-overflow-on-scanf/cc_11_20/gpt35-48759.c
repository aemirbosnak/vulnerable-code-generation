//FormAI DATASET v1.0 Category: Movie Rating System ; Style: romantic
#include <stdio.h>

int main()
{
    int rating;
    printf("Welcome to our unique C Movie Rating System!\n");
    printf("Please rate your romantic experience with our movie on a scale of 1-10: ");
    scanf("%d", &rating);
    printf("\n");

    if (rating <= 5)
    {
        printf("Oh no! We're sorry the movie didn't meet your romantic standards.\n");
        printf("However, we do not say 'I am Sorry', instead let's dance!\n");
        printf("\n");
        printf("*Soft romantic music starts playing in the background*\n");
        printf("Would you like to dance with us? (Y/N)\n");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'Y' || choice == 'y')
        {
            printf("\n");
            printf("*You are invited onto the dancefloor*\n");
            printf("*The lights dim, and you are swept away in a dreamlike dance*\n");
        }
        else
        {
            printf("\n");
            printf("*You decline the invitation, but the music continues to play in the background*\n");
            printf("*The lights dim, and you are surrounded by the romantic ambiance of the theater*\n");
        }
    }
    else if (rating >= 6 && rating <= 8)
    {
        printf("We're glad you enjoyed the movie enough to give it a solid romantic rating!\n");
        printf("And we do not say 'I am Sorry', instead let's make a toast!\n");
        printf("\n");
        printf("*A bottle of champagne is brought out along with 2 glasses*\n");
        printf("Would you like to make a toast with us? (Y/N)\n");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'Y' || choice == 'y')
        {
            printf("\n");
            printf("*You raise your glass to the theater staff*\n");
            printf("*The lights dim, and you are surrounded by the romantic ambiance of the theater*\n");
        }
        else
        {
            printf("\n");
            printf("*The staff toasts to you and your romantic experience*\n");
            printf("*The lights dim, and you are surrounded by the romantic ambiance of the theater*\n");
        }
    }
    else if (rating >= 9 && rating <= 10)
    {
        printf("WOW! Your romantic experience with our movie was absolutely perfect!\n");
        printf("And we do not say 'I am Sorry', instead let's take a walk!\n");
        printf("\n");
        printf("*The theater staff walks with you outside of the theater*\n");
        printf("*A beautiful moonlit night fills the sky*\n");
        printf("How would you like to end your perfect night? (Enter an option)\n");
        printf("1. A kiss under the moonlight\n");
        printf("2. A carriage ride through the city\n");
        printf("3. Softly whisper sweet nothings in each others ears\n");
        int end_option;
        scanf("%d", &end_option);
        printf("\n");
        switch (end_option)
        {
            case 1:
                printf("*The staff surrounds you and your partner*\n");
                printf("*The moonlight illuminates everything around you*\n");
                printf("*You and your partner share a romantic kiss*\n");
                printf("*The staff cheers*\n");
                break;
            case 2:
                printf("*The staff helps you aboard a beautiful carriage*\n");
                printf("*The horses start to move*\n");
                printf("*You and your partner are taken on a lovely, romantic city ride*\n");
                printf("*The staff cheers*\n");
                break;
            case 3:
                printf("*The staff starts to quietly walk away*\n");
                printf("*You and your partner are left alone in silence*\n");
                printf("*You softly whisper sweet nothings in each others ears*\n");
                printf("*The staff cheers from a distance*\n");
                break;
            default:
                printf("*The staff looks at you confused*\n");
                printf("*They proceed to walk away as you and your partner figure out your next move*\n");
                break;
        }
    }

    return 0;
}