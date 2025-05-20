//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_YEARS 9999
#define MIN_YEARS 0

void introduce_time_machine();
int get_year_from_user();
void travel_to_year(int year);
void meet_famous_person(int year);
void time_trip_fail(int year);
void make_snack();
void randomly_generated_event();

int main() {
    int user_year;

    introduce_time_machine();

    while (1) {
        user_year = get_year_from_user();

        if (user_year < MIN_YEARS || user_year > MAX_YEARS) {
            printf("Oops! I wouldn't want you to risk going to the age of dinosaurs or beyond the current year.\n");
            continue;
        }

        travel_to_year(user_year);
        
        // Check if it lands on a significant year to meet a famous person or experience something strange.
        if (user_year == 1969) {
            meet_famous_person(user_year);
        } else if (user_year % 42 == 0) {
            printf("You are lucky! You just might stumble upon a random event!\n");
            randomly_generated_event();
        } else {
            time_trip_fail(user_year);
        }

        printf("Would you like to time travel again? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            printf("Wise choice! Let's keep the past in the past and the future as a mystery for now!\n");
            break;
        }
    }
    return 0;
}

void introduce_time_machine() {
    printf("Hello Time Traveler! Welcome to the Fuzzy-Wuzzy Time Machine!\n");
    printf("All systems operational. Just don't forget to bring snacks!\n");
}

int get_year_from_user() {
    int year;
    printf("Please enter the year you want to travel to (0-9999): ");
    scanf("%d", &year);
    return year;
}

void travel_to_year(int year) {
    printf("Initiating time travel to the year %d...\n", year);
    printf("*Wooooossshhh* You have arrived in %d!\n", year);
}

void meet_famous_person(int year) {
    printf("Wow! It's %d! You're about to meet Neil Armstrong on the moon!\n", year);
    printf("He gives you a cheese sandwich and says, 'One small bite for man, one giant sandwich for mankind.'\n");
}

void time_trip_fail(int year) {
    printf("Oops! You traveled to %d... Oh no, the computers didn't exist yet, and it's asking for... rocks?\n", year);
    make_snack(); // Let's make a snack instead!
}

void make_snack() {
    printf("While you're stuck here, let's whip up a quick snack: \n");
    printf("Get some ancient grain and sprinkle it with... uh, a hint of salt?\n");
    printf("Enjoy your prehistoric hummus!\n");
}

void randomly_generated_event() {
    printf("A portal opens, and you see... a dancing T-Rex in a tutu!\n");
    printf("It seems this era loves a good dance-off, will you join it?\n");
    printf("Bite-sized dinosaurs munch on popcorn in the background, cheering you on!\n");
}