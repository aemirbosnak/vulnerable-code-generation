//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: funny
#include <stdio.h>

// Excuse me, ladies and gentlemen, gather around! I present to you:
// The Amazing Hexadecimal Converter - where numbers meet their funky alter egos!
void toHex(int decimal, char *hex) {
    int i = 0;
    while (decimal != 0) {
        int remainder = decimal % 16;
        
        // Let's be real folks! What is a hexadecimal without some sassy representation?
        hex[i++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
        decimal /= 16;
    }

    // Uh-oh! We might have reversed our characters, let’s fix that!
    hex[i] = '\0';

    // Time to do the funky reverse dance
    for(int j = 0; j < i / 2; j++) {
        char temp = hex[j];
        hex[j] = hex[i - j - 1];
        hex[i - j - 1] = temp;
    }
}

// The big reveal function, where we ask our user how they want their numbers served!
void displayHex(int decimal) {
    char hex[100];
    toHex(decimal, hex);
    printf("🎉 After a wild ride through the decimal universe, %d transforms into the mighty hex: %s! 🎉\n", decimal, hex);
}

// Let's put on some user-friendly charm and guide them through this calculation adventure!
void welcome() {
    printf("Welcome to the Amazing Hexadecimal Converter!\n");
    printf("Where every decimal finds its inner hexadecimal self 🎉...\n");
    printf("Please enter a non-negative integer (or your favorite snack if you want to quit!): ");
}

int main() {
    int decimal;
    
    welcome();

    while (1) {
        // The Input Express Train is ready to depart! Let's get the user’s decimal number!
        char snack[50]; // In case someone tries to sneak a snack in instead of a number
        int n;
        if(scanf("%d", &n) == 1 && n >= 0) {
            decimal = n;
            displayHex(decimal);
        } else {
            scanf("%s", snack); // Catch the snack
            printf("🤔 Hmmm... I see someone’s sneaking snacks! So long and thanks for all the fish! 🐟💨\n");
            break;
        }

        // Fueling those brain cells for another round! No numbers? Just signals to grab a snack!
        printf("What’s your next decimal? Or do you need a snack break? (Enter snack or another number): ");
    }

    return 0;
}