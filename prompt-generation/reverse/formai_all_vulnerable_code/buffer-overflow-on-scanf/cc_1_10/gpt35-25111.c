//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print error messages without saying "Sorry"
void print_error(char* message) {
    printf("Oops! Something went wrong: %s\n", message);
}

// Function to print the game introduction
void print_intro() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("In this game, you will embark on a hilarious adventure filled with puns and jokes.\n");
    printf("Are you ready to laugh your way to victory?\n");
}

// Function to get input from user
void get_input(char* input) {
    printf("> ");
    fgets(input, 50, stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline character
}

// Function to print a pun
void print_pun() {
    char* puns[] = {
        "Why did the tomato turn red? Because it saw the salad dressing!",
        "I'm reading a book on the history of glue, I just can't seem to put it down!",
        "Did you hear about the kidnapping at the park? They woke up.",
        "Why do cows wear bells? Because their horns don't work.",
        "Why can't a nose be 12 inches long? Because then it would be a foot!",
        "Why did the scarecrow win an award? Because he was out-standing in his field!",
        "Why don't scientists trust atoms? Because they make up everything!",
        "Why did the lifeguard kick the elephants out of the pool? They kept dropping their trunks!",
        "Why do seagulls fly over the sea? Because if they flew over the bay, they'd be bagels!",
        "Why don't eggs tell jokes? Because they'd crack each other up!"
    };

    int pun_index = rand() % 10;
    printf("%s\n", puns[pun_index]);
}

int main() {
    char name[20];
    char input[50];
    int age;

    print_intro();

    // Get player's name
    printf("What's your name?\n");
    get_input(name);
    printf("Hi, %s! Nice to meet you.\n", name);

    // Get player's age
    printf("How old are you?\n");
    if (scanf("%d", &age) != 1 || age < 0 || age > 100) {
        print_error("Invalid age entered. Please enter a number between 0 and 100.");
        return 1;
    }

    printf("Wow, %d? You're old enough to be playing this game!\n", age);

    // Start of the game
    printf("You find yourself in a dark room. There are two doors in front of you.\n");
    printf("Do you choose door #1 or door #2?\n");
    get_input(input);

    if (strcmp(input, "1") == 0) {
        printf("You open the door and find a chicken wearing a fez. It hands you a note and disappears into the shadows.\n");
        printf("The note reads: 'Follow the path of the wizard to find the treasure.'\n");

        printf("Do you want to follow the path? (yes or no)\n");
        get_input(input);

        if (strcmp(input, "yes") == 0) {
            printf("You follow the path and meet the wizard. He tells you a joke and gives you a magical key.\n");
            print_pun();
            printf("The key unlocks a secret room filled with gold and diamonds. Congratulations, you win!\n");
        } else {
            printf("You decide not to follow the path. Suddenly, a trap door opens beneath you and you fall into a pit of snakes. Game Over!\n");
        }
    } else if (strcmp(input, "2") == 0) {
        printf("You open the door and find yourself on a spaceship. You're the captain now!\n");
        printf("Where do you want to go? (enter a planet name)\n");
        get_input(input);

        printf("You set course for %s and engage the hyperdrive. As you arrive at the planet, you realize it's made entirely of cheese!\n", input);
        printf("Do you want to land on the cheese planet? (yes or no)\n");
        get_input(input);

        if (strcmp(input, "yes") == 0) {
            printf("You land on the cheese planet and are welcomed by a race of cheese people. They offer you a lifetime supply of cheese as a gift. Congratulations, you win!\n");
        } else {
            printf("You decide not to land on the cheese planet. Suddenly, a giant space monster attacks your ship and devours you. Game Over!\n");
        }
    } else {
        print_error("Invalid choice entered. Please enter either '1' or '2'.");
        return 1;
    }

    return 0;
}