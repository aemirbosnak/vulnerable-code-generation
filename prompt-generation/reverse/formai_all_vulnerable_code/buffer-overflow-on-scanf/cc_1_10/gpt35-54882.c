//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void delay(int miliseconds) {
    int microsecond = 1000;
    usleep(miliseconds * microsecond);
}

void print_slow(char *str) {
    int delay_time = 40;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        delay(delay_time);
        printf("%c", str[i]);
        fflush(stdout);
    }
}

void clear() {
    system("clear");
}

void print_header() {
    clear();
    printf("*************************************************************\n");
    printf("*                                                           *\n");
    printf("*            Welcome to the Peaceful Adventure Game!         *\n");
    printf("*                                                           *\n");
    printf("*************************************************************\n\n");
}

void print_menu() {
    printf("1. Go for a walk in the park\n");
    printf("2. Enjoy a cup of tea at cafe\n");
    printf("3. Read a book in the library\n");
    printf("4. Visit a farmer's market\n");
    printf("5. Exit the game\n");
}

void go_for_walk() {
    printf("\nYou take a stroll through a peaceful park.\n");
    printf("You stop to smell the flowers and enjoy the beauty of nature.\n");
    printf("As you walk, you feel your stress and worries melting away.\n\n");
}

void enjoy_cup_of_tea() {
    printf("\nYou sit down at a quaint little cafe and order a cup of tea.\n");
    printf("As you sip your tea, you savor the flavor and aroma.\n");
    printf("You feel yourself becoming more relaxed and content.\n\n");
}

void read_book() {
    printf("\nYou visit the library and pick out a book to read.\n");
    printf("As you read, you become lost in the story and forget about your troubles.\n");
    printf("You emerge from the book feeling refreshed and at peace.\n\n");
}

void visit_market() {
    printf("\nYou wander through a bustling farmer's market.\n");
    printf("You sample fresh fruits and vegetables and chat with friendly vendors.\n");
    printf("You leave with a bag full of healthy and delicious treats.\n\n");
}

int main() {
    int choice;

    print_header();

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                go_for_walk();
                break;
            case 2:
                enjoy_cup_of_tea();
                break;
            case 3:
                read_book();
                break;
            case 4:
                visit_market();
                break;
            case 5:
                printf("\nThank you for playing the Peaceful Adventure Game!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}