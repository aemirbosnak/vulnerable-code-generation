//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 12

const char *fortunes[MAX_FORTUNES] = {
    "You will find great success in your future endeavors.",
    "A thrilling time is in your near future.",
    "You will discover an unexpected treasure.",
    "A friend will bring you good news soon.",
    "Expect an exciting change in your life soon.",
    "You will overcome a challenge that has been troubling you.",
    "Someone you admire will compliment you.",
    "Travel is on the horizon for you.",
    "Your dreams will soon manifest into reality.",
    "You will meet someone influential who will change your life.",
    "A great opportunity will present itself to you.",
    "Believe in yourself and great things will happen."
};

void print_greeting() {
    printf("Welcome to the Decentralized Fortune Teller!\n");
    printf("Let's unveil your future... \n");
}

int get_random_index(int max) {
    return rand() % max;
}

void display_fortune(const char *fortune) {
    printf("Your fortune: %s\n", fortune);
}

void record_fortune(const char *fortune) {
    FILE *file = fopen("fortunes.log", "a");
    if (file != NULL) {
        fprintf(file, "Fortune: %s\n", fortune);
        fclose(file);
    } else {
        printf("Error logging fortune. Please check your permissions.\n");
    }
}

void ask_for_another() {
    char response;
    printf("Would you like another fortune? (y/n): ");
    scanf(" %c", &response);
    
    if (response == 'y' || response == 'Y') {
        int random_index = get_random_index(MAX_FORTUNES);
        display_fortune(fortunes[random_index]);
        record_fortune(fortunes[random_index]);
        ask_for_another();
    } else {
        printf("Thank you for using the Decentralized Fortune Teller. Goodbye!\n");
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    print_greeting();

    int random_index = get_random_index(MAX_FORTUNES);
    display_fortune(fortunes[random_index]);
    record_fortune(fortunes[random_index]);

    ask_for_another();

    return 0;
}