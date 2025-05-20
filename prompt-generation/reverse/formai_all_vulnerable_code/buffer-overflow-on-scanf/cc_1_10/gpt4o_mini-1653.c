//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// A scroll of towers for color representation
struct Color {
    char name[50];
    int red;
    int green;
    int blue;
};

// A magic scroll of colors
struct Color colorPalette[] = {
    {"Crimson Red", 255, 0, 0},
    {"Emerald Green", 0, 255, 0},
    {"Royal Blue", 0, 0, 255},
    {"Golden Yellow", 255, 255, 0},
    {"Purplish Lavender", 128, 0, 128},
    {"Cyan Sea", 0, 255, 255},
    {"Sandy Brown", 139, 69, 19}
};

// The tome of functions to enchant the user input
void printColor(struct Color color) {
    printf("Behold! The mighty color: %s\n", color.name);
    printf("Its RGB incantation is: (%d, %d, %d)\n", color.red, color.green, color.blue);
}

void convertToHex(struct Color color) {
    printf("The hex representation of %s is: #%02X%02X%02X\n", color.name, color.red, color.green, color.blue);
}

void invokeColorConversion(int choice) {
    if (choice < 0 || choice >= sizeof(colorPalette) / sizeof(colorPalette[0])) {
        printf("Alas! Such a color does not belong in our kingdom!\n");
        return;
    }
    
    // Summon the chosen color from the enchanted palette
    struct Color chosenColor = colorPalette[choice];
    printColor(chosenColor);
    convertToHex(chosenColor);
}

int main() {
    int choice;
    
    printf("Welcome to the Realm of Colors!\n");
    printf("Here you may choose a color from our cherished palette:\n");
    
    // Presentation of the enchanted colors
    for (int i = 0; i < sizeof(colorPalette) / sizeof(colorPalette[0]); i++) {
        printf("%d. %s\n", i, colorPalette[i].name);
    }
    
    // The query of choice
    printf("Please select the number of your desired color: ");
    scanf("%d", &choice);
    
    // Invoke the spell of color conversion
    invokeColorConversion(choice);
    
    printf("Let thine inspiration flow with the colors of the kingdom!\n");
    return 0;
}