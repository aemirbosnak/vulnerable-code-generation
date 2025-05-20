//FormAI DATASET v1.0 Category: Browser Plugin ; Style: funny
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Function to generate a random plugin name
char* generate_plugin_name() {
    char* plugin_names[] = {"ChattyMcChatface", "CatMeow", "ButterflyNet", "UnicornMagic", "RainbowSurf"};
    int length = sizeof(plugin_names) / sizeof(char*);
    int random_index = rand() % length;
    char* plugin_name = plugin_names[random_index];
    return plugin_name;
}

// Function to convert a string to uppercase
void string_to_uppercase(char* string) {
    int i = 0;
    while (string[i]) {
        string[i] = toupper(string[i]);
        i++;
    }
}

int main() {
    srand(time(NULL));

    // Generate a random plugin name
    char* plugin_name = generate_plugin_name();

    // Convert the plugin name to uppercase
    string_to_uppercase(plugin_name);

    // Print a welcome message
    printf("Welcome to the %s Browser Plugin!\n\n", plugin_name);

    // Prompt the user for their name
    printf("What's your name? ");
    char user_name[50];
    scanf("%s", user_name);
    printf("\n");

    // Generate a random age for the user
    int user_age = rand() % 100;

    // Determine if the user is old enough to use the plugin
    if (user_age < 18) {
        printf("Sorry %s, you're not old enough to use the %s Browser Plugin!\n", user_name, plugin_name);
        printf("Come back in %d years when you're old enough!\n", 18 - user_age);
    } else {
        printf("Congratulations %s, you're old enough to use the %s Browser Plugin!\n", user_name, plugin_name);

        // Prompt the user for their favorite website
        printf("\nWhat's your favorite website? ");
        char favorite_website[100];
        scanf("%s", favorite_website);

        // Print a message using the user's favorite website
        printf("\nWow, I love %s too! Did you know that the %s Browser Plugin works perfectly on %s?\n", favorite_website, plugin_name, favorite_website);

        // Generate a random number of exclamation points to add to the message
        int num_exclamation_points = rand() % 10 + 1;
        char exclamation_points[num_exclamation_points];
        memset(exclamation_points, '!', num_exclamation_points);

        // Print the final message
        printf("\n%s%s%s\n", plugin_name, exclamation_points, exclamation_points);
    }

    return 0;
}