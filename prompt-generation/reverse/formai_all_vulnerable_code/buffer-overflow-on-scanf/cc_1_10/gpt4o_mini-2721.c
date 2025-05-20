//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mystic_line(const char *line) {
    printf("\n~~ %s ~~\n", line);
}

void spin_wheel() {
    printf("Spinning the wheel of fate...\n");
    // Simulate a short delay
    for(int i = 0; i < 3; i++) {
        printf(". ");
        fflush(stdout);
        for (volatile int j = 0; j < 100000000; j++); // NOP for crude delay
    }
    printf("\nTransformation process complete.\n\n");
}

const char* fetch_fortune(int index) {
    const char *fortunes[] = {
        "You shall find great wealth in unexpected places.",
        "A journey of a thousand miles will begin with a single step.",
        "Your future is as bright as the stars above.",
        "The winds of change are blowing your way.",
        "Love is just around the corner; keep your eyes open.",
        "A shadow in the night will reveal your true desires.",
        "Patience is the key to unlocking your greatest treasure.",
        "An old friend will soon re-enter your life.",
        "Trust your instincts; they will guide you to success.",
        "A surprise awaits you in the next coming week."
    };
    return fortunes[index];
}

int main() {
    int choice;
    srand(time(NULL)); // Seed for randomness
    mystic_line("Welcome to the Cryptic Oracle");
    mystic_line("Let the mysteries unfold...");

    printf("Please, choose a number between 1 and 10 to unveil your fortune: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 10) {
        mystic_line("Beware! The fates are not pleased with your choice.");
    } else {
        spin_wheel(); // Spin the fortune wheel
        int fortune_index = rand() % 10; // Random index for fortunes
        const char *fortune = fetch_fortune(fortune_index);
        mystic_line(fortune);
    }

    mystic_line("The session is complete. May the stars guide your path.");
    return 0;
}