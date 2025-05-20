//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void make_invisible(int *ptr) {
    // Function to make the pointer buddy disappear
    printf("Now you see it, now you don’t!\n");
    free(ptr);
}

void reveal_memory(int *ptr) {
    // Function to reveal what was stored before
    printf("You lost your memory buddy! But lets see what we stored:\n");
    printf("Memory buddies value: %d\n", *ptr);
    free(ptr);
}

void vanishing_trick(int size) {
    // Allocating memory with a bit of a magic twist
    int *magic_buddy = (int *)malloc(size * sizeof(int));
    if (magic_buddy == NULL) {
        printf("Oops! Magic went wrong, no memory left! 🎩\n");
        exit(1);
    } else {
        printf("Ta-da! I conjured up %d magical numbers!\n", size);
    }

    for (int i = 0; i < size; i++) {
        magic_buddy[i] = rand() % 100; // Filling our array with random numbers
        printf("Magic Buddy %d: %d \n", i + 1, magic_buddy[i]);
    }

    // Randomly choose to make buddy invisible or reveal
    if (rand() % 2) {
        make_invisible(magic_buddy);
    } else {
        reveal_memory(magic_buddy);
    }
}

int main() {
    printf("Welcome to the Magical Memory Management Show! 🎉\n");
    srand(time(0)); // Seed for randomness

    int buddy_count;

    printf("How many memory buddies do you want to create? (1-10): ");
    scanf("%d", &buddy_count);

    if(buddy_count < 1 || buddy_count > 10) {
        printf("You don't want too many buddies, trust me! Let’s keep it sensible.\n");
        buddy_count = 5;  // Default to 5 if user goes wild
    }

    while(buddy_count--) {
        printf("\nCreating your magical memory buddy...\n");
        vanishing_trick(1);
    }

    printf("All magic done! Thanks for coming to the show! 🎩\n");
    return 0;
}