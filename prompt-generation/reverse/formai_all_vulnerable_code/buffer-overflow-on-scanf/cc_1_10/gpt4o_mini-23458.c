//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 10

void print_greeting() {
    printf("--------------------------------------------------\n");
    printf("                Automated Fortune Teller          \n");
    printf("--------------------------------------------------\n");
    printf("Welcome! Ask a question and I'll tell you your fortune.\n");
    printf("--------------------------------------------------\n");
}

void print_fortune(int fortune_index) {
    const char* fortunes[NUM_FORTUNES] = {
        "You will encounter a pleasant surprise today.",
        "A thrilling adventure awaits you soon.",
        "Someone close will give you unexpected news.",
        "You will find joy in the small things.",
        "A long-lost friend will reconnect with you.",
        "You will achieve something you have long desired.",
        "Beware of the people you trust.",
        "You will discover a new passion.",
        "Expect to witness a significant change in your life.",
        "Fortune favors the bold; take that leap!"
    };
    printf("Your fortune: %s\n", fortunes[fortune_index]);
}

void ask_question() {
    char question[256];
    printf("Please enter your question: ");
    fgets(question, sizeof(question), stdin);
    printf("You asked: \"%s\"\n", question);
}

int get_random_fortune_index() {
    return rand() % NUM_FORTUNES;
}

void play_fortune_teller() {
    char choice;
    do {
        ask_question();
        int fortune_index = get_random_fortune_index();
        print_fortune(fortune_index);
        
        printf("Would you like to ask another question? (y/n): ");
        scanf(" %c", &choice);
        while(getchar() != '\n'); // Clear input buffer
    } while (choice == 'y' || choice == 'Y');
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    print_greeting();
    play_fortune_teller();
    printf("Thank you for using the Automated Fortune Teller!\n");
    printf("--------------------------------------------------\n");
    return 0;
}