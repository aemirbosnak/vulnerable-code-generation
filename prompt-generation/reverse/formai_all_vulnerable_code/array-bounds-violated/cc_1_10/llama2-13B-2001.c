//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NAME_LENGTH 20
#define MAX_ROMANCE_LENGTH 100

// Global variables
const char* names[5] = {"Cinderella", "Sleeping Beauty", "Snow White", "Beauty", "Bella"};
const char* romance_messages[5][5] = {
    {"You are my Prince Charming", "I love you more than words can say", "Forever and always", "You are my true love", "I will never let you go"},
    {"You are my dream come true", "I can't imagine life without you", "You are my everything", "You are my soulmate", "I will love you until the end of time"},
    {"You are my happily ever after", "You make my heart skip a beat", "I am lost in your eyes", "You are my forever love", "I will cherish you forever"},
    {"You are my fairy tale come true", "I am swept off my feet by you", "You are my perfect match", "You are my dream come true", "I will love you until the end of time"},
    {"You are my everything and more", "I am so lucky to have you", "You are my forever love", "You are my happily ever after", "I will love you until the end of time"}
};

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    char romance[MAX_ROMANCE_LENGTH];

    // Print a menu to choose a name and a romance message
    printf("Welcome to the Romantic Arithmetic Program!\n");
    printf("Please choose a name: ");
    scanf("%19s", name);
    printf("Please choose a romance message: ");
    scanf("%99s", romance);

    // Check if the input is valid
    if (name[0] == '\0' || romance[0] == '\0') {
        printf("Invalid input. Please try again.\n");
        return 1;
    }

    // Print the chosen name and romance message
    printf("Hello, %s! Here is your romantic message: %s\n", name, romance);

    // Print a list of all possible combinations
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d. %s %s\n", i * 5 + j, names[i], romance_messages[i][j]);
        }
    }

    // Ask the user to choose a combination
    printf("Please choose a combination by typing the number of the combination you want (1-25): ");
    scanf("%d", &choice);

    // Print the chosen combination
    printf("You chose combination %d: %s %s\n", choice, names[choice / 5], romance_messages[choice % 5]);

    return 0;
}