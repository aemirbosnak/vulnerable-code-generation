//FormAI DATASET v1.0 Category: Browser Plugin ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// our browser plugin that's going to be a pleasant surprise!
int surprise_plugin(void) {
    printf("SURPRISE! You just installed the coolest browser plugin ever!\n");
    printf("Now let's make your online experience even better!\n");
    int favorite_number;
    printf("What's your favorite number? ");
    scanf("%d", &favorite_number);
    printf("Awesome! Your favorite number is %d!\n", favorite_number);
    printf("Now, let's see what other surprises we have in store for you...\n");
    int random_number = rand() % 10 + 1;
    printf("Your random number surprise is...drumroll please...%d!\n", random_number);
    printf("Wow, this plugin really knows how to keep things exciting! Let's do it again!\n");
    random_number = rand() % 10 + 1;
    printf("Your next random number surprise is...%d! Woohoo!\n", random_number);
    printf("But wait, there's more! With this plugin, you get an infinite amount of surprises!\n");
    printf("The next surprise is an ASCII art drawing of your choosing...what do you want to see? ");
    char art_choice[10];
    scanf("%s", art_choice);
    if (strcmp(art_choice, "dog") == 0) {
        printf("  __\n");
        printf("o-''))_____\\ \n");
        printf(" \"\"      )  )\n");
        printf("        (_)(_)");
    } else if (strcmp(art_choice, "cat") == 0) {
        printf(" /\\_/\\   /\n");
        printf("( o   o )\n");
        printf(" (  =^=  )\n");
        printf("  (\")_(\")_");
    } else {
        printf("Sorry, we don't have that ASCII art option. Maybe try again later?\n");
    }
    printf("We hope you're loving our plugin so far, but we still have more in store for you!\n");
    printf("For our next surprise...we're going to sing a song!\n");
    printf("Ready? Here we go!\n\n");

    // sing a little song!
    printf("♫ Row, row, row your boat,\n");
    printf("♫ Gently down the stream.\n");
    printf("♫ Merrily, merrily, merrily, merrily,\n");
    printf("♫ Life is but a dream. ♫\n\n");

    // one last surprise!
    printf("Okay, it's time for our final surprise.\n");
    printf("You ready for this? It's a big one!\n");
    printf("Are you sure you're ready?\n");
    printf("Okay, here goes...\n\n");
    printf(".................................................................\n");
    printf(".............................................\n");
    printf(".................................................................\n");
    printf(".............................................\n");
    printf(".................................................................\n");
    printf(".............................................\n");
    printf(".................................................................\n");
    printf(".............................................\n");
    printf(".................................................................\n");
    printf(".............................................\n");
    printf(".................................................................\n");
    printf(".............................................\n");
    printf(".................................................................\n");
    printf(".............................................\n");
    printf(".................................................................\n");
    printf(".............................................\n");
    printf(".................................................................\n");
    printf(".............................................\n");
    printf(".................................................................\n");
    printf(".............................................\n");
    printf(".................................................................\n");
    printf(".............................................\n");
    printf(".................................................................\n");
    printf(".............................................\n");
    printf(".................................................................\n");
    printf(".............................................\n");
    printf(".................................................................\n");
    printf(".............................................\n");
    printf(".................................................................\n");
    printf(".............................................\n");
    printf(".................................................................\n");
    printf(".............................................\n");
    printf(".................................................................\n");
    printf(".............................................\n");
    printf(".................................................................\n");
    printf(".............................................\n");
    printf(".................................................................\n");
    printf(".............................................\n");
    printf(".................................................................\n");
    printf(".............................................\n");
    printf(".................................................................\n");
    printf(".............................................\n");
    printf(".................................................................\n");
    printf(".............................................\n");
    printf(".................................................................\n");
    printf(".............................................\n");
    printf(".................................................................\n");
    printf(".............................................\n");
    printf(".................................................................\n\n");

    printf("Congratulations, you reached the end of our surprises. Thanks for using our plugin!\n");

    return 0;
}

// main program
int main(void) {
    surprise_plugin();
    return 0;
}