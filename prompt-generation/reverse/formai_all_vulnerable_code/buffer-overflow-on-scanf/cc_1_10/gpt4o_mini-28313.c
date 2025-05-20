//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_welcome_message() {
    printf("*******************************\n");
    printf("* Welcome to the Mystic Realm! *\n");
    printf("* Your personal Automated      *\n");
    printf("* Fortune Teller awaits!       *\n");
    printf("*******************************\n");
    printf("\nPrepare yourself for a glimpse into the future...\n");
}

void show_fortune(int fortune_number) {
    switch(fortune_number) {
        case 1:
            printf("Fortune: You will embark on a journey that will change your life..\n");
            break;
        case 2:
            printf("Fortune: A surprise invitation will unlock new opportunities...\n");
            break;
        case 3:
            printf("Fortune: Trust your instincts; they will lead you to success...\n");
            break;
        case 4:
            printf("Fortune: Don't be afraid to take risks; fortune favors the brave...\n");
            break;
        case 5:
            printf("Fortune: A chance meeting will spark an unexpected romance...\n");
            break;
        case 6:
            printf("Fortune: Your hard work will soon pay off in ways you can't imagine...\n");
            break;
        case 7:
            printf("Fortune: The stars are aligning in your favor, be ready...\n");
            break;
        case 8:
            printf("Fortune: New friendships will bloom; cherish these connections...\n");
            break;
        case 9:
            printf("Fortune: A problem from the past will resolve itself unexpectedly...\n");
            break;
        case 10:
            printf("Fortune: A hidden talent will surface; embrace it...\n");
            break;
        default:
            printf("Fortune: The universe is full of mysteries yet to be unveiled...\n");
            break;
    }
}

int get_user_choice() {
    int choice;
    printf("You'll now choose a number between 1 and 10 to reveal your fortune: ");
    scanf("%d", &choice);
    return choice;
}

int generate_random_fortune_number() {
    return rand() % 10 + 1; // Random number between 1 and 10
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    display_welcome_message();

    char continue_fortune;
    do {
        int fortune_number = generate_random_fortune_number();
        int user_choice = get_user_choice();

        printf("\nYour chosen number: %d\n", user_choice);
        printf("Generated fortune number: %d\n", fortune_number);

        show_fortune(user_choice);
        printf("\nDo you wish to unveil more of the universe's secrets? (y/n): ");
        scanf(" %c", &continue_fortune);
    } while(continue_fortune == 'y' || continue_fortune == 'Y');

    printf("Thank you for visiting the Mystic Realm. May the stars shine brightly upon your path!\n");
    
    return 0;
}