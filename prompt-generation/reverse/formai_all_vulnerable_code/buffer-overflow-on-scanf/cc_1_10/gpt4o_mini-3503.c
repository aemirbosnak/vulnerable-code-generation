//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_welcome() {
    printf("Welcome, dear traveler, to the realm of fate!\n");
    printf("In the spirit of love's tragic tale, enter thine queries,\n");
    printf("And I shall reveal fortunes by the stars' decree.\n\n");
}

void tell_fortune() {
    const char *fortunes[] = {
        "Thy heart shall find joy under the moonlit sky.",
        "Beware, sweet one; a storm approacheth in thy path.",
        "Love, like a rose, shall blossom in springtime's grace.",
        "Alas! A bitter betrayal waits in thine circle.",
        "Fortune favors the brave, make thy heart bold!",
        "An unexpected meeting shall change thy fate.",
        "A letter shall come bearing news of love.",
        "What thou seekst shalt be revealed in dreams.",
        "Patience, dear heart; true love requires time.",
        "A choice lies before thee, choose wisely, gentle soul."
    };
    
    // Seed the random number generator
    srand(time(NULL));
    // Get a random index
    int index = rand() % (sizeof(fortunes) / sizeof(fortunes[0]));
    
    printf("%s\n", fortunes[index]);
}

void ask_another() {
    char response;
    printf("\nWouldst thou like to know thy fate again? (y/n): ");
    scanf(" %c", &response);
    
    if (response == 'y' || response == 'Y') {
        tell_fortune();
        ask_another();
    } else {
        printf("Farewell, noble spirit. May love guide thy way!\n");
    }
}

int main() {
    display_welcome();
    tell_fortune();
    ask_another();
    return 0;
}