//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_ADJECTIVE_LEN 20
#define MAX_LOCATION_LEN 30
#define BUFFER_SIZE 128

void clearInputBuffer() {
    while (getchar() != '\n') {}
}

void createAdventure(const char *name, const char *adjective, const char *location) {
    printf("\n🎉✨ Welcome to the Adventure of Brave %s! ✨🎉\n\n", name);
    printf("One fine day, %s was feeling very %s.\n", name, adjective);
    printf("They decided to embark on a journey to the faraway land of %s!\n", location);
    printf("Armed with nothing but courage and a backpack full of snacks, %s ventured forth!\n\n", name);
    
    printf("On the way to %s, they met a wise fox.\n", location);
    printf("The fox said: 'Hello, %s! If you want to proceed, you must answer my riddle!'\n", name);
    
    printf("The fox posed a riddle: 'I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I?'\n");
    printf("1. An Echo\n2. A Shadow\n3. A Wave\n\n");
    
    int choice;
    printf("Choose the correct answer (1-3): ");
    scanf("%d", &choice);
    
    clearInputBuffer(); // Clear the input buffer for any extra characters.

    if (choice == 1) {
        printf("\n💡 Correct! The fox smiled and said: 'You are indeed wise, brave %s! Carry on!'\n", name);
        printf("With renewed spirit, %s continued towards %s!\n", name, location);
    } else {
        printf("\n❌ Wrong answer! The fox frowned but kindly said: 'Don't worry, every great adventurer makes mistakes!'\n");
        printf("However, the fox decided to guide %s to the nearest village instead!\n", name);
    }
    
    printf("\nAfter a long and exciting day, %s finally reached %s.\n", name, location);
    printf("They were greeted with a grand feast and laughter.\n");
    printf("%s realized that the journey and the friends made along the way were more important than the destination itself.\n", name);
    printf("And so, from that day on, %s shared their story with everyone they met, inspiring them to embark on their own adventures!\n", name);
    printf("\n✨ The End! ✨\n");
}

int main() {
    char name[MAX_NAME_LEN];
    char adjective[MAX_ADJECTIVE_LEN];
    char location[MAX_LOCATION_LEN];

    printf("🌟 Welcome to the Whimsical Adventure Creator! 🌟\n");
    
    printf("What's your name, brave adventurer? ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;  // Remove the newline character from the input
    
    printf("Describe how you feel today with one word (an adjective): ");
    fgets(adjective, sizeof(adjective), stdin);
    adjective[strcspn(adjective, "\n")] = 0;  // Remove the newline character from the input
    
    printf("Choose a fantastical location: ");
    fgets(location, sizeof(location), stdin);
    location[strcspn(location, "\n")] = 0;  // Remove the newline character from the input
    
    createAdventure(name, adjective, location);

    return 0;
}