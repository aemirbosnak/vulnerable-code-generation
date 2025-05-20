//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100
#define MAX_FORTUNE_LENGTH 80

typedef struct {
    char text[MAX_FORTUNE_LENGTH];
    int length;
} fortune;

fortune fortunes[MAX_FORTUNES] = {
    { "You will meet a tall, dark stranger. ", 35 },
    { "A financial opportunity is coming your way. ", 47 },
    { "Beware of a friend who is not what they seem. ", 60 },
    { "Travel is in your future, but be cautious. ", 43 },
    { "Your hard work will soon pay off. ", 31 },
    { "A new romance is on the horizon. ", 39 },
    { "A long-lost relative will contact you. ", 45 },
    { "Good health and prosperity are in your future. ", 53 },
    { "A change of residence is imminent. ", 42 },
    { "A secret will be revealed to you. ", 37 }
};

void generate_random_number(int *random_number) {
    *random_number = rand() % 100;
}

int get_random_fortune() {
    return rand() % MAX_FORTUNES;
}

void print_fortune(fortune fortune) {
    printf("%s\n", fortune.text);
}

int main() {
    srand(time(NULL));

    int choice;
    printf("Welcome to Sherlock's Automated Fortune Teller!\n");
    printf("Please choose an option:\n");
    printf("1. Get a random fortune\n");
    printf("2. Exit\n");
    scanf("%d", &choice);

    if (choice == 1) {
        int random_fortune = get_random_fortune();
        fortune fortune = fortunes[random_fortune];
        print_fortune(fortune);
    } else if (choice == 2) {
        printf("Thank you for using Sherlock's Automated Fortune Teller!\n");
    } else {
        printf("Invalid choice. Please try again.\n");
    }

    return 0;
}