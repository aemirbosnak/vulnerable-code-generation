//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 10
#define MAX_PROMPTS 5

const char *fortunes[MAX_FORTUNES] = {
    "You will find great success in your endeavors.",
    "A thrilling time is in your immediate future.",
    "Your abilities are being tested, and you will prevail.",
    "Someone close to you is in need of your support.",
    "You will soon receive unexpected good news.",
    "A new opportunity will reveal itself within the week.",
    "Have confidence in your ideas; they are valuable.",
    "You will obtain much joy from a small gesture.",
    "A great change is coming; embrace it.",
    "Your creativity is your greatest asset."
};

const char *prompts[MAX_PROMPTS] = {
    "Think of a question about your future.",
    "What is on your mind that needs guidance?",
    "Reflect on your recent decisions. Ready for advice?",
    "Consider your aspirations and dreams.",
    "Are you ready to unveil your destiny?"
};

void display_prompt();
void tell_fortune();
void display_shape_shifter(int step);
char* get_random_fortune();

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    // Shape-shifting welcome
    for (int i = 0; i < 5; i++) {
        display_shape_shifter(i);
        sleep(1); // Delay for effect
    }
    
    // User interaction
    while (1) {
        display_prompt();
        tell_fortune();
        
        char choice;
        printf("\nWould you like to ask another question? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    printf("Thank you for visiting the fortune teller. Goodbye!\n");

    return 0;
}

void display_prompt() {
    int random_index = rand() % MAX_PROMPTS;
    printf("\n%s\n", prompts[random_index]);
}

void tell_fortune() {
    char *fortune = get_random_fortune();
    printf("Your fortune: %s\n", fortune);
}

char* get_random_fortune() {
    int random_index = rand() % MAX_FORTUNES;
    return (char *)fortunes[random_index];
}

void display_shape_shifter(int step) {
    const char *shapes[] = {
        "  *  ",
        " /|\\ ",
        "/_|_\\",
        "  |  ",
        " / \\ ",
        "  -  ",
        "  o  ",
        "\\ | /",
        "  |  " 
    };

    printf("\r%s", shapes[step % (sizeof(shapes) / sizeof(shapes[0]))]);
    fflush(stdout);  // Forcing output to be printed immediately
}